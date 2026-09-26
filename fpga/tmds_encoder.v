// ============================================================================
// File: fpga/tmds_encoder.v
// Module: tmds_encoder
// Description: Standard DVI 1.0 / HDMI 8b/10b TMDS Encoder
// ============================================================================

`timescale 1ns / 1ps

module tmds_encoder (
    input  wire       clk,          // Pixel clock (25 MHz)
    input  wire       rst,          // Reset (active high)
    input  wire [7:0] video_data,   // 8-bit pixel color component
    input  wire [1:0] control_data, // 2-bit control data ({vsync, hsync})
    input  wire       video_enable, // 1: Active video, 0: Blanking
    output reg  [9:0] tmds_out      // 10-bit encoded TMDS symbol
);

    // Count ones in video_data
    wire [3:0] ones_vd = {3'd0, video_data[0]} + {3'd0, video_data[1]} +
                         {3'd0, video_data[2]} + {3'd0, video_data[3]} +
                         {3'd0, video_data[4]} + {3'd0, video_data[5]} +
                         {3'd0, video_data[6]} + {3'd0, video_data[7]};

    wire use_xnor = (ones_vd > 4'd4) || ((ones_vd == 4'd4) && (video_data[0] == 1'b0));

    reg [8:0] q_m;
    integer i;
    always @(*) begin
        q_m[0] = video_data[0];
        for (i = 1; i < 8; i = i + 1) begin
            q_m[i] = use_xnor ? ~(q_m[i-1] ^ video_data[i]) : (q_m[i-1] ^ video_data[i]);
        end
        q_m[8] = use_xnor ? 1'b0 : 1'b1;
    end

    wire [3:0] ones_qm  = {3'd0, q_m[0]} + {3'd0, q_m[1]} + {3'd0, q_m[2]} + {3'd0, q_m[3]} +
                          {3'd0, q_m[4]} + {3'd0, q_m[5]} + {3'd0, q_m[6]} + {3'd0, q_m[7]};
    wire [3:0] zeros_qm = 4'd8 - ones_qm;

    reg signed [4:0] disparity = 5'sd0;

    reg [9:0] control_word;
    always @(*) begin
        case (control_data)
            2'b00:   control_word = 10'b1101010100;
            2'b01:   control_word = 10'b0010101011;
            2'b10:   control_word = 10'b0101010100;
            default: control_word = 10'b1010101011;
        endcase
    end

    always @(posedge clk) begin
        if (rst) begin
            tmds_out  <= 10'b1101010100;
            disparity <= 5'sd0;
        end else if (!video_enable) begin
            tmds_out  <= control_word;
            disparity <= 5'sd0;
        end else begin
            if ((disparity == 5'sd0) || (ones_qm == zeros_qm)) begin
                tmds_out[9]   <= ~q_m[8];
                tmds_out[8]   <= q_m[8];
                tmds_out[7:0] <= q_m[8] ? q_m[7:0] : ~q_m[7:0];

                if (q_m[8] == 1'b0)
                    disparity <= disparity + $signed({1'b0, zeros_qm}) - $signed({1'b0, ones_qm});
                else
                    disparity <= disparity + $signed({1'b0, ones_qm}) - $signed({1'b0, zeros_qm});
            end else begin
                if (((disparity > 5'sd0) && (ones_qm > zeros_qm)) ||
                    ((disparity < 5'sd0) && (zeros_qm > ones_qm))) begin
                    tmds_out[9]   <= 1'b1;
                    tmds_out[8]   <= q_m[8];
                    tmds_out[7:0] <= ~q_m[7:0];
                    disparity     <= disparity + $signed({3'b000, q_m[8], 1'b0}) +
                                     $signed({1'b0, zeros_qm}) - $signed({1'b0, ones_qm});
                end else begin
                    tmds_out[9]   <= 1'b0;
                    tmds_out[8]   <= q_m[8];
                    tmds_out[7:0] <= q_m[7:0];
                    disparity     <= disparity - $signed({3'b000, ~q_m[8], 1'b0}) +
                                     $signed({1'b0, ones_qm}) - $signed({1'b0, zeros_qm});
                end
            end
        end
    end

endmodule
