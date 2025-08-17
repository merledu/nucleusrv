/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

module Decrypt (
    input logic clk,
    input logic rst_n,
    input logic decryption_enable,
    input logic signed [31:0] secret_key [1:0][3:0],
    input logic signed [31:0] ciphertext[1:0][1:0][3:0],
    output logic signed [3:0] m_b, 
    output logic decryption_done,
    output logic [31:0] decimal_value    
);
    parameter int Q = 17; 
    logic signed [31:0] poly_out0 [3:0];
    logic signed [31:0] poly_out1 [3:0];
    logic signed [31:0] temp_m_n [3:0];
    logic decryption_done_next; // Intermediate signal for delaying decryption_done

    PolynomialMatrixMultiplication poly_mult1 (
        .clk(clk),
        .rst_n(rst_n),
        .enable(decryption_enable),
        .polynomial1(ciphertext[0][0]),
        .polynomial2(secret_key[0]),
        .polynomial_out(poly_out0)
    );

    PolynomialMatrixMultiplication poly_mult2 (
        .clk(clk),
        .rst_n(rst_n),
        .enable(decryption_enable),
        .polynomial1(ciphertext[0][1]),
        .polynomial2(secret_key[1]),
        .polynomial_out(poly_out1)
    );

    always_comb begin
        for (int i = 0; i < 4; i++) begin
            temp_m_n[i] = ciphertext[1][0][i] - (poly_out0[i] + poly_out1[i]);

            if (temp_m_n[i] < 0) begin
                temp_m_n[i] += Q;
                if (temp_m_n[i] < 0) begin
                    temp_m_n[i] += Q;
                end
            end else begin
                temp_m_n[i] = temp_m_n[i] % Q;
            end
        end

        for (int i = 0; i < 4; i++) begin
            if (temp_m_n[i] < 5) begin
                temp_m_n[i] = 0;
            end else if (temp_m_n[i] < 14) begin
                temp_m_n[i] = 9;
            end else begin
                temp_m_n[i] = 0;
            end
        end

        for (int i = 0; i < 4; i++) begin
            m_b[i] = (temp_m_n[i] == 9) ? 1 : 0;
        end
        
        decimal_value = (m_b[0] ? 8 : 0) | (m_b[1] ? 4 : 0) | (m_b[2] ? 2 : 0) | (m_b[3] ? 1 : 0);
        $display("decimal_value = %0d", decimal_value);
    end

    // Sequential logic for decryption_done
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            decryption_done <= 0;
            decryption_done_next <= 0;
        end else begin
            decryption_done_next <= decryption_enable; // Set when decryption_enable is active
            decryption_done <= decryption_done_next; // Delay by one cycle
        end
    end

endmodule