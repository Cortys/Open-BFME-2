// cl: /O1 /EHsc

// ??0Rva00222719Temp@@QAE@ABVUnicodeString@@@Z, retail 0x00222719, 49 bytes.
// EH temp copy via wide set: m_data null then set from source. Stack temp for Apt text setters 0x225299 plus 0x225301 plus 24 other callers. No donor; honest address class.
template <typename T>
class StringBase
{
public:
	void set(const StringBase &src);
	~StringBase();
protected:
	void *m_data;
};

class UnicodeString : public StringBase<unsigned short>
{
public:
	UnicodeString() { m_data = 0; }
	UnicodeString(const UnicodeString &src);
	~UnicodeString() {}
};

class Rva00222719Temp
{
public:
	Rva00222719Temp(const UnicodeString &src);
private:
	UnicodeString m_str;
};

Rva00222719Temp::Rva00222719Temp(const UnicodeString &src) : m_str()
{
	m_str.set(src);
}
