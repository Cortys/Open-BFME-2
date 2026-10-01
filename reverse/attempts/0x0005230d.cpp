// ?rva0005230D@Rva00699180Owner@@QAEXMMMMM@Z
// partial score=0.94 date=2026-09-30
// ?rva0005230D@Rva00699180Owner@@QAEXMMMMM@Z
// partial score=0.94 date=2026-09-30
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /arch:SSE2 /Oi
// Combined TU: thiscall refreshPair (0x00699180) + setVolumes (0x006999C0).
// Helper body is the real member; no stand-in.
//
// Retail bodies: refreshPair 296B @0x00051ED6, refreshAll 28B @0x0005202C.
// Transferred from the BFME1 reconstruction (same Rva00699180Volume.cpp TU
// family). Retail adaptations, all measured from the target bytes:
// float-heavy refreshPair needs /arch:SSE2 with intrinsics (/Oi) so the
// slot copy folds to four movsd and the zero-fill to stosd;
// #pragma optimize("y", off) keeps its ebp frame while frameless
// refreshAll keeps the sibling-loop shape (no this reload); the clamp
// section is a rolled 0..3 loop here, and setVolumes is not claimed.
// Both bodies rowed: the m_scale reference local (float &scale) forces the
// scale-first mulss operand order retail shows (plain member reorder is
// commutative-inert); the pointer homes to eax via lea like retail.

class Rva00699180Owner
{
public:
	void refreshPair(int a, int b);
	void refreshAll();
	void rva00051FFE(int b);
	void rva00052015(int b);
	void rva00052048(int idx);
	void rva00052098(int b);
	void rva0005230D(float a1, float a2, float a3, float a4, float a5);
	void setVolumes(float volume, unsigned char flags);

	char m_pad0[4];
	float m_base[12];
	float m_product[6];
	char m_pad4c[0x94 - 0x4c];
	float m_atten;
	float m_vol;
	float m_scale;
	char m_padA0[0xAC - 0xA0];
	float m_ac;
	float m_b0;
	float m_b4;
	float m_b8;
	float m_bc;
	float m_c0;
	unsigned char m_c4;
	char m_padC5[0xC8 - 0xC5];
	float m_slot[12][4];
};

extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
extern "C" void *memset(void *dst, int v, unsigned int n);
extern float g_Va00BBB8D8;

#pragma optimize("y", off)
// ?refreshPair@Rva00699180Owner@@QAEXHH@Z
void Rva00699180Owner::refreshPair(int a, int b)
{
	int idx = b + a * 2;
	float *slot = (float *)((char *)this + 0xC8 + (idx << 4));
	float old[4];
	memcpy(old, slot, sizeof(old));

	if (a == 5)
	{
		slot[0] = 1.0f;
		slot[1] = 1.0f;
		slot[2] = 1.0f;
		slot[3] = 1.0f;
	}
	else if (*(unsigned char *)0x00DB3F7C)
	{
		slot[0] = *((float *)((char *)this + 4 + idx * 4)) * ((float *)0x00DB3F64)[a] * m_vol;
		if (b == 1)
			slot[0] = slot[0] * m_atten;
		float &scale = m_scale;
		slot[1] = scale * slot[0];
		slot[2] = m_product[a] * slot[0];
		slot[3] = scale * slot[2];

		for (int i = 0; i < 4; ++i)
		{
			float x = slot[i];
			if (x < 0.0f)
				x = 0.0f;
			else if (x > 1.0f)
				x = 1.0f;
			slot[i] = x;
		}
	}
	else
	{
		memset(slot, 0, sizeof(float) * 4);
	}

	for (int i = 0; i < 4; ++i)
	{
		if (slot[i] != old[i])
			*((unsigned char *)this + 0x188 + (b + a * 2) * 4 + i) = 2;
	}
}
#pragma optimize("", on)

// ?refreshAll@Rva00699180Owner@@QAEXXZ
void Rva00699180Owner::refreshAll()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 2; ++j)
			refreshPair(i, j);
	}
}

void Rva00699180Owner::rva00051FFE(int b)
{
	for (int i = 0; i < 2; ++i)
		refreshPair(b, i);
}

void Rva00699180Owner::rva00052015(int b)
{
	for (int i = 0; i < 6; ++i)
		refreshPair(i, b);
}

void Rva00699180Owner::rva00052048(int idx)
{
	struct Factor
	{
		float v;
		float w;
	};
	float *slot = (float *)((char *)this + 0x34 + idx * 4);
	char *base = (char *)this + idx * 12;
	Factor *begin = *(Factor **)(base + 0x4c);
	Factor *end = *(Factor **)(base + 0x50);
	*slot = 1.0f;
	float &r = *slot;
	for (Factor *p = begin; p != end; ++p)
		r = r * p->v;
	float v = r;
	if (v < 0.0f)
		v = 0.0f;
	else if (v > 1.0f)
		v = 1.0f;
	r = v;
}

void Rva00699180Owner::rva00052098(int b)
{
	rva00052048(b);
	rva00051FFE(b);
}

// ?rva0005230D@Rva00699180Owner@@QAEXMMMMM@Z present-unmatched
void Rva00699180Owner::rva0005230D(float a1, float a2, float a3, float a4, float a5)
{
	float one = g_Va00BBB8D8;
	float v1 = a1;
	if (v1 < 0.0f)
		v1 = 0.0f;
	else if (v1 > one)
		v1 = one;
	m_ac = v1;
	float v2 = a2;
	float r2 = one;
	if (v2 < 0.0f)
		r2 = 0.0f;
	else if (v2 <= one)
		r2 = v2;
	m_b0 = r2;
	m_b4 = a3;
	m_b8 = a4;
	m_bc = a5;
	m_c0 = 0.0f;
	m_c4 = 1;
	m_scale = v1;
	refreshAll();
}

void Rva00699180Owner::setVolumes(float volume, unsigned char flags)
{
	if (flags & 1)
	{
		for (int i = 4; i < 6; ++i)
			m_base[i] = volume;
		rva00051FFE(2);
	}
	if (flags & 2)
	{
		m_base[0] = volume;
		refreshPair(0, 0);
	}
	if (flags & 4)
	{
		m_base[1] = volume;
		refreshPair(0, 1);
	}
	if (flags & 8)
	{
		for (int i = 0; i < 2; ++i)
		{
			m_base[2 + i] = volume;
			m_base[8 + i] = volume;
		}
		rva00051FFE(1);
		rva00051FFE(4);
	}
	if (flags & 16)
	{
		for (int i = 6; i < 8; ++i)
			m_base[i] = volume;
		rva00051FFE(3);
	}
}
