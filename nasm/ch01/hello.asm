; hello.asm
section .data
    msg	db      "hello, world",0
    nl  db       0xa ; ascii code for newline
section .bss
section .text
    global main
main:
	mov     rax, 1		; 1 = sys_write
    mov     rdi, 1		; 1 = stdout
    mov     rsi, msg	; string to display in rsi
    mov     rdx, 12		; length of the string, without 0
    syscall				; display the string

    mov     rax, 1
    mov     rdi, 1
    mov     rsi, nl
    mov     rdx, 1
    syscall

    mov     rax, 60		; 60 = sys_exit
    mov     rdi, 0		; 0 = success exit code
    syscall				; quit
