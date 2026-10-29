// Boots the real BRAM bootloader against a behavioral DDR model preloaded with
// doom.bin (0x1000_0000) and DOOM1.WAD (0x1080_0000), and reports where it gets stuck.
#include <verilated.h>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <verilated_save.h>
#include "Vnucleusrv_soc_top.h"
#include "Vnucleusrv_soc_top___024root.h"

#define R top->rootp
#define SIG(n) R->nucleusrv_soc_top__DOT__##n

static void load(Vnucleusrv_soc_top* top, const char* path, uint32_t addr) {
    FILE* f = fopen(path, "rb");
    if (!f) { printf("cannot open %s\n", path); exit(1); }
    std::vector<uint8_t> b; int c;
    while ((c = fgetc(f)) != EOF) b.push_back((uint8_t)c);
    fclose(f);
    while (b.size() % 4) b.push_back(0);
    uint32_t base = (addr - 0x10000000u) / 4;
    for (size_t i = 0; i < b.size(); i += 4)
        SIG(u_zynq_soc__DOT__mem)[base + i / 4] = b[i] | b[i+1] << 8 | b[i+2] << 16 | (uint32_t)b[i+3] << 24;
    printf("[TB] loaded %s (%zu bytes) at 0x%08X\n", path, b.size(), addr);
}

