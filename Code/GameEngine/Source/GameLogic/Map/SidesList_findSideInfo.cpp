// cl: /Ireference/shims/bfme2_ascii /O1 /G7
//
// ?findSideInfo@SidesList@@QAEPAVSidesInfo@@VAsciiString@@PAH@Z @0x0032B0A9 150B
// SidesList::findSideInfo: linear search of m_sides for the entry whose dict
// playerName matches. Donor: BFME1 SidesList.cpp findSideInfo (ZH identical).
// BFME2 differences from retail bytes: playerName key comes from the NameKey
// cache at 0x00DBDE24 via rowed get 0x00148F5E, dict at SidesInfo+0x04
// (SidesList+0x44, 0x60 stride, count at +0x3C), compare via rowed
// StringBase<char>::compare 0x000069D6 with bool materialization, temps via
// rowed releaseBuffer 0x00036410. /G7 for imul scaling of the return pointer.
// Private AsciiString/StringBase (not the shared header): the header's
// non-throw compare emits two extra EH state stores (mov byte ptr [ebp-4],1/0)
// around the compare call; declaring compare throw() drops them to match
// retail 150B. Layout and row names unchanged.

template <typename T> class StringBase
{
	friend class AsciiString;

public:
	int compare(const StringBase &s) const throw();

private:
	void releaseBuffer();

	void *m_data;
};

class AsciiString
{
public:
	~AsciiString() { ((StringBase<char> *)this)->releaseBuffer(); }
	int compare(const AsciiString &s) const throw()
	{
		return ((const StringBase<char> *)this)->compare(*(const StringBase<char> *)&s);
	}

private:
	char *m_text;
};

inline bool operator==(const AsciiString &a, const AsciiString &b) throw() { return a.compare(b) == 0; }

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class Rva00148F5ECache
{
public:
	NameKeyType get();

private:
	NameKeyType m_key;
	const char *m_name;
};

extern Rva00148F5ECache g_00DBDE24;

class Dict
{
public:
	AsciiString getAsciiString(int key, bool *exists = 0) const;

private:
	void *m_data;
};

class SidesInfo
{
public:
	Dict *getDict() { return &m_dict; }

private:
	void *m_pBuildList;
	Dict m_dict;
	unsigned char m_pad[0x60 - 8];
};

class SidesList
{
public:
	SidesInfo *findSideInfo(AsciiString name, int *index);

private:
	unsigned char m_pad[0x3C];
	int m_numSides;
	SidesInfo m_sides[20];
};

SidesInfo *SidesList::findSideInfo(AsciiString name, int *index)
{
	for (int i = 0; i < m_numSides; i++) {
		if (m_sides[i].getDict()->getAsciiString(g_00DBDE24.get()) == name) {
			if (index)
				*index = i;
			return &m_sides[i];
		}
	}
	return 0;
}
