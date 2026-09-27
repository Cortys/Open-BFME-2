// ?Rva003FB6C5@Rva005C4B1B@@UAEXABUVector3@@@Z
// partial score=0.93 date=2026-09-27
// ?Rva003FB6C5@Rva005C4B1B@@UAEXABUVector3@@@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /arch:SSE
struct Vector3
{
	float X;
	float Y;
	float Z;
};

struct Matrix3D
{
	float m00;
	float m01;
	float m02;
	float m03;
	float m10;
	float m11;
	float m12;
	float m13;
	float m20;
	float m21;
	float m22;
	float m23;
};

class InnerTarget
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual void s16();
	virtual void s17();
	virtual void s18();
	virtual void s19();
	virtual void slot20();
	virtual void slot21(const Matrix3D *m);
public:
	char m_pad04[0x14];
	float m_f18;
	float m_f1C;
	float m_f20;
	float m_f24;
	float m_f28;
	float m_f2C;
	float m_f30;
	float m_f34;
	float m_f38;
	float m_f3C;
	float m_f40;
};

class Rva005C4B1B
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void Rva003FB6C5(const Vector3 &v);
private:
	char m_pad04[4];
	InnerTarget *m_ptr08;
	char m_pad0C[8];
	InnerTarget *m_ptr14;
};

void Rva005C4B1B::Rva003FB6C5(const Vector3 &v)
{
	InnerTarget *p = m_ptr08;
	if (!p)
		return;
	p->slot20();
	InnerTarget *q = m_ptr08;
	Matrix3D tmp;
	tmp.m00 = p->m_f18;
	tmp.m01 = p->m_f1C;
	tmp.m02 = p->m_f20;
	tmp.m03 = p->m_f24;
	tmp.m10 = p->m_f28;
	tmp.m11 = p->m_f2C;
	tmp.m12 = p->m_f30;
	tmp.m13 = p->m_f34;
	tmp.m20 = p->m_f38;
	tmp.m21 = p->m_f3C;
	tmp.m22 = p->m_f40;
	tmp.m03 = v.X;
	tmp.m13 = v.Y;
	tmp.m23 = v.Z;
	q->slot21(&tmp);
	if (m_ptr14)
		m_ptr14->slot21(&tmp);
}
