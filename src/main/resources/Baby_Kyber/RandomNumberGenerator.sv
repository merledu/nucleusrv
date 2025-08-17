/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

module RandomNumberGenerator #(
    parameter int MIN_VALUE, 
    parameter int MAX_VALUE  
)(
    input logic clk,
    input logic rst_n,
    input logic enable,
    output logic signed [31:0] random_number
);

    import "DPI-C" function int generate_random_number(int min_value, int max_value);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            random_number <= 0; 
        end else if (enable) begin
            random_number <= generate_random_number(MIN_VALUE, MAX_VALUE);  
        end
    end

endmodule
