// cl: /O1 /GX /DNDEBUG /MD
//
// ??1BezierProjectileBehavior@@UAE@XZ, retail 0x0045BF6E, 101 bytes.
// Target evidence: vtable 0x00C41E04 slot 0 = deleting dtor 0x0045C959 which
// calls here; donor BFME1 BezierProjectileBehaviorDestructorThunk proves the
// vector at +0x44 plus list member at +0x7C; ctor 0x0045C850 installs vtables
// 0x00C41E04/+0x0C 0x00C53570/+0x10 0x00C41DF8/+0x20 0x00C41DE0/+0x24 0x00C41DC8
// with vector base at +0x44 and init at +0x7C. Teardown restores 5 vptrs then
// pool-free of +0x7C via pinned 0x00268902 then inline null-checked free of
// +0x44 via rowed _free 0x00030830 then base ??1Rva0024A797 at 0x0024A797.
// Layout follows SiegeDockingBehaviorDtor MI base with 3 vptrs to 0x20 plus
// two secondary bases at +0x20/+0x24. Manual 3-pointer view earns retail free;
// explicit PoolMember call earns the lea plus call.

class Thing;
class ModuleData;

class BehaviorModuleBase
{
	virtual void unused();
	int a;
	int b;
};

class BehaviorModuleOther
{
	virtual void unused();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};

class UpdateModuleInterface
{
public:
	virtual void update() = 0;
};

class Rva0024A797 : public BehaviorModule, public UpdateModuleInterface
{
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;

public:
	virtual ~Rva0024A797();
};

class BezierProjectileBehaviorSecondaryBase0
{
public:
	virtual void slot();
};

class BezierProjectileBehaviorSecondaryBase1
{
public:
	virtual void slot();
};

extern "C" void free(void *ptr);

struct BezierProjectileVec
{
	~BezierProjectileVec()
	{
		if (m_start != 0)
			free(m_start);
	}

	void *m_start;
	void *m_finish;
	void *m_end;
};

class Rva0029FB3BMember
{
public:
	void init(void *context);
	void reset();

private:
	void *m_head;
};

class PoolMember
{
public:
	void Rva00268902() throw();
};

class BezierProjectileBehavior : public Rva0024A797, public BezierProjectileBehaviorSecondaryBase0, public BezierProjectileBehaviorSecondaryBase1
{
public:
	virtual ~BezierProjectileBehavior();

private:
	unsigned char m_pad28[0x44 - 0x28];
	BezierProjectileVec m_vector; // +0x44
	unsigned char m_pad50[0x7C - 0x50];
	Rva0029FB3BMember m_7C; // +0x7C
	unsigned char m_pad80[0x88 - 0x80];
};

BezierProjectileBehavior::~BezierProjectileBehavior()
{
	((PoolMember *)&m_7C)->Rva00268902();
}
