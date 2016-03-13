section .text
	global _start

_start:
	mov ecx,[num1]
	mov eax,[num2]
	jmp _find_gcd
	

_find_gcd:
	cmp ecx,eax
	je _exit
	jg _first_case
	jmp _second_case


_first_case:
	sub ecx,eax
	jmp _find_gcd
		

_second_case:
	sub eax,ecx
	jmp _find_gcd
	

_exit:
	add ecx,'0'
	mov [gcd],ecx
	mov ecx,msg
	mov edx,len
	mov ebx,1
	mov eax,4
	int 0x80

	mov ecx,gcd
	mov edx,2
	mov ebx,1
	mov eax,4
	int 0x80

	mov eax,1
	int 80h


section .data
	msg db "GCD is: ", 0xA, 0xD
	len equ $-msg
	num1 DD 10
	num2 DD 5
	gcd DD 0
