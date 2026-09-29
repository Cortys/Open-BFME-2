// cl: /O1 /DNDEBUG /MD /EHsc /G7
//
// ?rva00272393@Drawable@@QAEXH@Z, retail 0x00272393, 45 bytes.
// Draw-module walk at this+0x14C via slot 0xA8, forwarding int arg to
// slot 0x64 targets. Evidence: same +0x14C/slot-0xA8 walk as landed
// rva002723ED/rva002724FD/rva00272414 in neighbour
// Drawable_rva002724FD.cpp (// cl: /O1 /DNDEBUG /MD /EHsc /Oy- /G7);
// this body is frameless (push [esp+8], ret 4) so /Oy- dropped.
// Unblocks 0x0048EB53 0x003941FD 0x00497FF3; callers pass one int
// (0x0039430F 0x0048EC0E 0x00498199 plus 6).

class BfmeObjectDrawForRva272393
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
	virtual void slot60() = 0;
	virtual void rva00272393Target(int arg) = 0;
};

class BfmeDrawModuleForRva272393
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
	virtual BfmeObjectDrawForRva272393 *getObjectDrawInterface() = 0;
};

class Drawable
{
public:
	void rva00272393(int arg);
};

void Drawable::rva00272393(int arg)
{
	BfmeDrawModuleForRva272393 **modules =
		*reinterpret_cast<BfmeDrawModuleForRva272393 ***>((unsigned char *)this + 0x14C);
	for (BfmeDrawModuleForRva272393 **dm = modules; *dm; ++dm) {
		BfmeObjectDrawForRva272393 *di = (*dm)->getObjectDrawInterface();
		if (di)
			di->rva00272393Target(arg);
	}
}
