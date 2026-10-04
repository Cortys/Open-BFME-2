// cl: /O1 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// The DamageNugget "DamageScalar" field (BFME2 FieldParse table at 0x00864264,
// owner Rva005088CE: "DamageScalar" -> 0x00508862, offset 0x168) and the
// vector growth path it reaches.
//
// Target evidence:
//   0x00508862  parser: builds an 8-byte entry on the stack (filter ctor
//               0x003623E5 at +0, dtor 0x00360D26), stores
//               INI::dup_002EE10(getNextToken(0)) at +4, parses the filter
//               through 0x00361CA5(ini, instance, &entry.filter, 0), then
//               push_back(entry) on the store.
//   0x0050882B  that push_back: _Construct 0x0060C9D9 (two-dword copy) or
//               _M_insert_overflow 0x005085B6.
//   0x005085B6  the overflow path: raw (bytes, hint) allocator 0x00523D6C,
//               copy 0x004C3121, fill 0x00507958, out-of-line _M_clear
//               0x00507C0F whose destroy loop reaches 0x00495C43 -> 0x00360D26.
// Inferred: the entry is { filter, Real scalar }, which is what the field name
// and the percent scanner say; the filter keeps the opaque Rva003623E5Filter
// name its other pins use, and the owner keeps the address-derived name of
// its buildFieldParse (0x005088CE).
#include <vector>

class INI
{
public:
	const char *getNextToken(const char *seps = 0);
	float dup_002EE10(const char *token);
};

class Rva003623E5Filter
{
public:
	Rva003623E5Filter();
	~Rva003623E5Filter();

private:
	int m_index;
};

struct Rva005088CEDamageScalar
{
	Rva003623E5Filter filter;
	float scalar;
};

void Rva00361CA5Parse(INI *ini, void *instance, void *store, const void *userData);

typedef _STL::vector<Rva005088CEDamageScalar, _STL::allocator<Rva005088CEDamageScalar> > Rva005088CEDamageScalarVec;

// Base of the nugget: dtor 0x00507823 (Rva00507823Dtor.cpp), vtable 0x00864010.
class Rva00507823
{
public:
	virtual ~Rva00507823();
private:
	unsigned char m_pad04[0x128 - 4];
};

// The nugget (vtable 0x00864040; slot 0 is the deleting dtor 0x00508668).
// Its FieldParse table at 0x00864180 begins at +0x128 ("Damage"); only the
// two members its destructor 0x00508684 tears down are modelled.
class __declspec(novtable) Rva005088CE : public Rva00507823
{
public:
	virtual ~Rva005088CE();
	void *Rva00508668Release(unsigned int flags);
	static void parseDamageScalar(INI *ini, void *instance, void *store, const void *userData);
private:
	unsigned char m_pad128[0x168 - 0x128];
	Rva005088CEDamageScalarVec m_damageScalars;	// +0x168 "DamageScalar"
	unsigned char m_pad174[0x19C - 0x174];
	Rva003623E5Filter m_filter19C;			// +0x19C
};

// ??1Rva005088CE@@UAE@XZ
Rva005088CE::~Rva005088CE()
{
}

// Vtable slot 0 at 0x00864048 is 0x00508668: the destructor above, then
// scalar operator delete 0x0002FD60 on flag bit zero. novtable (the dtor
// stores no vptr) keeps cl from emitting ??_G itself, so the release is
// spelled out under an address-derived name, as Rva0050A7ADDtor.cpp does.
void *Rva005088CE::Rva00508668Release(unsigned int flags)
{
	this->Rva005088CE::~Rva005088CE();
	if (flags & 1) ::operator delete(this);
	return this;
}

// ?parseDamageScalar@Rva005088CE@@SAXPAVINI@@PAX1PBX@Z
void Rva005088CE::parseDamageScalar(INI *ini, void *instance, void *store, const void * /*userData*/)
{
	Rva005088CEDamageScalar entry;
	entry.scalar = ini->dup_002EE10(ini->getNextToken());
	Rva00361CA5Parse(ini, instance, &entry.filter, 0);
	((Rva005088CEDamageScalarVec *)store)->push_back(entry);
}
