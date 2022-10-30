.import ../read_matrix.s
.import ../utils.s

.data
file_path: .asciiz "./test_files/test_input.bin"
#file_path: .asciiz "./inputs/mnist/bin/m.bin"

.text
main:
    # Read matrix into memory
    
    #TESTING
    # la a1, file_path
    # jal print_str 
    #TESTING

    # Print out elements of matrix
    la a0, file_path
    jal read_matrix #returns --> ptr, rows, cols

    #TESTING
    # mv a1, a2
    # jal print_int
    #TESTING

    # mv s2, a0
    # mv s3, a1
    # lw s5, 0 (s3)

    #TESTING
    # mv a1, s3
    # jal print_int
    #TESTING


    # mv a0, s2
    # mv a1, s5
    # li a2, 1
    jal print_int_array # intput --> ptr, rows, cols

    jal ra, free

    # Terminate the program
    addi a0, x0, 10
    ecall