// ??0Rva004F10E6@@QAE@XZ
// partial score=0.94 date=2026-10-03
// cl: /Os /MD
// ??0Rva004F10E6@@QAE@XZ @ 0x004F10E6 48B evidence: ctor stores vtable 0x00C62E40 then zeros plus0x04 plus0x08 plus0x0C plus0x10 ones at plus0x14 plus0x1C zero byte plus0x19 zero dword plus0x20 or -1 at plus0x2C zeros plus0x28 plus0x29; callers 0x004F2902 0x004F1A94 0x004F25BC 0x004F264E 0x004F3C7A 0x004F3FA8; prev true getter next ModuleNameGetters; size 0x30 matches new in 0x004F288C
extern const void *const g_00C62E40[];

struct Rva004F10E6
{
	const void *m_00;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
	unsigned char m_pad18;
	unsigned char m_19;
	unsigned char m_pad1A[2];
	int m_1C;
	int m_20;
	int m_pad24;
	unsigned char m_28;
	unsigned char m_29;
	unsigned char m_pad2A[2];
	int m_2C;
	Rva004F10E6();
};

// ??0Rva004F10E6@@QAE@XZ present-unmatched
Rva004F10E6::Rva004F10E6()
{
	m_00 = g_00C62E40;
	m_04 = 0;
	m_08 = 0;
	m_0C = 0;
	m_10 = 0;
	m_14 = 1;
	m_19 = 0;
	m_1C = 1;
	m_20 = 0;
	m_2C = -1;
	m_28 = 0;
	m_29 = 0;
}
