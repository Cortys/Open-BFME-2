// ?rva003FC149@Rva003FC149@@QAEXABVMatrix3@@@Z
// partial score=0.96 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva003FC149@Rva003FC149@@QAEXABVMatrix3@@@Z @0x003FC149 328B
// Honest address-derived method: this+8 delegate with matrix at +0x18 and scale at +0x48,
// this+0x14 second delegate; slot20 update then Matrix3D build via Set_Rotation, scale 3x3, slot21.
// Evidence: rowed Set_Rotation 0x00711EF0; callers 0x003F935A; neighbours use /O1 /DNDEBUG /MD.
class Matrix3
{
public:
	float m[9];
};
class Matrix3D
{
public:
	void Set_Rotation(const Matrix3 &m);
	float m[12];
};
class Rva003FC149Target
{
public:
	virtual void _p00(); virtual void _p01(); virtual void _p02(); virtual void _p03();
	virtual void _p04(); virtual void _p05(); virtual void _p06(); virtual void _p07();
	virtual void _p08(); virtual void _p09(); virtual void _p10(); virtual void _p11();
	virtual void _p12(); virtual void _p13(); virtual void _p14(); virtual void _p15();
	virtual void _p16(); virtual void _p17(); virtual void _p18(); virtual void _p19();
	virtual void slot20();
	virtual void slot21(Matrix3D *m);
public:
	char m_pad04[20];
	Matrix3D m_mat;
	float m_scale;
};
class Rva003FC149
{
public:
	void rva003FC149(const Matrix3 &m);
private:
	char m_pad00[8];
	Rva003FC149Target *m_08;
	char m_pad0C[8];
	Rva003FC149Target *m_14;
};
// ?rva003FC149@Rva003FC149@@QAEXABVMatrix3@@@Z present-unmatched
void Rva003FC149::rva003FC149(const Matrix3 &m)
{
	Rva003FC149Target *p = m_08;
	if (!p)
		return;
	p->slot20();
	Matrix3D tm;
	tm.m[0] = p->m_mat.m[0];
	tm.m[1] = p->m_mat.m[1];
	tm.m[2] = p->m_mat.m[2];
	tm.m[3] = p->m_mat.m[3];
	tm.m[4] = p->m_mat.m[4];
	tm.m[5] = p->m_mat.m[5];
	tm.m[6] = p->m_mat.m[6];
	tm.m[7] = p->m_mat.m[7];
	tm.m[8] = p->m_mat.m[8];
	tm.m[9] = p->m_mat.m[9];
	tm.m[10] = p->m_mat.m[10];
	tm.m[11] = p->m_mat.m[11];
	tm.Set_Rotation(m);
	float s = m_08->m_scale;
	tm.m[0] *= s;
	tm.m[4] *= s;
	tm.m[8] *= s;
	tm.m[1] *= s;
	tm.m[5] *= s;
	tm.m[9] *= s;
	tm.m[2] *= s;
	tm.m[6] *= s;
	tm.m[10] *= s;
	m_08->slot21(&tm);
	if (m_14)
		m_14->slot21(&tm);
}
