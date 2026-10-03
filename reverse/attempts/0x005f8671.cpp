// ??0Rva005F8671@@QAE@HH@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /MD /arch:SSE /Oa
// stlport
// ??0Rva005F8671@@QAE@HH@Z @0x005F8671 82B: derived ctor calls rowed base 0x005782F4 then stores vtable g_00C79CBC plus float int defaults plus vector. Evidence: chain from 0x005782F4 plus caller 0x005F86FE plus vtable 0x00879CBC.
#include <vector>
struct BfmeE16
{
	char _p[16];
};
extern const float g_00BC6EA0;
class Rva00577936
{
public:
	virtual void d0();
	Rva00577936(int v) throw();
private:
	void *m_04;
};
class Rva005F8671 : public Rva00577936
{
public:
	Rva005F8671(int a, int b);
	virtual void d0();
private:
	int m_08;
	float m_0C;
	float m_10;
	float m_14;
	int m_18;
	int m_1C;
	_STL::vector<BfmeE16> m_20;
};
// ??0Rva005F8671@@QAE@HH@Z present-unmatched
Rva005F8671::Rva005F8671(int a, int b) : Rva00577936(a), m_08(b), m_0C(g_00BC6EA0), m_10(g_00BC6EA0), m_14(0.0f), m_18(-500), m_1C(m_18), m_20()
{
}
