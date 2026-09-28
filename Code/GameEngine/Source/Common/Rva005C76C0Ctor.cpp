// cl: /O1 /arch:SSE /MD
// ??0Rva005C76C0@@QAE@XZ @ 0x005C76C0, 85 bytes.
// Ctor: zero ints at +0x00 +0x04 init Rva0055A246 at +0x08 zero 12 floats at +0x38.
// Evidence: retail and [esi] 0 and [esi+4] 0 lea ecx [esi+8] call 0x55A246 xorps movss x12; chain from 0x55A246.
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
	Rva005C76C0();
	int m_00;
	int m_04;
	Rva0055A246 m_08;
	Coord3D m_38[4];
};

Rva005C76C0::Rva005C76C0() : m_00(0), m_04(0)
{
	m_38[0].x = 0.0f;
	m_38[0].y = 0.0f;
	m_38[0].z = 0.0f;
	m_38[3].x = 0.0f;
	m_38[3].y = 0.0f;
	m_38[3].z = 0.0f;
	m_38[2].x = 0.0f;
	m_38[2].y = 0.0f;
	m_38[2].z = 0.0f;
	m_38[1].x = 0.0f;
	m_38[1].y = 0.0f;
	m_38[1].z = 0.0f;
}
