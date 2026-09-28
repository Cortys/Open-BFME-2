// cl: /O1 /Oy- /MD /EHsc
// ?rva0022C4DF@Rva0022C4DF@@QBE?AVUnicodeString@@XZ @0x0022C4DF (27B):
// RVO UnicodeString getter copying the member at +0x04 through the rowed
// wide StringBase copy ctor at 0x37050 into the hidden return pointer.
// Same 27B shape as ?rva0023E928@Rva0023E928@@QBE?AVUnicodeString@@XZ
// at 0x0023E928 in Code/GameEngine/Source/GameNetwork/Rva0023E928Getter.cpp
// with identical flags. Callers pass a stack temp and read the string out
// of it at 0x00046929 0x0023F7B2 0x002B846E 0x00383979 0x004FE2F4 0x004FEF3E
// 0x005A0E75 0x005A2CBB 0x005A2D24. Unlock lane unblocks 7 functions.
// Owner unproven so honest-address class Rva0022C4DF. No new pins.
typedef unsigned short WideChar;

template <typename T>
class StringBase
{
	friend class UnicodeString;
public:
	StringBase() : m_data(0) {}
private:
	StringBase(const StringBase<T> &that);
	void *m_data;
};

class UnicodeString : public StringBase<WideChar>
{
public:
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	~UnicodeString();
};

class Rva0022C4DF
{
public:
	unsigned char m_pad[0x04];
	UnicodeString m_str;
	UnicodeString rva0022C4DF() const;
};

UnicodeString Rva0022C4DF::rva0022C4DF() const
{
	return m_str;
}
