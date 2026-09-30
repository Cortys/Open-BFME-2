// ??1Rva00161220@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??1Rva00161220@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /GX
//
// ??1Rva00161220@@QAE@XZ @0x004F05F0 102B. Destructor of Rva00161220 (layout
// copied verbatim from Rva00161220Ctor.cpp): releases the node list at +0x14
// through virtual slot 0 with a zero argument, freeing each returned pointer
// through rowed operator delete, sets paired flags at +0x5D/+0x5E of the
// object at +0x1C, clears the head, and parks the vptr on g_00BBB554.
// Vtable anchor declared as the extern name the packet pins. Honest class,
// real layout; caller 0x004EF609.
extern "C" int Rva00161220VTableAnchor;
extern const void *const g_00BBB554[];

void __cdecl operator delete(void *p);

struct Rva004F05F0Node {
	virtual void *slot00(int flag);
	char m_pad04[8];
	Rva004F05F0Node *m_next;
};

struct Rva004F05F0Flags {
	unsigned char m_pad00[0x5D];
	unsigned char m_5D;
	unsigned char m_5E;
};

class Rva00161220
{
	void *m_vptr;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	Rva004F05F0Node *m_14;
	char m_18;
	Rva004F05F0Flags *m_1C;
	int m_20;
	int m_24;
	char m_28;
	char m_29;
	char m_2A;
	int m_2C;

public:
	Rva00161220();
	~Rva00161220();
};

struct VptrGuard {
	void **m_pp;
	~VptrGuard() { *m_pp = (void *)g_00BBB554; }
};

// ??1Rva00161220@@QAE@XZ present-unmatched
Rva00161220::~Rva00161220()
{
	VptrGuard g = { &m_vptr };
	m_vptr = (void *)&Rva00161220VTableAnchor;
	if (m_14) {
		Rva004F05F0Node *cur = m_14;
		do {
			Rva004F05F0Node *next = cur->m_next;
			void *q = cur->slot00(0);
			::operator delete(q);
			cur = next;
		} while (cur);
	}
	Rva004F05F0Flags *f = m_1C;
	if (f && f->m_5D == 0) {
		f->m_5E = 1;
		f->m_5D = 1;
	}
	m_14 = 0;
}
