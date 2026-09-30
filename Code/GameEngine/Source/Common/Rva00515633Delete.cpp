// cl: /O1 /EHsc
// ?Rva00515633Delete@@YAXXZ @ 0x00515633 108B
// Delete save file built from wide literal via GameState helper then DeleteFileW.
// Evidence: StringBase<G> ctor row 0x00037E30 plus releaseBuffer row 0x00036E70 plus rva002DC74A row 0x002DC74A plus TheGameState plus TheNullChr plus DeleteFileW IAT plus caller 0x005158BD plus prev OpaqueSingleInheritanceDtors /O1.
typedef unsigned short WideChar;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
protected:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class UnicodeString : public StringBase<WideChar>
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	UnicodeString(const WideChar *text) : StringBase<WideChar>(text) {}
	~UnicodeString() { releaseBuffer(); }
	const WideChar *str() const
	{
		static const WideChar TheNullChr = 0;
		return m_data ? &m_data->data[0] : &TheNullChr;
	}
};

class Rva002DC74A
{
public:
	UnicodeString rva002DC74A(const UnicodeString &src) const;
};

class GameState;
extern GameState *TheGameState;
extern const WideChar g_00C65EC4[];
extern "C" __declspec(dllimport) int __stdcall DeleteFileW(const WideChar *lpFileName);

void __cdecl Rva00515633Delete(void)
{
	UnicodeString path = ((const Rva002DC74A *)TheGameState)->rva002DC74A(UnicodeString(g_00C65EC4));
	DeleteFileW(path.str());
}
