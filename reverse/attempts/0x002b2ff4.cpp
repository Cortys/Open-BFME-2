// ?Rva002B2FF4Swap@@YAXAAVRva002B2F97@@0@Z
// partial score=0.93 date=2026-09-27
// ?Rva002B2FF4Swap@@YAXAAVRva002B2F97@@0@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /MD /EHsc
struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);
struct Rva002B2F97Target
{
	char m_pad[0xAC];
	TargetRef00217D4C m_ac;
};
class Rva002B2F97
{
public:
	Rva002B2F97(const Rva002B2F97 &other) : m_ptr(other.m_ptr) { if (m_ptr) ++m_ptr->m_ac.references; }
	~Rva002B2F97() { if (m_ptr) ReleaseTreeHintRef00217D4C(&m_ptr->m_ac); }
	Rva002B2F97 &operator=(const Rva002B2F97 &other);
private:
	Rva002B2F97Target *m_ptr;
};
void __cdecl Rva002B2FF4Swap(Rva002B2F97 &a, Rva002B2F97 &b)
{
	Rva002B2F97 tmp = a;
	a = b;
	b = tmp;
}
