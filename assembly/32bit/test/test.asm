SYS_EXIT equ 1
SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1

section .data
	msg1 db "Enter a:",10,13
	len1 equ $-msg1

	msg2 db "Enter b:",10,13
	len2 equ $-msg2

	msg3 db "Result is:",10,13
	len3 equ $-msg3
	
section .bss
	a resb 2
	b resb 2
	res resb 2
section .text
	global main

main:
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg1
	mov edx, len1
	int 80h

	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, a
	mov edx, 2
	int 80h

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg2
	mov edx, len2
	int 80h

	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, b
	mov edx, 2
	int 80h
	
	mov eax, [a]
	mov ebx, [b]
	sub eax, '0'
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [res], eax

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg3
	mov edx, len3
	int 80h
		
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, res
	mov edx, 1
	int 80h
		
	mov eax, SYS_EXIT
	mov ebx, STDIN
	int 80h
