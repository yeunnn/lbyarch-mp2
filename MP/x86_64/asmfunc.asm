; assembly using x86-64

section .data
msg db "Hello World", 13, 10, 0

section .text
bits 64
default rel ; to handle address relocation
global asmhello
extern printf

asmhello:
	sub rsp, 8*5 ; caller or stack frame with 40 bytes
	lea rcx, [msg]
	call printf
	add rsp, 8*5 ; closing statement

	ret