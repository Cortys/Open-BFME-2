// cl: /O1 /MD /EHsc /DNDEBUG
//
// ??1UpgradeSoundSelectorClientBehaviorModuleData@@UAE@XZ, retail 0x004CBAEA, 48 bytes.
// Target evidence: the audited scalar deleting dtor 0x004CBACE calls this
// body (registration UpgradeSoundSelectorClientBehavior -> factory
// 0x00252C64). It destroys the record vector at +0x08 (rowed
// vector<BfmeRecordOwner900> dtor 0x004CB996), then the inlined trivial
// Snapshot base stores 0x00BBB554. No derived vptr store (novtable).

class Snapshot
{
public:
	virtual ~Snapshot();
};

inline Snapshot::~Snapshot()
{
	*(const void **)this = reinterpret_cast<const void *>(0x00BBB554);
}

struct BfmeRecordOwner900;

namespace _STL
{
template <class T> class allocator;
template <class T, class A> class vector
{
public:
	~vector();

private:
	T *m_begin;
	T *m_finish;
	T *m_end;
};
}

class __declspec(novtable) UpgradeSoundSelectorClientBehaviorModuleData : public Snapshot
{
public:
	virtual ~UpgradeSoundSelectorClientBehaviorModuleData();

private:
	int m_04;
	_STL::vector<BfmeRecordOwner900, _STL::allocator<BfmeRecordOwner900> > m_records;	// +0x08
};

UpgradeSoundSelectorClientBehaviorModuleData::~UpgradeSoundSelectorClientBehaviorModuleData()
{
}
