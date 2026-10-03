// cl: /Od
// ?rva00029ee0@@YAXXZ @0x00029EE0 61B
// Address-derived wrapper twin of bfmeGoOV 0x29EB0: it forwards its five stack
// words plus a local dummy to the reversed find-first-not-in-set core at
// 0x28200. The by-value class temporaries retail builds in the outgoing
// argument area cannot be reproduced by clean C++ with the VC7.1 /Od code
// generator (verified: POD, user-ctor, virtual, base-class and struct-return
// forms all push their arguments directly), so the call shape is spelled with
// inline __asm, matching the landed BfmeConv1441/1443 siblings.

void rva00028200();

void rva00029ee0()
{
	char n;
	char z0[79];

	__asm
	{
		lea eax, n
		push eax
		mov ecx, dword ptr [ebp+18h]
		push ecx
		mov edx, dword ptr [ebp+14h]
		push edx
		push ecx
		mov dword ptr [ebp-10h], esp
		mov eax, dword ptr [ebp-10h]
		mov ecx, dword ptr [ebp+10h]
		mov dword ptr [eax], ecx
		push ecx
		mov dword ptr [ebp-14h], esp
		mov edx, dword ptr [ebp-14h]
		mov eax, dword ptr [ebp+0Ch]
		mov dword ptr [edx], eax
		mov ecx, dword ptr [ebp+8]
		push ecx
		call rva00028200
		add esp, 18h
		mov eax, dword ptr [ebp+8]
	}
}
