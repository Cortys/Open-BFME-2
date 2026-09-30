// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?Rva0059F20BSet@@YAXHABVUnicodeString@@@Z @ 0x0059F20B (85B).
// Free Apt connecting-player name setter: formats local AsciiString with
// "APT:ConnectingPlayer%dName" (id+1) via rowed format 0x00038150, calls
// pin-only bfmeSetText 0x00225301 on global g_009FE4CC with (tmp, unicode,
// false), releases tmp via rowed releaseBuffer 0x00036410. Callers
// 0x0059F275/0x0059F3C2.
//
// ?Rva0059F296Set@@YAXHABVUnicodeString@@@Z @ 0x0059F296 (85B).
// Sibling status setter with "APT:ConnectingPlayer%dStatus". Same rows/pin
// and global. Callers 0x0059F3EA/0x0059FB2D.
class UnicodeString;

class AsciiString
{
public:
	AsciiString()
	{
		m_data = 0;
	}
	void __cdecl format(const char *format, ...);
	~AsciiString()
	{
		releaseBuffer();
	}

private:
	void releaseBuffer();
	void *m_data;
};

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &a, const UnicodeString &u, bool flag);
};

extern BfmeAptWindowManager *g_009FE4CC;

void __cdecl Rva0059F20BSet(int id, const UnicodeString &u)
{
	AsciiString tmp;
	tmp.format("APT:ConnectingPlayer%dName", id + 1);
	g_009FE4CC->bfmeSetText(tmp, u, false);
}

void __cdecl Rva0059F296Set(int id, const UnicodeString &u)
{
	AsciiString tmp;
	tmp.format("APT:ConnectingPlayer%dStatus", id + 1);
	g_009FE4CC->bfmeSetText(tmp, u, false);
}
