// ?rva0020F685@Rva0020F685@@QAEXXZ
// partial score=0.9 date=2026-10-01
// ?rva0020F685@Rva0020F685@@QAEXXZ
// partial score=0.90 date=2026-10-01
// cl: /O1 /MD
// stlport
// ?rva0020F685@Rva0020F685@@QAEXXZ @ 0x0020F685 141B
// Double vector<void*> clear at +0x14/+0x20 via slot0 with 0 plus delete
// then erase. Evidence calls at 0x20F6A6/0x20F6AD/0x20F6C7/0x20F6E8/0x20F6EF/
// 0x20F709 size sub-sar-2 pop-ecx callers 0x20F7CD/0x20FB48/0x210BB3.
// Near miss: same 139/141B only ebx-edi swap for this-index plus null
// jmp-xor vs xor differs. Tried polarity/ref/self-order/G7: same or worse.
// t=20 model=muse-spark
#include <vector>
struct Rva0020F685Elem
{
	virtual void *v0(int x);
};
class Rva0020F685
{
public:
	void rva0020F685();
private:
	char m_pad00[0x14];
	_STL::vector<void *> m_14;
	_STL::vector<void *> m_20;
};
void Rva0020F685::rva0020F685()
{
	for (unsigned int i = 0; i < m_14.size(); ++i) {
		void *p = m_14[i];
		void *q = 0;
		if (p != 0)
			q = ((Rva0020F685Elem *)p)->v0(0);
		::operator delete(q);
	}
	m_14.erase(m_14.begin(), m_14.end());
	for (unsigned int j = 0; j < m_20.size(); ++j) {
		void *p = m_20[j];
		void *q = 0;
		if (p != 0)
			q = ((Rva0020F685Elem *)p)->v0(0);
		::operator delete(q);
	}
	m_20.erase(m_20.begin(), m_20.end());
}
