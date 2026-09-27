// cl: /O1 /arch:SSE /MD /DNDEBUG /DWIN32 /D_WINDOWS
// ??0Rva003ECD60Object@@QAE@ABVAsciiString@@E@Z @0x003ECD60 (87B): heap
// object ctor that constructs the 20-element 0x44 array via ??_H with the
// rowed element ctor 0x003ECA4B copies the +0x550 name via the pinned
// StringBase copy 0x000365F0 zeroes four floats at +0x554/+0x558/+0x55C/
// +0x560 zeroes +0x564 via AND-imm and stores the flag byte at +0x568.
// Called from Xfer 0x003ECED5 plus two 0x002C5xxx sites. No donor name.
template <class T> class StringBase
{
public:
	StringBase(const StringBase &other);
};

class AsciiString : public StringBase<char>
{
};

class Rva003ECA4BElement
{
public:
	Rva003ECA4BElement();

private:
	float m_0;
	char m_rest[0x40];
};

class Rva003ECD60Object
{
public:
	Rva003ECD60Object(const StringBase<char> &name, bool flag);

private:
	Rva003ECA4BElement m_elems[20];
	StringBase<char> m_name;
	float m_f554;
	float m_f558;
	float m_f55C;
	float m_f560;
	int m_564;
	bool m_568;
};

Rva003ECD60Object::Rva003ECD60Object(const StringBase<char> &name, bool flag)
	: m_name(name)
{
	float *p = &m_f554;
	p[0] = 0.0f;
	p[1] = 0.0f;
	p[2] = 0.0f;
	m_564 = 0;
	m_568 = flag;
	m_f560 = 0.0f;
}
