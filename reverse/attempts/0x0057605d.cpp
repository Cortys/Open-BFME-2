// ??0Rva0057605D@@QAE@HPAUParent0057605D@@@Z
// partial score=0.9 date=2026-09-29
// ??0Rva0057605D@@QAE@HPAUParent0057605D@@@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /EHsc /MD
// ??0Rva0057605D@@QAE@HPAUParent0057605D@@@Z retail 0x0057605D 84B ctor with EH.
// Evidence: vtable stores at [this] and [this+8]; int at +4 and parent at +C;
// member +8 registered via rowed append 0x005A0B4C with parent+8 list;
// EH prolog rowed 0x00629188; caller 0x00576145.
class Rva005A0B4CList;
struct Rva002BA8F1Listener { virtual ~Rva002BA8F1Listener(); };
class Rva005A0B4CList
{
public:
	void append(Rva002BA8F1Listener *p);
};
struct Parent0057605D { char pad[8]; Rva005A0B4CList list; };
struct EmptyBase0057605D
{
	EmptyBase0057605D() {}
	~EmptyBase0057605D();
};
struct EmptyBase2_0057605D
{
	EmptyBase2_0057605D() {}
	~EmptyBase2_0057605D();
};
class Rva0057605D : public EmptyBase0057605D, public EmptyBase2_0057605D
{
public:
	Rva0057605D(int a, Parent0057605D *b);
private:
	unsigned m_00;
	int m_a4;
	volatile unsigned m_08;
	Parent0057605D *m_parentC;
};
// ??0Rva0057605D@@QAE@HPAUParent0057605D@@@Z present-unmatched
Rva0057605D::Rva0057605D(int a, Parent0057605D *b)
	: m_a4(a), m_08(0x00C77F44), m_parentC(b)
{
	m_00 = 0x00C6E6A0;
	m_08 = 0x00C6E690;
	b->list.append((Rva002BA8F1Listener *)(void *)&m_08);
}
