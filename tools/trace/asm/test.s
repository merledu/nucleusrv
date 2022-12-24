
riscv_arithmetic_basic_test_0.o:     file format elf32-littleriscv


Disassembly of section .text:

80000000 <_start>:
80000000:	f14022f3          	csrr	t0,mhartid
80000004:	00000313          	li	t1,0
80000008:	00628263          	beq	t0,t1,8000000c <_start+0xc>
8000000c:	00000797          	auipc	a5,0x0
80000010:	00c78793          	addi	a5,a5,12 # 80000018 <h0_start>
80000014:	00078067          	jr	a5

80000018 <h0_start>:
80000018:	40000637          	lui	a2,0x40000
8000001c:	10060613          	addi	a2,a2,256 # 40000100 <_start-0x3fffff00>
80000020:	30161073          	csrw	misa,a2

80000024 <kernel_sp>:
80000024:	0000b697          	auipc	a3,0xb
80000028:	c6068693          	addi	a3,a3,-928 # 8000ac84 <kernel_stack_end>

8000002c <trap_vec_init>:
8000002c:	00001617          	auipc	a2,0x1
80000030:	ca460613          	addi	a2,a2,-860 # 80000cd0 <mtvec_handler>
80000034:	00166613          	ori	a2,a2,1
80000038:	30561073          	csrw	mtvec,a2

8000003c <mepc_setup>:
8000003c:	00000617          	auipc	a2,0x0
80000040:	02460613          	addi	a2,a2,36 # 80000060 <init>
80000044:	34161073          	csrw	mepc,a2

80000048 <init_machine_mode>:
80000048:	00002637          	lui	a2,0x2
8000004c:	c0060613          	addi	a2,a2,-1024 # 1c00 <_start-0x7fffe400>
80000050:	30061073          	csrw	mstatus,a2
80000054:	00000613          	li	a2,0
80000058:	30461073          	csrw	mie,a2
8000005c:	30200073          	mret

80000060 <init>:
80000060:	b8918037          	lui	zero,0xb8918
80000064:	63800013          	li	zero,1592
80000068:	00000093          	li	ra,0
8000006c:	00000113          	li	sp,0
80000070:	ad8ae1b7          	lui	gp,0xad8ae
80000074:	4fc18193          	addi	gp,gp,1276 # ad8ae4fc <_end+0x2d8a3874>
80000078:	08696237          	lui	tp,0x8696
8000007c:	01520213          	addi	tp,tp,21 # 8696015 <_start-0x77969feb>
80000080:	93b5c2b7          	lui	t0,0x93b5c
80000084:	72228293          	addi	t0,t0,1826 # 93b5c722 <_end+0x13b51a9a>
80000088:	fdc5d337          	lui	t1,0xfdc5d
8000008c:	09230313          	addi	t1,t1,146 # fdc5d092 <_end+0x7dc5240a>
80000090:	fe1b33b7          	lui	t2,0xfe1b3
80000094:	de338393          	addi	t2,t2,-541 # fe1b2de3 <_end+0x7e1a815b>
80000098:	00600413          	li	s0,6
8000009c:	fa8634b7          	lui	s1,0xfa863
800000a0:	0e648493          	addi	s1,s1,230 # fa8630e6 <_end+0x7a85845e>
800000a4:	093b5537          	lui	a0,0x93b5
800000a8:	93a50513          	addi	a0,a0,-1734 # 93b493a <_start-0x76c4b6c6>
800000ac:	00100593          	li	a1,1
800000b0:	00000613          	li	a2,0
800000b4:	f43c9737          	lui	a4,0xf43c9
800000b8:	21170713          	addi	a4,a4,529 # f43c9211 <_end+0x743be589>
800000bc:	00900793          	li	a5,9
800000c0:	80000837          	lui	a6,0x80000
800000c4:	022428b7          	lui	a7,0x2242
800000c8:	05888893          	addi	a7,a7,88 # 2242058 <_start-0x7ddbdfa8>
800000cc:	80000937          	lui	s2,0x80000
800000d0:	d1e3f9b7          	lui	s3,0xd1e3f
800000d4:	75698993          	addi	s3,s3,1878 # d1e3f756 <_end+0x51e34ace>
800000d8:	ff51da37          	lui	s4,0xff51d
800000dc:	4d8a0a13          	addi	s4,s4,1240 # ff51d4d8 <_end+0x7f512850>
800000e0:	0a692ab7          	lui	s5,0xa692
800000e4:	9a7a8a93          	addi	s5,s5,-1625 # a6919a7 <_start-0x7596e659>
800000e8:	00000b13          	li	s6,0
800000ec:	f6ab8bb7          	lui	s7,0xf6ab8
800000f0:	22cb8b93          	addi	s7,s7,556 # f6ab822c <_end+0x76aad5a4>
800000f4:	00200c13          	li	s8,2
800000f8:	4650ecb7          	lui	s9,0x4650e
800000fc:	f4fc8c93          	addi	s9,s9,-177 # 4650df4f <_start-0x39af20b1>
80000100:	fa83fd37          	lui	s10,0xfa83f
80000104:	d49d0d13          	addi	s10,s10,-695 # fa83ed49 <_end+0x7a8340c1>
80000108:	51a3de37          	lui	t3,0x51a3d
8000010c:	511e0e13          	addi	t3,t3,1297 # 51a3d511 <_start-0x2e5c2aef>
80000110:	00000e93          	li	t4,0
80000114:	80000f37          	lui	t5,0x80000
80000118:	00500f93          	li	t6,5
8000011c:	00006d97          	auipc	s11,0x6
80000120:	d48d8d93          	addi	s11,s11,-696 # 80005e64 <user_stack_end>

