open_project /home/hshoaib/project_3/project_3.xpr
reset_run synth_1
reset_run impl_1
launch_runs synth_1 -jobs 4
wait_on_run synth_1
launch_runs impl_1 -to_step write_bitstream -jobs 4
wait_on_run impl_1
puts "BUILD_COMPLETE_STATUS: [get_property STATUS [get_runs impl_1]]"
