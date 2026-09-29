// ?Rva00545239Get@@YAMPAX@Z
// partial score=0.95 date=2026-09-29
// ?Rva00545239Get@@YAMPAX@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /arch:SSE /G7
// ?Rva00545239Get@@YAMPAX@Z @0x00545239 84B. Free float getter: base rate from
// TheAI 0x009FF0F8 (+0x18 +0xC8) scaled by global 0x007FC15C when the object's
// current weapon (rowed getCurrentWeapon 0x0028AEBD twice with slot 0) has its
// +4 ByteField set (rowed get 0x002C9400). Evidence: two getCurrentWeapon calls
// with test-je, ByteField test-je, mulss plus fld return, callers 0x0054544F
// 0x005459D6, neighbours ModuleNameGetters3 and ConstIntGetters4.
class Weapon;
enum WeaponSlotType
{
	WEAPONSLOT_PRIMARY = 0
};
class Object
{
public:
	const Weapon *getCurrentWeapon(WeaponSlotType *slot) const;
};
class Rva002C9400ByteField
{
public:
	unsigned char get() const;
};
struct AIInner
{
	char m_pad[0xC8];
	float m_rate;
};
struct AIMid
{
	char m_pad[0x18];
	AIInner *m_ptr;
};
extern AIMid *TheAI;
extern float g_007FC15C;
// ?Rva00545239Get@@YAMPAX@Z present-unmatched
float __cdecl Rva00545239Get(void *objPtr)
{
	Object *obj = (Object *)objPtr;
	float val = TheAI->m_ptr->m_rate;
	const Weapon *w = obj->getCurrentWeapon((WeaponSlotType *)0);
	if (w) {
		const Weapon *w2 = obj->getCurrentWeapon((WeaponSlotType *)0);
		Rva002C9400ByteField *field = *(Rva002C9400ByteField **)((char *)w2 + 4);
		if (field->get())
			val = g_007FC15C * val;
	}
	return val;
}
