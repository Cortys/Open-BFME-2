// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva004E44FBSet@@YGXHHABVUnicodeString@@@Z @0x004E44FB 88B
// Free __stdcall setter formatting "PlayerTable:%d:%d" via rowed AsciiString::format
// 0x00038150 then pinned BfmeAptWindowManager::bfmeSetText 0x00225301 with false.
// Manager at VA 0x009FE4CC via in-use TheRva00222A8BTarget; AsciiString local
// cleanup via rowed releaseBuffer 0x00036410 with EH_prolog. Ret 0xC is 3 args.
// Callers 0x004E4886/0x004E48A2/0x004E4910/0x004E4991 in 0x004E476C.
// Layout and flags from AptPlayerNameSet.cpp sibling using same callees.
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
    friend class UnicodeString;
public:
    StringBase() : m_data(0) {}
private:
    StringBase(const T *text);
    StringBase(const StringBase<T> &other);
    ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
    BfmeStringData<T> *m_data;
};
class AsciiString : private StringBase<char>
{
public:
    AsciiString() {}
    AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    ~AsciiString() {}
    void format(const char *fmt, ...);
};
class UnicodeString : public StringBase<unsigned short>
{
public:
    UnicodeString() {}
    UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    ~UnicodeString() {}
};
class BfmeAptWindowManager
{
public:
    void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;

void __stdcall Rva004E44FBSet(int a, int b, const UnicodeString &text)
{
    AsciiString key;
    key.format("PlayerTable:%d:%d", a, b);
    ((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, text, false);
}
