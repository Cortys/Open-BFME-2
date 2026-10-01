// ?rva002907A1@Object@@QAE_NXZ
// partial score=0.9 date=2026-10-01
// ?rva002907A1@Object@@QAE_NXZ
// partial score=0.90 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?rva002907A1@Object@@QAE_NXZ @ 0x002907A1 107B: chain from 0x0028F528 popcount;
// Object disabled-mask gate over +0x1C8 BitFlags<11>::any via rowed 0x0023C58B
// then bit8 and popcount==1 via rowed 0x0028F528 then !isKindOf(0x81) then
// template+0x113&0x20 template+0x108&4 then !testStatus(0x3B). Unblocks 59.
// Prev/next Object Rva TUs same flags. 40+ callers prove Object owner.
typedef bool Bool;

enum KindOfType
{
	KINDOF_DUMMY = 0
};

enum ObjectStatusTypes
{
	STATUS_DUMMY = 0
};

template <int N>
class BitFlags
{
public:
	bool any() const;
};

class Rva0028F528
{
public:
	int rva0028F528();
};

struct ThingTemplate907A1
{
	unsigned char m_pad[0x120];
};

class Object
{
public:
	bool rva002907A1();
	Bool isKindOf(KindOfType kind) const;
	Bool testStatus(ObjectStatusTypes bit) const;
	bool rva0028F518();
private:
	unsigned char m_pad00[4];
	ThingTemplate907A1 *m_template;
	unsigned char m_pad08[0x1C8 - 0x08];
	BitFlags<11> m_disabled;
};

// ?rva002907A1@Object@@QAE_NXZ present-unmatched
bool Object::rva002907A1()
{
	if ((m_template->m_pad[0x108] & 4) != 0)
		return false;
	BitFlags<11> *mask = &m_disabled;
	if (mask->any())
	{
		unsigned w = *(const unsigned *)mask >> 8;
		if ((w & 1u) == 0)
			return false;
		if (((Rva0028F528 *)mask)->rva0028F528() != 1)
			return false;
	}
	if (isKindOf((KindOfType)0x81))
		return false;
	if ((m_template->m_pad[0x113] & 0x20) != 0)
	{
		if (testStatus((ObjectStatusTypes)0x3B))
			return false;
	}
	return true;
}
