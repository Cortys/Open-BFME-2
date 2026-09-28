// ?rva0036CE87@AIGroup@@QAEXXZ
// partial score=0.96 date=2026-09-28
// ?rva0036CE87@AIGroup@@QAEXXZ
// partial score=0.96 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva0036CE87@AIGroup@@QAEXXZ @0x0036CE87 73B
// AIGroup ground-path clear: delete Path at +0x14 when present, zero
// +0x14/+0x18/+0x1C/+0x20, set +0x24 to 10.0f, zero +0x28/+0x2C.
// Evidence: called from AIGroup recompute 0x0036D2C5 (getCenter 0x0036D035
// plus m_speed 1e10 plus m_dirty) and from AIGroup dtor 0x0036E564
// (vptr stores plus member-list clear plus list base dtor 0x004EC395),
// callees Path dtor row 0x00364A89 plus operator delete row 0x0002FD60,
// BFME1 AIGroupDestructors plus AIGroup_recompute donor shape.
class Path
{
public:
	~Path();
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class AIGroup
{
public:
	void rva0036CE87();

private:
	char m_pad00[0x14];
	Path *m_groundPath;
	float m_18;
	float m_1c;
	float m_20;
	float m_24;
	float m_28;
	float m_2c;
};

void AIGroup::rva0036CE87()
{
	Path *path = m_groundPath;
	if (!path)
		return;
	delete path;
	m_groundPath = 0;
	_ReadWriteBarrier();
	m_18 = 0.0f;
	m_1c = 0.0f;
	m_20 = 0.0f;
	m_24 = 10.0f;
	m_28 = 0.0f;
	m_2c = 0.0f;
}
