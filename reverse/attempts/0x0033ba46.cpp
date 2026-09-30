// ?rva0033BA46@ThingTemplate@@QAEPBVImage@@XZ
// partial score=0.93 date=2026-09-30
// ?rva0033BA46@ThingTemplate@@QAEPBVImage@@XZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva0033BA46@ThingTemplate@@QAEPBVImage@@XZ @0x0033BA46 190B.
// ThingTemplate portrait-image resolver (portrait slot +0x74/+0x488).
// BFME1 donor GameEngine/Source/Common/Thing/ThingTemplate.cpp resolveNames
// does TheMappedImageCollection->findImageByName(name) then name.clear() for
// portrait and button with DEBUG_ASSERTCRASH("%s is looking for Portrait %s
// but can't find it. Skipping..."); retail splits them: button sibling
// 0x0033B580 (+0x78/+0x48c, 56B, no debug) and this portrait body with the
// SkipNext/CrashBegin/operator<</CrashDone debug expansion plus the empty
// string global at 0x00BBAC1C for str(). INI table has SelectPortrait then
// ButtonImage back to back and the ctor NULLs portrait then button. Callers
// 0x0031D6E1 0x0031D6EC 0x0033C385 0x005F0411 plus tail-jmps 0x0033BC53
// 0x005D234D 0x005D237D 0x005F030F agree. Callees rowed: isEmpty 0x00001E2F
// findImageByName 0x002D92F6 releaseBuffer 0x00036410 plus debug flag
// 0x000387C0 and recordCallsite 0x00038790. Global g_00DFF078.
template <typename T>
class StringBase
{
public:
    bool isEmpty() const;
    void clear() { releaseBuffer(); }
    void *m_data;
private:
    void releaseBuffer();
};

class AsciiString : public StringBase<char>
{
};

class Image;

class ImageCollection
{
public:
    const Image *findImageByName(const AsciiString &name);
};

extern ImageCollection *g_00DFF078;
extern const char g_Rva0107301CEmptyString[];

bool bfmeRva000387C0();
void _bfme_debugRecordCallsite(int kind);

class Debug
{
public:
    virtual void pad00(); virtual void pad01(); virtual void pad02(); virtual void pad03();
    virtual void pad04(); virtual void pad05(); virtual void pad06(); virtual void pad07();
    virtual void pad08(); virtual void pad09(); virtual void pad10(); virtual void pad11();
    virtual void pad12(); virtual void pad13();
    virtual Debug &operator<<(const char *str);
    virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18();
    virtual bool CrashDone(int mode);
    virtual void pad20(); virtual void pad21(); virtual void pad22();
    virtual void SetCrashAddress(void *returnAddress, int set);
    virtual void SkipNext();
    virtual void pad25(); virtual void pad26();
    virtual Debug &CrashBegin(const char *file, int line, int reserved);
};

extern Debug *theDebug;

class ThingTemplate
{
public:
    const Image *rva0033BA46();
private:
    char m_pad0[0x64];
    AsciiString m_name;
    char m_pad68[0x74 - 0x68];
    AsciiString m_portraitName;
    char m_pad78[0x488 - 0x78];
    const Image *m_portraitImage;
};

// ?rva0033BA46@ThingTemplate@@QAEPBVImage@@XZ present-unmatched
const Image *ThingTemplate::rva0033BA46()
{
    if (!m_portraitName.isEmpty() && g_00DFF078 != 0)
    {
        m_portraitImage = g_00DFF078->findImageByName(m_portraitName);
        if (bfmeRva000387C0())
        {
            _bfme_debugRecordCallsite(1);
            theDebug->SkipNext();
            const char *nameStr = m_name.m_data != 0 ? (const char *)m_name.m_data + 8 : g_Rva0107301CEmptyString;
            const char *portraitStr = m_portraitName.m_data != 0 ? (const char *)m_portraitName.m_data + 8 : g_Rva0107301CEmptyString;
            (theDebug->CrashBegin(0, 0, 0) << nameStr << " is looking for Portrait " << portraitStr << " but can't find it. Skipping...").CrashDone(2);
        }
        m_portraitName.clear();
    }
    return m_portraitImage;
}
