; assembly using x86-64
section .text
bits 64
default rel ; to handle address relocation
global saxpy_asm

saxpy_asm:
    pxor xmm0, xmm0
    pxor xmm1, xmm1
    pxor xmm2, xmm2
    pxor xmm3, xmm3

    movss xmm0, [rcx] ; A
    movss xmm1, [rdx] ; X
    movss xmm2, [r8] ; Y
    movss xmm3, [r9] ; Z
    mov rcx, [r10] ;  n

    saxpy_loop:

        mulss xmm1, xmm0   ; Result stored in xmm1

        addss xmm1, xmm2   ; Result stored in xmm1

        movss xmm3, xmm1   ; Store the result in Z

        add rdx, 4         ; Move to the next element of X
        add r8, 4          ; Move to the next element of Y
        add r9, 4          ; Move to the next element of Z

        loop saxpy_loop
    ret
