// cl: /O1 /G7 /DNDEBUG /MD /EHsc
// Rva0037B9D4Get, retail 0x0037B9D4, 116 bytes. Returns a UnicodeString
// built from the narrow string that the rowed GlobalData::rva002360DE
// 0x002360DE returns for TheWritableGlobalData, converted through the rowed
// UnicodeString(const AsciiString &) 0x006CB6D0 and then suffixed with the
// wide literal at 0x00C18798.
// Retail's unwind map tracks the returned narrow string as a temporary of
// the constructing expression (state 1), the local (states 2/3) and the
// return slot (state 0). The banked 0.95 attempt released the narrow string
// by hand and missed state 1.
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
    __forceinline ~AsciiString() { releaseBuffer(); }
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
UnicodeString Rva0037B9D4Get()
{
    UnicodeString wtmp(TheWritableGlobalData->rva002360DE());
    wtmp.concat(g_00C18798);
    return wtmp;
}
