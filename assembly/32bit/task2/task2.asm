SYS_EXIT equ 1
SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1

section .data
	msg1 db "Enter a:",10,13
	len1 equ $- msg1
 
	msg2 db "Enter b:",10,13
	len2 equ $- msg2

	msg3 db "Enter h:",10,13
 	len3 equ $-msg3
	
	msg4 db "The sum is:",10,13
	len4 equ $- msg4

section .bss 
	a resb 2
 	b resb 2
	h resb 2
 	res resb 2

section .text
	global main ;must be declared for using gcc

main:
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg1
	mov edx, len1
	int 0x80
 
	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, a
	mov edx, 2
	int 0x80
 
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg2
	mov edx, len2
	int 0x80
 
	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, b
	mov edx, 2
	int 0x80

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg3
	mov edx, len3
	int 80h

	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, h
	mov ecx, 2
	int 80h
 
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg4
	mov edx, len4
	int 0x80

	mov ax,[a]
	sub ax,'0'
	mov bx,[b]
	sub bx,'0'
	add ax,bx
	mov bx,2
	mov dx,0
	div bx
	mov bx,[h]
	sub bx,'0'
	mul bx
	add ax,'0'
	mov word[res],ax
 	
	; print the sum
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, res
	mov edx, 2
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
