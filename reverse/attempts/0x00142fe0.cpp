// ??1Rva001431B0@@QAE@XZ
// partial score=0.55 date=2026-10-03
// cl: /O2 /G7 /arch:SSE /MD /EHsc /Oy /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ??1Rva001431B0@@UAE@XZ @0x00142FE0 141B: complete destructor of the class
// whose member vector<Rva00142DF0String> sits at +0x13C (Rva001431B0Pop.cpp).
// Target evidence: the body drains a 32-entry handle array at +0x30 from the
// end, decrementing the count at +0xB0 and skipping +0xB4 slots, releasing
// each handle's refcount at +4 and calling its virtual slot 0; then it
// destroys the +0x13C vector through 0x00142E30. Layout and element type are
// the near file's; the class/member names stay address-derived.

#include <vector>

class Rva00142DF0String
{
	struct Rva00142DF0StringData
	{
		virtual void _M_slot_00();
		int m_refCount;
	};

	Rva00142DF0StringData *m_data;

public:
	Rva00142DF0String();
	~Rva00142DF0String()
	{
		Rva00142DF0StringData *data = m_data;
		if (data && --data->m_refCount == 0)
			data->_M_slot_00();
	}
};

class Rva001431B0
{
public:
	~Rva001431B0();

private:
	char m_pad00[0x30];
	Rva00142DF0String m_slots[0x20];	// +0x30 .. +0xAF
	int m_count;						// +0xB0
	int m_extra;						// +0xB4
	char m_padB8[0x13C - 0xB8];
	_STL::vector<Rva00142DF0String, _STL::allocator<Rva00142DF0String> > m_vec;	// +0x13C
};

Rva001431B0::~Rva001431B0()
{
	while (m_count != 0) {
		if (m_extra != 0) {
			--m_extra;
		} else {
			--m_count;
			m_slots[m_count].~Rva00142DF0String();
		}
	}
}
