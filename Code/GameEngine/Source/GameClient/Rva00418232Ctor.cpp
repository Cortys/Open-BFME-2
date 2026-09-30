// cl: /O1 /Ob2 /EHsc /MD
// ??0Rva00418232@@QAE@ABVAsciiString@@ABVRva004181A6@@@Z @0x00418232 57B
// Ctor with AsciiString at +0 via pinned StringBase copy 0x000365F0 plus
// Rva004181A6 at +4 via rowed copy 0x004181A6. No vptrs. AsciiString inline
// copy/dtor via StringBase releaseBuffer gives EH state after first call.
// Evidence: chain lane after landing 0x004181A6; unblocks 0x004183AC.
template <typename T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    StringBase(const StringBase &);
    __forceinline ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
    void *m_data;
};
class AsciiString : private StringBase<char> {
public:
    __forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    __forceinline ~AsciiString() {}
    AsciiString &operator=(const AsciiString &other);
};
class UnicodeString : private StringBase<unsigned short> {
public:
    __forceinline UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    __forceinline ~UnicodeString() {}
};
class Rva004181A6 {
public:
    Rva004181A6(const Rva004181A6 &other);
private:
    char m_pad[0x18];
};
class Rva00418232 {
public:
    Rva00418232(const AsciiString &a, const Rva004181A6 &b);
private:
    AsciiString m_str;
    Rva004181A6 m_rva;
};
Rva00418232::Rva00418232(const AsciiString &a, const Rva004181A6 &b)
    : m_str(a)
    , m_rva(b)
{
}
