// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /DZH_EMIT_POOL_GLUE /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ?rva002AC629@Player@@QAEPAVObject@@XZ @0x002AC629 (74B): Player cached finder via iterateObjects then GameLogic findObjectByID.
// Evidence: Player this from 0x0029FD99 and 0x002AD1FE sharing findNaturalCommandCenter context; caches ObjectID at +0x6f0 from Object+0x74; returns via rowed findObjectByID at 0x00049DC5; callback at 0x002AA45A is masked DIR32; prev 0x002AC60A in PlayerO1Shard.
enum ObjectID
{
	INVALID_OBJECT_ID = 0
};

class Object
{
public:
	char m_pad[0x74];
	ObjectID m_id;
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class Player
{
	char m_pad[0x6f0];
	ObjectID m_cachedID;
public:
	void iterateObjects(void (*func)(Object *, void *), void *userData) const;
	Object *rva002AC629();
};

void doFindRva002AC629(Object *obj, void *userData);

Object *Player::rva002AC629()
{
	if (m_cachedID == INVALID_OBJECT_ID) {
		struct { Player *player; Object *obj; } info;
		info.player = this;
		info.obj = 0;
		iterateObjects(doFindRva002AC629, &info);
		if (info.obj)
			m_cachedID = info.obj->m_id;
	}
	return TheGameLogic->findObjectByID(m_cachedID);
}
