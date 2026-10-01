// ?rva002DC681@Rva002DC267@@QBE_NXZ
// partial score=0.93 date=2026-09-30
// ?rva002DC681@Rva002DC267@@QBE_NXZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /EHsc
// ?rva002DC267@Rva002DC267@@QBE?AVUnicodeString@@XZ @0x002DC267 (118B):
// Unicode save-directory builder. Ascii user-data path from GlobalData
// rva002360DE at 0x002360DE widens through UnicodeString ctor at 0x006CB6D0
// then concats wide L"Save\\" at 0x00C03F88 via StringBase concat at
// 0x00005692 and returns into the hidden pointer via wide copy at 0x00037050.
// Callers pass a stack temp and read the string out (0x002DC681 disk-space
// check via GetDiskFreeSpaceExW and 0x002DC7C1 startsWithNoCase and 0x002DC74A
// getFilePath helper plus 8 more unblocked). Neighbour pins place this in
// GameState save code (realMapPath at 0x002DC833). Honest-address name:
// owner unproven so class Rva002DC267. Donor shape is GameState
// getSaveDirectory in BFME1 GameState.cpp and BFME2 GameState.cpp.

typedef int Int;
typedef unsigned short WideChar;

#define NULL 0

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	friend class Rva002DC267;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	void concat(const T *text);
	void concat(const StringBase<T> &other);
	bool startsWithNoCase(const StringBase<T> &other) const;
	const T *find(T c) const;
	const T *reverseFind(T c) const;
	bool isEmpty() const;
	void set(const StringBase<T> &other);
protected:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	__forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	__forceinline AsciiString(const char *text) : StringBase<char>(text) {}
	__forceinline ~AsciiString() { releaseBuffer(); }
};

class UnicodeString : public StringBase<WideChar>
{
public:
	UnicodeString() {}
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	UnicodeString(const AsciiString &src);
	__forceinline ~UnicodeString() { releaseBuffer(); }
	const WideChar *str() const { return m_data ? &m_data->data[0] : L""; }
};

class GlobalData
{
public:
	AsciiString rva002360DE() const;
};

#define TheGlobalData (*(GlobalData **)0x00DFE758)

class Rva002DC267
{
public:
	UnicodeString rva002DC267() const;
	bool rva002DC681() const;
};

extern const WideChar g_00C03F94[];
extern "C" __declspec(dllimport) Int __stdcall GetDiskFreeSpaceExW(
	const WideChar *dir, void *freeAvail, void *totalBytes, void *totalFree);

class Rva002DC7C1
{
public:
	bool rva002DC7C1(const UnicodeString &path) const;
};

class Rva002DC74A
{
public:
	UnicodeString rva002DC74A(const UnicodeString &leaf) const;
};

class BFME2FileSystemFacade
{
public:
	bool doesWideFileExist(const WideChar *path);
};

#define TheFileSystem (*(BFME2FileSystemFacade **)0x00E06A48)

class Rva002DCCFB
{
public:
	bool rva002DCCFB(UnicodeString filename);
};

UnicodeString Rva002DC267::rva002DC267() const
{
	UnicodeString wtmp(TheGlobalData->rva002360DE());
	wtmp.concat(L"Save\\");
	return wtmp;
}

// Unicode isInSaveDirectory: save dir from 0x002DC267 then
// StringBase startsWithNoCase at 0x000362B0. Callers pass a stack temp.
bool Rva002DC7C1::rva002DC7C1(const UnicodeString &path) const
{
	return ((const StringBase<WideChar> *)&path)->startsWithNoCase((const StringBase<WideChar> &)((const Rva002DC267 *)this)->rva002DC267());
}

// Unicode getFilePathInSaveDirectory: if leaf holds a backslash return it,
// else save dir from 0x002DC267 plus leaf via StringBase concat at 0x00006A2A.
UnicodeString Rva002DC74A::rva002DC74A(const UnicodeString &leaf) const
{
	if (((const StringBase<WideChar> *)&leaf)->find((WideChar)L'\\'))
		return leaf;
	UnicodeString tmp(((const Rva002DC267 *)this)->rva002DC267());
	((StringBase<WideChar> *)&tmp)->concat(*(const StringBase<WideChar> *)&leaf);
	return tmp;
}

// Unicode doesSaveGameExist: full path from 0x002DC74A then wide existence
// via facade doesWideFileExist pin at 0x0060068A. Filename by value.
bool Rva002DCCFB::rva002DCCFB(UnicodeString filename)
{
	UnicodeString filepath(((const Rva002DC74A *)this)->rva002DC74A((const UnicodeString &)filename));
	bool result = TheFileSystem->doesWideFileExist(filepath.str());
	return result;
}

// ?Rva002DC802BaseName@@YG?AVAsciiString@@ABV1@@Z @0x002DC802 49B:
// Ascii basename: reverseFind '\\' at 0x00035930 then AsciiString from
// substring at 0x00037BA0 or copy at 0x000365F0 into hidden return buffer.
// Caller 0x00356E8E forwards map path at ebp+8 with temp at ebp-0x14 then
// translates via UnicodeString at 0x006CB6A0. Honest-address free function.
// Ret 8 proves __stdcall.
AsciiString __stdcall Rva002DC802BaseName(const AsciiString &in)
{
	const char *slash = ((const StringBase<char> &)in).reverseFind('\\');
	if (slash)
		return AsciiString(slash + 1);
	return in;
}

// ?rva002DC681@Rva002DC267@@QBE_NXZ @0x002DC681 201B: save-dir disk-space check.
// Calls rva002DC267 with same this (Rva002DC267 proven), StringBase wide ctor 0x00037E30
// from g_00C03F94, isEmpty 0x00035740, set 0x00037150, release 0x00036E70, then
// GetDiskFreeSpaceExW IAT with TheNullChr fallback 0x007BB5C4; needs 0xF00000 free.
// Callers 0x002409F5 0x00435246 unclaimed.
bool Rva002DC267::rva002DC681() const
{
	StringBase<WideChar> path(g_00C03F94);
	bool has;
	{
		UnicodeString dir(rva002DC267());
		has = !((const StringBase<WideChar> *)&dir)->isEmpty();
	}
	if (has) {
		UnicodeString dir(rva002DC267());
		((StringBase<WideChar> *)&path)->set(*(const StringBase<WideChar> *)&dir);
	}
	unsigned long long freeBytes = 0;
	bool ok;
	if (GetDiskFreeSpaceExW(*(void **)&path ? (const WideChar *)(*(char **)&path + 8) : L"", &freeBytes, 0, 0) == 0)
		ok = true;
	else if (freeBytes >= 0xF00000)
		ok = true;
	else
		ok = false;
	((StringBase<WideChar> *)&path)->releaseBuffer();
	return ok;
}
