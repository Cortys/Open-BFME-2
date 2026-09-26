// cl: /O1 /DNDEBUG /MD /EHsc

// Target boundary 0x0025C378/25 (Ghidra). Retail stores the argument at
// Display+0x0C, then conditionally dispatches through TheMouse's vtable slot
// +0x58. The BFME1 Display::setHeight donor identifies that operation as
// updating m_height and calling Mouse::setMouseLimits; the field and call
// shape above are independently visible in BFME2 retail.

class Mouse
{
public:
#define V(n) virtual void pad##n();
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10)
	V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21)
#undef V
	virtual void setMouseLimits();
};

#define TheMouse (*(Mouse **)0x00DFDCA0)

class Display
{
public:
	virtual void setHeight(unsigned int height);

private:
	unsigned char m_pad4[8];
	unsigned int m_height;
};

void Display::setHeight(unsigned int height)
{
	m_height = height;
	Mouse *mouse = TheMouse;
	if (mouse)
		mouse->setMouseLimits();
}
