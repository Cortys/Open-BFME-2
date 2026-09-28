// cl: /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?rva00142DF0@Rva001431B0@@QAEXXZ, RVA 0x00142DF0, 44B.
// Guarded pop from the member vector<AsciiString> at +0x13c.
// Evidence: empty check mov eax [ecx+0x13c] cmp [ecx+0x140] matches vector
// empty; tail decrements finish and releases AsciiString via refcount at +4
// plus slot-0 call; same class and vector as push 0x001431B0 and dtor 0x00142E30;
// lea getter 0x00142C40 proves +0x13c; callers at 0x0007DDEF 0x000D7CD4 0x00101161.

#include <vector>

class AsciiString
{
	struct AsciiStringData
	{
		virtual void _M_slot_00();
		int m_refCount;
	};

	AsciiStringData *m_data;

public:
	AsciiString(const AsciiString &that)
	{
		m_data = that.m_data;
		if (m_data)
			m_data->m_refCount++;
	}
	~AsciiString()
	{
		AsciiStringData *data = m_data;
		if (data && --data->m_refCount == 0)
			data->_M_slot_00();
	}
};

class Rva001431B0
{
	char m_pad[0x13c];
	_STL::vector<AsciiString, _STL::allocator<AsciiString> > m_vec;

public:
	void rva00142DF0();
};

void Rva001431B0::rva00142DF0()
{
	if (!m_vec.empty())
		m_vec.pop_back();
}
