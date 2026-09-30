// ??0Rva00431FB5@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??0Rva00431FB5@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /GX
// ??0Rva00431FB5@@QAE@XZ @0x00431FB5 61B: ctor stores vtable 0x0083C9B8 then clears +0x08 via rowed Rva000AD6F4::clear then stores vtable 0x007DBA74 and zeroes global 0x00A0322C; caller 0x00432154 28B; prev Disp0 next DispDword setters; no donor.
extern int g_00E0322C;
extern const void *const g_00C3C9B8[];
extern const void *const g_00BDBA74[];

class Rva000AD6F4
{
public:
	void clear();
	~Rva000AD6F4();
};

class Rva00431FB5
{
public:
	Rva00431FB5();
private:
	void *m_vptr;
	int m_04;
	Rva000AD6F4 m_08;
};

// ??0Rva00431FB5@@QAE@XZ present-unmatched
Rva00431FB5::Rva00431FB5()
{
	*(const void **)this = g_00C3C9B8;
	g_00E0322C &= 0;
	m_08.clear();
	*(const void **)this = g_00BDBA74;
}
