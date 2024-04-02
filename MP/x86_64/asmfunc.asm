; assembly using x86-64
section .text
bits 64
default rel ; to handle address relocation
global saxpy_asm

saxpy_asm:
    ; n, X, Y, Z, A is the order
    ; rcx, rdx, r8, r9
    ; We only need to find A the 5th parameter that's outside the safe 4, which is +32
     
    push rbp
    mov rbp, rsp
    add rbp, 16

    movss xmm4, [rbp + 32] ; the Value of A, which xmm4 is designated for

    saxpy_loop:

        movss xmm1, [rdx] ; X
        movss xmm2, [r8] ; Y

        mulss xmm1, xmm4
        addss xmm1, xmm2

        movss [r9], xmm1

        add rdx, 4;
        add r8, 4;
        add r9, 4;

        loop saxpy_loop

    pop rbp
    ret