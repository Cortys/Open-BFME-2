// ??0Rva0010F058@@QAE@H@Z
// partial score=0.91 date=2026-09-28
// ??0Rva0010F058@@QAE@H@Z
// partial score=0.91 date=2026-09-28
// cl: /O1 /GX /DNDEBUG /MD
// ??0Rva0010F058@@QAE@H@Z at 0x0010F058 (108B).
// Ctor storing vtable 0x00BCFAAC with event member at +0x14 via rowed Rva0040F9D ctor
// plus InterlockedIncrement id at +0x20 and set. Same layout as Rva0010F0C4 dtor TU.
// Evidence: vtable 0x00BCFAAC; ctor args 1 0 0 0 to 0x00040F64; caller at 0x000A8D32;
// callers pass event this at +0x14 for set at 0x00040F9D.
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

class Rva0010F058EmptyBase
{
public:
	Rva0010F058EmptyBase() {}
	~Rva0010F058EmptyBase();
};

class Rva0010F058 : public Rva0010F058EmptyBase
{
public:
	virtual ~Rva0010F058();
	Rva0010F058(int x);
private:
	int m_unused04;
	void *m_stream08;
	int m_arg0C;
	int m_unused10;
	Rva0040F9D m_event14;
	int m_flag1C;
	long m_id20;
	int m_unused24;
};

Rva0010F058::Rva0010F058(int x) : m_unused04(0), m_stream08(0), m_arg0C(x), m_unused10(0), m_event14(1, 0, 0, 0), m_flag1C(1), m_id20(Rva0010EFB1Inc()), m_unused24(0)
{
	m_event14.set();
}
