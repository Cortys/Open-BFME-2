// cl: /O1 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
//
// Retail 0x001EF5BD 164B:
// ??$_M_find@VAsciiString@@@?$_Rb_tree@VAsciiString@@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@U?$_Select1st@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@@3@UAsciiComparator@@V?$allocator@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@@3@@_STL@@ABEPAU?$_Rb_tree_node@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@@1@ABVAsciiString@@@Z
// _Rb_tree _M_find worker for map<AsciiString Open2Rec4F1120 AsciiComparator>.
// Key at node+0x10 left at +8 right at +0xC header pointer at this+0
// comparator at this+8. By-value comparator needs EH (two StringBase copies
// per call destroyed by the callee at 0x0038233A). Caller 0x001EF90E copies
// Open2Rec4F1120 from node+0x14 proving the mapped type.
//
#include <map>

template <typename T>
struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T>
class StringBase
{
	friend class AsciiString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

struct AsciiComparator
{
	bool operator()(AsciiString s1, AsciiString s2) const;
};

class Open2Rec4F1120
{
public:
	AsciiString m_at00;
	AsciiString m_at04;
	AsciiString m_at08;
	int m_at0c;
	int m_at10;
	int m_at14;
	int m_at18;
	int m_at1c;
	int m_at20;
	int m_at24;
	int m_at28;
	int m_at2c;
	int m_at30;
};

typedef _STL::map<AsciiString, Open2Rec4F1120, AsciiComparator> Rec4F1120Map;

// ?RecMapFind@@YA?AU?$_Rb_tree_iterator@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@U?$_Const_traits@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@@2@@_STL@@ABV?$map@VAsciiString@@VOpen2Rec4F1120@@UAsciiComparator@@V?$allocator@U?$pair@$$CBVAsciiString@@VOpen2Rec4F1120@@@_STL@@@_STL@@@2@ABVAsciiString@@@Z present-unmatched
Rec4F1120Map::const_iterator RecMapFind(const Rec4F1120Map &m, const AsciiString &key)
{
	return m.find(key);
}
