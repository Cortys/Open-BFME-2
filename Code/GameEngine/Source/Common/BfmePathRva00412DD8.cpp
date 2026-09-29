// cl: /O1 /DNDEBUG /MD /EHsc

// ?Rva00412DD8Get@@YA?AVAsciiString@@PBD@Z, retail 0x00412DD8 158B.
// Free AsciiString(const char*) normalizer: null uses g_bfmeEmptyF9 at
// 0x00BBAC1C, skips one leading '/', strncpy 0x7fff into 32k stack buffer,
// rewrites '/' to '.', then RVO via StringBase copy 0x365F0 and temp
// teardown via releaseBuffer 0x36410. Caller at 0x0041196E passes hidden
// return plus path; PBD ctor is rowed 0x37BA0.

extern "C" __declspec(dllimport) char *__cdecl strncpy(char *dest, const char *source, unsigned int count);

extern char g_bfmeEmptyF9[];

template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const T *str);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	T *m_data;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const char *s) : StringBase<char>(s) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

AsciiString Rva00412DD8Get(const char *path)
{
	char buf[32768];
	if (path == 0)
		path = g_bfmeEmptyF9;
	if (*path == '/')
		path++;
	strncpy(buf, path, 0x7fff);
	for (char *p = buf; *p != 0; p++) {
		if (*p == '/')
			*p = '.';
	}
	AsciiString tmp(buf);
	return tmp;
}
