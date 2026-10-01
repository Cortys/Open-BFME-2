// Two guarded accessors through a sub-object.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv812.cpp); trimmed to the two T1
// bodies the sweep places.

// The matched getter at 0x005C4ACD returns the opaque +0x2C pointer that these
// callers view as BfmeSubEHA; both symbols use a no-argument pointer-return ABI.
#pragma comment(linker, "/alternatename:?bfmeGetEHA@BfmeObjEHA@@QAEPAUBfmeSubEHA@@XZ=?winGetUserData@GameWindow@@QAEPAXXZ")

struct BfmeSubEHA
{
	char m_bfmeFlag;
	unsigned char m_bfmePad[3];
	void *m_bfmeP;
	void *m_bfmeQ;
};

class BfmeObjEHA
{
public:
	BfmeSubEHA *bfmeGetEHA();
};

void *bfmeGoEHAa(BfmeObjEHA *o)
{
	if (o)
	{
		BfmeSubEHA *s = o->bfmeGetEHA();
		if (s && s->m_bfmeFlag)
			return s->m_bfmeP;
	}
	return 0;
}

void *bfmeGoEHAb(BfmeObjEHA *o)
{
	if (o)
	{
		BfmeSubEHA *s = o->bfmeGetEHA();
		if (s && s->m_bfmeFlag)
			return s->m_bfmeQ;
	}
	return 0;
}