80000124 <main>:
80000124:	40830ab3          	sub	s5,t1,s0
80000128:	012aa3b3          	slt	t2,s5,s2
8000012c:	41640b33          	sub	s6,s0,s6
80000130:	bb7c8993          	addi	s3,s9,-1097
80000134:	40add413          	srai	s0,s11,0xa
80000138:	00b37033          	and	zero,t1,a1
8000013c:	c2a2b617          	auipc	a2,0xc2a2b
80000140:	41b75e93          	srai	t4,a4,0x1b
80000144:	013f74b3          	and	s1,t5,s3
80000148:	01d95eb3          	srl	t4,s2,t4
8000014c:	00472ab3          	slt	s5,a4,tp
80000150:	53b56813          	ori	a6,a0,1339
80000154:	00453033          	sltu	zero,a0,tp
80000158:	00000f93          	li	t6,0
8000015c:	00100f13          	li	t5,1
80000160:	00000d13          	li	s10,0
80000164:	00100393          	li	t2,1
80000168:	00000e93          	li	t4,0
8000016c:	00000e13          	li	t3,0
80000170:	00000513          	li	a0,0
80000174:	00000a93          	li	s5,0
80000178:	3e638937          	lui	s2,0x3e638
8000017c:	d2790913          	addi	s2,s2,-729 # 3e637d27 <_start-0x419c82d9>
80000180:	63b90cb7          	lui	s9,0x63b90
80000184:	f93c8c93          	addi	s9,s9,-109 # 63b8ff93 <_start-0x1c47006d>
80000188:	00000013          	nop
8000018c:	018c08b3          	add	a7,s8,s8
80000190:	41a705b3          	sub	a1,a4,s10
80000194:	00000013          	nop
80000198:	00460fb3          	add	t6,a2,tp
8000019c:	c4340293          	addi	t0,s0,-957
800001a0:	4d6a1bb7          	lui	s7,0x4d6a1
800001a4:	00a500b3          	add	ra,a0,a0
800001a8:	00000013          	nop
800001ac:	00000013          	nop
800001b0:	011b80b3          	add	ra,s7,a7
800001b4:	cd2bd737          	lui	a4,0xcd2bd
800001b8:	00000013          	nop
800001bc:	410d8033          	sub	zero,s11,a6
800001c0:	b1b241b7          	lui	gp,0xb1b24
800001c4:	b4980e93          	addi	t4,a6,-1207 # 7ffffb49 <_end+0xffff4ec1>
800001c8:	fa628013          	addi	zero,t0,-90
800001cc:	00000013          	nop
800001d0:	017589b3          	add	s3,a1,s7
800001d4:	00f50fb3          	add	t6,a0,a5
800001d8:	010c8a33          	add	s4,s9,a6
800001dc:	404f08b3          	sub	a7,t5,tp
800001e0:	00000013          	nop
800001e4:	00000013          	nop
800001e8:	9d02e237          	lui	tp,0x9d02e
800001ec:	00000013          	nop
800001f0:	00000013          	nop
800001f4:	00000013          	nop
800001f8:	ba892337          	lui	t1,0xba892
800001fc:	40ac03b3          	sub	t2,s8,a0
80000200:	01109313          	slli	t1,ra,0x11
80000204:	41e2d013          	srai	zero,t0,0x1e
80000208:	94253313          	sltiu	t1,a0,-1726
8000020c:	43030813          	addi	a6,t1,1072 # ba892430 <_end+0x3a8877a8>
80000210:	ac632093          	slti	ra,t1,-1338
80000214:	00e8d033          	srl	zero,a7,a4
80000218:	010e54b3          	srl	s1,t3,a6
8000021c:	401a8033          	sub	zero,s5,ra
80000220:	01d80533          	add	a0,a6,t4
80000224:	0041d113          	srli	sp,gp,0x4
80000228:	00c625b3          	slt	a1,a2,a2
8000022c:	faf2bd13          	sltiu	s10,t0,-81
80000230:	84c80513          	addi	a0,a6,-1972
80000234:	0139a933          	slt	s2,s3,s3
80000238:	019a5193          	srli	gp,s4,0x19
8000023c:	007558b3          	srl	a7,a0,t2
80000240:	01d11fb3          	sll	t6,sp,t4
80000244:	4091db93          	srai	s7,gp,0x9
80000248:	e1e0c293          	xori	t0,ra,-482
8000024c:	414b5d13          	srai	s10,s6,0x14
80000250:	c4149fb7          	lui	t6,0xc4149
80000254:	015f9513          	slli	a0,t6,0x15
80000258:	41c305b3          	sub	a1,t1,t3
8000025c:	01680133          	add	sp,a6,s6
80000260:	0199dab3          	srl	s5,s3,s9
80000264:	00c34033          	xor	zero,t1,a2
80000268:	b2494013          	xori	zero,s2,-1244
8000026c:	8d186013          	ori	zero,a6,-1839
80000270:	414e82b3          	sub	t0,t4,s4
80000274:	414c5b93          	srai	s7,s8,0x14
80000278:	007f9e93          	slli	t4,t6,0x7
8000027c:	3bfea013          	slti	zero,t4,959
80000280:	0112d093          	srli	ra,t0,0x11
80000284:	01bb35b3          	sltu	a1,s6,s11
80000288:	404754b3          	sra	s1,a4,tp
8000028c:	0af9c893          	xori	a7,s3,175
80000290:	014385b3          	add	a1,t2,s4
80000294:	01ff9013          	slli	zero,t6,0x1f
80000298:	0151d1b3          	srl	gp,gp,s5
8000029c:	00769033          	sll	zero,a3,t2
800002a0:	44dbc093          	xori	ra,s7,1101
800002a4:	e2516837          	lui	a6,0xe2516
800002a8:	e18b4a13          	xori	s4,s6,-488
800002ac:	00000013          	nop
800002b0:	ce42bb97          	auipc	s7,0xce42b
800002b4:	0892b013          	sltiu	zero,t0,137
800002b8:	01cac5b3          	xor	a1,s5,t3
800002bc:	41a55533          	sra	a0,a0,s10
800002c0:	00000013          	nop
800002c4:	018a1633          	sll	a2,s4,s8
800002c8:	0197e4b3          	or	s1,a5,s9
800002cc:	419cd4b3          	sra	s1,s9,s9
800002d0:	003cd213          	srli	tp,s9,0x3
800002d4:	007def33          	or	t5,s11,t2
800002d8:	00afe333          	or	t1,t6,a0
800002dc:	01e28bb3          	add	s7,t0,t5
800002e0:	00000013          	nop
800002e4:	012a8b33          	add	s6,s5,s2
800002e8:	00779f93          	slli	t6,a5,0x7
800002ec:	4068da93          	srai	s5,a7,0x6
800002f0:	41140133          	sub	sp,s0,a7
800002f4:	004ad033          	srl	zero,s5,tp
800002f8:	019f2833          	slt	a6,t5,s9
800002fc:	f66abe93          	sltiu	t4,s5,-154
80000300:	01dd9f33          	sll	t5,s11,t4
80000304:	00552033          	slt	zero,a0,t0
80000308:	1ac17913          	andi	s2,sp,428
8000030c:	00000013          	nop
80000310:	00000797          	auipc	a5,0x0
80000314:	00c78793          	addi	a5,a5,12 # 8000031c <test_done>
80000318:	00078067          	jr	a5

8000031c <test_done>:
8000031c:	00100193          	li	gp,1
80000320:	00000073          	ecall

80000324 <write_tohost>:
80000324:	00001f17          	auipc	t5,0x1
80000328:	cc3f2e23          	sw	gp,-804(t5) # 80001000 <tohost>

8000032c <_exit>:
8000032c:	ff9ff06f          	j	80000324 <write_tohost>

80000330 <instr_end>:
80000330:	00000013          	nop

80000334 <mmode_intr_vector_1>:
80000334:	340d9df3          	csrrw	s11,mscratch,s11
80000338:	00068db3          	add	s11,a3,zero
8000033c:	f84d8d93          	addi	s11,s11,-124
80000340:	001da223          	sw	ra,4(s11)
80000344:	002da423          	sw	sp,8(s11)
80000348:	003da623          	sw	gp,12(s11)
8000034c:	004da823          	sw	tp,16(s11)
80000350:	005daa23          	sw	t0,20(s11)
80000354:	006dac23          	sw	t1,24(s11)
80000358:	007dae23          	sw	t2,28(s11)
8000035c:	028da023          	sw	s0,32(s11)
80000360:	029da223          	sw	s1,36(s11)
80000364:	02ada423          	sw	a0,40(s11)
80000368:	02bda623          	sw	a1,44(s11)
8000036c:	02cda823          	sw	a2,48(s11)
80000370:	02ddaa23          	sw	a3,52(s11)
80000374:	02edac23          	sw	a4,56(s11)
80000378:	02fdae23          	sw	a5,60(s11)
8000037c:	050da023          	sw	a6,64(s11)
80000380:	051da223          	sw	a7,68(s11)
80000384:	052da423          	sw	s2,72(s11)
80000388:	053da623          	sw	s3,76(s11)
8000038c:	054da823          	sw	s4,80(s11)
80000390:	055daa23          	sw	s5,84(s11)
80000394:	056dac23          	sw	s6,88(s11)
80000398:	057dae23          	sw	s7,92(s11)
8000039c:	078da023          	sw	s8,96(s11)
800003a0:	079da223          	sw	s9,100(s11)
800003a4:	07ada423          	sw	s10,104(s11)
800003a8:	07bda623          	sw	s11,108(s11)
800003ac:	07cda823          	sw	t3,112(s11)
800003b0:	07ddaa23          	sw	t4,116(s11)
800003b4:	07edac23          	sw	t5,120(s11)
800003b8:	07fdae23          	sw	t6,124(s11)
800003bc:	34202673          	csrr	a2,mcause
800003c0:	01f65613          	srli	a2,a2,0x1f
800003c4:	00060463          	beqz	a2,800003cc <mmode_intr_vector_1+0x98>
800003c8:	3250006f          	j	80000eec <mmode_intr_handler>
800003cc:	00000797          	auipc	a5,0x0
800003d0:	f5078793          	addi	a5,a5,-176 # 8000031c <test_done>
800003d4:	00078067          	jr	a5

