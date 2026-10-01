// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@V2@@Z
// partial score=0.96 date=2026-10-01
// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@V2@@Z
// partial score=0.96 date=2026-10-01
// cl: /O1 /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS
// stlport
// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@V2@@Z @ 0x00240167 89B
// Circular name search at this+0x1C0 via compare 0x69D6 key by value via
// 0x36410. Follows TerrainTypes_findTerrain recipe. Evidence calls at
// 0x240188/0x2401A4 head +0x1C0 next +0 name +8 callers 0x245FE5/0x247C1A.
// Near miss: same 89B/31insns 0 reg 0 mem only lea ecx scheduling
// (retail lea-lea-push ours lea-push-lea) differs. Tried swap/G7/slot: same
// or worse. t=30 model=muse-spark
typedef int Int;
class AsciiString
{
public:
	AsciiString(const AsciiString &that);
	~AsciiString();
	Int compare(const AsciiString &other) const throw();
private:
	void *m_data;
};
struct Rva00240167Node
{
	Rva00240167Node *m_next;
	char m_pad04[4];
	AsciiString m_name;
};
class Rva00240167
{
public:
	AsciiString *rva00240167(AsciiString name);
private:
	char m_pad00[0x1C0];
	Rva00240167Node *m_head;
};
AsciiString *Rva00240167::rva00240167(AsciiString name)
{
	for (Rva00240167Node *cur = m_head->m_next; cur != m_head; cur = cur->m_next) {
		if (cur->m_name.compare(name) == 0)
			return &cur->m_name;
	}
	return 0;
}
