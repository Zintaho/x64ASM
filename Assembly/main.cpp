int main()
{
	__asm
	{
		mov eax, 0
		mov ebx, 0
		mov ecx, 0
		mov edx, 0

		mov ax, 0xfd
		mov bx, ax

		mov ch, 0xce
		mov dl, ch
	}
}