800003d8 <mmode_intr_vector_2>:
800003d8:	340d9df3          	csrrw	s11,mscratch,s11
800003dc:	00068db3          	add	s11,a3,zero
800003e0:	f84d8d93          	addi	s11,s11,-124
800003e4:	001da223          	sw	ra,4(s11)
800003e8:	002da423          	sw	sp,8(s11)
800003ec:	003da623          	sw	gp,12(s11)
800003f0:	004da823          	sw	tp,16(s11)
800003f4:	005daa23          	sw	t0,20(s11)
800003f8:	006dac23          	sw	t1,24(s11)
800003fc:	007dae23          	sw	t2,28(s11)
80000400:	028da023          	sw	s0,32(s11)
80000404:	029da223          	sw	s1,36(s11)
80000408:	02ada423          	sw	a0,40(s11)
8000040c:	02bda623          	sw	a1,44(s11)
80000410:	02cda823          	sw	a2,48(s11)
80000414:	02ddaa23          	sw	a3,52(s11)
80000418:	02edac23          	sw	a4,56(s11)
8000041c:	02fdae23          	sw	a5,60(s11)
80000420:	050da023          	sw	a6,64(s11)
80000424:	051da223          	sw	a7,68(s11)
80000428:	052da423          	sw	s2,72(s11)
8000042c:	053da623          	sw	s3,76(s11)
80000430:	054da823          	sw	s4,80(s11)
80000434:	055daa23          	sw	s5,84(s11)
80000438:	056dac23          	sw	s6,88(s11)
8000043c:	057dae23          	sw	s7,92(s11)
80000440:	078da023          	sw	s8,96(s11)
80000444:	079da223          	sw	s9,100(s11)
80000448:	07ada423          	sw	s10,104(s11)
8000044c:	07bda623          	sw	s11,108(s11)
80000450:	07cda823          	sw	t3,112(s11)
80000454:	07ddaa23          	sw	t4,116(s11)
80000458:	07edac23          	sw	t5,120(s11)
8000045c:	07fdae23          	sw	t6,124(s11)
80000460:	34202673          	csrr	a2,mcause
80000464:	01f65613          	srli	a2,a2,0x1f
80000468:	00060463          	beqz	a2,80000470 <mmode_intr_vector_2+0x98>
8000046c:	2810006f          	j	80000eec <mmode_intr_handler>
80000470:	00000797          	auipc	a5,0x0
80000474:	eac78793          	addi	a5,a5,-340 # 8000031c <test_done>
80000478:	00078067          	jr	a5

8000047c <mmode_intr_vector_3>:
8000047c:	340d9df3          	csrrw	s11,mscratch,s11
80000480:	00068db3          	add	s11,a3,zero
80000484:	f84d8d93          	addi	s11,s11,-124
80000488:	001da223          	sw	ra,4(s11)
8000048c:	002da423          	sw	sp,8(s11)
80000490:	003da623          	sw	gp,12(s11)
80000494:	004da823          	sw	tp,16(s11)
80000498:	005daa23          	sw	t0,20(s11)
8000049c:	006dac23          	sw	t1,24(s11)
800004a0:	007dae23          	sw	t2,28(s11)
800004a4:	028da023          	sw	s0,32(s11)
800004a8:	029da223          	sw	s1,36(s11)
800004ac:	02ada423          	sw	a0,40(s11)
800004b0:	02bda623          	sw	a1,44(s11)
800004b4:	02cda823          	sw	a2,48(s11)
800004b8:	02ddaa23          	sw	a3,52(s11)
800004bc:	02edac23          	sw	a4,56(s11)
800004c0:	02fdae23          	sw	a5,60(s11)
800004c4:	050da023          	sw	a6,64(s11)
800004c8:	051da223          	sw	a7,68(s11)
800004cc:	052da423          	sw	s2,72(s11)
800004d0:	053da623          	sw	s3,76(s11)
800004d4:	054da823          	sw	s4,80(s11)
800004d8:	055daa23          	sw	s5,84(s11)
800004dc:	056dac23          	sw	s6,88(s11)
800004e0:	057dae23          	sw	s7,92(s11)
800004e4:	078da023          	sw	s8,96(s11)
800004e8:	079da223          	sw	s9,100(s11)
800004ec:	07ada423          	sw	s10,104(s11)
800004f0:	07bda623          	sw	s11,108(s11)
800004f4:	07cda823          	sw	t3,112(s11)
800004f8:	07ddaa23          	sw	t4,116(s11)
800004fc:	07edac23          	sw	t5,120(s11)
80000500:	07fdae23          	sw	t6,124(s11)
80000504:	34202673          	csrr	a2,mcause
80000508:	01f65613          	srli	a2,a2,0x1f
8000050c:	00060463          	beqz	a2,80000514 <mmode_intr_vector_3+0x98>
80000510:	1dd0006f          	j	80000eec <mmode_intr_handler>
80000514:	00000797          	auipc	a5,0x0
80000518:	e0878793          	addi	a5,a5,-504 # 8000031c <test_done>
8000051c:	00078067          	jr	a5

80000520 <mmode_intr_vector_4>:
80000520:	340d9df3          	csrrw	s11,mscratch,s11
80000524:	00068db3          	add	s11,a3,zero
80000528:	f84d8d93          	addi	s11,s11,-124
8000052c:	001da223          	sw	ra,4(s11)
80000530:	002da423          	sw	sp,8(s11)
80000534:	003da623          	sw	gp,12(s11)
80000538:	004da823          	sw	tp,16(s11)
8000053c:	005daa23          	sw	t0,20(s11)
80000540:	006dac23          	sw	t1,24(s11)
80000544:	007dae23          	sw	t2,28(s11)
80000548:	028da023          	sw	s0,32(s11)
8000054c:	029da223          	sw	s1,36(s11)
80000550:	02ada423          	sw	a0,40(s11)
80000554:	02bda623          	sw	a1,44(s11)
80000558:	02cda823          	sw	a2,48(s11)
8000055c:	02ddaa23          	sw	a3,52(s11)
80000560:	02edac23          	sw	a4,56(s11)
80000564:	02fdae23          	sw	a5,60(s11)
80000568:	050da023          	sw	a6,64(s11)
8000056c:	051da223          	sw	a7,68(s11)
80000570:	052da423          	sw	s2,72(s11)
80000574:	053da623          	sw	s3,76(s11)
80000578:	054da823          	sw	s4,80(s11)
8000057c:	055daa23          	sw	s5,84(s11)
80000580:	056dac23          	sw	s6,88(s11)
80000584:	057dae23          	sw	s7,92(s11)
80000588:	078da023          	sw	s8,96(s11)
8000058c:	079da223          	sw	s9,100(s11)
80000590:	07ada423          	sw	s10,104(s11)
80000594:	07bda623          	sw	s11,108(s11)
80000598:	07cda823          	sw	t3,112(s11)
8000059c:	07ddaa23          	sw	t4,116(s11)
800005a0:	07edac23          	sw	t5,120(s11)
800005a4:	07fdae23          	sw	t6,124(s11)
800005a8:	34202673          	csrr	a2,mcause
800005ac:	01f65613          	srli	a2,a2,0x1f
800005b0:	00060463          	beqz	a2,800005b8 <mmode_intr_vector_4+0x98>
800005b4:	1390006f          	j	80000eec <mmode_intr_handler>
800005b8:	00000797          	auipc	a5,0x0
800005bc:	d6478793          	addi	a5,a5,-668 # 8000031c <test_done>
800005c0:	00078067          	jr	a5

