// cl: /O1 /MD /EHsc /G7
// ?rva005ED708@Rva005ED445@@QAEXHH@Z, retail 0x005ED708, 98 bytes.
// NumRegions cached setter via Rva005ED310Get and rva005ED516; imul needs /G7.
// Evidence: calls 0x005ED310 0x005ED516 0x00036E70; string APT NumRegions via callee; base +0x44 slot size 0x14 field +0xC; caller 0x005ED849.
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class UnicodeString;
public:
	StringBase() : m_data(0) {}
	int compare(const StringBase<T> &other) const;
	void set(const StringBase<T> &other);
private:
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
};

class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString() {}
	~UnicodeString() {}
};

UnicodeString Rva005ED310Get(int val);

struct Rva005ED445Slot
{
	char m_pad[0x0C];
	int m_num;
	char m_pad2[0x14 - 0x10];
};

class Rva005ED445
{
public:
	void rva005ED516(int suffixIndex, const char *suffix, const UnicodeString &text);
	void rva005ED708(int index, int num);
private:
	char m_pad44[0x44];
	Rva005ED445Slot *m_slots;
};

void Rva005ED445::rva005ED708(int index, int num)
{
	Rva005ED445Slot *base = m_slots;
	Rva005ED445Slot *slot = base + index;
	if (num != slot->m_num) {
		rva005ED516(index, "NumRegions", Rva005ED310Get(num));
		slot->m_num = num;
	}
}
