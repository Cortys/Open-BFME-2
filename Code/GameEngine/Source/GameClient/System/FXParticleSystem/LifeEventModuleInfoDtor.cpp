// cl: /O1 /DNDEBUG /MD /EHsc
// ??1LifeEventModuleInfo@FXParticleSystem@@UAE@XZ @0x003A9F8A 48B
// Dtor releasing StringBase<char> at +4 via rowed releaseBuffer 0x00036410
// plus Snapshot base BBB554. Evidence: EH_prolog with handler 0x00781D33
// plus single releaseBuffer call plus BBB554 store, layout from
// LifeEventModuleInfoCopyCtorThunk, ghidra ~LifeEventModuleInfo.
template <typename T> class StringBase {
public: ~StringBase() { releaseBuffer(); }
private: void releaseBuffer(); void *m_data; };

class Snapshot {
public: virtual ~Snapshot();
};

inline Snapshot::~Snapshot()
{
	*(const void **)this = (const void *)0x00BBB554;
}

namespace FXParticleSystem
{
class __declspec(novtable) LifeEventModuleInfo : public Snapshot
{
public:
	virtual ~LifeEventModuleInfo();
private:
	StringBase<char> m_name;
	int m_values[3];
	int m_eventType;
};
}

FXParticleSystem::LifeEventModuleInfo::~LifeEventModuleInfo()
{
}
