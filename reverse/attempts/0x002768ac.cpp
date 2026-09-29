// ?rva002768AC@Rva002768AC@@QAEXXZ
// partial score=0.96 date=2026-09-29
// ?rva002768AC@Rva002768AC@@QAEXXZ
// partial score=0.96 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
// ?rva002768AC@Rva002768AC@@QAEXXZ @0x002768AC 166B
// Tornado-bone update: refresh Matrix3D at +0x10 from B_TORNADO bone or transform.
// Evidence: callers 0x00276952 and 0x00278869; rowed getCurrentClientBonePositions; pinned getTransformMatrix;
// global 0x9FE77C slot 0x7C time; string B_TORNADO 0x7FB010.

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Matrix3D
{
public:
	int v[12];
};

class Drawable
{
public:
	int getCurrentClientBonePositions(const char *boneNamePrefix, int startIndex, Coord3D *positions, Matrix3D *transforms, int maxBones) const;
	const Matrix3D *getTransformMatrix() const;
};

class TimeGlobal
{
public:
	virtual void f00();
	virtual void f04();
	virtual void f08();
	virtual void f0C();
	virtual void f10();
	virtual void f14();
	virtual void f18();
	virtual void f1C();
	virtual void f20();
	virtual void f24();
	virtual void f28();
	virtual void f2C();
	virtual void f30();
	virtual void f34();
	virtual void f38();
	virtual void f3C();
	virtual void f40();
	virtual void f44();
	virtual void f48();
	virtual void f4C();
	virtual void f50();
	virtual void f54();
	virtual void f58();
	virtual void f5C();
	virtual void f60();
	virtual void f64();
	virtual void f68();
	virtual void f6C();
	virtual void f70();
	virtual void f74();
	virtual void f78();
	virtual unsigned int GetTime();
};

extern TimeGlobal *TheTimeGlobal;

class Rva002768AC
{
public:
	void rva002768AC();
private:
	char m_pad00[4];
	unsigned int m_time4;
	int m_count8;
	Drawable *m_drawC;
	Matrix3D m_mat10;
};

// ?rva002768AC@Rva002768AC@@QAEXXZ present-unmatched
void Rva002768AC::rva002768AC()
{
	if (m_drawC == 0)
		return;
	unsigned int t = TheTimeGlobal->GetTime();
	if (m_time4 >= t)
		return;
	t = TheTimeGlobal->GetTime();
	m_time4 = t;
	int n = m_drawC->getCurrentClientBonePositions("B_TORNADO", 1, 0, &m_mat10, 0x10);
	m_count8 = n;
	if (n != 0)
		return;
	const Matrix3D *tm = m_drawC->getTransformMatrix();
	m_mat10.v[0] = tm->v[0];
	m_mat10.v[1] = tm->v[1];
	m_mat10.v[2] = tm->v[2];
	m_mat10.v[3] = tm->v[3];
	m_mat10.v[4] = tm->v[4];
	m_mat10.v[5] = tm->v[5];
	m_mat10.v[6] = tm->v[6];
	m_mat10.v[7] = tm->v[7];
	m_mat10.v[8] = tm->v[8];
	m_mat10.v[9] = tm->v[9];
	m_mat10.v[10] = tm->v[10];
	m_mat10.v[11] = tm->v[11];
	m_count8 = 1;
}

