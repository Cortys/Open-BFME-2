// ??1Rva001E3624@@UAE@XZ
// partial score=0.94 date=2026-09-30
// ??1Rva001E3624@@UAE@XZ
// partial score=0.94 date=2026-09-30
// cl: /O1
void __cdecl operator delete(void *ptr);
class Rva001E3624Member {
public:
	virtual void *scalarDeletingDestructor(unsigned int flags);
};
class Rva001E3624 {
public:
	virtual ~Rva001E3624();
private:
	Rva001E3624Member *m_04;
};
// ??1Rva001E3624@@UAE@XZ present-unmatched
Rva001E3624::~Rva001E3624()
{
	if (m_04 != 0) {
		::operator delete(m_04 != 0 ? m_04->scalarDeletingDestructor(0) : 0);
		m_04 = 0;
	}
}
