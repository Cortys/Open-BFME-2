// ?rva005C7636@Rva005C76C0@@QAEXXZ
// partial score=0.93 date=2026-10-01
// ?rva005C7636@Rva005C76C0@@QAEXXZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /arch:SSE /MD
// ?rva005C7636@Rva005C76C0@@QAEXXZ, retail 0x005C7636 138B.
// Accumulator on Rva005C76C0::m_38[4]: m_38[i] += m_38[i+1] for i 0..2
// plus ++m_00. Evidence: 9 movss/addss triples 0x38+=0x44 etc plus inc
// [ecx]; layout from Rva005C76C0Ctor m_38[4] at +0x38; caller 0x0055A853.
class Coord3D
{
public:
	float x;
	float y;
	float z;
};

class Rva0055A246
{
public:
	Rva0055A246();
	Coord3D m_arr[4];
};

class Rva005C76C0
{
public:
	void rva005C7636();
	int m_00;
	int m_04;
	Rva0055A246 m_08;
	Coord3D m_38[4];
};

void Rva005C76C0::rva005C7636()
{
	m_38[0].x += m_38[1].x;
	m_38[0].y += m_38[1].y;
	m_38[0].z += m_38[1].z;
	m_38[1].x += m_38[2].x;
	m_38[1].y += m_38[2].y;
	m_38[1].z += m_38[2].z;
	m_38[2].x += m_38[3].x;
	m_38[2].y += m_38[3].y;
	m_38[2].z += m_38[3].z;
	++m_00;
}
