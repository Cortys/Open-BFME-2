// cl: /O1 /G7
// stlport
// ?updateUpgradeModules@Object@@QAEXXZ, retail 0x00292EEA, 194 bytes.
// Object upgrade-module recheck: player mask at +0x13c ORed with self at
// +0x284 and castle at +0x284 (via CastleMember +0x14 and TheGameLogic at
// 0x00DFE78C), then per-module getUpgrade at slot 0x28, isAlreadyUpgraded
// at slot 0, attemptUpgrade at slot 4, postUpgradeCheck at slot 0x18.
// Evidence: BFME1 donor ObjectUpdateUpgradeModulesBody.cpp (same castle and
// post-check shape, masks 24B at +0x8c/+0x224 and behaviors at +0x1f0);
// BFME2 callers 0x0029306D 0x00293513 0x00294F73 0x00298A97 0x00298BF2 and
// Player::onUpgradeCompleted plus DozerAIUpdate updateUpgradeModules call
// prove Object owner; vtable slot layout from Bridge/Spawn precedents.

enum ObjectID
{
	INVALID_ID = 0
};

struct BfmeFixedStorage128
{
	BfmeFixedStorage128(const BfmeFixedStorage128&);
	unsigned char bytes[128];
};

namespace _STL
{
template<unsigned N> struct _Base_bitset;
template<> struct _Base_bitset<32>
{
	void _M_do_or(const _Base_bitset<32>&);
	unsigned long _M_w[32];
};
}

class Player
{
public:
	char m_pad00[0x13c];
	BfmeFixedStorage128 m_mask13c;
};

class Object;
class Module;

class CastleBehavior
{
public:
	static Module *rva000395708(Object *obj);
};

class GameLogic
{
public:
	class Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

class UpgradeModuleInterface
{
public:
	virtual bool isAlreadyUpgraded() const = 0;
	virtual bool attemptUpgrade(const BfmeFixedStorage128 &mask) = 0;
	virtual void slot02() = 0;
	virtual void slot03() = 0;
	virtual void slot04() = 0;
	virtual void slot05() = 0;
	virtual void postUpgradeCheck() = 0;
};

class BehaviorModuleInterface
{
public:
	virtual void slot00() = 0;
	virtual void slot01() = 0;
	virtual void slot02() = 0;
	virtual void slot03() = 0;
	virtual void slot04() = 0;
	virtual void slot05() = 0;
	virtual void slot06() = 0;
	virtual void slot07() = 0;
	virtual void slot08() = 0;
	virtual void slot09() = 0;
	virtual UpgradeModuleInterface *getUpgrade() = 0;
};

class BfmeObjectModule
{
public:
	virtual void slot0() = 0;

private:
	unsigned int m_data[2];
};

class BehaviorModule : public BfmeObjectModule, public BehaviorModuleInterface
{
};

class Module
{
public:
	char m_pad00[0x14];
	ObjectID m_castleID;
};

class Object
{
public:
	Player *getControllingPlayer() const;
	void updateUpgradeModules();

private:
	char m_pad00[0x244];
	BehaviorModule **m_modules;
	char m_pad248[0x284 - 0x248];
	_STL::_Base_bitset<32> m_mask284;
};

void Object::updateUpgradeModules()
{
	Player *player = getControllingPlayer();
	if (!player)
		return;
	Object *castle = 0;
	const BfmeFixedStorage128 *playerMask = &player->m_mask13c;
	Module *member = CastleBehavior::rva000395708(this);
	if (member != 0)
		castle = TheGameLogic->findObjectByID(member->m_castleID);
	for (BehaviorModule **m = m_modules; *m; ++m)
	{
		BehaviorModuleInterface *beh = (BehaviorModuleInterface *)((char *)*m + 0x0c);
		UpgradeModuleInterface *up = beh->getUpgrade();
		if (!up)
			continue;
		if (!up->isAlreadyUpgraded())
		{
			BfmeFixedStorage128 tmp(*playerMask);
			((_STL::_Base_bitset<32> *)&tmp)->_M_do_or(m_mask284);
			if (castle)
				((_STL::_Base_bitset<32> *)&tmp)->_M_do_or(castle->m_mask284);
			up->attemptUpgrade(tmp);
		}
		up->postUpgradeCheck();
	}
}
