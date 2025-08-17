/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

module kybertop (
    input logic clk,
    input logic rst_n,
    input logic enable,
    input logic key_enable,
    input logic encryption_enable,
    input logic decryption_enable,
    input logic signed [31:0] data_Req,
    input logic signed [31:0] addr_Req,
    input logic wen_Req,
    output logic key_done,
    output logic encryption_done,
    output logic decryption_done,
    input logic [7:0] bytelane_Req,
    output logic signed [31:0] data_Resp

);

// logic [31:0] data_Resp;
logic signed [31:0] secretkey [1:0][3:0];
logic signed [31:0] result [1:0][3:0];
logic signed [31:0] public_key [1:0][3:0][3:0];
logic signed [31:0] A_reg [3:0][3:0];
logic signed [31:0] s_reg [1:0][3:0];
logic signed [31:0] e_reg [1:0][3:0];
logic signed [31:0] ciphertext[1:0] [1:0][3:0];
logic signed [31:0] r [1:0][3:0];
logic signed [31:0] e1 [1:0][3:0];
logic signed [31:0] e2 [3:0];
logic signed [31:0] decimal_value;
logic signed [3:0] m_b;

//Key Generation Input Registers
logic signed [31:0] A_t000;
logic signed [31:0] A_t001;
logic signed [31:0] A_t002;
logic signed [31:0] A_t003;
logic signed [31:0] A_t010;
logic signed [31:0] A_t011;
logic signed [31:0] A_t012;
logic signed [31:0] A_t013;
logic signed [31:0] A_t020;
logic signed [31:0] A_t021;
logic signed [31:0] A_t022;
logic signed [31:0] A_t023;
logic signed [31:0] A_t030;
logic signed [31:0] A_t031;
logic signed [31:0] A_t032;
logic signed [31:0] A_t033;

logic signed [31:0] s_00;
logic signed [31:0] s_01;
logic signed [31:0] s_02;
logic signed [31:0] s_03;
logic signed [31:0] s_10;
logic signed [31:0] s_11;
logic signed [31:0] s_12;
logic signed [31:0] s_13;

logic signed [31:0] e_00;
logic signed [31:0] e_01;
logic signed [31:0] e_02;
logic signed [31:0] e_03;
logic signed [31:0] e_10;
logic signed [31:0] e_11;
logic signed [31:0] e_12;
logic signed [31:0] e_13;

//Encrypt Input Registers
logic signed [31:0] message;

logic signed [31:0] public_key000;
logic signed [31:0] public_key001;
logic signed [31:0] public_key002;
logic signed [31:0] public_key003;
logic signed [31:0] public_key010;
logic signed [31:0] public_key011;
logic signed [31:0] public_key012;
logic signed [31:0] public_key013;
logic signed [31:0] public_key020;
logic signed [31:0] public_key021;
logic signed [31:0] public_key022;
logic signed [31:0] public_key023;
logic signed [31:0] public_key030;
logic signed [31:0] public_key031;
logic signed [31:0] public_key032;
logic signed [31:0] public_key033;
logic signed [31:0] public_key100;
logic signed [31:0] public_key101;
logic signed [31:0] public_key102;
logic signed [31:0] public_key103;
logic signed [31:0] public_key110;
logic signed [31:0] public_key111;
logic signed [31:0] public_key112;
logic signed [31:0] public_key113;

logic signed [31:0] r_00;
logic signed [31:0] r_01;
logic signed [31:0] r_02;
logic signed [31:0] r_03;
logic signed [31:0] r_10;
logic signed [31:0] r_11;
logic signed [31:0] r_12;
logic signed [31:0] r_13;

logic signed [31:0] e1_00;
logic signed [31:0] e1_01;
logic signed [31:0] e1_02;
logic signed [31:0] e1_03;
logic signed [31:0] e1_10;
logic signed [31:0] e1_11;
logic signed [31:0] e1_12;
logic signed [31:0] e1_13;

logic signed [31:0] e2_0;
logic signed [31:0] e2_1;
logic signed [31:0] e2_2;
logic signed [31:0] e2_3;

