// ?rva0025FBBC@Rva0025FBBC@@QAEXPAHHH@Z
// partial score=0.92 date=2026-09-29
// ?rva0025FBBC@Rva0025FBBC@@QAEXPAHHH@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /MD
// ?rva0025FBBC@Rva0025FBBC@@QAEXPAHHH@Z 0x0025FBBC 165B: color packing with three modes.
// Evidence: ret 0xc with ecx use proves __thiscall with 3 args; reads [ecx+0x28]; masks 0xffffff and shifts 0x15/0x17/0x18; caller 0x0025FCE8.
class Rva0025FBBC
{
public:
	void rva0025FBBC(int *out, int color, int mode);
private:
	int m_pad[10];
	int m_flags;
};

void Rva0025FBBC::rva0025FBBC(int *out, int color, int mode)
{
	int i = 0;
	switch (mode)
	{
	case 2:
	{
		int c = color & 0xffffff;
		for (; i < 4; ++i)
		{
			out[i] = c;
			int f = m_flags;
			if (i < 2)
			{
				f &= 0xfffffff8;
				f <<= 0x15;
			}
			else
			{
				f &= 0xfffffffe;
				f <<= 0x17;
			}
			out[i] = f | c;
		}
		break;
	}
	case 1:
	{
		int c = color & 0xffffff;
		for (; i < 4; ++i)
		{
			out[i] = c;
			int f = m_flags;
			f <<= 0x18;
			out[i] = f | c;
		}
		break;
	}
	case 0:
	{
		int c = color & 0xffffff;
		for (; i < 4; ++i)
		{
			out[i] = c;
			int f = m_flags;
			if (i >= 2)
			{
				f &= 0xfffffffe;
				f <<= 0x17;
			}
			else
			{
				f &= 0xfffffff8;
				f <<= 0x15;
			}
			out[i] = f | c;
		}
		break;
	}
	}
}
