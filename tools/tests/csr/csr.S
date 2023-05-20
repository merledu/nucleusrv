.global _boot
.text
_boot:


      li x9, 0 #	x9 is always 0
      
      li x10, 31
      fscsr x10 # FCSR = 31
      fsflagsi 2 # FCSR = 2
      fsrmi 2 #	FCSR = 66
      
      li x10, 0
      fscsr x10
      li x10, 31
      li x11, 7
      fsflags x10 # FCSR = 31
      fsrm x11 # FCSR = 255
      
      li x10, 0
      fscsr x10
      li x10, 255
      fscsr x10 # FCSR = 255
      fsflags x9 # FCSR = 224
      fsrm x9 # # FCSR = 0
      
      li x10, 0
      fscsr x10
      fsflagsi 31 # FCSR = 31
      fsrmi 7 	  # FCSR = 255
      
      li x10, 33 # NV and RDN HIGH
      fscsr x10
      frflags x11 # x11 = 1
      frrm x12 # x12 = 1
      addi x11, x11, 1
      addi x12, x12, 1
      fsflags x11 # FCSR = 34	 
      fsrm x12 # FCSR = 66
      
      li x10, 1
      li x11, 2
      fscsr x10 # FCSR = 1
      fscsr x12, x11 # FCSR = 2
      fscsr x11, x12 # FCSR = 1
      
      fscsr x9
      li x10, 1
      li x11, 2
      fsflags x10 # FCSR = 32
      fsflags x12, x11 # FCSR = 64
      fsflags x11, x12 # FCSR = 32
      
      fscsr x9
      li x10, 1
      li x11, 2
      fsrm x10 # FCSR = 32
      fsrm x12, x11 # FCSR = 64
      fsrm x11, x12 # FCSR = 32
      
      fscsr x9
      li x10, 0
      li x11, 0
      fsflagsi 1 # FCSR = 1
      fsflagsi x12, 2 # FCSR = 2
      fsflags x12 # FCSR = 1
      
      
      
      
      
      
      
      
      
      
      
     
      
      
      
	
    
      
      
      
      
      
      
     
      
      
      
	
      
_end:
	nop
	.end			# End of file