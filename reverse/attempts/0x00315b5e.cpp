// ?parseDefaultFont@@YA_NPAVGameFont@@PAVFile@@PAD@Z
// partial score=0.5 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?parseDefaultFont@@YA_NPAVGameFont@@PAVFile@@PAD@Z, retail 0x00315B5E,
// 69 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameClient/GUI/GameWindowManagerScript.cpp,
// parseDefaultFont): scan the font name into a local AsciiString, read the
// remainder of the definition up to the semicolon, and return TRUE. The
// font-parsing body is stubbed out in the reference (@todo), so the identity
// rests on the retail bytes: a 69-byte body whose scanString virtual dispatch,
// readUntilSemicolon call (0x00314DE8) and releaseBuffer epilogue match the
// reference source shape exactly.
// BFME2 facts (all retail-measured):
// - File's own vtable has scanString at slot 9 (offset 0x24); the sweep shim's
//   MemoryPoolObject adds one virtual ahead of File's, so this TU carries the
//   same TU-local 17-slot File view used by the parseLayoutBlock TU.
// - readUntilSemicolon is the file-static at 0x00314DE8 (defined here verbatim
//   so MSVC keeps its register convention; its own bytes are not compared).
// - AsciiString::releaseBuffer is the out-of-line StringBase<char>::releaseBuffer
//   row at 0x00036410.
// - __EH_prolog is pinned at 0x00629188.
// - Identity evidence: the unique call at 0x00315B63 sets up the EH frame and
//   the call at 0x00315B82 targets the already-rowed readUntilSemicolon; the
//   0x24 scanString slot is the retail File vtable slot. Signature carried from
//   the reference source.

typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE true
#endif

#ifndef FALSE
#define FALSE false
#endif

class GameFont;
class File;

enum
{
	WIN_BUFFER_LENGTH = 2048
};

class File
{
public:
	enum seekMode { START, CURRENT, END };

	virtual ~File();								// slot 0
	virtual bool open(const char *filename, int access = 0);	// slot 1
	virtual void close(void);						// slot 2
	virtual int read(void *buffer, int bytes);			// slot 3
	virtual int write(const void *buffer, int bytes);		// slot 4
	virtual int seek(int pos, seekMode mode);			// slot 5
	virtual void nextLine(char *buf, int bufSize);			// slot 6
	virtual bool scanInt(int &newInt);				// slot 7
	virtual bool scanReal(float &newReal);				// slot 8
	virtual bool scanString(void *newString);			// slot 9
	virtual bool print(const char *format, ...);			// slot 10
	virtual int size(void);						// slot 11
	virtual int position(void);					// slot 12
	virtual char *readEntireAndClose(void);				// slot 13
	virtual File *convertToRAMFile(void);				// slot 14
	virtual void lock(void);					// slot 15
	virtual void unlock(void);					// slot 16
};

template <typename T>
class StringBase
{
	friend class AsciiString;

private:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};

	Header *m_data;

	void releaseBuffer();

public:
	StringBase() : m_data(0) {}
	int compare(const T *str) const;

	const T *str() const
	{
		return m_data ? m_data->data : "";
	}
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() : StringBase<char>() {}
	~AsciiString() { releaseBuffer(); }

	const char *str() const
	{
		return StringBase<char>::str();
	}

	int compare(const char *s) const
	{
		return StringBase<char>::compare(s);
	}
};

extern "C" __declspec(dllimport) int __cdecl isspace(int c);

// readUntilSemicolon =========================================================
// noinline: with a single caller MSVC folds this 90-byte static into
// parseDefaultFont, but retail keeps the out-of-line call at 0x00314DE8.
static __declspec(noinline) void readUntilSemicolon(File *fp, char *buffer, int maxBufLen)
{
	int i = 0;
	Bool start = TRUE;

	while (i < maxBufLen)
	{
		// get next character
		fp->read(buffer + i, 1);

		// make all whitespace characters spaces
		if (isspace(buffer[i]))
		{
			if (start == FALSE)
				buffer[i++] = ' ';
		}
		else
		{
			start = FALSE;

			if (buffer[i] == ';')
			{
				// found end of data chunk
				buffer[i] = '\000';
				return;
			}

			i++;
		}
	}

	buffer[maxBufLen - 1] = '\000';
}

// ?parseDefaultFont@@YA_NPAVGameFont@@PAVFile@@PAD@Z
Bool parseDefaultFont(GameFont *font, File *inFile, char *buffer)
{
	// eat '='
	AsciiString str;
	inFile->scanString(&str);

	// Read the rest of the color definition
	readUntilSemicolon(inFile, buffer, WIN_BUFFER_LENGTH);

	/// @todo font parsing for window files work needed here
	//	*font = GetFont( buffer );
	//	if( *font == NULL )
	//		return FALSE;

	return TRUE;
}

static const void *s_parseDefaultFontAnchor = (const void *)parseDefaultFont;
