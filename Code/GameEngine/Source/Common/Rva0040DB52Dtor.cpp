// cl: /O1 /DNDEBUG /MD /GX
// ??1Rva0040DB52@@UAE@XZ @0x0040DB52 81B. ModuleData-like dtor: vtable 0x008394CC
// then frees at +0x20 and +0x14 via rowed _free at 0x00030830, then restores
// Snapshot base vtable 0x007BB554. Evidence: two test-je-free sequences with EH
// states 1 then 0, deleting-dtor caller at 0x0040E09B (28B), unwind funclets at
// 0x0077152F and 0x00771867, neighbours in Common. TU-local Snapshot with inline
// BBB554-restoring dtor, novtable derived to suppress own store, empty body.
// Layout: two heap members at +0x14/+0x20 freed via inlined AsciiString-like
// dtors (test plus free), other members trivial.
extern "C" void __cdecl free(void *ptr);
struct AsciiStringLike
{
	char *m_str;
	~AsciiStringLike()
	{
		if (m_str)
			free(m_str);
	}
};
class Xfer;
class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer);
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};
extern const void *const g_00BBB554[];
inline Snapshot::~Snapshot()
{
	*(const void **)this = g_00BBB554;
}
class Rva0040DB52 : public Snapshot
{
public:
	virtual ~Rva0040DB52();
private:
	char m_pad04[0x10];
	AsciiStringLike m_str14;
	char m_pad18[0x08];
	AsciiStringLike m_str20;
};
Rva0040DB52::~Rva0040DB52()
{
}
