// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva002ABD1D@Player@@QAEHHH@Z, RVA 0x002ABD1D, size 43: Player count of KindOf up to limit via iterateObjects.
// Evidence: ecx pass-through to Player::iterateObjects pinned at 0x002AB08B; callback at 0x002AA531 tests Object::isKindOf and counts to limit; caller 0x003C2FEF passes kind in edi and limit 0x7ffffffe with Player in ecx and sums result.

class Object;
typedef void (__cdecl *ObjectIterateFunc)(Object *obj, void *userData);

class Player
{
public:
	void iterateObjects(ObjectIterateFunc func, void *userData) const;
	int rva002ABD1D(int kind, int limit);
};

void __cdecl Rva002AA531(Object *obj, void *userData);

struct Rva002ABD1DContext
{
	int m_kind;
	int m_count;
	int m_limit;
};

int Player::rva002ABD1D(int kind, int limit)
{
	Rva002ABD1DContext ctx;
	ctx.m_kind = kind;
	ctx.m_count = 0;
	ctx.m_limit = limit;
	iterateObjects(Rva002AA531, &ctx);
	return ctx.m_count;
}
