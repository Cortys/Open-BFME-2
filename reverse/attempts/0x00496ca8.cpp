// ?rva00496CA8@Rva00496CA8@@QAEXH@Z
// partial score=0.91 date=2026-10-02
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /Ireference/shims/moduledata
// ?rva00496CA8@Rva00496CA8@@QAEXH@Z, retail 0x00496CA8 155B. Unlock: outer vector
// at this+4+0x24/0x28 of SubA* (key at +0 vs arg, inner vector at +4/+8 of SubB*);
// each SubB holds AsciiString at +0 and byte at +4, forwarded as
// drawable->rva002724FD(ascii, byte, 1, 0.0f, 0.0f) via Thing+8 getDrawable.
// Evidence: callees getDrawable 0x005508E2 rva002724FD 0x002724FD, caller 0x00420DC6.

class AsciiString;

class Drawable
{
public:
	void rva002724FD(const AsciiString &a, int b, int c, float d, float e);
};

class Thing
{
public:
	Drawable *getDrawable() const;
};

struct Rva00496CA8SubB
{
	char m_ascii00[4];
	unsigned char m_byte04;
};

struct Rva00496CA8SubA
{
	int m_key00;
	Rva00496CA8SubB **m_begin04;
	Rva00496CA8SubB **m_end08;
};

struct Rva00496CA8Holder04
{
	char m_pad00[0x24];
	Rva00496CA8SubA **m_begin24;
	Rva00496CA8SubA **m_end28;
};

class Rva00496CA8
{
public:
	void rva00496CA8(int key);
private:
	char m_pad00[4];
	Rva00496CA8Holder04 *m_p04;
	Thing *m_thing08;
};

// ?rva00496CA8@Rva00496CA8@@QAEXH@Z present-unmatched
void Rva00496CA8::rva00496CA8(int key)
{
	Thing *thing = m_thing08;
	if (thing == 0)
		return;
	Drawable *drawable = thing->getDrawable();
	if (drawable == 0)
		return;
	Rva00496CA8Holder04 *holder = m_p04;
	Rva00496CA8SubA **begin = holder->m_begin24;
	Rva00496CA8SubA **end = holder->m_end28;
	int outerCount = (int)(end - begin);
	if (outerCount == 0)
		return;
	for (unsigned i = 0; i < (unsigned)outerCount; ++i) {
		Rva00496CA8SubA *sub = begin[i];
		if (sub->m_key00 != key)
			continue;
		Rva00496CA8SubB **ibegin = sub->m_begin04;
		Rva00496CA8SubB **iend = sub->m_end08;
		int innerCount = (int)(iend - ibegin);
		if (innerCount == 0)
			continue;
		for (unsigned j = 0; j < (unsigned)innerCount; ++j) {
			Rva00496CA8SubB *b = ibegin[j];
			drawable->rva002724FD(*(const AsciiString *)b, (int)(unsigned char)b->m_byte04, 1, 0.0f, 0.0f);
		}
	}
}
