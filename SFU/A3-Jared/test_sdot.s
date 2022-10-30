.import ../sdot.s
.import ../utils.s

# Set vector values for testing
.data
# Sparse vector
#              Each entry in coo is struct [Row,Col,Value]. Since vector; here each row is always 0.
#              e.g., consider the first three ints [0,0,1]. This says element [0] in vector is 1.
coo_vector0: .word 0 0 1 0 2 3 0 4 5 0 5 6 0 6 7 0 8 9
# Dense vector
vector1: .word 1 2 3 4 5 6 7 8 9
# Result is 1*1 + 3*3 + 5*5 + 6*6 + 7*7 + 9*9 = 201

.text
# main function for testing
main:
    # Load address of vector registers.
    la a0,coo_vector0
    la a1,vector1

    # Set number of non zeros in vector
    li s0, 0 # count
    mv s1, a0 # coo vector
zero_loop:
    lw t0, 0(s1)
    bne t0, x0 zero_loop_end # the first element is always zero because its a vector
    addi s0, s0, 1 # increment the number of elements
    addi s1, s1, 12 # move to the next element of the coo vector
    j zero_loop
zero_loop_end:
    mv a2, s0

    #TESTING
    # mv a1, a2
    # jal print_int
    #TESTING
    

    # Call sdot function
    jal sdot
    
    # Print integer result
    mv a1,a0
    jal print_int


    # Print newline
    li	a1, '\n' 
    jal print_char

    # Exit
    jal exit
