// ??1Rva005ECAD0@@QAE@XZ
// partial score=0.93 date=2026-10-03
// cl: /O2 /EHsc /MD
// ??1Rva005ECAD0@@QAE@XZ @ 0x005ECAD0 (60B): vtable store then two member dtors.
// Evidence: vtable 0x008785B0 at [this]; member +0x10 dtor 0x005242D7; member +0x4 dtor 0x005EC9BA;
// EH prolog with handler 0x007A4611; unblocks 0x005ECFE4 0x005ED152 0x005ECB0C; callers include Unwind funclets.
extern const void *const g_00C785B0[];

class Rva005242D7
{
	void *m_s0;
	void *m_s4;
	void *m_s8;
public:
	~Rva005242D7();
};

class Rva005EC9BA
{
	void *m_s0;
	void *m_s4;
	void *m_s8;
public:
	~Rva005EC9BA();
};

class Rva005ECAD0
{
	void *m_vtbl;
	Rva005EC9BA m_vec4;
	Rva005242D7 m_chain10;
public:
	~Rva005ECAD0();
};

// ??1Rva005ECAD0@@QAE@XZ present-unmatched
Rva005ECAD0::~Rva005ECAD0()
{
	*(const void **)this = g_00C785B0;
}