//Decryption Input Registers
logic signed [31:0] ciphertext000;
logic signed [31:0] ciphertext001;
logic signed [31:0] ciphertext002;
logic signed [31:0] ciphertext003;
logic signed [31:0] ciphertext010;
logic signed [31:0] ciphertext011;
logic signed [31:0] ciphertext012;
logic signed [31:0] ciphertext013;
logic signed [31:0] ciphertext100;
logic signed [31:0] ciphertext101;
logic signed [31:0] ciphertext102;
logic signed [31:0] ciphertext103;


KeyGeneration keygen (
    .clk(clk),
    .rst_n(rst_n),
    .key_enable(key_enable),
    .A(A_reg),
    .secret_key(s_reg),
    .e(e_reg),
    .secretkey(secretkey),
    .result(result),
    .key_done(key_done),
    .combined_output(public_key)
);
Encrypt encryption (
    .clk(clk),
    .rst_n(rst_n),
    .encryption_enable(encryption_enable),
    .message(message),
    .combined_output(public_key),
    .r(r),
    .e1(e1),
    .e2(e2),
    .encryption_done(encryption_done),
    .ciphertext(ciphertext)
);
Decrypt decryption (
    .clk(clk),
    .rst_n(rst_n),
    .decryption_enable(decryption_enable),
    .ciphertext(ciphertext),
    .secret_key(secretkey),
    .m_b(m_b),
    .decryption_done(decryption_done),
    .decimal_value(decimal_value)

);


    always_ff @(posedge clk ) begin
        if (!rst_n) begin
            for (int i = 0; i < 2; i++) begin
                for (int j = 0; j < 4; j++) begin
                    secretkey[i][j] <= 32'b0;
                    result[i][j] <= 32'b0;
                    s_reg[i][j] <= 32'b0;
                    e_reg[i][j] <= 32'b0;
                    r[i][j] <= 32'b0;
                    e1[i][j] <= 32'b0;
                    ciphertext[0][i][j] <= 32'b0;
                    ciphertext[1][i][j] <= 32'b0;
                end
            end

            for (int i = 0; i < 4; i++) begin
                for (int j = 0; j < 4; j++) begin
                    A_reg[i][j] <= 32'b0;
                    public_key[0][i][j] <= 32'b0;
                    public_key[1][i][j] <= 32'b0;
                end
            end

            for (int i = 0; i < 4; i++) begin
                e2[i] <= 32'b0;
            end

            
            
            data_Resp <= 32'b0;
            // decimal_value <= 3'b0;

        // Resetting arrays and matrices to zero
        
            A_t000 <= 32'b0;
            A_t001 <= 32'b0;
            A_t002 <= 32'b0;
            A_t003 <= 32'b0;
            A_t010 <= 32'b0;
            A_t011 <= 32'b0;
            A_t012 <= 32'b0;
            A_t013 <= 32'b0;
            A_t020 <= 32'b0;
            A_t021 <= 32'b0;
            A_t022 <= 32'b0;
            A_t023 <= 32'b0;
            A_t030 <= 32'b0;
            A_t031 <= 32'b0;
            A_t032 <= 32'b0;
            A_t033 <= 32'b0;

            s_00 <= 32'b0;
            s_01 <= 32'b0;
            s_02 <= 32'b0;
            s_03 <= 32'b0;
            s_10 <= 32'b0;
            s_11 <= 32'b0;
            s_12 <= 32'b0;
            s_13 <= 32'b0;

            e_00 <= 32'b0;
            e_01 <= 32'b0;
            e_02 <= 32'b0;
            e_03 <= 32'b0;
            e_10 <= 32'b0;
            e_11 <= 32'b0;
            e_12 <= 32'b0;
            e_13 <= 32'b0;

            // Reset Encryption Registers
            public_key000 <= 32'b0;
            public_key001 <= 32'b0;
            public_key002 <= 32'b0;
            public_key003 <= 32'b0;
            public_key010 <= 32'b0;
            public_key011 <= 32'b0;
            public_key012 <= 32'b0;
            public_key013 <= 32'b0;
            public_key020 <= 32'b0;
            public_key021 <= 32'b0;
            public_key022 <= 32'b0;
            public_key023 <= 32'b0;
            public_key030 <= 32'b0;
            public_key031 <= 32'b0;
            public_key032 <= 32'b0;
            public_key033 <= 32'b0;
            public_key100 <= 32'b0;
            public_key101 <= 32'b0;
            public_key102 <= 32'b0;
            public_key103 <= 32'b0;
            public_key110 <= 32'b0;
            public_key111 <= 32'b0;
            public_key112 <= 32'b0;
            public_key113 <= 32'b0;

            r_00 <= 32'b0;
            r_01 <= 32'b0;
            r_02 <= 32'b0;
            r_03 <= 32'b0;
            r_10 <= 32'b0;
            r_11 <= 32'b0;
            r_12 <= 32'b0;
            r_13 <= 32'b0;

            e1_00 <= 32'b0;
            e1_01 <= 32'b0;
            e1_02 <= 32'b0;
            e1_03 <= 32'b0;
            e1_10 <= 32'b0;
            e1_11 <= 32'b0;
            e1_12 <= 32'b0;
            e1_13 <= 32'b0;

            e2_0 <= 32'b0;
            e2_1 <= 32'b0;
            e2_2 <= 32'b0;
            e2_3 <= 32'b0;

            // Reset Decryption Registers
            ciphertext000 <= 32'b0;
            ciphertext001 <= 32'b0;
            ciphertext002 <= 32'b0;
            ciphertext003 <= 32'b0;
            ciphertext010 <= 32'b0;
            ciphertext011 <= 32'b0;
            ciphertext012 <= 32'b0;
            ciphertext013 <= 32'b0;
            ciphertext100 <= 32'b0;
            ciphertext101 <= 32'b0;
            ciphertext102 <= 32'b0;
            ciphertext103 <= 32'b0;

           

        end else if (enable) begin 
            //keygen
            if (wen_Req == 1'b1  )begin  
                data_Resp <= 1;
                $display("checking");
            if ( addr_Req == 'h40007000  )begin
                A_t000 <= data_Req;

            end else if (addr_Req == 'h40007004  )begin
                A_t001 <= data_Req;
            end
            else if (addr_Req == 'h40007008 )begin
                A_t002 <= data_Req;
            end
            else if (addr_Req == 'h40007012 )begin
                A_t003 <= data_Req;
            end
            else if (addr_Req == 'h40007016 )begin
                A_t010 <= data_Req;
            end
            else if (addr_Req == 'h40007020 )begin
                A_t011 <= data_Req;
            end
            else if (addr_Req == 'h40007024 )begin
                A_t012 <= data_Req;
            end
            else if (addr_Req == 'h40007028 )begin
                A_t013 <= data_Req;
            end
            else if (addr_Req == 'h40007032 )begin
                A_t020 <= data_Req;
            end
            else if (addr_Req == 'h40007036 )begin
                A_t021 <= data_Req;
            end
            else if (addr_Req == 'h40007040 )begin
                A_t022 <= data_Req;
            end
            else if (addr_Req == 'h40007044 )begin
                A_t023 <= data_Req;
            end
            else if (addr_Req == 'h40007048 )begin
                A_t030 <= data_Req;
            end
            else if (addr_Req == 'h40007052 )begin
                A_t031 <= data_Req;
            end
            else if (addr_Req == 'h40007056 )begin
                A_t032 <= data_Req;
            end
            else if (addr_Req == 'h40007060 )begin
                A_t033 <= data_Req;
            end
            else if (addr_Req == 'h40007064 )begin
                s_00 <= data_Req;
            end
            else if (addr_Req == 'h40007068 )begin
                s_01 <= data_Req;
            end
            else if (addr_Req == 'h40007072 )begin
                s_02 <= data_Req;
            end
            else if (addr_Req == 'h40007076 )begin
                s_03 <= data_Req;
            end
            else if (addr_Req == 'h40007080 )begin
                s_10 <= data_Req;
            end
            else if (addr_Req == 'h40007084 )begin
                s_11 <= data_Req;
            end
            else if (addr_Req == 'h40007088 )begin
                s_12 <= data_Req;
            end
            else if (addr_Req == 'h40007092 )begin
                s_13 <= data_Req;
            end
            else if (addr_Req == 'h40007096 )begin
                e_00 <= data_Req;
            end
            else if (addr_Req == 'h40007100 )begin
                e_01 <= data_Req;
            end
            else if (addr_Req == 'h40007104 )begin
                e_02 <= data_Req;
            end
            else if (addr_Req == 'h40007108 )begin
                e_03 <= data_Req;
            end
            else if (addr_Req == 'h40007112 )begin
                e_10 <= data_Req;
            end
            else if (addr_Req == 'h40007116 )begin
                e_11 <= data_Req;
            end
            else if (addr_Req == 'h40007120 )begin
                e_12 <= data_Req;
            end
            else if (addr_Req == 'h40007124 )begin
                e_13 <= data_Req;
            end
            else if (addr_Req == 'h40007128 )begin //encrypt
                message <= data_Req;
            end
            else if (addr_Req == 'h40007132 )begin
                public_key000 <= data_Req;
            end
            else if (addr_Req == 'h40007136 )begin
                public_key001 <= data_Req;
            end
            else if (addr_Req == 'h40007140 )begin
                public_key002 <= data_Req;
            end
            else if (addr_Req == 'h40007144 )begin
                public_key003 <= data_Req;
            end
            else if (addr_Req == 'h40007148 )begin
                public_key010 <= data_Req;
            end
            else if (addr_Req == 'h40007152 )begin
                public_key011 <= data_Req;
            end
            else if (addr_Req == 'h40007156 )begin
                public_key012 <= data_Req;
            end
            else if (addr_Req == 'h40007160 )begin
                public_key013 <= data_Req;
            end
            else if (addr_Req == 'h40007164 )begin
                public_key020 <= data_Req;
            end
            else if (addr_Req == 'h40007168 )begin
                public_key021 <= data_Req;
            end
            else if (addr_Req == 'h40007172 )begin
                public_key022 <= data_Req;
            end
            else if (addr_Req == 'h40007176 )begin
                public_key023 <= data_Req;
            end
            else if (addr_Req == 'h40007180 )begin
                public_key030 <= data_Req;
            end
            else if (addr_Req == 'h40007184 )begin
                public_key031 <= data_Req;
            end
            else if (addr_Req == 'h40007188 )begin
                public_key032 <= data_Req;
            end
            else if (addr_Req == 'h40007192 )begin
                public_key033 <= data_Req;
            end
            else if (addr_Req == 'h40007196 )begin
                public_key100 <= data_Req;
            end
            else if (addr_Req == 'h40007200 )begin
                public_key101 <= data_Req;
            end
            else if (addr_Req == 'h40007204 )begin
                public_key102 <= data_Req;
            end
            else if (addr_Req == 'h40007208 )begin
                public_key103 <= data_Req;
            end
            else if (addr_Req == 'h40007212 )begin
                public_key110 <= data_Req;
            end
            else if (addr_Req == 'h40007216 )begin
                public_key111 <= data_Req;
            end
            else if (addr_Req == 'h40007220 )begin
                public_key112 <= data_Req;
            end
            else if (addr_Req == 'h40007224 )begin
                public_key113 <= data_Req;
            end
            else if (addr_Req == 'h40007228 )begin
                r_00 <= data_Req;
            end
            else if (addr_Req == 'h40007232 )begin
                r_01 <= data_Req;
            end
            else if (addr_Req == 'h40007236 )begin
                r_02 <= data_Req;
            end
            else if (addr_Req == 'h40007240 )begin
                r_03 <= data_Req;
            end
            else if (addr_Req == 'h40007244 )begin
                r_10 <= data_Req;
            end
            else if (addr_Req == 'h40007248 )begin
                r_11 <= data_Req;
            end
            else if (addr_Req == 'h40007252 )begin
                r_12 <= data_Req;
            end
            else if (addr_Req == 'h40007256 )begin
                r_13 <= data_Req;
            end
            else if (addr_Req == 'h40007260 )begin
                e1_00 <= data_Req;
            end
            else if (addr_Req == 'h40007264 )begin
                e1_01 <= data_Req;
            end
            else if (addr_Req == 'h40007268 )begin
                e1_02 <= data_Req;
            end
            else if (addr_Req == 'h40007272 )begin
                e1_03 <= data_Req;
            end
            else if (addr_Req == 'h40007276 )begin
                e1_10 <= data_Req;
            end
            else if (addr_Req == 'h40007280 )begin
                e1_11 <= data_Req;
            end
            else if (addr_Req == 'h40007284 )begin
                e1_12 <= data_Req;
            end
            else if (addr_Req == 'h40007288 )begin
                e1_13 <= data_Req;
            end
            else if (addr_Req == 'h40007292 )begin
                e2_0 <= data_Req;
            end
            else if (addr_Req == 'h40007296 )begin
                e2_1 <= data_Req;
            end
            else if (addr_Req == 'h40007300 )begin
                e2_2 <= data_Req;
            end
            else if (addr_Req == 'h40007304 )begin
                e2_3 <= data_Req;
            end
            else if (addr_Req == 'h40007308)begin
                ciphertext000 <= data_Req;
            end
            else if (addr_Req == 'h40007312 )begin
                ciphertext001 <= data_Req;
            end
            else if (addr_Req == 'h40007316 )begin
                ciphertext002 <= data_Req;
            end
            else if (addr_Req == 'h40007320 )begin
                ciphertext003 <= data_Req;
            end
            else if (addr_Req == 'h40007324 )begin
                ciphertext010 <= data_Req;
            end
            else if (addr_Req == 'h40007328 )begin
                ciphertext011 <= data_Req;
            end
            else if (addr_Req == 'h40007332 )begin
                ciphertext012 <= data_Req;
            end
            else if (addr_Req == 'h40007336 )begin
                ciphertext013 <= data_Req;
            end
            else if (addr_Req == 'h40007340 )begin
                ciphertext100 <= data_Req;
            end
            else if (addr_Req == 'h40007344 )begin
                ciphertext101 <= data_Req;
            end
            else if (addr_Req == 'h40007348 )begin
                ciphertext102 <= data_Req;
            end
            else if (addr_Req == 'h40007352 )begin
                ciphertext103 <= data_Req;
            end
            else if (addr_Req == 'h40007356 )begin

                //key generation inputs
                A_reg[0][0] <= A_t000;
                A_reg[0][1] <= A_t001;
                A_reg[0][2] <= A_t002;
                A_reg[0][3] <= A_t003;
                
                A_reg[1][0] <= A_t010;
                A_reg[1][1] <= A_t011;
                A_reg[1][2] <= A_t012;
                A_reg[1][3] <= A_t013;
                
                A_reg[2][0] <= A_t020;
                A_reg[2][1] <= A_t021;
                A_reg[2][2] <= A_t022;
                A_reg[2][3] <= A_t023;
                
                A_reg[3][0] <= A_t030;
                A_reg[3][1] <= A_t031;
                A_reg[3][2] <= A_t032;
                A_reg[3][3] <= A_t033;

                s_reg[0][0] <= s_00;
                s_reg[0][1] <= s_01;
                s_reg[0][2] <= s_02;
                s_reg[0][3] <= s_03;
                s_reg[1][0] <= s_10;
                s_reg[1][1] <= s_11;
                s_reg[1][2] <= s_12;
                s_reg[1][3] <= s_13;

                e_reg[0][0] <= e_00;
                e_reg[0][1] <= e_01;
                e_reg[0][2] <= e_02;
                e_reg[0][3] <= e_03;
                e_reg[1][0] <= e_10;
                e_reg[1][1] <= e_11;
                e_reg[1][2] <= e_12;
                e_reg[1][3] <= e_13;

                //key generation outputs to output registers
                public_key000 <= public_key[0][0][0];
                public_key001 <= public_key[0][0][1];
                public_key002 <= public_key[0][0][2];
                public_key003 <= public_key[0][0][3];
                public_key010 <= public_key[0][1][0];
                public_key011 <= public_key[0][1][1];
                public_key012 <= public_key[0][1][2];
                public_key013 <= public_key[0][1][3];
                public_key020 <= public_key[0][2][0];
                public_key021 <= public_key[0][2][1];
                public_key022 <= public_key[0][2][2];
                public_key023 <= public_key[0][2][3];
                public_key030 <= public_key[0][3][0];
                public_key031 <= public_key[0][3][1];
                public_key032 <= public_key[0][3][2];
                public_key033 <= public_key[0][3][3];
                public_key100 <= public_key[1][0][0];
                public_key101 <= public_key[1][0][1];
                public_key102 <= public_key[1][0][2];
                public_key103 <= public_key[1][0][3];
                public_key110 <= public_key[1][1][0];
                public_key111 <= public_key[1][1][1];
                public_key112 <= public_key[1][1][2];
                public_key113 <= public_key[1][1][3];

               // s_reg <= secretkey;
            end
            else if (addr_Req == 'h40007360 )begin
                //encrypt inputs
               // message <= data_Req;
                public_key[0][0][0] <= public_key000;
                public_key[0][0][1] <= public_key001;
                public_key[0][0][2] <= public_key002;
                public_key[0][0][3] <= public_key003;
                public_key[0][1][0] <= public_key010;
                public_key[0][1][1] <= public_key011;
                public_key[0][1][2] <= public_key012;
                public_key[0][1][3] <= public_key013;
                public_key[0][2][0] <= public_key020;
                public_key[0][2][1] <= public_key021;
                public_key[0][2][2] <= public_key022;
                public_key[0][2][3] <= public_key023;
                public_key[0][3][0] <= public_key030;
                public_key[0][3][1] <= public_key031;
                public_key[0][3][2] <= public_key032;
                public_key[0][3][3] <= public_key033;
                public_key[1][0][0] <= public_key100;
                public_key[1][0][1] <= public_key101;
                public_key[1][0][2] <= public_key102;
                public_key[1][0][3] <= public_key103;
                public_key[1][1][0] <= public_key110;
                public_key[1][1][1] <= public_key111;
                public_key[1][1][2] <= public_key112;
                public_key[1][1][3] <= public_key113;

                r[0][0] <= r_00;
                r[0][1] <= r_01;
                r[0][2] <= r_02;
                r[0][3] <= r_03;
                r[1][0] <= r_10;
                r[1][1] <= r_11;
                r[1][2] <= r_12;
                r[1][3] <= r_13;

                e1[0][0] <= e1_00;
                e1[0][1] <= e1_01;
                e1[0][2] <= e1_02;
                e1[0][3] <= e1_03;
                e1[1][0] <= e1_10;
                e1[1][1] <= e1_11;
                e1[1][2] <= e1_12;
                e1[1][3] <= e1_13;

                e2[0] <= e2_0;
                e2[1] <= e2_1;
                e2[2] <= e2_2;
                e2[3] <= e2_3;

                // output
                ciphertext000 <= ciphertext[0][0][0];
                ciphertext001 <= ciphertext[0][0][1];
                ciphertext002 <= ciphertext[0][0][2];
                ciphertext003 <= ciphertext[0][0][3];
                ciphertext010 <= ciphertext[0][1][0];
                ciphertext011 <= ciphertext[0][1][1];
                ciphertext012 <= ciphertext[0][1][2];
                ciphertext013 <= ciphertext[0][1][3];
                ciphertext100 <= ciphertext[1][0][0];
                ciphertext101 <= ciphertext[1][0][1];
                ciphertext102 <= ciphertext[1][0][2];
                ciphertext103 <= ciphertext[1][0][3];

            end
            else if (addr_Req == 'h40007364 )begin
                //decrypt
                ciphertext[0][0][0] <= ciphertext000;
                ciphertext[0][0][1] <= ciphertext001;
                ciphertext[0][0][2] <= ciphertext002;
                ciphertext[0][0][3] <= ciphertext003;
                ciphertext[0][1][0] <= ciphertext010;
                ciphertext[0][1][1] <= ciphertext011;
                ciphertext[0][1][2] <= ciphertext012;
                ciphertext[0][1][3] <= ciphertext013;
                ciphertext[1][0][0] <= ciphertext100;
                ciphertext[1][0][1] <= ciphertext101;
                ciphertext[1][0][2] <= ciphertext102;
                ciphertext[1][0][3] <= ciphertext103;

                secretkey <= s_reg;
                //output
               // message <= decimal_value;
            end
            end 
            else if (wen_Req == 1'b0  ) begin 
                if (addr_Req == 'h40007000) begin 
                    data_Resp <= public_key000;
                end
                else if (addr_Req == 'h40007004) begin 
                    data_Resp <= public_key001;
                end
                else if (addr_Req == 'h40007008) begin 
                    data_Resp <= public_key002;
                end
                else if (addr_Req == 'h40007012) begin 
                    data_Resp <= public_key003;
                end
                else if (addr_Req == 'h40007016) begin 
                    data_Resp <= public_key010;
                end
                else if (addr_Req == 'h40007020) begin 
                    data_Resp <= public_key011;
                end
                else if (addr_Req == 'h40007024) begin 
                    data_Resp <= public_key012;
                end
                else if (addr_Req == 'h40007028) begin 
                    data_Resp <= public_key013;
                end
                else if (addr_Req == 'h40007032) begin 
                    data_Resp <= public_key020;
                end
                else if (addr_Req == 'h40007036) begin 
                    data_Resp <= public_key021;
                end
                else if (addr_Req == 'h40007040) begin 
                    data_Resp <= public_key022;
                end
                else if (addr_Req == 'h40007044) begin 
                    data_Resp <= public_key023;
                end
                else if (addr_Req == 'h40007048) begin 
                    data_Resp <= public_key030;
                end
                else if (addr_Req == 'h40007052) begin 
                    data_Resp <= public_key031;
                end
                else if (addr_Req == 'h40007056) begin 
                    data_Resp <= public_key032;
                end
                else if (addr_Req == 'h40007060) begin 
                    data_Resp <= public_key033;
                end
                else if (addr_Req == 'h40007064) begin 
                    data_Resp <= public_key100;
                end
                else if (addr_Req == 'h40007068) begin 
                    data_Resp <= public_key101;
                end
                else if (addr_Req == 'h40007072) begin 
                    data_Resp <= public_key102;
                end
                else if (addr_Req == 'h40007076) begin 
                    data_Resp <= public_key103;
                end
                else if (addr_Req == 'h40007080) begin 
                    data_Resp <= public_key110;
                end
                else if (addr_Req == 'h40007084) begin 
                    data_Resp <= public_key111;
                end
                else if (addr_Req == 'h40007088) begin 
                    data_Resp <= public_key112;
                end
                else if (addr_Req == 'h40007092) begin 
                    data_Resp <= public_key113;
                end
                else if (addr_Req == 'h40007096) begin 
                    data_Resp <= ciphertext000;
                end
                else if (addr_Req == 'h40007100) begin 
                    data_Resp <= ciphertext001;
                end
                else if (addr_Req == 'h40007104) begin 
                    data_Resp <= ciphertext002;
                end
                else if (addr_Req == 'h40007108) begin 
                    data_Resp <= ciphertext003;
                end
                else if (addr_Req == 'h40007112) begin 
                    data_Resp <= ciphertext010;
                end
                else if (addr_Req == 'h40007116) begin 
                    data_Resp <= ciphertext011;
                end
                else if (addr_Req == 'h40007120) begin 
                    data_Resp <= ciphertext012;
                end
                else if (addr_Req == 'h40007124) begin 
                    data_Resp <= ciphertext013;
                end
                else if (addr_Req == 'h40007128) begin 
                    data_Resp <= ciphertext100;
                end
                else if (addr_Req == 'h40007132) begin 
                    data_Resp <= ciphertext101;
                end
                else if (addr_Req == 'h40007136) begin 
                    data_Resp <= ciphertext102;
                end
                else if (addr_Req == 'h40007140) begin 
                    data_Resp <= ciphertext103;
                end
                else if (addr_Req == 'h40007144) begin 
                    data_Resp <= message;
                end
                
            end

        end
    end

endmodule
