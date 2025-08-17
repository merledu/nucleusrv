/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

module DecimalToBitConverter (
    input logic [31:0] input_value,  
    output logic [3:0] coefficients  
);
    logic [7:0] bit_list;  
    reg [31:0] expanded_value;

    always_comb begin
        m = input_value[3:0];

        for (int i = 0; i < 4; i++) begin
            coefficients[i] = 0; 
            for (int j = 0; j < 2; j++) begin
                coefficients[i] += (bit_list[i * 2 + j] << j); 
            end
        end
    end

endmodule
