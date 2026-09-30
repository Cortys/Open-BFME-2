// ?Rva0037B9D4Get@@YA?AVUnicodeString@@XZ
// partial score=0.95 date=2026-09-30
// ?Rva0037B9D4Get@@YA?AVUnicodeString@@XZ
// partial score=0.95 date=2026-09-30
#include <new>
// cl: /O1 /G7 /DNDEBUG /MD /EHsc
typedef int Int;
typedef unsigned short WideChar;
#define NULL 0
template <typename T>
class StringBase
{
    friend class AsciiString;
    friend class UnicodeString;
    friend UnicodeString Rva0037B9D4Get();
public:
    StringBase() : m_data(0) {}
    void concat(const WideChar *text);
private:
    StringBase(const StringBase<T> &that);
    void releaseBuffer();
    T *m_data;
};
class AsciiString : public StringBase<char>
{
public:
    __forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
};
class UnicodeString : public StringBase<WideChar>
{
public:
    __forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
    UnicodeString(const AsciiString &other);
    __forceinline ~UnicodeString() { releaseBuffer(); }
};
class GlobalData
{
public:
    AsciiString rva002360DE() const;
private:
    char m_pad[0x1240];
    AsciiString m_string1240;
};
extern GlobalData *TheWritableGlobalData;
extern const WideChar g_00C18798[];
// ?Rva0037B9D4Get@@YA?AVUnicodeString@@XZ present-unmatched
UnicodeString Rva0037B9D4Get()
{
    AsciiString tmp = TheWritableGlobalData->rva002360DE();
    UnicodeString wtmp(tmp);
    ((StringBase<char> *)&tmp)->releaseBuffer();
    wtmp.concat(g_00C18798);
    return wtmp;
}
