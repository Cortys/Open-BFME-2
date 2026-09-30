// ?rva0037AE4E@RecorderClass@@QAEXXZ
// partial score=0.95 date=2026-09-30
// ?rva0037AE4E@RecorderClass@@QAEXXZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0037AE4E@RecorderClass@@QAEXXZ @0x0037AE4E (148B).
// RecorderClass file header refresh: writes GameLogic +0x40 frame at file
// offset 0xC and current time at 0x10, then restores ftell position.
// Evidence: FILE* at +0x10, TheGameLogic global, IAT time/ftell/fseek/
// fwrite, callers 0x0037B430/0x0037D93B, sibling RecorderIsMultiplayer layout.
typedef int Int;
typedef long Long;
typedef unsigned int UnsignedInt;

struct FILE;

extern "C" __declspec(dllimport) Long __cdecl time(Long *timer);
extern "C" __declspec(dllimport) Long __cdecl ftell(FILE *stream);
extern "C" __declspec(dllimport) Int __cdecl fseek(FILE *stream, Long offset, Int origin);
extern "C" __declspec(dllimport) UnsignedInt __cdecl fwrite(const void *buffer, UnsignedInt size, UnsignedInt count, FILE *stream);

class GameLogic
{
public:
	char m_pad[0x40];
	Int m_unk40;
};

extern GameLogic *TheGameLogic;

class RecorderClass
{
public:
	void rva0037AE4E();
private:
	char m_pad[0x10];
	FILE *m_file;
};

// ?rva0037AE4E@RecorderClass@@QAEXXZ present-unmatched
void RecorderClass::rva0037AE4E()
{
	if (m_file == 0)
		return;
	Int frame;
	Long curTime;
	time(&curTime);
	frame = TheGameLogic->m_unk40;
	Int pos = ftell(m_file);
	if (fseek(m_file, 12, 0) == 0)
		fwrite(&frame, 4, 1, m_file);
	if (fseek(m_file, 16, 0) == 0)
		fwrite(&curTime, 4, 1, m_file);
	fseek(m_file, pos, 0);
}
