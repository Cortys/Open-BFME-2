// cl: /O1 /DNDEBUG /MD /EHsc
// ??1RenderObjectDrawModuleInfo@FXParticleSystem@@UAE@XZ @0x003A9A8B 75B
// Dtor releasing StringBase<char> at +0x10 +0x20 +0x30 via rowed releaseBuffer
// 0x00036410 plus Snapshot base BBB554. Evidence: EH_prolog with 2/1/0 states
// plus three releaseBuffer calls plus BBB554 store, layout from
// RenderObjectDrawModuleInfoCopyCtorThunk, callers include template dtor.
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
class __declspec(novtable) RenderObjectDrawModuleInfo : public Snapshot
{
public:
	virtual ~RenderObjectDrawModuleInfo();
private:
	char m_pad04[0x10 - 4];
	StringBase<char> m_10;
	char m_pad14[0x20 - 0x14];
	StringBase<char> m_20;
	char m_pad24[0x30 - 0x24];
	StringBase<char> m_30;
	char m_pad34[0x40 - 0x34];
};
}

FXParticleSystem::RenderObjectDrawModuleInfo::~RenderObjectDrawModuleInfo()
{
}
