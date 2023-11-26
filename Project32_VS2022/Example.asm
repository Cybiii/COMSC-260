.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	var1 BYTE 'A'
	var2 BYTE 'B'
	var3 BYTE 'C'
	var4 BYTE 'D'
	
.code
main proc

	mov eax, var1
	mov ebx, var2
	mov ecx, var3
	mov edx, var4

	mov var1, edx
	mov var2, eax
	mov var3, ebx
	mov var4, ecx

	invoke ExitProcess,0
main endp
end main