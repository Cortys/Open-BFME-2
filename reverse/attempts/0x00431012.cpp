// ?Rva00431012Get@@YAPAVObject@@HPAVRva0035AFE4@@H@Z
// partial score=0.95 date=2026-10-01
// ?Rva00431012Get@@YAPAVObject@@HPAVRva0035AFE4@@H@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva00431012Get@@YAPAVObject@@HPAVRva0035AFE4@@H@Z retail 0x00431012 69B
// Free function: TacticalView pick at slot 9 then relationship-mask row 0x0035B010.
// Evidence: callers at 0x004310FE 0x00431139 0x004313A2; TheTacticalView + ThePlayerList externs in use.
class Object;
class Player;
class PlayerList
{
public:
	char m_pad[0x10];
	Player *m_player;
};
class PickResult
{
public:
	char m_pad[0xfc];
	Object *m_object;
};
class TacticalView
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual PickResult *pick(int x, int y, int z);
};
class Rva0035AFE4
{
public:
	bool rva0035B010(Player *player, Object *obj);
};
extern TacticalView *TheTacticalView;
extern PlayerList *ThePlayerList;
// ?Rva00431012Get@@YAPAVObject@@HPAVRva0035AFE4@@H@Z present-unmatched
Object *Rva00431012Get(int x, Rva0035AFE4 *mask, int z)
{
	Object *ret = 0;
	PickResult *picked = TheTacticalView->pick(x, 0, z);
	if (picked) {
		Object *obj = picked->m_object;
		if (obj)
			ret = obj;
	}
	if (ret) {
		Player *player = ThePlayerList->m_player;
		if (!mask->rva0035B010(player, ret))
			ret = 0;
	}
	return ret;
}
