# Type your code here.
# Do not initialize register values here.

# Compare $t0 and $t1
slt $t4, $t0, $t1    
bne $t4, $zero, less 

# $t0 >= $t1
move $t5, $t0         
j compare_t2         

less: 
# $t0 < $t1
move $t5, $t1  

compare_t2:
# Compare $t5 and $t2 (where $t5 holds the max of $t0 and $t1)
slt $t4, $t5, $t2  
bne $t4, $zero, less_t5_t2 
# $t5 >= $t2
move $t3, $t5 
j end

less_t5_t2:
# $t5 < $t2
move $t3, $t2

