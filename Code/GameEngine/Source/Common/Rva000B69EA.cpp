// cl: /O1 /EHsc /MD
// ?Rva000B69EAGet@@YA?AVAsciiString@@ABV1@H@Z @0x000B69EA 125B free function returning AsciiString.
// Early return src when mode<0 else local copy plus switch 1/2 concat then copy out.
// Callees rowed 0x000365F0 copy plus 0x00005629 concat plus 0x00036410 release.
// Callers 0x000C2E3A twice prove signature. Prev 0x000B6971 Next 0x000B6A67 same dir.
template <typename T>
class StringBase
{
	friend class AsciiString;
public:
	void concat(const char *s);
private:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
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
	AsciiString() {}
	AsciiString(const AsciiString &that) : m_data(that.m_data) {}
	~AsciiString() { m_data.releaseBuffer(); }
	void concat(const char *s) { m_data.concat(s); }
private:
	StringBase<char> m_data;
};

AsciiString Rva000B69EAGet(const AsciiString &src, int mode)
{
	if (mode < 0)
		return src;
	AsciiString tmp(src);
	switch (mode) {
	case 1:
		tmp.concat("M");
		break;
	case 2:
		tmp.concat("L");
		break;
	}
	return tmp;
}
