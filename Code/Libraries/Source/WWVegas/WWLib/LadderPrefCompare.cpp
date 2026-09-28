// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??8LadderPref@@QAE_NABV0@@Z @0x005DFC0B 46B: LadderPref::operator== compares address via rowed StringBase<char>::compare 0x000069D6 then port word at +8; donor ZH LadderPreferences.h inline address==other.address && port==other.port; caller addRecentLadder loop at 0x005E0419 over map nodes +0x14.
template <typename T> class StringBase
{
public:
    int compare(const StringBase &other) const;
    void *m_data;
};

class AsciiString : public StringBase<char>
{
public:
    AsciiString(const AsciiString &source);
    ~AsciiString();
};

class UnicodeString : public StringBase<unsigned short>
{
public:
    UnicodeString(const UnicodeString &source);
    ~UnicodeString();
};

class LadderPref
{
public:
    UnicodeString name;
    AsciiString address;
    unsigned short port;
    long lastPlayDate;
    bool operator==(const LadderPref &other);
};

bool LadderPref::operator==(const LadderPref &other)
{
    return address.compare(other.address) == 0 && port == other.port;
}
