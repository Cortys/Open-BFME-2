// ?Rva000787BAOpen@@YAPAVFile@@PBD@Z
// partial score=0.93 date=2026-09-29
// ?Rva000787BAOpen@@YAPAVFile@@PBD@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva000787BAOpen@@YAPAVFile@@PBD@Z, retail 0x000787BA, 117 bytes.
// Free __cdecl File opener: returns 0 if either global is null, else builds a
// GameFileClass stack object from the filename and, when its exists byte at
// +8 is set, opens FileSystem::openFile over its path at +9 with 0x41/0.
// Evidence: EH_prolog with funclet; ctor row ??0GameFileClass@@QAE@PBD@Z;
// byte check plus lea for openFile row ?openFile@FileSystem@@QAEPAVFile@@PBDHH@Z;
// dtor row ??1GameFileClass@@UAE@XZ; globals at VA 0x009E1FAC and 0x00A06A48
// (second is TheFileSystem); ret with caller cleanup.

class File
{
};

class FileSystem
{
public:
	File *openFile(char const *filename, int a, int b);
};

extern FileSystem *TheFileSystem;

class W3DFileSystem
{
};

extern W3DFileSystem *TheW3DFileSystem;

class GameFileClass
{
public:
	GameFileClass(char const *filename);
	virtual ~GameFileClass();
	void *m_theFile;
	bool m_fileExists;
	char m_filePath[260];
	char m_filename[260];
};

// ?Rva000787BAOpen@@YAPAVFile@@PBD@Z present-unmatched
File *__cdecl Rva000787BAOpen(char const *filename)
{
	File *ret = 0;
	if (TheW3DFileSystem == 0)
		return 0;
	if (TheFileSystem == 0)
		return 0;
	GameFileClass file(filename);
	if (file.m_fileExists)
		ret = TheFileSystem->openFile(file.m_filePath, 0x41, 0);
	return ret;
}
