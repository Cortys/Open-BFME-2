// cl: /O1 /arch:SSE /MD /DNDEBUG /DWIN32 /D_WINDOWS
// ?clear@Rva003ECA69Element@@QAEXXZ @0x003ECA69 (24B): zeroes the 0x44-byte
// array element (float at +0 plus 0x40 bytes at +4) via SSE float zero plus
// CRT memset through thunk 0x6291AE. Called by the 20-element array clear
// at 0x003ECB13 (loops 0x14 times calling this) and by 0x00596277. No donor
// name claimed so the name keeps the address token with an honest Rva owner.
#pragma function(memset)

extern "C" void *memset(void *dst, int value, unsigned int size);

class Rva003ECA69Element
{
public:
	void clear();

private:
	float m_0;
	char m_rest[0x40];
};

void Rva003ECA69Element::clear()
{
	m_0 = 0.0f;
	memset(m_rest, 0, 0x40);
}

class Rva003ECA4BElement
{
public:
	Rva003ECA4BElement();

private:
	float m_0;
	char m_rest[0x40];
};

Rva003ECA4BElement::Rva003ECA4BElement()
{
	m_0 = 0.0f;
	memset(m_rest, 0, 0x40);
}
