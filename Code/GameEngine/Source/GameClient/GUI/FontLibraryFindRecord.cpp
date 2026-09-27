// cl: /O1 /EHsc /MD /arch:SSE /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ?rva002186A6@FontLibrary@@QAEPAXPBVAsciiString@@M@Z, retail 0x002186A6, 69 bytes.
// FontLibrary record lookup called by pinned getFont at 0x002189E1.
// BFME1 donor (reference/open-bfme-1/Code/GameEngine/Source/GameClient/GUI/FontLibraryBFMERetail_getFont.cpp:
// bfmeFindRecord): AsciiString table find, int sizeKey from float, int-map find,
// default-record fallback, second-pointer return. BFME2 deltas (all retail-measured):
// table map lives at this+0x14, size-table records at table+0x0C with default at +0x08,
// float-to-int via cvttss2si (/arch:SSE). True member types are
// map<AsciiString,BfmeFontSizeTable*> and map<int,UnsignedInt>; they are spelled
// map<AsciiString,AsciiString> and map<int,int> so the emitted _M_find calls name
// the rowed workers at 0x001F8437 and 0x00388F63 (identical tree mechanics;
// LocomotorStoreFindTemplate precedent), the stored pointer recast from second.

#include <map>

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
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other);
	~AsciiString() {}
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

struct BfmeFontSizeTable
{
	unsigned char m_pad[8];
	void *m_defaultRecord;
	_STL::map<int, int> m_records;
};

class FontLibrary
{
public:
	void *rva002186A6(const AsciiString *name, float size);
private:
	char m_pad[0x14];
	_STL::map<AsciiString, AsciiString> m_tables;
};

void *FontLibrary::rva002186A6(const AsciiString *name, float size)
{
	_STL::map<AsciiString, AsciiString>::iterator table = m_tables.find(*name);
	if (table == m_tables.end())
		return 0;
	int sizeKey = (int)size;
	BfmeFontSizeTable *sizes = *(BfmeFontSizeTable **)&table->second;
	_STL::map<int, int>::iterator record = sizes->m_records.find(sizeKey);
	if (record == sizes->m_records.end())
		return sizes->m_defaultRecord;
	return (void *)record->second;
}
