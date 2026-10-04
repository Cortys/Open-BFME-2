// ?rva006C2FB0@Rva006C2D20Sink@@QAEXPBD0@Z
// partial score=0.95 date=2026-10-04
// ?rva006C2FB0@Rva006C2D20Sink@@QAEXPBD0@Z
// partial score=0.95 date=2026-10-04
// cl: /O2 /DNDEBUG /MD
// Retail body 0x006C2FB0, 100 bytes. Log/chat line formatter: it copies the
// second stack argument into a 0x300-byte stack buffer, appends a newline after
// it, then hands the REMAINDER of the buffer plus the first stack argument and
// the remaining room to a thiscall sink on `this`.
//
// Evidence (retail bytes):
//   mov edx,[esp+8]            second stack argument (the text copied)
//   sub esp,0x300              0x300-byte stack buffer, buffer base at esp+8
//   push ebx ; mov eax,edx ; push esi ; lea esi,[eax+1]
//   strlen loop (mov bl,[eax]; inc eax; test bl,bl; jne)  eax-esi = strlen
//   lea esi,[eax+1]           esi = strlen+1
//   cmp esi,0x2ff; jae done    bail when the copy would not fit
//   lea esi,[esp+8]; sub esi,edx
//   copy loop (mov bl,[edx]; mov [esi+edx],bl; inc edx; ...)  hand-rolled strcpy
//   mov edx,0x2fe; sub edx,eax third argument = 0x2FE - strlen(text)
//   mov byte [esp+eax+0xc],0x0a   buffer[strlen] = '\n'
//   lea eax,[esp+eax+0xd]     first sink argument = buffer + strlen + 1
//   push eax; push edx; push [esp+0x310]   ... and the first stack argument
//   call 0x006C2D20            thiscall sink (ecx is still the incoming `this`)
//   pop esi; pop ebx; add esp,0x300; ret 8
//
// The sink 0x006C2D20 is not recovered here; it is declared under an
// address-derived name and resolves through its symbols.csv pin. Its own body
// reads its three arguments at [esp+0x294]/[esp+0x298]/[esp+0x29c] behind its
// 0x274-byte frame, which is consistent with (dst, src, room).
class Rva006C2D20Sink
{
public:
	void rva006C2D20(const char *dst, const char *src, unsigned int room);
	void rva006C2FB0(const char *text, const char *extra);
};

// ?rva006C2FB0@Rva006C2D20Sink@@QAEXPBD0@Z  0x006C2FB0 100B
void Rva006C2D20Sink::rva006C2FB0(const char *text, const char *extra)
{
	char buffer[0x300];
	const char *p = extra;
	const char *base = p + 1;
	char c;
	do
	{
		c = *p;
		++p;
	} while (c);
	int len = (int)(p - base);
	if ((unsigned int)(len + 1) < 0x2ff)
	{
		const char *src = extra;
		char *dst = buffer;
		do
		{
			*dst = *src;
			++dst;
			++src;
		} while (*src);
		buffer[len] = '\n';
		rva006C2D20(buffer + len + 1, text, 0x2fe - len);
	}
}