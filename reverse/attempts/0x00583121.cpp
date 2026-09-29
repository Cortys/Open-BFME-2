// ?rva00583121@Rva00583121@@QAEXHHVUnicodeString@@@Z
// partial score=0.9 date=2026-09-29
// ?rva00583121@Rva00583121@@QAEXHHVUnicodeString@@@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva00583121@Rva00583121@@QAEXHHVUnicodeString@@@Z @0x00583121 225B
// File-transfer status updater: validates index 0..7, reads the id at
// +0x5C, formats "FileTransfer::Status%d", sets the APT text, then sprintfs
// the id and the second arg for a SetBarTo invoke with owner 13.
// Evidence: callers 0x0044C77E 0x0044C7DC 0x00583487 ret 0xC thiscall;
// AsciiString::format row 0x00038150; sprintf IAT msvcr71.dll; invoke pin
// 0x00222A8B; bfmeSetText pin 0x00225301; releaseBuffer 0x00036410 ansi
// 0x00036E70 wide.
typedef unsigned short wchar_t;

template <typename T> class StringBase;
class UnicodeString;
class AsciiString;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;

	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();

public:
	StringBase() { m_data = 0; }

private:
	struct Header
	{
		int refCount;
		unsigned short length;
		unsigned short capacity;
		T text[1];
	};
	Header *m_data;
};

class UnicodeString : public StringBase<wchar_t>
{
public:
	UnicodeString(const UnicodeString &other) : StringBase<wchar_t>(other) {}
	~UnicodeString() {}
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	void __cdecl format(const char *fmt, ...);
};

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};

class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern BfmeAptWindowManager *g_Va009FE4CC;

extern "C" __declspec(dllimport) int sprintf(char *buffer, const char *format, ...);

class Rva00583121
{
public:
	void rva00583121(int index, int x, UnicodeString text);
private:
	char m_pad[0x5C];
	int m_ids[8];
};

void Rva00583121::rva00583121(int index, int x, UnicodeString text)
{
	int id;
	if (index >= 0) {
		if (index < 8) {
			id = m_ids[index];
			if (id != -1) {
			AsciiString key;
			key.format("FileTransfer::Status%d", id);
			g_Va009FE4CC->bfmeSetText(key, text, false);
			char buf1[64];
			char buf2[64];
			sprintf(buf1, "%d", id);
			sprintf(buf2, "%d", x);
			((Rva00222A8BTarget *)g_Va009FE4CC)->invoke((void *)13, "SetBarTo", 2, buf1, buf2, 0, 0, 0);
			}
		}
	}
}
