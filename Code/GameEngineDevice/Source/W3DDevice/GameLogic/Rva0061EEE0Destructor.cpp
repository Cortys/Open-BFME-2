// cl: /DNDEBUG /MD /EHsc

// BFME2's base destructor call goes to the rowed 14-byte body at 0x001B4E74
// (??1GameEngineDeletingBase@@UAE@XZ, folded with ??1Snapshot/??1Subsystem-
// Interface pins), so the base is declared under that established name: zero
// new pins for the base call. The member's identity is unrecovered (opaque
// address-derived name on the BFME2 target).
//
// The class is not W3DRenderObjectSnapshot: that class's vftable is
// 0x00BC59F4 (slot 2 returns the string "W3DRenderObjectSnapshot"; see
// W3DGhostObjectScene.cpp). This one's 15-slot vftable 0x00C7C5C0 is
// installed by the ctor at 0x0061EEE0 (subsystem base ctor 0x001B4E63, then
// news a 0x200-byte member into +0x0C) and by this dtor. BFME1 carries the
// same body as the address-derived Rva009EB960 singleton destructor, whose
// member is the asset-registry object; named here after the BFME2 ctor.
// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/Snapshot.h
class GameEngineDeletingBase
{
public:
	virtual void anchor();
	virtual ~GameEngineDeletingBase();
};

class Gen_dtor_00625040
{
public:
	~Gen_dtor_00625040();
};

class Rva0061EEE0 : public GameEngineDeletingBase
{
public:
	virtual ~Rva0061EEE0();

private:
	void *m_debugName;
	// BFME2 reads the member at +0x0C (BFME1: +0x08): one unidentified dword
	// sits between the debug name and the render object.
	void *m_bfme08;
	Gen_dtor_00625040 *m_renderObject;
};

Rva0061EEE0::~Rva0061EEE0()
{
	delete m_renderObject;
}

// Placeholder virtuals in this unit's vftables: in retail, every vftable that holds
// each one has the same function in that slot (vftable addresses from matched vptr
// stores). Bind them to the rows at those functions.
#pragma comment(linker, "/alternatename:?anchor@GameEngineDeletingBase@@UAEXXZ=??_GRva0061EEE0@@UAEPAXI@Z")