static uint32_t ddr_rd(Vnucleusrv_soc_top* top, uint32_t a) {
    return R->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__mem[(a - 0x10000000u) / 4];
}
#define XREG(n) R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_##n

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    long max_cycles = argc > 1 ? atol(argv[1]) : 3000000;
    bool trace_ddr_pc = argc > 2;
    auto top = std::make_unique<Vnucleusrv_soc_top>();
    load(top.get(), getenv("BIN") ? getenv("BIN") : "doom/doom.bin", 0x10000000);
    load(top.get(), getenv("DATA") ? getenv("DATA") : "doom/DOOM1.WAD", 0x10800000);

    top->btn_rst = 1; top->uart_rxd = 1; top->clk = 0;
    for (int i = 0; i < 200; ++i) { top->clk ^= 1; top->eval(); }
    if (getenv("DIRECT")) {  // skip the bootloader: lui t0,0x10000 ; jr t0
        SIG(boot_ram)[0] = 0x100002b7;
        SIG(boot_ram)[1] = 0x00028067;
        printf("[TB] DIRECT: boot BRAM patched to jump to 0x10000000\n");
    }
    top->btn_rst = 0;

    // Checkpoints: SAVE_AT=<cycle> SAVE=<file> writes the full model state;
    // RESTORE=<file> resumes from it (cycle count is stored alongside).
    long restored_cycles = 0;
    if (getenv("RESTORE")) {
        VerilatedRestore is;
        is.open(getenv("RESTORE"));
        is >> *top;
        is.close();
        FILE* m = fopen((std::string(getenv("RESTORE")) + ".cyc").c_str(), "r");
        if (m) { if (fscanf(m, "%ld", &restored_cycles) != 1) restored_cycles = 0; fclose(m); }
        printf("[TB] restored %s at cycle %ld\n", getenv("RESTORE"), restored_cycles);
    }

    const int CPB = 25000000 / 115200;
    int rx_state = 0, rx_cnt = 0, bit = 0; uint8_t byte = 0;
    uint32_t last_pc = 0; long same_pc = 0, core_cycles = 0;
    int ddr_req_log = 0, pc_log = 0;
    bool entered_ddr = false;
    uint8_t prev_clk25 = SIG(clk25MHz);
    core_cycles = restored_cycles;
    if (restored_cycles) entered_ddr = true;
    long save_at = getenv("SAVE_AT") ? atol(getenv("SAVE_AT")) : -1;

    for (long t = 0; core_cycles < max_cycles; ++t) {
        top->clk ^= 1; top->eval();
        uint8_t c25 = SIG(clk25MHz);
        bool rise = c25 && !prev_clk25; prev_clk25 = c25;
        if (!rise) continue;
        core_cycles++;

        if (core_cycles == save_at && getenv("SAVE")) {
            VerilatedSave os;
            os.open(getenv("SAVE"));
            os << *top;
            os.close();
            FILE* m = fopen((std::string(getenv("SAVE")) + ".cyc").c_str(), "w");
            fprintf(m, "%ld\n", core_cycles); fclose(m);
            printf("[TB] saved state at cycle %ld to %s\n", core_cycles, getenv("SAVE"));
            fflush(stdout);
        }
        uint32_t pc = SIG(u_core__DOT__pc__DOT__pc_reg);
        static long bus_from = getenv("BUS_FROM") ? atol(getenv("BUS_FROM")) : -1;
        if (bus_from >= 0 && core_cycles >= bus_from && core_cycles < bus_from + 60)
            printf("[BUS] %ld pc=%03X req_v=%d rdy=%d %s addr=%08X wdata=%08X | rsp_v=%d rdata=%08X tgt=%d | s0v=%d s1v=%d\n",
                   core_cycles, pc, SIG(dmem_req_valid), SIG(dmem_req_ready), SIG(dmem_req_is_write) ? "W" : "R",
                   SIG(dmem_req_addr), SIG(dmem_req_wdata), SIG(dmem_rsp_valid), SIG(dmem_rsp_rdata),
                   SIG(u_bus__DOT__active_target), SIG(s0_rsp_valid), SIG(s1_rsp_valid));
        if (pc >= 0x10000000 && !entered_ddr) {
            entered_ddr = true;
            printf("[TB] cycle %ld: PC entered DDR (0x%08X)\n", core_cycles, pc);
        }
        if (trace_ddr_pc && entered_ddr && pc_log < 400 && pc != last_pc) {
            printf("[PC] %ld 0x%08X imem_valid=%d rsp_valid=%d ic_ready=%d\n", core_cycles, pc,
                   SIG(imem_req_valid), SIG(imem_rsp_valid), SIG(icache_cpu_req_ready));
            pc_log++;
        }
        if (SIG(s3_req_valid) && SIG(s3_req_ready) && ddr_req_log < 40) {
            printf("[DDR-D] cycle %ld %s addr=0x%08X pc=0x%08X\n", core_cycles,
                   SIG(s3_req_is_write) ? "WR" : "RD", SIG(s3_req_addr), pc);
            ddr_req_log++;
        }
        if (SIG(s3_rsp_valid) && ddr_req_log < 40) {
            printf("[DDR-D] cycle %ld rsp rdata=0x%08X rsp_ready=%d active_target=%d m_rsp_valid=%d\n",
                   core_cycles, SIG(s3_rsp_rdata), SIG(s3_rsp_ready),
                   SIG(u_bus__DOT__active_target), SIG(dmem_rsp_valid));
        }

        static long jtrace = getenv("JTRACE") ? atol(getenv("JTRACE")) : 0;
        static uint32_t prev_pc = 0;
        static long jfrom = getenv("JFROM") ? atol(getenv("JFROM")) : 0;
        if (jtrace > 0 && pc != prev_pc && core_cycles >= jfrom) {
            if (pc != prev_pc + 4 && pc != prev_pc + 2) {
                printf("[JMP] %ld 0x%08X -> 0x%08X\n", core_cycles, prev_pc, pc);
                jtrace--;
            }
            prev_pc = pc;
        }
        static bool utrace = getenv("UTRACE");
        if (utrace && SIG(s1_req_valid) && SIG(s1_req_ready) && SIG(s1_req_is_write) && (SIG(s1_req_addr) & 0xFF) == 0)
            printf("[UTX] %ld '%c' 0x%02X tx_ready=%d\n", core_cycles, SIG(s1_req_wdata) & 0x7F >= 32 ? SIG(s1_req_wdata) & 0xFF : '.',
                   SIG(s1_req_wdata) & 0xFF, SIG(u_periph__DOT__tx_ready));
        static long pfrom = getenv("PFROM") ? atol(getenv("PFROM")) : -1;
        static long plen = getenv("PLEN") ? atol(getenv("PLEN")) : 80;
        if (pfrom >= 0 && core_cycles >= pfrom && core_cycles < pfrom + plen)
            printf("[PIPE] %ld pc=%08X st=%d kill=%d ireq=%d irsp=%d/%d | IF/ID %08X@%08X ID/EX %08X EX/MEM %08X MEM/WB %08X | pcSrc=%d ifstall=%d dreq=%d drsp=%d | ra=%08X wb=%08X memToReg=%d mem_pc=%08X ex_pc=%08X\n",
                   core_cycles, pc, R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__kill,
                   SIG(imem_req_valid), SIG(imem_rsp_valid), SIG(imem_rsp_ready),
                   R->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_ins, R->nucleusrv_soc_top__DOT__u_core__DOT__if_reg_pc,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__id_reg_ins, R->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ins,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ins,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__io_pcSrc,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__io_stall,
                   SIG(dmem_req_valid), SIG(dmem_rsp_valid),
                   R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_1,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__wb_data,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ctl_memToReg,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_pc,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_pc);
        static bool rawatch = getenv("RAWATCH");
        static uint32_t prev_ra = 0;
        if (rawatch) {
            uint32_t ra = R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_1;
            if (ra != prev_ra) {
                printf("[RA] %ld ra 0x%08X -> 0x%08X  (MEM/WB ins %08X pc %08X)\n", core_cycles, prev_ra, ra,
                       R->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_ins, R->nucleusrv_soc_top__DOT__u_core__DOT__mem_reg_pc);
                prev_ra = ra;
            }
        }
        static long pcsample = getenv("PCSAMPLE") ? atol(getenv("PCSAMPLE")) : 0;
        if (pcsample && core_cycles % pcsample == 0) {
            int fb_nz = 0; uint32_t fb_hash = 0;
            for (int w = 0; w < 16000; ++w) {
                uint32_t v = SIG(u_video__DOT__fb_mem)[w];
                fb_nz += v != 0; fb_hash = fb_hash * 31 + v;
            }
            printf("[PCS] %ld 0x%08X sp=%08X fb_nonzero=%d fb_hash=%08X\n", core_cycles, pc,
                   R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionDecode__DOT__registers__DOT__i_reg_2,
                   fb_nz, fb_hash);
            fflush(stdout);
        }
        static long low_acc = 0;
        if (entered_ddr && SIG(s0_req_valid) && pc >= 0x10000000) {
            if (low_acc < 12)
                printf("[LOWMEM] %ld %s addr=0x%08X pc=0x%08X\n", core_cycles,
                       SIG(s0_req_is_write) ? "WR" : "RD", SIG(s0_req_addr), pc);
            low_acc++;
        }
        static bool texdbg = getenv("TEXDBG");
        static long loop_hits = 0;
        if (texdbg && pc == 0x10029504 && pc != last_pc) {
            if (++loop_hits == 2000) {
                uint32_t i = XREG(9), a4 = XREG(14), a5 = XREG(15);
                uint32_t textures = ddr_rd(top.get(), XREG(21) + 868);
                uint32_t hashtab = ddr_rd(top.get(), XREG(18) + 864);
                uint32_t num = ddr_rd(top.get(), XREG(19) + 872);
                printf("\n[TEX] stuck at cycle %ld: i=%u numtextures=%u textures=%08X hashtable=%08X a4=%08X a5=%08X\n",
                       core_cycles, i, num, textures, hashtab, a4, a5);
                uint32_t n = a5;
                for (int k = 0; k < 12 && n; ++k) {
                    printf("[TEX]   node %08X name=%.8s index=%u next=%08X\n", n,
                           (char*)&R->nucleusrv_soc_top__DOT__u_zynq_soc__DOT__mem[(n - 0x10000000u) / 4],
                           ddr_rd(top.get(), n + 12), ddr_rd(top.get(), n + 16));
                    n = ddr_rd(top.get(), n + 16);
                }
                for (uint32_t k = 0; k < num; ++k) {
                    uint32_t e = ddr_rd(top.get(), hashtab + 4 * k);
                    if (e) printf("[TEX]   bucket[%u] @%08X = %08X\n", k, hashtab + 4 * k, e);
                }
                for (uint32_t k = 0; k <= i && k < num; ++k) {
                    uint32_t t = ddr_rd(top.get(), textures + 4 * k);
                    for (uint32_t j = 0; j < k; ++j)
                        if (ddr_rd(top.get(), textures + 4 * j) == t)
                            printf("[TEX]   DUPLICATE textures[%u] == textures[%u] = %08X\n", j, k, t);
                    if (ddr_rd(top.get(), t + 12) != k)
                        printf("[TEX]   textures[%u]=%08X has index=%u\n", k, t, ddr_rd(top.get(), t + 12));
                }
                fflush(stdout);
                break;
            }
        }
        static uint32_t wlo = getenv("WATCH_LO") ? strtoul(getenv("WATCH_LO"), 0, 16) : 0;
        static uint32_t whi = getenv("WATCH_HI") ? strtoul(getenv("WATCH_HI"), 0, 16) : 0;
        if (wlo && SIG(dmem_req_valid) && SIG(dmem_req_ready) && SIG(dmem_req_is_write)) {
            uint32_t a = SIG(dmem_req_addr);
            static uint32_t wplo = getenv("WATCH_PCLO") ? strtoul(getenv("WATCH_PCLO"), 0, 16) : 0;
            static uint32_t wphi = getenv("WATCH_PCHI") ? strtoul(getenv("WATCH_PCHI"), 0, 16) : 0xFFFFFFFF;
            uint32_t mpc = R->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_pc;
            if (a >= wlo && a < whi && mpc >= wplo && mpc < wphi) {
                static long wcount = 0;
                uint32_t mempc = R->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_pc;
                if (wcount++ < 400 || SIG(dmem_req_wdata) != 0)
                    printf("[WATCH] %ld WR addr=%08X data=%08X mask=%X mem_pc=%08X\n", core_cycles, a,
                           SIG(dmem_req_wdata), SIG(dmem_req_wmask), mempc);
            }
        }
        // Protocol checker: a load may only complete after its request was accepted
        static bool check = getenv("CHECK");
        if (check) {
            static bool load_accepted = false;
            static long violations = 0;
            static uint32_t ring[64]; static int rpos = 0;
            static uint32_t rprev = 0;
            if (pc != rprev) { if (pc != rprev + 4 && pc != rprev + 2) ring[rpos++ & 63] = rprev, ring[rpos++ & 63] = pc; rprev = pc; }
            bool mem_read = R->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_ctl_memRead;
            bool fire = SIG(dmem_req_valid) && SIG(dmem_req_ready);
            if (fire && !SIG(dmem_req_is_write)) load_accepted = true;
            if (mem_read && SIG(dmem_rsp_valid)) {
                if (!load_accepted && violations++ < 10)
                    printf("[CHECK] %ld load at mem_pc=%08X addr=%08X completed without accepted request (rsp from target %d, data %08X)\n",
                           core_cycles, R->nucleusrv_soc_top__DOT__u_core__DOT__ex_reg_pc, SIG(dmem_req_addr),
                           SIG(u_bus__DOT__active_target), SIG(dmem_rsp_rdata));
                load_accepted = fire && !SIG(dmem_req_is_write);
            }
            if (entered_ddr && pc < 0x10000000 && core_cycles > 100) {
                printf("[CHECK] %ld jump into boot memory: pc=%08X; recent jumps:\n", core_cycles, pc);
                for (int k = 0; k < 64; k += 2)
                    printf("   %08X -> %08X\n", ring[(rpos + k) & 63], ring[(rpos + k + 1) & 63]);
                fflush(stdout);
                break;
            }
        }
        // Frame counter: entries into DG_DrawFrame (FRAME_PC=hex)
        static uint32_t frame_pc = getenv("FRAME_PC") ? strtoul(getenv("FRAME_PC"), 0, 16) : 0;
        if (frame_pc && pc == frame_pc && last_pc != frame_pc) {
            static long frames = 0, last_frame_cycle = 0;
            static uint32_t last_rd = 0, last_wr = 0, last_ird = 0;
            uint32_t rd = SIG(u_zynq_soc__DOT__dmem_rd_cnt), wr = SIG(u_zynq_soc__DOT__dmem_wr_cnt),
                     ird = SIG(u_zynq_soc__DOT__imem_rd_cnt);
            if (frames > 0)
                printf("[FRAME] %ld at %ld: %ld cycles (%.2f fps @25MHz) ddr_rd_bursts=%u ddr_wr_bursts=%u icache_refills=%u\n",
                       frames, core_cycles, core_cycles - last_frame_cycle,
                       25e6 / (double)(core_cycles - last_frame_cycle), rd - last_rd, wr - last_wr, ird - last_ird);
            fflush(stdout);
            frames++; last_frame_cycle = core_cycles; last_rd = rd; last_wr = wr; last_ird = ird;
        }
        // INPUT="cycle:sw:btn,..." sets switches/buttons from that cycle on (values in hex)
        static std::vector<std::array<long, 3>> input_script = [] {
            std::vector<std::array<long, 3>> v;
            if (const char* e = getenv("INPUT")) {
                std::string str(e);
                size_t pos = 0;
                while (pos < str.size()) {
                    size_t end = str.find(',', pos);
                    std::string item = str.substr(pos, end == std::string::npos ? std::string::npos : end - pos);
                    long c = 0, sw = 0, bt = 0;
                    if (sscanf(item.c_str(), "%ld:%lx:%lx", &c, &sw, &bt) == 3) v.push_back({c, sw, bt});
                    if (end == std::string::npos) break;
                    pos = end + 1;
                }
            }
            return v;
        }();
        for (auto& ev : input_script)
            if (ev[0] == core_cycles) {
                top->sw = ev[1]; top->btn = ev[2];
                printf("[INPUT] %ld sw=%lx btn=%lx\n", core_cycles, ev[1], ev[2]);
            }
        // FBDUMP_EVERY=N writes <FBDUMP>.<cycle>.ppm every N cycles
        static long fb_every = getenv("FBDUMP_EVERY") ? atol(getenv("FBDUMP_EVERY")) : 0;
        if (fb_every && getenv("FBDUMP") && core_cycles % fb_every == 0) {
            std::string name = std::string(getenv("FBDUMP")) + "." + std::to_string(core_cycles) + ".ppm";
            FILE* f = fopen(name.c_str(), "wb");
            fprintf(f, "P6\n320 200\n255\n");
            for (int i = 0; i < 64000; ++i) {
                uint32_t w = SIG(u_video__DOT__fb_mem)[i / 4];
                uint32_t rgb = SIG(u_video__DOT__palette_ram)[(w >> (8 * (i & 3))) & 0xFF];
                fputc((rgb >> 16) & 0xFF, f); fputc((rgb >> 8) & 0xFF, f); fputc(rgb & 0xFF, f);
            }
            fclose(f);
        }
        if (pc == last_pc) same_pc++; else { same_pc = 0; last_pc = pc; }
        if (same_pc == 200000) {
            printf("\n[TB] HANG: PC stuck at 0x%08X for 200k cycles (cycle %ld)\n", pc, core_cycles);
            printf("     dmem_req_valid=%d addr=0x%08X we=%d ready=%d | m_rsp_valid=%d active_target=%d\n",
                   SIG(dmem_req_valid), SIG(dmem_req_addr), SIG(dmem_req_is_write), SIG(dmem_req_ready),
                   SIG(dmem_rsp_valid), SIG(u_bus__DOT__active_target));
            printf("     dcache state=%d | icache state=%d\n",
                   SIG(u_dcache__DOT__state), SIG(u_icache__DOT__state));
            printf("     imem_req_valid=%d imem_addr=0x%08X imem_rsp_valid=%d fetch_state=%d\n",
                   SIG(imem_req_valid), SIG(imem_req_addr), SIG(imem_rsp_valid),
                   R->nucleusrv_soc_top__DOT__u_core__DOT__InstructionFetch__DOT__state_reg);
            printf("     DDR model: dmem reads=%u writes=%u imem reads=%u\n",
                   SIG(u_zynq_soc__DOT__dmem_rd_cnt), SIG(u_zynq_soc__DOT__dmem_wr_cnt),
                   SIG(u_zynq_soc__DOT__imem_rd_cnt));
            break;
        }

        int txd = top->uart_txd;
        switch (rx_state) {
            case 0: if (!txd) { rx_state = 1; rx_cnt = CPB / 2; } break;
            case 1: if (--rx_cnt == 0) { rx_state = 2; rx_cnt = CPB; bit = 0; byte = 0; } break;
            case 2: if (--rx_cnt == 0) { if (txd) byte |= 1 << bit; rx_cnt = CPB; if (++bit == 8) rx_state = 3; } break;
            case 3: if (--rx_cnt == 0) { rx_state = 0; putchar(byte); fflush(stdout); } break;
        }
    }
    if (getenv("FBDUMP")) {  // 320x200 PPM through the hardware palette
        FILE* f = fopen(getenv("FBDUMP"), "wb");
        fprintf(f, "P6\n320 200\n255\n");
        for (int i = 0; i < 64000; ++i) {
            uint32_t w = SIG(u_video__DOT__fb_mem)[i / 4];
            uint32_t rgb = SIG(u_video__DOT__palette_ram)[(w >> (8 * (i & 3))) & 0xFF];
            fputc((rgb >> 16) & 0xFF, f); fputc((rgb >> 8) & 0xFF, f); fputc(rgb & 0xFF, f);
        }
        fclose(f);
        printf("[TB] framebuffer written to %s\n", getenv("FBDUMP"));
    }
    printf("\n[TB] end: %ld core cycles, PC=0x%08X, fb word[60*80]=0x%08X (middle bar)\n",
           core_cycles, last_pc, SIG(u_video__DOT__fb_mem)[60 * 80]);
    return 0;
}
