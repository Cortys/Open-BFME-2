// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva004BA1C8@@QAE@XZ, retail 0x004BA1C8 8B: add ecx,4 then jmp to vector<AsciiString> dtor at 0x0002CC70.
// Evidence: callees all rowed; callers at 0x004BA2D0 and 0x004BA34A plus jmp at 0x004BA31F; shares 0x2C layout
// with copy ctor at 0x004BA1D0 and assign at 0x004BA291 which both use vector<AsciiString> at +4.
#include <vector>

template <typename T> class StringBase {
	void *m_data;
	void releaseBuffer();
protected:
	~StringBase() { releaseBuffer(); }
};

class AsciiString : private StringBase<char> {
public:
	~AsciiString() {}
};

class Rva004BA1C8 {
public:
	~Rva004BA1C8();
private:
	int m_00;
	_STL::vector<AsciiString> m_04;
	unsigned int m_10;
	unsigned int m_14;
	unsigned int m_18;
	unsigned int m_1C;
	unsigned int m_20;
	unsigned int m_24;
	unsigned int m_28;
};

Rva004BA1C8::~Rva004BA1C8()
{
}
