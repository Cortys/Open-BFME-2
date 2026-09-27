// cl: /O1 /DNDEBUG /MD /EHsc /Oy- /G7
//
// ?rva002724FD@Drawable@@QAEXABVAsciiString@@HHMM@Z, retail 0x002724FD, 72 bytes.
// Drawable broadcaster over draw modules at this+0x14C via non-const
// getObjectDrawInterface at DrawModule slot 0xA8, forwarding 5 args to
// ObjectDrawInterface slot 0x88. Evidence: same +0x14C walk as landed
// Drawable_getPristineBonePositions 0x0027274D and siblings 0x002723ED,
// 0x0027248A, 0x0027257B; callers pass AsciiString plus ints plus floats
// (lua 0x00333424/0x003334EA/0x003335AF, vector 0x0045628C, 0x00496CA8).

class AsciiString;

class BfmeObjectDrawForRva2724FD
{
public:
	virtual void slot00() = 0; virtual void slot04() = 0;
	virtual void slot08() = 0; virtual void slot0C() = 0;
	virtual void slot10() = 0; virtual void slot14() = 0;
	virtual void slot18() = 0; virtual void slot1C() = 0;
	virtual void slot20() = 0; virtual void slot24() = 0;
	virtual void slot28() = 0; virtual void slot2C() = 0;
	virtual void slot30() = 0; virtual void slot34() = 0;
	virtual void slot38() = 0; virtual void slot3C() = 0;
	virtual void slot40() = 0; virtual void slot44() = 0;
	virtual void slot48() = 0; virtual void slot4C() = 0;
	virtual void slot50() = 0; virtual void slot54() = 0;
	virtual void slot58() = 0; virtual void slot5C() = 0;
	virtual void slot60() = 0; virtual void slot64() = 0;
	virtual void slot68() = 0; virtual void slot6C() = 0;
	virtual void slot70() = 0; virtual void slot74() = 0;
	virtual void slot78() = 0; virtual void slot7C() = 0;
	virtual void slot80() = 0; virtual void slot84() = 0;
	virtual void rva002724FDTarget(const AsciiString &a, int b, int c, float d, float e) = 0;
};

class BfmeDrawModuleForRva2724FD
{
public:
	virtual void slot00() = 0; virtual void slot04() = 0;
	virtual void slot08() = 0; virtual void slot0C() = 0;
	virtual void slot10() = 0; virtual void slot14() = 0;
	virtual void slot18() = 0; virtual void slot1C() = 0;
	virtual void slot20() = 0; virtual void slot24() = 0;
	virtual void slot28() = 0; virtual void slot2C() = 0;
	virtual void slot30() = 0; virtual void slot34() = 0;
	virtual void slot38() = 0; virtual void slot3C() = 0;
	virtual void slot40() = 0; virtual void slot44() = 0;
	virtual void slot48() = 0; virtual void slot4C() = 0;
	virtual void slot50() = 0; virtual void slot54() = 0;
	virtual void slot58() = 0; virtual void slot5C() = 0;
	virtual void slot60() = 0; virtual void slot64() = 0;
	virtual void slot68() = 0; virtual void slot6C() = 0;
	virtual void slot70() = 0; virtual void slot74() = 0;
	virtual void slot78() = 0; virtual void slot7C() = 0;
	virtual void slot80() = 0; virtual void slot84() = 0;
	virtual void slot88() = 0; virtual void slot8C() = 0;
	virtual void slot90() = 0; virtual void slot94() = 0;
	virtual void slot98() = 0; virtual void slot9C() = 0;
	virtual void slotA0() = 0; virtual void slotA4() = 0;
	virtual BfmeObjectDrawForRva2724FD *getObjectDrawInterface() = 0;
};

class Drawable
{
public:
	void rva002724FD(const AsciiString &a, int b, int c, float d, float e);
};

void Drawable::rva002724FD(const AsciiString &a, int b, int c, float d, float e)
{
	BfmeDrawModuleForRva2724FD **modules =
		*reinterpret_cast<BfmeDrawModuleForRva2724FD ***>((unsigned char *)this + 0x14C);
	for (BfmeDrawModuleForRva2724FD **dm = modules; *dm; ++dm) {
		BfmeObjectDrawForRva2724FD *di = (*dm)->getObjectDrawInterface();
		if (di) {
			di->rva002724FDTarget(a, b, c, d, e);
		}
	}
}
