// Carried from the Open-BFME-1 donor at submodule revision 5cae4bdf
// (game/GameEngine/Source/Common/Rva009A5800Forward.cpp). Target evidence: the
// 23B body is byte-identical at BFME2 0x001B62C0 (donor b1 0x009A5800). The
// ?Rva009A5800Forward name and the EAX middle-argument ABI are donor assertions.
// The middle stack argument is passed to the callee in EAX, outside the
// MSVC C++ calling conventions. Keep the proven register setup in inline asm.
void __cdecl d_009a5620(void);

void __cdecl Rva009A5800Forward(int, int, int)
{
	__asm {
		mov eax, dword ptr [esp + 0Ch]
		mov ecx, dword ptr [esp + 04h]
		push eax
		mov eax, dword ptr [esp + 0Ch]
		push ecx
		call d_009a5620
		add esp, 8
	}
}
