// ?rva002A3DD3@Rva002A3DD3@@QAEXXZ
// partial score=0.95 date=2026-10-02
// cl: /O1 /MD
// stlport
// ?rva002A3DD3@Rva002A3DD3@@QAEXXZ 0x002A3DD3 81B evidence: chain via rowed 0x0029B1C2 twice plus rowed vector erase; 4 ptrs at +0x5B4 vec at +0x5A0 stride 0xC check +8
#include <vector>

class Rva0029B1C2
{
public:
	void rva0029B1C2();
};

struct Gen_p12pod
{
	int _a[2];
	Rva0029B1C2 * _p;
};

class Rva002A3DD3
{
	char _p00[0x5A0];
	_STL::vector<Gen_p12pod> m_vec;
	char _gap[0x5B4 - 0x5A0 - 12];
	Rva0029B1C2 *m_arr[4];
public:
	void rva002A3DD3();
};

// ?rva002A3DD3@Rva002A3DD3@@QAEXXZ present-unmatched
void Rva002A3DD3::rva002A3DD3()
{
	Rva0029B1C2 **pp = m_arr;
	for (int n = 4; n != 0; --n, ++pp) {
		if (*pp != 0)
			(*pp)->rva0029B1C2();
		*pp = 0;
	}
	for (Gen_p12pod *p = &*m_vec.begin(); p != &*m_vec.end(); ++p) {
		p->_p->rva0029B1C2();
	}
	m_vec.erase(m_vec.begin(), m_vec.end());
}
