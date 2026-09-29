// cl: /O1 /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
// ?rva002E52FC@OptionPreferences@@QAEXH@Z 0x002E52FC 127B
// Evidence: map at +4 via rowed operator[] 0x002031FB and erase 0x002E4ED1;
// key StaticGameLOD at 0x007E38B8 with LOD table at 0x00DB95F4; callers none;
// prev next OptionPreferences setters.
#include <map>

typedef bool Bool;
typedef int Int;

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
private:
	StringBase() {}
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	void set(const T *text);
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() { m_data = 0; }
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	AsciiString &operator=(const AsciiString &other);
	void set(const char *text) { StringBase<char>::set(text); }
};

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL
{
template <> struct less<AsciiString>
{
	bool operator()(const AsciiString &left, const AsciiString &right) const
	{
		return left < right;
	}
};
}

typedef _STL::map<AsciiString, AsciiString> AsciiPreferenceMap;

namespace _STL
{
template <> AsciiString &map<AsciiString, AsciiString, less<AsciiString>, allocator<pair<const AsciiString, AsciiString> > >::operator[](const AsciiString &key);
template <> unsigned int _Rb_tree<AsciiString, pair<const AsciiString, AsciiString>, _Select1st<pair<const AsciiString, AsciiString> >, less<AsciiString>, allocator<pair<const AsciiString, AsciiString> > >::erase(const AsciiString &key);
}

const char *BfmeLODLevelNames[7];

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	void rva002E52FC(int index);
};

void OptionPreferences::rva002E52FC(int index)
{
	if (index != -1) {
		AsciiString key("StaticGameLOD");
		(*this)[key].set(BfmeLODLevelNames[index]);
	} else {
		AsciiString key("StaticGameLOD");
		erase(key);
	}
}
