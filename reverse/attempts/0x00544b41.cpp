// ?rva00544B41@Rva00544B41@@QAEXXZ
// partial score=0.93 date=2026-10-03
// ?rva00544B41@Rva00544B41@@QAEXXZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /MD
// ?rva00544B41@Rva00544B41@@QAEXXZ, retail 0x00544B41, 85 bytes.
// ObjectID refresh via TheGameLogic findObjectByID then controlling-player
// iterateObjects with 0x00544B13 callback updating +0x24 from +0x74.
// Evidence: callers 0x00544BD3 in FUN_00944b96; rowed findObjectByID
// 0x00049DC5 plus getControllingPlayer 0x0028AFA9 plus pinned iterateObjects
// 0x002AB08B; TheGameLogic extern; adjacent callback 0x00544B13.
class Object;
class Player;
class GameLogic;
enum ObjectID {};

extern GameLogic *TheGameLogic;

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

class Object
{
public:
	Player *getControllingPlayer() const;
	unsigned char m_pad[0x74];
	ObjectID m_id74;
};

class Player
{
public:
	typedef void (__cdecl *ObjectIterateFunc)(Object *, void *);
	void iterateObjects(ObjectIterateFunc func, void *userData) const;
};

struct Rva00544B41Info
{
	Object *m_orig;
	Object *m_found;
};

struct Rva00544B41Holder
{
	unsigned char m_pad[0x14];
	Object *m_obj14;
};

int __cdecl Rva00544B13Callback(void *obj, void *userData);

class Rva00544B41
{
public:
	void rva00544B41();
private:
	unsigned char m_pad18[0x18];
	Rva00544B41Holder *m_holder18;
	unsigned char m_pad1C[0x24 - 0x1C];
	ObjectID m_id24;
};

void Rva00544B41::rva00544B41()
{
	ObjectID id = m_id24;
	Object *found = TheGameLogic->findObjectByID(id);
	if (found)
		return;
	Object *orig = m_holder18->m_obj14;
	Player *player = orig->getControllingPlayer();
	Rva00544B41Info info = { orig, 0 };
	if (!player)
		return;
	player->iterateObjects((Player::ObjectIterateFunc)Rva00544B13Callback, &info);
	Object *f = info.m_found;
	if (!f)
		return;
	m_id24 = f->m_id74;
}

