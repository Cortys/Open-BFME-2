// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva004110DCGet@@YAPAXPBD@Z, retail 0x004110DC (54B).
// Chain over rowed ?rva00056F61@Rva00056F61@@QAEPAXPBVAsciiString@@@Z with a
// temp AsciiString from char*: lookup in global table at 0x00E02FF8,
// teardown via rowed releaseBuffer 0x00036410, returning node+8 or null.
// Same shape as rowed-adjacent 0x00411112 plus temp; caller at 0x004120C0.

class AsciiString;

template <typename T>
class StringBase
{
private:
	friend class AsciiString;
	friend void *__cdecl Rva004110DCGet(const char *key);
	void releaseBuffer();
	StringBase(const T *text);
	StringBase(const StringBase<T> &that);
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString
{
public:
	AsciiString(const char *text)
	{
		((StringBase<char> *)this)->StringBase<char>::StringBase(text);
	}
	~AsciiString() {}
private:
	char *m_text;
};

class Rva00056F61
{
public:
	void *rva00056F61(const AsciiString *key);
};

void * __cdecl Rva004110DCGet(const char *key)
{
	AsciiString tmp(key);
	void *node = ((Rva00056F61 *)0x00E02FF8)->rva00056F61(&tmp);
	((StringBase<char> *)&tmp)->releaseBuffer();
	if (node != 0)
		return *(void **)((char *)node + 8);
	return 0;
}