800005c4 <mmode_intr_vector_5>:
800005c4:	340d9df3          	csrrw	s11,mscratch,s11
800005c8:	00068db3          	add	s11,a3,zero
800005cc:	f84d8d93          	addi	s11,s11,-124
800005d0:	001da223          	sw	ra,4(s11)
800005d4:	002da423          	sw	sp,8(s11)
800005d8:	003da623          	sw	gp,12(s11)
800005dc:	004da823          	sw	tp,16(s11)
800005e0:	005daa23          	sw	t0,20(s11)
800005e4:	006dac23          	sw	t1,24(s11)
800005e8:	007dae23          	sw	t2,28(s11)
800005ec:	028da023          	sw	s0,32(s11)
800005f0:	029da223          	sw	s1,36(s11)
800005f4:	02ada423          	sw	a0,40(s11)
800005f8:	02bda623          	sw	a1,44(s11)
800005fc:	02cda823          	sw	a2,48(s11)
80000600:	02ddaa23          	sw	a3,52(s11)
80000604:	02edac23          	sw	a4,56(s11)
80000608:	02fdae23          	sw	a5,60(s11)
8000060c:	050da023          	sw	a6,64(s11)
80000610:	051da223          	sw	a7,68(s11)
80000614:	052da423          	sw	s2,72(s11)
80000618:	053da623          	sw	s3,76(s11)
8000061c:	054da823          	sw	s4,80(s11)
80000620:	055daa23          	sw	s5,84(s11)
80000624:	056dac23          	sw	s6,88(s11)
80000628:	057dae23          	sw	s7,92(s11)
8000062c:	078da023          	sw	s8,96(s11)
80000630:	079da223          	sw	s9,100(s11)
80000634:	07ada423          	sw	s10,104(s11)
80000638:	07bda623          	sw	s11,108(s11)
8000063c:	07cda823          	sw	t3,112(s11)
80000640:	07ddaa23          	sw	t4,116(s11)
80000644:	07edac23          	sw	t5,120(s11)
80000648:	07fdae23          	sw	t6,124(s11)
8000064c:	34202673          	csrr	a2,mcause
80000650:	01f65613          	srli	a2,a2,0x1f
80000654:	00060463          	beqz	a2,8000065c <mmode_intr_vector_5+0x98>
80000658:	0950006f          	j	80000eec <mmode_intr_handler>
8000065c:	00000797          	auipc	a5,0x0
80000660:	cc078793          	addi	a5,a5,-832 # 8000031c <test_done>
80000664:	00078067          	jr	a5

80000668 <mmode_intr_vector_6>:
80000668:	340d9df3          	csrrw	s11,mscratch,s11
8000066c:	00068db3          	add	s11,a3,zero
80000670:	f84d8d93          	addi	s11,s11,-124
80000674:	001da223          	sw	ra,4(s11)
80000678:	002da423          	sw	sp,8(s11)
8000067c:	003da623          	sw	gp,12(s11)
80000680:	004da823          	sw	tp,16(s11)
80000684:	005daa23          	sw	t0,20(s11)
80000688:	006dac23          	sw	t1,24(s11)
8000068c:	007dae23          	sw	t2,28(s11)
80000690:	028da023          	sw	s0,32(s11)
80000694:	029da223          	sw	s1,36(s11)
80000698:	02ada423          	sw	a0,40(s11)
8000069c:	02bda623          	sw	a1,44(s11)
800006a0:	02cda823          	sw	a2,48(s11)
800006a4:	02ddaa23          	sw	a3,52(s11)
800006a8:	02edac23          	sw	a4,56(s11)
800006ac:	02fdae23          	sw	a5,60(s11)
800006b0:	050da023          	sw	a6,64(s11)
800006b4:	051da223          	sw	a7,68(s11)
800006b8:	052da423          	sw	s2,72(s11)
800006bc:	053da623          	sw	s3,76(s11)
800006c0:	054da823          	sw	s4,80(s11)
800006c4:	055daa23          	sw	s5,84(s11)
800006c8:	056dac23          	sw	s6,88(s11)
800006cc:	057dae23          	sw	s7,92(s11)
800006d0:	078da023          	sw	s8,96(s11)
800006d4:	079da223          	sw	s9,100(s11)
800006d8:	07ada423          	sw	s10,104(s11)
800006dc:	07bda623          	sw	s11,108(s11)
800006e0:	07cda823          	sw	t3,112(s11)
800006e4:	07ddaa23          	sw	t4,116(s11)
800006e8:	07edac23          	sw	t5,120(s11)
800006ec:	07fdae23          	sw	t6,124(s11)
800006f0:	34202673          	csrr	a2,mcause
800006f4:	01f65613          	srli	a2,a2,0x1f
800006f8:	00060463          	beqz	a2,80000700 <mmode_intr_vector_6+0x98>
800006fc:	7f00006f          	j	80000eec <mmode_intr_handler>
80000700:	00000797          	auipc	a5,0x0
80000704:	c1c78793          	addi	a5,a5,-996 # 8000031c <test_done>
80000708:	00078067          	jr	a5

8000070c <mmode_intr_vector_7>:
8000070c:	340d9df3          	csrrw	s11,mscratch,s11
80000710:	00068db3          	add	s11,a3,zero
80000714:	f84d8d93          	addi	s11,s11,-124
80000718:	001da223          	sw	ra,4(s11)
8000071c:	002da423          	sw	sp,8(s11)
80000720:	003da623          	sw	gp,12(s11)
80000724:	004da823          	sw	tp,16(s11)
80000728:	005daa23          	sw	t0,20(s11)
8000072c:	006dac23          	sw	t1,24(s11)
80000730:	007dae23          	sw	t2,28(s11)
80000734:	028da023          	sw	s0,32(s11)
80000738:	029da223          	sw	s1,36(s11)
8000073c:	02ada423          	sw	a0,40(s11)
80000740:	02bda623          	sw	a1,44(s11)
80000744:	02cda823          	sw	a2,48(s11)
80000748:	02ddaa23          	sw	a3,52(s11)
8000074c:	02edac23          	sw	a4,56(s11)
80000750:	02fdae23          	sw	a5,60(s11)
80000754:	050da023          	sw	a6,64(s11)
80000758:	051da223          	sw	a7,68(s11)
8000075c:	052da423          	sw	s2,72(s11)
80000760:	053da623          	sw	s3,76(s11)
80000764:	054da823          	sw	s4,80(s11)
80000768:	055daa23          	sw	s5,84(s11)
8000076c:	056dac23          	sw	s6,88(s11)
80000770:	057dae23          	sw	s7,92(s11)
80000774:	078da023          	sw	s8,96(s11)
80000778:	079da223          	sw	s9,100(s11)
8000077c:	07ada423          	sw	s10,104(s11)
80000780:	07bda623          	sw	s11,108(s11)
80000784:	07cda823          	sw	t3,112(s11)
80000788:	07ddaa23          	sw	t4,116(s11)
8000078c:	07edac23          	sw	t5,120(s11)
80000790:	07fdae23          	sw	t6,124(s11)
80000794:	34202673          	csrr	a2,mcause
80000798:	01f65613          	srli	a2,a2,0x1f
8000079c:	00060463          	beqz	a2,800007a4 <mmode_intr_vector_7+0x98>
800007a0:	74c0006f          	j	80000eec <mmode_intr_handler>
800007a4:	00000797          	auipc	a5,0x0
800007a8:	b7878793          	addi	a5,a5,-1160 # 8000031c <test_done>
800007ac:	00078067          	jr	a5

