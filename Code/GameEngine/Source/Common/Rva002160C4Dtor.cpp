// cl: /DNDEBUG /MD /EHsc /O1 /Ob2
// ??1Rva002160C4@@QAE@XZ 0x002160C4 68B evidence: dtor over three StringBase<char> at +0 +4 +8 via releaseBuffer row 0x00036410 with EH states; callers 0x00216120 0x00217019 and Unwind funclet; unblocks 0x00216108
template <typename T> class StringBase {
    friend class AsciiString;
    void releaseBuffer();
public:
    ~StringBase();
protected:
    void *m_data;
};
class AsciiString : public StringBase<char> {
public:
    ~AsciiString() { releaseBuffer(); }
};
class Rva002160C4 {
    AsciiString m_0;
    AsciiString m_4;
    AsciiString m_8;
public:
    ~Rva002160C4();
};
Rva002160C4::~Rva002160C4()
{
}
