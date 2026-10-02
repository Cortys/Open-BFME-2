// Memory-pool block hook from the 0x00033E90 neighbourhood. A __thiscall
// member that recognises the "PANS" block signature and tail-calls its own
// freeBlock method (pinned at 0x00033150) when the +0x0C byte is clear and
// +0x0D is set, otherwise clears the +0x20 field. The tail-callee must be a
// member of the same object: that is what keeps ecx live across the byte loads
// and makes the compiler use dl rather than cl. Identity is not recovered; the
// class and method names are address-derived. No // cl: line: the default /O2
// tail-call shape matches.

class Rva00033E90
{
public:
	void freeBlock(void *p);
	void check(void *p);
};

void Rva00033E90::check(void *p)
{
	if (p != 0 && *(int *)p == 0x534e4150)
	{
		if (*((char *)p + 0xd) != 0)
		{
			if (*((char *)p + 0xc) == 0)
				return freeBlock(p);
		}
		else
		{
			*(int *)((char *)p + 0x20) = 0;
		}
	}
}