800007b0 <mmode_intr_vector_8>:
800007b0:	340d9df3          	csrrw	s11,mscratch,s11
800007b4:	00068db3          	add	s11,a3,zero
800007b8:	f84d8d93          	addi	s11,s11,-124
800007bc:	001da223          	sw	ra,4(s11)
800007c0:	002da423          	sw	sp,8(s11)
800007c4:	003da623          	sw	gp,12(s11)
800007c8:	004da823          	sw	tp,16(s11)
800007cc:	005daa23          	sw	t0,20(s11)
800007d0:	006dac23          	sw	t1,24(s11)
800007d4:	007dae23          	sw	t2,28(s11)
800007d8:	028da023          	sw	s0,32(s11)
800007dc:	029da223          	sw	s1,36(s11)
800007e0:	02ada423          	sw	a0,40(s11)
800007e4:	02bda623          	sw	a1,44(s11)
800007e8:	02cda823          	sw	a2,48(s11)
800007ec:	02ddaa23          	sw	a3,52(s11)
800007f0:	02edac23          	sw	a4,56(s11)
800007f4:	02fdae23          	sw	a5,60(s11)
800007f8:	050da023          	sw	a6,64(s11)
800007fc:	051da223          	sw	a7,68(s11)
80000800:	052da423          	sw	s2,72(s11)
80000804:	053da623          	sw	s3,76(s11)
80000808:	054da823          	sw	s4,80(s11)
8000080c:	055daa23          	sw	s5,84(s11)
80000810:	056dac23          	sw	s6,88(s11)
80000814:	057dae23          	sw	s7,92(s11)
80000818:	078da023          	sw	s8,96(s11)
8000081c:	079da223          	sw	s9,100(s11)
80000820:	07ada423          	sw	s10,104(s11)
80000824:	07bda623          	sw	s11,108(s11)
80000828:	07cda823          	sw	t3,112(s11)
8000082c:	07ddaa23          	sw	t4,116(s11)
80000830:	07edac23          	sw	t5,120(s11)
80000834:	07fdae23          	sw	t6,124(s11)
80000838:	34202673          	csrr	a2,mcause
8000083c:	01f65613          	srli	a2,a2,0x1f
80000840:	00060463          	beqz	a2,80000848 <mmode_intr_vector_8+0x98>
80000844:	6a80006f          	j	80000eec <mmode_intr_handler>
80000848:	00000797          	auipc	a5,0x0
8000084c:	ad478793          	addi	a5,a5,-1324 # 8000031c <test_done>
80000850:	00078067          	jr	a5

80000854 <mmode_intr_vector_9>:
80000854:	340d9df3          	csrrw	s11,mscratch,s11
80000858:	00068db3          	add	s11,a3,zero
8000085c:	f84d8d93          	addi	s11,s11,-124
80000860:	001da223          	sw	ra,4(s11)
80000864:	002da423          	sw	sp,8(s11)
80000868:	003da623          	sw	gp,12(s11)
8000086c:	004da823          	sw	tp,16(s11)
80000870:	005daa23          	sw	t0,20(s11)
80000874:	006dac23          	sw	t1,24(s11)
80000878:	007dae23          	sw	t2,28(s11)
8000087c:	028da023          	sw	s0,32(s11)
80000880:	029da223          	sw	s1,36(s11)
80000884:	02ada423          	sw	a0,40(s11)
80000888:	02bda623          	sw	a1,44(s11)
8000088c:	02cda823          	sw	a2,48(s11)
80000890:	02ddaa23          	sw	a3,52(s11)
80000894:	02edac23          	sw	a4,56(s11)
80000898:	02fdae23          	sw	a5,60(s11)
8000089c:	050da023          	sw	a6,64(s11)
800008a0:	051da223          	sw	a7,68(s11)
800008a4:	052da423          	sw	s2,72(s11)
800008a8:	053da623          	sw	s3,76(s11)
800008ac:	054da823          	sw	s4,80(s11)
800008b0:	055daa23          	sw	s5,84(s11)
800008b4:	056dac23          	sw	s6,88(s11)
800008b8:	057dae23          	sw	s7,92(s11)
800008bc:	078da023          	sw	s8,96(s11)
800008c0:	079da223          	sw	s9,100(s11)
800008c4:	07ada423          	sw	s10,104(s11)
800008c8:	07bda623          	sw	s11,108(s11)
800008cc:	07cda823          	sw	t3,112(s11)
800008d0:	07ddaa23          	sw	t4,116(s11)
800008d4:	07edac23          	sw	t5,120(s11)
800008d8:	07fdae23          	sw	t6,124(s11)
800008dc:	34202673          	csrr	a2,mcause
800008e0:	01f65613          	srli	a2,a2,0x1f
800008e4:	00060463          	beqz	a2,800008ec <mmode_intr_vector_9+0x98>
800008e8:	6040006f          	j	80000eec <mmode_intr_handler>
800008ec:	00000797          	auipc	a5,0x0
800008f0:	a3078793          	addi	a5,a5,-1488 # 8000031c <test_done>
800008f4:	00078067          	jr	a5

800008f8 <mmode_intr_vector_10>:
800008f8:	340d9df3          	csrrw	s11,mscratch,s11
800008fc:	00068db3          	add	s11,a3,zero
80000900:	f84d8d93          	addi	s11,s11,-124
80000904:	001da223          	sw	ra,4(s11)
80000908:	002da423          	sw	sp,8(s11)
8000090c:	003da623          	sw	gp,12(s11)
80000910:	004da823          	sw	tp,16(s11)
80000914:	005daa23          	sw	t0,20(s11)
80000918:	006dac23          	sw	t1,24(s11)
8000091c:	007dae23          	sw	t2,28(s11)
80000920:	028da023          	sw	s0,32(s11)
80000924:	029da223          	sw	s1,36(s11)
80000928:	02ada423          	sw	a0,40(s11)
8000092c:	02bda623          	sw	a1,44(s11)
80000930:	02cda823          	sw	a2,48(s11)
80000934:	02ddaa23          	sw	a3,52(s11)
80000938:	02edac23          	sw	a4,56(s11)
8000093c:	02fdae23          	sw	a5,60(s11)
80000940:	050da023          	sw	a6,64(s11)
80000944:	051da223          	sw	a7,68(s11)
80000948:	052da423          	sw	s2,72(s11)
8000094c:	053da623          	sw	s3,76(s11)
80000950:	054da823          	sw	s4,80(s11)
80000954:	055daa23          	sw	s5,84(s11)
80000958:	056dac23          	sw	s6,88(s11)
8000095c:	057dae23          	sw	s7,92(s11)
80000960:	078da023          	sw	s8,96(s11)
80000964:	079da223          	sw	s9,100(s11)
80000968:	07ada423          	sw	s10,104(s11)
8000096c:	07bda623          	sw	s11,108(s11)
80000970:	07cda823          	sw	t3,112(s11)
80000974:	07ddaa23          	sw	t4,116(s11)
80000978:	07edac23          	sw	t5,120(s11)
8000097c:	07fdae23          	sw	t6,124(s11)
80000980:	34202673          	csrr	a2,mcause
80000984:	01f65613          	srli	a2,a2,0x1f
80000988:	00060463          	beqz	a2,80000990 <mmode_intr_vector_10+0x98>
8000098c:	5600006f          	j	80000eec <mmode_intr_handler>
80000990:	00000797          	auipc	a5,0x0
80000994:	98c78793          	addi	a5,a5,-1652 # 8000031c <test_done>
80000998:	00078067          	jr	a5

