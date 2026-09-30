// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /GX
// ??1Rva003FD789@@UAE@XZ @0x003FD789 69B
// ModuleData dtor: AsciiStrings at +0x0C and +0x1C via releaseBuffer then Snapshot base vtable 0x00BBB554.
// Same recipe as PillageModuleDataDtor (TU-local Snapshot with extern BBB554, empty derived body).
// Unblocks ??_G at 0x003FD82D.
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

#include "ascii_string.h"

class Rva003FD789 : public Snapshot
{
public:
	virtual ~Rva003FD789();
private:
	char m_pad04[8];
	AsciiString m_0c;
	char m_pad10[12];
	AsciiString m_1c;
};

Rva003FD789::~Rva003FD789()
{
}
