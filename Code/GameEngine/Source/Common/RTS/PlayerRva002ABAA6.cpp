// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002ABAA6@Player@@QAEXXZ @0x002ABAA6 (13B): Player ecx pass-through to iterateObjects with callback at 0x002AA264 and NULL userdata.
// Evidence: push 0 then push 0x6aa264 then call pinned Player::iterateObjects @0x002AB08B; 13B push-push-call-ret matches void Player method with no args; neighbours PlayerRva002ABD1D and PlayerRva002ABCF0 use same ecx pass-through recipe.
class Object;
typedef void (__cdecl *ObjectIterateFunc)(Object *obj, void *userData);

class Player
{
public:
	void iterateObjects(ObjectIterateFunc func, void *userData) const;
	void rva002ABAA6();
};

void __cdecl Rva002AA264(Object *obj, void *userData);

void Player::rva002ABAA6()
{
	iterateObjects(Rva002AA264, 0);
}
