// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002ABAB3@Player@@QAEXXZ @0x002ABAB3 (13B): Player ecx pass-through to iterateObjects with callback at 0x002AA27A and NULL userdata.
// Evidence: push 0 then push 0x6aa27a then call pinned Player::iterateObjects @0x002AB08B; 13B push-push-call-ret matches void Player method with no args; sibling PlayerRva002ABAA6 @0x002ABAA6 same shape with callback 0x002AA264.
class Object;
typedef void (__cdecl *ObjectIterateFunc)(Object *obj, void *userData);

class Player
{
public:
	void iterateObjects(ObjectIterateFunc func, void *userData) const;
	void rva002ABAB3();
};

void __cdecl Rva002AA27A(Object *obj, void *userData);

void Player::rva002ABAB3()
{
	iterateObjects(Rva002AA27A, 0);
}
