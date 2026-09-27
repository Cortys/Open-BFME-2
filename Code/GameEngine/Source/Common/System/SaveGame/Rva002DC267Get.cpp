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
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	void concat(const T *text);
	void concat(const StringBase<T> &other);
	bool startsWithNoCase(const StringBase<T> &other) const;
	const T *find(T c) const;
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
	__forceinline ~AsciiString() { releaseBuffer(); }
};

class UnicodeString : public StringBase<WideChar>
{
public:
	UnicodeString() {}
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	UnicodeString(const AsciiString &src);
	__forceinline ~UnicodeString() { releaseBuffer(); }
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
};

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
