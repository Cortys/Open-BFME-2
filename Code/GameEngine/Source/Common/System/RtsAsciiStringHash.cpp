// cl: /O1 /EHsc
//
// ??R?$hash@VAsciiString@@@rts@@QBEIABVAsciiString@@@Z, retail 0x0002BF8C, 89 bytes.
// rts::hash<AsciiString> case-insensitive hash: copy the key through the pinned
// StringBase<char> copy at 0x000365F0, lower it through the rowed toLower at
// 0x00036A70, then forward the chars-or-empty to the rowed __stl_hash_string
// at 0x0002BA61. The chars live 8 past the StringBase header and a null header
// falls back to the retail empty literal at VA 0x00BBAC1C. The teardown inlines
// releaseBuffer at 0x00036410. Donor is Zero Hour STLTypedefs.h hash<AsciiString>
// which hashes str() while BFME2 lowercases first for case-insensitive maps.
// Identity is pinned and proven by the _M_bkt_num_key caller at 0x0002C677 plus
// the _M_bkt_num callers at 0x0002C659 0x0002C86A 0x0002C9F8. Model and flags follow
// Code/GameEngineDevice/Source/W3DDevice/GameClient/Create_Render_Obj.cpp which
// shows the same lower plus chars-or-empty shape under /O1 /EHsc.

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
public:
	void toLower();
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)0x00BBAC1C; }
protected:
	BfmeStringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

namespace _STL
{
	unsigned int __stl_hash_string(const char *s);
}

namespace rts
{
	template <class T> struct hash
	{
	};
	template <> struct hash<AsciiString>
	{
		unsigned int operator()(const AsciiString &key) const;
	};
}

unsigned int rts::hash<AsciiString>::operator()(const AsciiString &key) const
{
	AsciiString tmp(key);
	tmp.toLower();
	const char *s = tmp.str();
	return _STL::__stl_hash_string(s);
}
