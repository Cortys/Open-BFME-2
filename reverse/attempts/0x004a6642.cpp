// ?rva004A6642@Rva004A6642@@QAE_NPAX@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /MD /arch:SSE
// ?rva004A6642@Rva004A6642@@QAE_NPAX@Z @0x004A6642 192B. __thiscall method returning bool, one pointer arg (ret 4), null-checks [ecx+8] then transforms vec at [ecx+4]+8 by matrix at [ecx+8]+8 into 12B at out arg. Vtable slot 13 of 0x0084B2AC/0x00852D30. No callees.
struct VecInput004A6642
{
	char m_pad[8];
	float m_x;
	float m_y;
	float m_z;
};
struct MatInput004A6642
{
	char m_pad[8];
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
struct Out004A6642
{
	float x;
	float y;
	float z;
};
class Rva004A6642
{
public:
	void *m_vft;
	VecInput004A6642 *m_vec;
	MatInput004A6642 *m_mat;
	// ?rva004A6642@Rva004A6642@@QAE_NPAX@Z present-unmatched
	bool rva004A6642(void *outp);
};
// ?rva004A6642@Rva004A6642@@QAE_NPAX@Z present-unmatched
bool Rva004A6642::rva004A6642(void *outp)
{
	MatInput004A6642 *m = m_mat;
	if (!m)
		return false;
	VecInput004A6642 *v = m_vec;
	float x, y, z;
	y = v->m_y;
	z = v->m_z;
	x = v->m_x;
	Out004A6642 tmp;
	tmp.x = m->m00 * x + m->m01 * y + m->m02 * z + m->m03;
	tmp.y = m->m10 * x + m->m11 * y + m->m12 * z + m->m13;
	tmp.z = m->m20 * x + m->m21 * y + m->m22 * z + m->m23;
	*(Out004A6642 *)outp = tmp;
	return true;
}