8000099c <mmode_intr_vector_11>:
8000099c:	340d9df3          	csrrw	s11,mscratch,s11
800009a0:	00068db3          	add	s11,a3,zero
800009a4:	f84d8d93          	addi	s11,s11,-124
800009a8:	001da223          	sw	ra,4(s11)
800009ac:	002da423          	sw	sp,8(s11)
800009b0:	003da623          	sw	gp,12(s11)
800009b4:	004da823          	sw	tp,16(s11)
800009b8:	005daa23          	sw	t0,20(s11)
800009bc:	006dac23          	sw	t1,24(s11)
800009c0:	007dae23          	sw	t2,28(s11)
800009c4:	028da023          	sw	s0,32(s11)
800009c8:	029da223          	sw	s1,36(s11)
800009cc:	02ada423          	sw	a0,40(s11)
800009d0:	02bda623          	sw	a1,44(s11)
800009d4:	02cda823          	sw	a2,48(s11)
800009d8:	02ddaa23          	sw	a3,52(s11)
800009dc:	02edac23          	sw	a4,56(s11)
800009e0:	02fdae23          	sw	a5,60(s11)
800009e4:	050da023          	sw	a6,64(s11)
800009e8:	051da223          	sw	a7,68(s11)
800009ec:	052da423          	sw	s2,72(s11)
800009f0:	053da623          	sw	s3,76(s11)
800009f4:	054da823          	sw	s4,80(s11)
800009f8:	055daa23          	sw	s5,84(s11)
800009fc:	056dac23          	sw	s6,88(s11)
80000a00:	057dae23          	sw	s7,92(s11)
80000a04:	078da023          	sw	s8,96(s11)
80000a08:	079da223          	sw	s9,100(s11)
80000a0c:	07ada423          	sw	s10,104(s11)
80000a10:	07bda623          	sw	s11,108(s11)
80000a14:	07cda823          	sw	t3,112(s11)
80000a18:	07ddaa23          	sw	t4,116(s11)
80000a1c:	07edac23          	sw	t5,120(s11)
80000a20:	07fdae23          	sw	t6,124(s11)
80000a24:	34202673          	csrr	a2,mcause
80000a28:	01f65613          	srli	a2,a2,0x1f
80000a2c:	00060463          	beqz	a2,80000a34 <mmode_intr_vector_11+0x98>
80000a30:	4bc0006f          	j	80000eec <mmode_intr_handler>
80000a34:	00000797          	auipc	a5,0x0
80000a38:	8e878793          	addi	a5,a5,-1816 # 8000031c <test_done>
80000a3c:	00078067          	jr	a5

80000a40 <mmode_intr_vector_12>:
80000a40:	340d9df3          	csrrw	s11,mscratch,s11
80000a44:	00068db3          	add	s11,a3,zero
80000a48:	f84d8d93          	addi	s11,s11,-124
80000a4c:	001da223          	sw	ra,4(s11)
80000a50:	002da423          	sw	sp,8(s11)
80000a54:	003da623          	sw	gp,12(s11)
80000a58:	004da823          	sw	tp,16(s11)
80000a5c:	005daa23          	sw	t0,20(s11)
80000a60:	006dac23          	sw	t1,24(s11)
80000a64:	007dae23          	sw	t2,28(s11)
80000a68:	028da023          	sw	s0,32(s11)
80000a6c:	029da223          	sw	s1,36(s11)
80000a70:	02ada423          	sw	a0,40(s11)
80000a74:	02bda623          	sw	a1,44(s11)
80000a78:	02cda823          	sw	a2,48(s11)
80000a7c:	02ddaa23          	sw	a3,52(s11)
80000a80:	02edac23          	sw	a4,56(s11)
80000a84:	02fdae23          	sw	a5,60(s11)
80000a88:	050da023          	sw	a6,64(s11)
80000a8c:	051da223          	sw	a7,68(s11)
80000a90:	052da423          	sw	s2,72(s11)
80000a94:	053da623          	sw	s3,76(s11)
80000a98:	054da823          	sw	s4,80(s11)
80000a9c:	055daa23          	sw	s5,84(s11)
80000aa0:	056dac23          	sw	s6,88(s11)
80000aa4:	057dae23          	sw	s7,92(s11)
80000aa8:	078da023          	sw	s8,96(s11)
80000aac:	079da223          	sw	s9,100(s11)
80000ab0:	07ada423          	sw	s10,104(s11)
80000ab4:	07bda623          	sw	s11,108(s11)
80000ab8:	07cda823          	sw	t3,112(s11)
80000abc:	07ddaa23          	sw	t4,116(s11)
80000ac0:	07edac23          	sw	t5,120(s11)
80000ac4:	07fdae23          	sw	t6,124(s11)
80000ac8:	34202673          	csrr	a2,mcause
80000acc:	01f65613          	srli	a2,a2,0x1f
80000ad0:	00060463          	beqz	a2,80000ad8 <mmode_intr_vector_12+0x98>
80000ad4:	4180006f          	j	80000eec <mmode_intr_handler>
80000ad8:	00000797          	auipc	a5,0x0
80000adc:	84478793          	addi	a5,a5,-1980 # 8000031c <test_done>
80000ae0:	00078067          	jr	a5

80000ae4 <mmode_intr_vector_13>:
80000ae4:	340d9df3          	csrrw	s11,mscratch,s11
80000ae8:	00068db3          	add	s11,a3,zero
80000aec:	f84d8d93          	addi	s11,s11,-124
80000af0:	001da223          	sw	ra,4(s11)
80000af4:	002da423          	sw	sp,8(s11)
80000af8:	003da623          	sw	gp,12(s11)
80000afc:	004da823          	sw	tp,16(s11)
80000b00:	005daa23          	sw	t0,20(s11)
80000b04:	006dac23          	sw	t1,24(s11)
80000b08:	007dae23          	sw	t2,28(s11)
80000b0c:	028da023          	sw	s0,32(s11)
80000b10:	029da223          	sw	s1,36(s11)
80000b14:	02ada423          	sw	a0,40(s11)
80000b18:	02bda623          	sw	a1,44(s11)
80000b1c:	02cda823          	sw	a2,48(s11)
80000b20:	02ddaa23          	sw	a3,52(s11)
80000b24:	02edac23          	sw	a4,56(s11)
80000b28:	02fdae23          	sw	a5,60(s11)
80000b2c:	050da023          	sw	a6,64(s11)
80000b30:	051da223          	sw	a7,68(s11)
80000b34:	052da423          	sw	s2,72(s11)
80000b38:	053da623          	sw	s3,76(s11)
80000b3c:	054da823          	sw	s4,80(s11)
80000b40:	055daa23          	sw	s5,84(s11)
80000b44:	056dac23          	sw	s6,88(s11)
80000b48:	057dae23          	sw	s7,92(s11)
80000b4c:	078da023          	sw	s8,96(s11)
80000b50:	079da223          	sw	s9,100(s11)
80000b54:	07ada423          	sw	s10,104(s11)
80000b58:	07bda623          	sw	s11,108(s11)
80000b5c:	07cda823          	sw	t3,112(s11)
80000b60:	07ddaa23          	sw	t4,116(s11)
80000b64:	07edac23          	sw	t5,120(s11)
80000b68:	07fdae23          	sw	t6,124(s11)
80000b6c:	34202673          	csrr	a2,mcause
80000b70:	01f65613          	srli	a2,a2,0x1f
80000b74:	00060463          	beqz	a2,80000b7c <mmode_intr_vector_13+0x98>
80000b78:	3740006f          	j	80000eec <mmode_intr_handler>
80000b7c:	fffff797          	auipc	a5,0xfffff
80000b80:	7a078793          	addi	a5,a5,1952 # 8000031c <test_done>
80000b84:	00078067          	jr	a5

