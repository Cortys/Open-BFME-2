// ??1BuildListInfo@@MAE@XZ
// partial score=0.93 date=2026-09-28
// ??1BuildListInfo@@MAE@XZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase() { m_data = 0; }
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	void *m_data;
};
class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() { releaseBuffer(); }
	AsciiString &operator=(const AsciiString &other);
};
class BFMERetailAsciiString : public AsciiString
{
public:
    ~BFMERetailAsciiString() {}
};
class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc();
	virtual void loadPostProcess();
	virtual void xfer();
};
inline Snapshot::~Snapshot()
{
	*(const void **)this = reinterpret_cast<const void *>(0x00BBB554);
}
class BuildListInfo : public Snapshot
{
public:
    void deleteInstance()
    {
        delete this;
    }
    BuildListInfo *getNext() const
    {
        return m_nextBuildList;
    }
    void setNextBuildList(BuildListInfo *next)
    {
        m_nextBuildList = next;
    }
    BFMERetailAsciiString m_buildingName;
    BFMERetailAsciiString m_templateName;
    unsigned char m_padding[32];
    BuildListInfo *m_nextBuildList;
    BFMERetailAsciiString m_script;
protected:
    virtual ~BuildListInfo();
};
BuildListInfo::~BuildListInfo()
{
    register BuildListInfo *next;
    if (m_nextBuildList) {
        register BuildListInfo *cur = m_nextBuildList;
        while (cur) {
            next = cur->getNext();
            cur->setNextBuildList(0);
            cur->deleteInstance();
            cur = next;
        }
    }
}
