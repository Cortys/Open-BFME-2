// cl: /O1 /MD /EHsc
//
// ?rva003F0FD1@Rva003F0FD1@@QAEXXZ @0x003F0FD1 (115B):
// __thiscall void check over AsciiString at +0x18; formats
// "maps\%s\%s.map" with the name twice via rowed AsciiString::format
// 0x00038150 then stores TheFileSystem->doesFileExist 0x00600D7D into
// bool at +0x1A4. Empty-string fallback is g_Rva0107301CEmptyString.
// Evidence: unlock lane; caller 0x003EEDD6 passes element as this;
// format string at 0x007DF034 and FileSystem row are annotated.
class AsciiString;
template <typename T> class StringBase
{
    friend class AsciiString;
public:
    StringBase() : m_data(0) {}
    void removeLastChar();
private:
    StringBase(const StringBase<T> &other);
    ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
    struct Header
    {
        int refCount;
        unsigned short length;
        unsigned short capacity;
        T text[1];
    };
    Header *m_data;
};
extern const char g_Rva0107301CEmptyString[];
class AsciiString : private StringBase<char>
{
public:
    AsciiString() {}
    AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    ~AsciiString() {}
    void __cdecl format(const char *fmt, ...);
    const char *str() const { return m_data ? m_data->text : g_Rva0107301CEmptyString; }
};
class FileSystem
{
public:
    bool doesFileExist(const char *filename) const;
};
extern FileSystem *TheFileSystem;
class Rva003F0FD1
{
public:
    void rva003F0FD1();
private:
    char m_pad18[0x18];
    AsciiString m_mapName;
    char m_pad1C[0x1A4 - 0x1C];
    bool m_exists;
};
void Rva003F0FD1::rva003F0FD1()
{
    AsciiString tmp;
    const char *s = m_mapName.str();
    tmp.format("maps\\%s\\%s.map", s, s);
    const char *path = tmp.str();
    m_exists = TheFileSystem->doesFileExist(path);
}
