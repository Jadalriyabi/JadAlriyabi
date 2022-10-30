.import ../read_matrix.s
.import ../gemv.s
.import ../dot.s
.import ../utils.s

.data
output_step1: .asciiz "\n**Step result = gemv(matrix, vector)**\n"



.globl main

.text
main:
    # =====================================
    # COMMAND LINE ARGUMENTS
    # =====================================
    # Args:
    #   a0: int argc
    #   a1: char** argv
    #
    # Usage:
    #   main.s <VECTOR_PATH> <MATRIX_PATH> 

    # Exit if incorrect number of command line args
    
# =====================================
# LOAD MATRIX and VECTOR. Iterate over argv.
# =====================================
# Load Matrix        
# Load Vector

# =====================================
# RUN GEMV
# =====================================
# SPMV :    m * v

    # addi sp, sp, -28
    # sw ra, 0(sp)
    # sw s2, 4(sp)
    # sw s3, 8(sp)
    # sw s4, 12(sp)
    # sw s5, 16(sp)
    # sw s6, 20(sp)
    # sw s7, 24(sp)

    
    
    #TESTING a0=3
    #TESTING 0(a1) = ./test_files/main_gemv.s 
    #TESTING 4(a1) = ./inputs/mnist/bin/v0.bin
    #TESTING 8(a1) = ./inputs/mnist/bin/m.bin 

    #
    mv s7, a1

    # lw a1, 4(s7)
    # jal print_str

    # Read the Matrix
    lw a0, 8(s7)
    jal read_matrix # returns --> ptr, rows, cols
    mv s0, a0
    mv s1, a1 #128
    mv s2, a2 #784

    #TESTING number of columns
    # mv a1, s2
    # jal print_int
    #TESTING

    # Read the Vector
    lw a0, 4(s7)
    # la a0, a0
    jal read_matrix # returns --> ptr, rows, cols
    mv s3, a0
    mv s4, a1 #784
    mv s5, a2 #1

    la a1, output_step1
    jal print_str

    #TESTING number of columns
    # mv a1, s5
    # jal print_int
    #TESTING

    # Allocate s2*s5*4 bytes for the output matrix in the a0 pointer.
    mul s6, s2, s5
    slli s6, s6, 2
    mv a0, s6
    jal malloc
    mv s6, a0

    # Multiply M * V
    mv a0, s0
    mv a1, s1
    mv a2, s2
    mv a3, s3
    mv a4, s4
    mv a5, s6
    jal gemv # returns --> a0 ptr to output vector

    ## FILL OUT. Output is a dense vector.
    # mv a0,# Base ptr
    mv a1, s1 #rows
    mv a2, s5 #cols
    jal print_int_array 

    jal ra, free

    # Epilogue
    # lw ra, 0 (sp)
    # lw s2, 4 (sp)
    # lw s3, 8 (sp)
    # lw s4, 12 (sp)
    # lw s5, 16 (sp)
    # lw s6, 20 (sp)
    # lw s7, 24 (sp)
    # addi sp, sp, 28

    addi a0,x0, 10
    ecall










    
 




















    # Print newline afterwards for clarity
    li a1 '\n'
    jal print_char

    jal exit
