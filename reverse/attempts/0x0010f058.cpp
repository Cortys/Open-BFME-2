// ??0Rva0010F058@@QAE@H@Z
// partial score=0.92 date=2026-10-04
// ??0Rva0010F058@@QAE@H@Z
// cl: /O1 /GX /DNDEBUG /MD
// ??0Rva0010F058@@QAE@H@Z at 0x0010F058 (108B).
// Ctor storing vtable 0x00BCFAAC with event member at +0x14 via rowed Rva0040F9D ctor
// plus InterlockedIncrement id at +0x20 and set. Same layout as Rva0010F0C4 dtor TU.
// The +0x04 zero belongs to a polymorphic BASE subobject (vtable 0x00BC5128,
// folded: only the derived 0x00BCFAAC store survives); moving it into a base
// class fixes the prologue push/mov order and lifts the shape ratio from
// 0.868 to 0.921 (first diff +0xD -> +0x13). Sole residual is the EH
// this-save (`mov [ebp-0x10],esi`) emitted before the inlined base store
// (`mov [esi+4],edi`) where retail emits the store first.
// Evidence: vtable 0x00BCFAAC; ctor args 1 0 0 0 to 0x00040F64; caller at 0x000A8D32;
// callers pass event this at +0x14 for set at 0x00040F9D; base vtable 0x00BC5128.
class Rva0040F9D
{
public:
	virtual ~Rva0040F9D();
	Rva0040F9D(int a1, int a2, char const *a3, void *a4);
	bool set();
private:
	void *m_handle;
};

long Rva0010EFB1Inc();

class Rva0010F058Base
{
public:
	virtual ~Rva0010F058Base() { *(const void **)this = reinterpret_cast<const void *>(0x00BC5128); }
	Rva0010F058Base() : m_unused04(0) {}
	int m_unused04;
};

class Rva0010F058 : public Rva0010F058Base
{
public:
	virtual ~Rva0010F058();
	Rva0010F058(int x);
private:
	void *m_stream08;
	int m_arg0C;
	int m_unused10;
	Rva0040F9D m_event14;
	int m_flag1C;
	long m_id20;
	int m_unused24;
};

Rva0010F058::Rva0010F058(int x) : m_stream08(0), m_arg0C(x), m_unused10(0), m_event14(1, 0, 0, 0), m_flag1C(1), m_id20(Rva0010EFB1Inc()), m_unused24(0)
{
	m_event14.set();
}
