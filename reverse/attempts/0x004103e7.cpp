// ??0Rva0045EF90Object@@QAE@XZ
// partial score=0.93 date=2026-10-02
// cl: /O1 /arch:SSE /MD
// ??0Rva0045EF90Object@@QAE@XZ, retail 0x004103E7 58B. Default ctor of
// Rva0045EF90Object (vtable 0x00839630): base member at +4 set to -1 via
// inlined non-virtual base ctor, vtable store, POD zeroes at +8/+0xC/+0x10
// byte +0x24 and +0x28, floats at +0x14/+0x18/+0x1C/+0x20 set to -1.0f
// (g_00BBB9AC). Same layout as CopyConstructor/Dtor TUs. No calls.
// Caller 0x00411233 in 0x00411205. Evidence: or [eax+4],-1 then vtable
// then xor-zero moves then 4x movss.
class Rva0045EF90Base
{
public:
	Rva0045EF90Base() : m_base((unsigned)-1) {}
protected:
	unsigned m_base;
};

class Rva0045EF90Object : public Rva0045EF90Base
{
public:
	Rva0045EF90Object();
	virtual ~Rva0045EF90Object();
private:
	void *m_first;
	void *m_second;
	unsigned m_handle;
	float m_value14;
	float m_value18;
	float m_value1c;
	float m_value20;
	unsigned char m_value24;
	unsigned char m_pad25[3];
	void *m_last;
};

// ??0Rva0045EF90Object@@QAE@XZ present-unmatched
Rva0045EF90Object::Rva0045EF90Object() : Rva0045EF90Base()
{
	m_first = 0;
	m_second = 0;
	m_handle = 0;
	m_value24 = 0;
	m_last = 0;
	m_value14 = -1.0f;
	m_value18 = -1.0f;
	m_value1c = -1.0f;
	m_value20 = -1.0f;
}
