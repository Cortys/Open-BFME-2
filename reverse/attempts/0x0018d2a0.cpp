// ??0Rva0018D2A0@@QAE@XZ
// partial score=0.95 date=2026-10-04
// ??0Rva0018D2A0@@QAE@XZ
// partial score=0.9 date=2026-10-03
// cl: /O2 /MD /EHsc /arch:SSE
// ??0Rva0018D2A0@@QAE@XZ @0x0018D2A0 (149B): ctor with EH via empty base plus two data-pointer stores at +0/+8 then nameToKey of +0x10 into +0x40. Evidence: caller 0x0014D15C; rowed nameToKey 0x00148E1A plus TheNameKeyGenerator 0x009F36A4; vtable-like stores at +0/+8 and float movss from retail bytes.
class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};

enum NameKeyType
{
	NK_INVALID = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

extern const void *const g_00BCEF94[];
extern const void *const g_00BD5D20[];
extern const void *const g_00BD5D14[];

extern "C" void *memset(void *dst, int val, unsigned int size);

class Rva0018D2A0 : public EmptyBase
{
public:
	Rva0018D2A0();

private:
	const void *m_0;
	int m_4;
	const void *m_8;
	int m_c;
	char m_10[16];
	char m_20[16];
	char m_30[16];
	NameKeyType m_40;
	int m_44;
	int m_48;
	float m_4c;
	int m_50;
};

// ??0Rva0018D2A0@@QAE@XZ present-unmatched
Rva0018D2A0::Rva0018D2A0()
{
	m_4 = 1;
	m_c = 0;
	// Retail's +8 is stored TWICE: once here with 0xBCEF94 and again further
	// down with 0xBD5D14. The first value is dead, so only a volatile-qualified
	// store survives elimination, and it must come before the float zero so it
	// does not move into the immediate block.
	{
		volatile const void **slot = (volatile const void **)&m_8;
		*slot = (const void *)g_00BCEF94;
	}
	m_0 = g_00BD5D20;
	m_8 = g_00BD5D14;
	m_4c = 0.0f;
	m_44 = 0;
	m_48 = 0;
	m_50 = 0;
	memset(m_10, 0, 16);
	m_40 = TheNameKeyGenerator->nameToKey(m_10);
	memset(m_30, 0, 16);
}