80000b88 <mmode_intr_vector_14>:
80000b88:	340d9df3          	csrrw	s11,mscratch,s11
80000b8c:	00068db3          	add	s11,a3,zero
80000b90:	f84d8d93          	addi	s11,s11,-124
80000b94:	001da223          	sw	ra,4(s11)
80000b98:	002da423          	sw	sp,8(s11)
80000b9c:	003da623          	sw	gp,12(s11)
80000ba0:	004da823          	sw	tp,16(s11)
80000ba4:	005daa23          	sw	t0,20(s11)
80000ba8:	006dac23          	sw	t1,24(s11)
80000bac:	007dae23          	sw	t2,28(s11)
80000bb0:	028da023          	sw	s0,32(s11)
80000bb4:	029da223          	sw	s1,36(s11)
80000bb8:	02ada423          	sw	a0,40(s11)
80000bbc:	02bda623          	sw	a1,44(s11)
80000bc0:	02cda823          	sw	a2,48(s11)
80000bc4:	02ddaa23          	sw	a3,52(s11)
80000bc8:	02edac23          	sw	a4,56(s11)
80000bcc:	02fdae23          	sw	a5,60(s11)
80000bd0:	050da023          	sw	a6,64(s11)
80000bd4:	051da223          	sw	a7,68(s11)
80000bd8:	052da423          	sw	s2,72(s11)
80000bdc:	053da623          	sw	s3,76(s11)
80000be0:	054da823          	sw	s4,80(s11)
80000be4:	055daa23          	sw	s5,84(s11)
80000be8:	056dac23          	sw	s6,88(s11)
80000bec:	057dae23          	sw	s7,92(s11)
80000bf0:	078da023          	sw	s8,96(s11)
80000bf4:	079da223          	sw	s9,100(s11)
80000bf8:	07ada423          	sw	s10,104(s11)
80000bfc:	07bda623          	sw	s11,108(s11)
80000c00:	07cda823          	sw	t3,112(s11)
80000c04:	07ddaa23          	sw	t4,116(s11)
80000c08:	07edac23          	sw	t5,120(s11)
80000c0c:	07fdae23          	sw	t6,124(s11)
80000c10:	34202673          	csrr	a2,mcause
80000c14:	01f65613          	srli	a2,a2,0x1f
80000c18:	00060463          	beqz	a2,80000c20 <mmode_intr_vector_14+0x98>
80000c1c:	2d00006f          	j	80000eec <mmode_intr_handler>
80000c20:	fffff797          	auipc	a5,0xfffff
80000c24:	6fc78793          	addi	a5,a5,1788 # 8000031c <test_done>
80000c28:	00078067          	jr	a5

80000c2c <mmode_intr_vector_15>:
80000c2c:	340d9df3          	csrrw	s11,mscratch,s11
80000c30:	00068db3          	add	s11,a3,zero
80000c34:	f84d8d93          	addi	s11,s11,-124
80000c38:	001da223          	sw	ra,4(s11)
80000c3c:	002da423          	sw	sp,8(s11)
80000c40:	003da623          	sw	gp,12(s11)
80000c44:	004da823          	sw	tp,16(s11)
80000c48:	005daa23          	sw	t0,20(s11)
80000c4c:	006dac23          	sw	t1,24(s11)
80000c50:	007dae23          	sw	t2,28(s11)
80000c54:	028da023          	sw	s0,32(s11)
80000c58:	029da223          	sw	s1,36(s11)
80000c5c:	02ada423          	sw	a0,40(s11)
80000c60:	02bda623          	sw	a1,44(s11)
80000c64:	02cda823          	sw	a2,48(s11)
80000c68:	02ddaa23          	sw	a3,52(s11)
80000c6c:	02edac23          	sw	a4,56(s11)
80000c70:	02fdae23          	sw	a5,60(s11)
80000c74:	050da023          	sw	a6,64(s11)
80000c78:	051da223          	sw	a7,68(s11)
80000c7c:	052da423          	sw	s2,72(s11)
80000c80:	053da623          	sw	s3,76(s11)
80000c84:	054da823          	sw	s4,80(s11)
80000c88:	055daa23          	sw	s5,84(s11)
80000c8c:	056dac23          	sw	s6,88(s11)
80000c90:	057dae23          	sw	s7,92(s11)
80000c94:	078da023          	sw	s8,96(s11)
80000c98:	079da223          	sw	s9,100(s11)
80000c9c:	07ada423          	sw	s10,104(s11)
80000ca0:	07bda623          	sw	s11,108(s11)
80000ca4:	07cda823          	sw	t3,112(s11)
80000ca8:	07ddaa23          	sw	t4,116(s11)
80000cac:	07edac23          	sw	t5,120(s11)
80000cb0:	07fdae23          	sw	t6,124(s11)
80000cb4:	34202673          	csrr	a2,mcause
80000cb8:	01f65613          	srli	a2,a2,0x1f
80000cbc:	00060463          	beqz	a2,80000cc4 <mmode_intr_vector_15+0x98>
80000cc0:	22c0006f          	j	80000eec <mmode_intr_handler>
80000cc4:	fffff797          	auipc	a5,0xfffff
80000cc8:	65878793          	addi	a5,a5,1624 # 8000031c <test_done>
80000ccc:	00078067          	jr	a5

80000cd0 <mtvec_handler>:
80000cd0:	0400006f          	j	80000d10 <mmode_exception_handler>
80000cd4:	e60ff06f          	j	80000334 <mmode_intr_vector_1>
80000cd8:	f00ff06f          	j	800003d8 <mmode_intr_vector_2>
80000cdc:	fa0ff06f          	j	8000047c <mmode_intr_vector_3>
80000ce0:	841ff06f          	j	80000520 <mmode_intr_vector_4>
80000ce4:	8e1ff06f          	j	800005c4 <mmode_intr_vector_5>
80000ce8:	981ff06f          	j	80000668 <mmode_intr_vector_6>
80000cec:	a21ff06f          	j	8000070c <mmode_intr_vector_7>
80000cf0:	ac1ff06f          	j	800007b0 <mmode_intr_vector_8>
80000cf4:	b61ff06f          	j	80000854 <mmode_intr_vector_9>
80000cf8:	c01ff06f          	j	800008f8 <mmode_intr_vector_10>
80000cfc:	ca1ff06f          	j	8000099c <mmode_intr_vector_11>
80000d00:	d41ff06f          	j	80000a40 <mmode_intr_vector_12>
80000d04:	de1ff06f          	j	80000ae4 <mmode_intr_vector_13>
80000d08:	e81ff06f          	j	80000b88 <mmode_intr_vector_14>
80000d0c:	f21ff06f          	j	80000c2c <mmode_intr_vector_15>

80000d10 <mmode_exception_handler>:
80000d10:	340d9df3          	csrrw	s11,mscratch,s11
80000d14:	00068db3          	add	s11,a3,zero
80000d18:	f84d8d93          	addi	s11,s11,-124
80000d1c:	001da223          	sw	ra,4(s11)
80000d20:	002da423          	sw	sp,8(s11)
80000d24:	003da623          	sw	gp,12(s11)
80000d28:	004da823          	sw	tp,16(s11)
80000d2c:	005daa23          	sw	t0,20(s11)
80000d30:	006dac23          	sw	t1,24(s11)
80000d34:	007dae23          	sw	t2,28(s11)
80000d38:	028da023          	sw	s0,32(s11)
80000d3c:	029da223          	sw	s1,36(s11)
80000d40:	02ada423          	sw	a0,40(s11)
80000d44:	02bda623          	sw	a1,44(s11)
80000d48:	02cda823          	sw	a2,48(s11)
80000d4c:	02ddaa23          	sw	a3,52(s11)
80000d50:	02edac23          	sw	a4,56(s11)
80000d54:	02fdae23          	sw	a5,60(s11)
80000d58:	050da023          	sw	a6,64(s11)
80000d5c:	051da223          	sw	a7,68(s11)
80000d60:	052da423          	sw	s2,72(s11)
80000d64:	053da623          	sw	s3,76(s11)
80000d68:	054da823          	sw	s4,80(s11)
80000d6c:	055daa23          	sw	s5,84(s11)
80000d70:	056dac23          	sw	s6,88(s11)
80000d74:	057dae23          	sw	s7,92(s11)
80000d78:	078da023          	sw	s8,96(s11)
80000d7c:	079da223          	sw	s9,100(s11)
80000d80:	07ada423          	sw	s10,104(s11)
80000d84:	07bda623          	sw	s11,108(s11)
80000d88:	07cda823          	sw	t3,112(s11)
80000d8c:	07ddaa23          	sw	t4,116(s11)
80000d90:	07edac23          	sw	t5,120(s11)
80000d94:	07fdae23          	sw	t6,124(s11)
80000d98:	34102673          	csrr	a2,mepc
80000d9c:	34202673          	csrr	a2,mcause
80000da0:	00b00f93          	li	t6,11
80000da4:	01f60e63          	beq	a2,t6,80000dc0 <ecall_handler>
80000da8:	00200f93          	li	t6,2
80000dac:	0bf60463          	beq	a2,t6,80000e54 <illegal_instr_handler>
80000db0:	34302ff3          	csrr	t6,mtval
80000db4:	fffff797          	auipc	a5,0xfffff
80000db8:	56878793          	addi	a5,a5,1384 # 8000031c <test_done>
80000dbc:	000780e7          	jalr	a5

