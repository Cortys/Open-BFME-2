// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva002706A8@Rva002706A8@@QAEXXZ, retail 0x002706A8, 72 bytes. Unlock lane.
// Sets byte at +0x445 to 1, then walks null-terminated Elem* array at
// [ecx+0xFC]+0x244. For each Elem calls virtual at +0xA8 on subobject +0xC,
// then virtual slot 0 on the result with (0x670689, &flag). Callees are
// indirect so gate has no direct refs. Neighbour next is DrawableFade.cpp
// (/O1 /DNDEBUG /MD /arch:SSE) whose flags are copied here.

class Rva002706A8Ret
{
public:
	virtual void slot00(int a, bool *b);
};

class Rva002706A8Mid
{
public:
	virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0C();
	virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C();
	virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C();
	virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3C();
	virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4C();
	virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5C();
	virtual void slot60(); virtual void slot64(); virtual void slot68(); virtual void slot6C();
	virtual void slot70(); virtual void slot74(); virtual void slot78(); virtual void slot7C();
	virtual void slot80(); virtual void slot84(); virtual void slot88(); virtual void slot8C();
	virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9C();
	virtual void slotA0(); virtual void slotA4();
	virtual Rva002706A8Ret *slotA8();
};

struct Rva002706A8Elem
{
	unsigned char m_pad[0xC];
	Rva002706A8Mid m_mid;
};

struct Rva002706A8Holder
{
	unsigned char m_pad[0x244];
	Rva002706A8Elem **m_244;
};

class Rva002706A8
{
public:
	void rva002706A8();
private:
	unsigned char m_pad00[0xFC];
	Rva002706A8Holder *m_fc;
	unsigned char m_pad100[0x445 - 0x100];
	unsigned char m_445;
};

void Rva002706A8::rva002706A8()
{
	Rva002706A8Holder *h = m_fc;
	m_445 = 1;
	bool flag = false;
	Rva002706A8Elem **pp = h->m_244;
	while (*pp)
	{
		Rva002706A8Elem *e = *pp;
		Rva002706A8Ret *r = e->m_mid.slotA8();
		if (r)
			r->slot00(0x670689, &flag);
		++pp;
	}
}
