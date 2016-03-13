section .text

global _start

_start:
	call _helper
	add eax,'0'
	mov [result],eax
	mov ecx, result		; string to print
	mov edx,2
	mov ebx,1		; file to write to 
	mov eax,4		; sys call num to print
	int 0x80

	jmp _exit

_helper:
	mov eax,[num1] 		; move var into reg
	mov ecx,[num2]		; move var into reg
	push eax		; push acutal param 1 on stack
	push ecx		; push actual param 2 on stack
	call _add		; call function
	add esp,8		; deallocate stack used
	ret			; return to caller

_add:
	push ebp 	; push callers ebp onto stack
	mov ebp,esp	; set callee ebp
	sub esp,4	; create room for local var
	push edi	; save caller reg
	push esi	; save caller reg

	mov eax,0
	mov [ebp - 4], DWORD 1  ; assign 1 to local var
	mov esi,[ebp + 8]       ; put formal param 1 into esi
	mov edi,[ebp + 12]	; formal param 2 into edi
	add eax,esi		; add param 1
	add eax,edi		; add param 2
	add eax,[ebp - 4]	; add local var

	pop esi			; restore caller esi
	pop edi			; restore caller edi
	mov esp,ebp		; restore stack pointer
	pop ebp			; restore caller ebp
	ret			; return to caller

_print_ecx:
	mov ecx,msg
	mov edx,len
	mov ebx,1
	mov eax,4
	int 0x80
	ret

_exit:	
	mov eax,1
	int 80h

section .data
	msg db "Called func", 0xA, 0x0
	len equ $-msg
	num1 DD 3
	num2 DD 4
	result DD 0
