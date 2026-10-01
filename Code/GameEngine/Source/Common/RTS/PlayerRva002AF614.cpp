// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002AF614@Player@@QAEXPAX@Z @0x002AF614 (17B): Player ecx pass-through to iterateObjects with callback at 0x002AF5EF and forwarded userdata.
// Evidence: push [esp+4] then push 0x6af5ef then call pinned Player::iterateObjects @0x002AB08B then ret 4; 17B matches void Player method with void* arg; sibling PlayerRva002AE475 @0x002AE475 same 17B shape with callback 0x002AE435.
class Object;
typedef void (__cdecl *ObjectIterateFunc)(Object *obj, void *userData);

class Player
{
public:
	void iterateObjects(ObjectIterateFunc func, void *userData) const;
	void rva002AF614(void *userData);
};

void __cdecl Rva002AF5EF(Object *obj, void *userData);

void Player::rva002AF614(void *userData)
{
	iterateObjects(Rva002AF5EF, userData);
}
