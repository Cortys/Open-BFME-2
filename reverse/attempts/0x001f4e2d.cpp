// ?rva001F4E2D@Rva001F4E2D@@QAE_NXZ
// partial score=0.93 date=2026-10-01
// ?rva001F4E2D@Rva001F4E2D@@QAE_NXZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD
// ?rva001F4E2D@Rva001F4E2D@@QAE_NXZ, retail 0x001F4E2D, 85 bytes.
// Branch on ParticleSystem+8 value selecting helper at +0x94 vs +0x98
// via virtual slot +0x10 with int arg. Guard dword at +0x8C, source at +0x3C.
// Evidence: unlock lane, 6 callers, pin ?Make001FCBD7@@YAPAVParticleSystem@@XZ,
// prev/next /O1 RGBColor getters, ret bool no args.
// ?rva001F4E2D@Rva001F4E2D@@QAE_NXZ present-unmatched
class ParticleSystem
{
public:
	int m_pad0;
	int m_pad4;
	int m_val;
};
class Rva001F4E2DHelper
{
public:
	virtual void u0();
	virtual void u1();
	virtual void u2();
	virtual void u3();
	virtual bool check(int v);
};
extern ParticleSystem *__cdecl Make001FCBD7();
class Rva001F4E2D
{
public:
	bool rva001F4E2D();
private:
	char m_pad0[0x3c];
	ParticleSystem *m_ps;
	char m_pad40[0x4c];
	int m_flag8C;
	char m_pad90[4];
	Rva001F4E2DHelper *m_h94;
	Rva001F4E2DHelper *m_h98;
};
bool Rva001F4E2D::rva001F4E2D()
{
	if (m_flag8C != 0)
		return false;
	ParticleSystem *ps = m_ps;
	if (ps == 0)
		ps = Make001FCBD7();
	int v = ps->m_val;
	Rva001F4E2DHelper *h;
	if (v > 0)
	{
		if (v > 2)
		{
			if (v > 4)
			{
				if (v > 6)
				{
					if (v == 7)
						h = m_h98;
					else
						return true;
				}
				else
					h = m_h94;
			}
			else
				h = m_h98;
		}
		else
			h = m_h94;
	}
	else
		return true;
	if (h != 0)
		return h->check(v);
	return false;
}
