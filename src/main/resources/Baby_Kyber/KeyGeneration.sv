/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

module KeyGeneration (
   
    input logic signed [31:0] A [3:0][3:0],
    input logic signed[31:0] e [1:0][3:0],
    input logic signed [31:0] secret_key [1:0][3:0],
    output logic signed [31:0] secretkey [1:0][3:0],
    output logic signed [31:0] result [1:0][3:0],
    output logic signed [31:0] combined_output [1:0][3:0][3:0],
    input logic clk,
    input logic rst_n,
    input logic key_enable,
    output logic key_done
);
   
    logic signed[31:0] poly_out0 [3:0];
    logic signed [31:0] poly_out1 [3:0];
    logic signed [31:0] poly_out2 [3:0];
    logic signed [31:0] poly_out3 [3:0];
    logic signed [31:0] added [3:0];
    logic signed [31:0] added1 [3:0];
    logic key_done_next; // Intermediate signal for delaying key_done

    // Secret key assignment
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int i = 0; i < 2; i++) begin
                for (int j = 0; j < 4; j++) begin
                    secretkey[i][j] <= 0;
                end
            end
        end else if (key_enable) begin
            secretkey[0][0] <= secret_key[0][0];
            secretkey[0][1] <= secret_key[0][1];
            secretkey[0][2] <= secret_key[0][2];
            secretkey[0][3] <= secret_key[0][3];
            secretkey[1][0] <= secret_key[1][0];
            secretkey[1][1] <= secret_key[1][1];
            secretkey[1][2] <= secret_key[1][2];
            secretkey[1][3] <= secret_key[1][3];
        end
    end

    // Polynomial matrix multiplications
    PolynomialMatrixMultiplication poly_mult0 (
        .clk(clk),
        .rst_n(rst_n),
        .enable(key_enable),
        .polynomial1(A[0]),
        .polynomial2(secret_key[0]),
        .polynomial_out(poly_out0)
    );
    
    PolynomialMatrixMultiplication poly_mult1 (
        .clk(clk),
        .rst_n(rst_n),
        .enable(key_enable),
        .polynomial1(A[1]),
        .polynomial2(secret_key[1]),
        .polynomial_out(poly_out1)
    );

    PolynomialMatrixMultiplication poly_mult2 (
        .clk(clk),
        .rst_n(rst_n),
        .enable(key_enable),
        .polynomial1(A[2]),
        .polynomial2(secret_key[0]),
        .polynomial_out(poly_out2)
    );

    PolynomialMatrixMultiplication poly_mult3 (
        .clk(clk),
        .rst_n(rst_n),
        .enable(key_enable),
        .polynomial1(A[3]),
        .polynomial2(secret_key[1]),
        .polynomial_out(poly_out3)
    );

    // Combinational logic for result computation
    always_comb begin
        for (int i = 0; i < 4; i++) begin
            added[i] = 0;
            added1[i] = 0;
            result[0][i] = 0;
            result[1][i] = 0;
        end
        if (key_enable) begin
            for (int i = 0; i < 4; i++) begin
                added[i] = (poly_out0[i] + poly_out1[i]);
                added1[i] = (poly_out2[i] + poly_out3[i]);
                if (added[i] < 0) begin
                    added[i] = added[i];
                end else begin
                    added[i] = (added[i] % 17);
                end

                if (added1[i] < 0) begin
                    added1[i] = added1[i];
                end else begin
                    added1[i] = (added1[i] % 17);
                end
            end
            for (int i = 0; i < 4; i++) begin
                result[0][i] = added[i] + e[0][i];
                result[1][i] = added1[i] + e[1][i];
                if (result[0][i] < 0) begin
                    result[0][i] = result[0][i];
                end else begin
                    result[0][i] = (result[0][i] % 17);
                end
                if (result[1][i] < 0) begin
                    result[1][i] = result[1][i];
                end else begin
                    result[1][i] = (result[1][i] % 17);
                end
            end
        end
    end

    // Sequential logic for combined_output and key_done
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < 2; i++) begin
                for (int j = 0; j < 4; j++) begin
                    for (int k = 0; k < 4; k++) begin
                        combined_output[i][j][k] <= 0;
                    end
                end
            end
            key_done <= 0;
            key_done_next <= 0;
        end else begin
            if (key_enable) begin
                for (int i = 0; i < 4; i++) begin
                    for (int j = 0; j < 4; j++) begin
                        combined_output[0][i][j] <= A[i][j];
                    end
                end
                for (int i = 0; i < 2; i++) begin
                    for (int j = 0; j < 4; j++) begin
                        combined_output[1][i][j] <= result[i][j];
                    end
                end
                key_done_next <= 1; // Set intermediate signal
            end else begin
                key_done_next <= 0;
            end
            key_done <= key_done_next; // Delay key_done by one cycle
        end
    end

endmodule