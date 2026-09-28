// ?rva00271008@Rva00270FEE@@QAEMXZ
// partial score=0.93 date=2026-09-28
// ?rva00271008@Rva00270FEE@@QAEMXZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva00271008@Rva00270FEE@@QAEMXZ 0x00271008 55B
// Rva00270FEE float helper: base float from rva00270FEE()+0x14 plus first entry
// at +0x14C slot 0xC8 when present. Same-class callee keeps this in ECX.
// Evidence: calls rowed ?rva00270FEE@Rva00270FEE@@QAEPADXZ on same this;
// same +0x14C walk as Drawable broadcasts; caller 0x00239220 uses float
// return with fadd; shape-lever ECX-survival needs same-class receiver.
class BfmeFloatModule
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
	virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
	virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
	virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
	virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
	virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
	virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
	virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
	virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
	virtual void slot48(); virtual void slot49();
	virtual float getC8();
};

class Rva00270FEE
{
public:
	char *rva00270FEE();
	float rva00271008();
};

// ?rva00271008@Rva00270FEE@@QAEMXZ present-unmatched
float Rva00270FEE::rva00271008()
{
	char *p = rva00270FEE();
	float base = *(float *)(p + 0x14);
	BfmeFloatModule **arr = *reinterpret_cast<BfmeFloatModule ***>((unsigned char *)this + 0x14c);
	if (arr && *arr)
		return base + (*arr)->getC8();
	return base;
}
