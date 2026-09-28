// cl: /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?rva001431B0@Rva001431B0@@QAEXVAsciiString@@@Z, RVA 0x001431B0, 131B.
// Push a by-value AsciiString into the member vector at +0x13c.
// Evidence: fast path inlines copy as test esi/mov [eax] esi/add [esi+4] 1,
// slow path calls rowed vector<AsciiString>::_M_insert_overflow at 0x00143070,
// trailing param release is dec-to-zero plus slot-0 call; callers at 0x0007DCD4
// 0x000D7C00 0x00101386 0x001016C2 pass this from [ebp+8] with pre-inc copy;
// layout proven by lea getter 0x00142C40 pop 0x00142DF0 and vector dtor 0x00142E30.

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

namespace _STL
{

template <>
inline void _Construct<AsciiString, AsciiString>(AsciiString *dest, const AsciiString &src)
{
	if (dest)
		new (dest) AsciiString(src);
}

}

class Rva001431B0
{
	char m_pad[0x13c];
	_STL::vector<AsciiString, _STL::allocator<AsciiString> > m_vec;

public:
	void rva001431B0(AsciiString str);
};

void Rva001431B0::rva001431B0(AsciiString str)
{
	m_vec.push_back(str);
}