80000dc0 <ecall_handler>:
80000dc0:	fffff617          	auipc	a2,0xfffff
80000dc4:	24060613          	addi	a2,a2,576 # 80000000 <_start>
80000dc8:	00062023          	sw	zero,0(a2)
80000dcc:	00162223          	sw	ra,4(a2)
80000dd0:	00262423          	sw	sp,8(a2)
80000dd4:	00362623          	sw	gp,12(a2)
80000dd8:	00462823          	sw	tp,16(a2)
80000ddc:	00562a23          	sw	t0,20(a2)
80000de0:	00662c23          	sw	t1,24(a2)
80000de4:	00762e23          	sw	t2,28(a2)
80000de8:	02862023          	sw	s0,32(a2)
80000dec:	02962223          	sw	s1,36(a2)
80000df0:	02a62423          	sw	a0,40(a2)
80000df4:	02b62623          	sw	a1,44(a2)
80000df8:	02c62823          	sw	a2,48(a2)
80000dfc:	02d62a23          	sw	a3,52(a2)
80000e00:	02e62c23          	sw	a4,56(a2)
80000e04:	02f62e23          	sw	a5,60(a2)
80000e08:	05062023          	sw	a6,64(a2)
80000e0c:	05162223          	sw	a7,68(a2)
80000e10:	05262423          	sw	s2,72(a2)
80000e14:	05362623          	sw	s3,76(a2)
80000e18:	05462823          	sw	s4,80(a2)
80000e1c:	05562a23          	sw	s5,84(a2)
80000e20:	05662c23          	sw	s6,88(a2)
80000e24:	05762e23          	sw	s7,92(a2)
80000e28:	07862023          	sw	s8,96(a2)
80000e2c:	07962223          	sw	s9,100(a2)
80000e30:	07a62423          	sw	s10,104(a2)
80000e34:	07b62623          	sw	s11,108(a2)
80000e38:	07c62823          	sw	t3,112(a2)
80000e3c:	07d62a23          	sw	t4,116(a2)
80000e40:	07e62c23          	sw	t5,120(a2)
80000e44:	07f62e23          	sw	t6,124(a2)
80000e48:	fffff797          	auipc	a5,0xfffff
80000e4c:	4dc78793          	addi	a5,a5,1244 # 80000324 <write_tohost>
80000e50:	00078067          	jr	a5

80000e54 <illegal_instr_handler>:
80000e54:	34102673          	csrr	a2,mepc
80000e58:	00460613          	addi	a2,a2,4
80000e5c:	34161073          	csrw	mepc,a2
80000e60:	004da083          	lw	ra,4(s11)
80000e64:	008da103          	lw	sp,8(s11)
80000e68:	00cda183          	lw	gp,12(s11)
80000e6c:	010da203          	lw	tp,16(s11)
80000e70:	014da283          	lw	t0,20(s11)
80000e74:	018da303          	lw	t1,24(s11)
80000e78:	01cda383          	lw	t2,28(s11)
80000e7c:	020da403          	lw	s0,32(s11)
80000e80:	024da483          	lw	s1,36(s11)
80000e84:	028da503          	lw	a0,40(s11)
80000e88:	02cda583          	lw	a1,44(s11)
80000e8c:	030da603          	lw	a2,48(s11)
80000e90:	034da683          	lw	a3,52(s11)
80000e94:	038da703          	lw	a4,56(s11)
80000e98:	03cda783          	lw	a5,60(s11)
80000e9c:	040da803          	lw	a6,64(s11)
80000ea0:	044da883          	lw	a7,68(s11)
80000ea4:	048da903          	lw	s2,72(s11)
80000ea8:	04cda983          	lw	s3,76(s11)
80000eac:	050daa03          	lw	s4,80(s11)
80000eb0:	054daa83          	lw	s5,84(s11)
80000eb4:	058dab03          	lw	s6,88(s11)
80000eb8:	05cdab83          	lw	s7,92(s11)
80000ebc:	060dac03          	lw	s8,96(s11)
80000ec0:	064dac83          	lw	s9,100(s11)
80000ec4:	068dad03          	lw	s10,104(s11)
80000ec8:	06cdad83          	lw	s11,108(s11)
80000ecc:	070dae03          	lw	t3,112(s11)
80000ed0:	074dae83          	lw	t4,116(s11)
80000ed4:	078daf03          	lw	t5,120(s11)
80000ed8:	07cdaf83          	lw	t6,124(s11)
80000edc:	07cd8d93          	addi	s11,s11,124
80000ee0:	000d86b3          	add	a3,s11,zero
80000ee4:	340d9df3          	csrrw	s11,mscratch,s11
80000ee8:	30200073          	mret

80000eec <mmode_intr_handler>:
80000eec:	30002673          	csrr	a2,mstatus
80000ef0:	30402673          	csrr	a2,mie
80000ef4:	34402673          	csrr	a2,mip
80000ef8:	34463673          	csrrc	a2,mip,a2
80000efc:	004da083          	lw	ra,4(s11)
80000f00:	008da103          	lw	sp,8(s11)
80000f04:	00cda183          	lw	gp,12(s11)
80000f08:	010da203          	lw	tp,16(s11)
80000f0c:	014da283          	lw	t0,20(s11)
80000f10:	018da303          	lw	t1,24(s11)
80000f14:	01cda383          	lw	t2,28(s11)
80000f18:	020da403          	lw	s0,32(s11)
80000f1c:	024da483          	lw	s1,36(s11)
80000f20:	028da503          	lw	a0,40(s11)
80000f24:	02cda583          	lw	a1,44(s11)
80000f28:	030da603          	lw	a2,48(s11)
80000f2c:	034da683          	lw	a3,52(s11)
80000f30:	038da703          	lw	a4,56(s11)
80000f34:	03cda783          	lw	a5,60(s11)
80000f38:	040da803          	lw	a6,64(s11)
80000f3c:	044da883          	lw	a7,68(s11)
80000f40:	048da903          	lw	s2,72(s11)
80000f44:	04cda983          	lw	s3,76(s11)
80000f48:	050daa03          	lw	s4,80(s11)
80000f4c:	054daa83          	lw	s5,84(s11)
80000f50:	058dab03          	lw	s6,88(s11)
80000f54:	05cdab83          	lw	s7,92(s11)
80000f58:	060dac03          	lw	s8,96(s11)
80000f5c:	064dac83          	lw	s9,100(s11)
80000f60:	068dad03          	lw	s10,104(s11)
80000f64:	06cdad83          	lw	s11,108(s11)
80000f68:	070dae03          	lw	t3,112(s11)
80000f6c:	074dae83          	lw	t4,116(s11)
80000f70:	078daf03          	lw	t5,120(s11)
80000f74:	07cdaf83          	lw	t6,124(s11)
80000f78:	07cd8d93          	addi	s11,s11,124
80000f7c:	000d86b3          	add	a3,s11,zero
80000f80:	340d9df3          	csrrw	s11,mscratch,s11
80000f84:	30200073          	mret

80000f88 <kernel_instr_end>:
80000f88:	00000013          	nop

80000f8c <kernel_data_start>:
	...
