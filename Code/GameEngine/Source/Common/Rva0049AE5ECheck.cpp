// cl: /O1 /MD
//
// ?rva0049AE5E@Rva0049AE5E@@QAEXXZ @ 0x0049AE5E 70B
// Checks three ObjectIDs at +0x3E8 +0x3EC +0x3F0 via rowed
// GameLogic::findObjectByID; clears byte at +0x3CA if all three miss.
// Evidence: TheGameLogic extern use; caller 0x0049AED7; unlocks 0x0049AEA4.
enum ObjectID
{
	INVALID_OBJECT_ID = 0
};
class Object;
class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};
extern GameLogic *TheGameLogic;
class Rva0049AE5E
{
public:
	void rva0049AE5E();
private:
	unsigned char m_pad0[0x3CA];
	unsigned char m_flag3CA;
	unsigned char m_pad1[0x3E8 - 0x3CB];
	ObjectID m_id3E8;
	ObjectID m_id3EC;
	ObjectID m_id3F0;
};
void Rva0049AE5E::rva0049AE5E()
{
	GameLogic *logic = TheGameLogic;
	if (logic->findObjectByID(m_id3E8) != 0)
		return;
	if (logic->findObjectByID(m_id3EC) != 0)
		return;
	if (logic->findObjectByID(m_id3F0) != 0)
		return;
	m_flag3CA = 0;
}
