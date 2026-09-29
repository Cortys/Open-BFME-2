// cl: /O1 /arch:SSE /MD
// ?rva0027D244@Rva0027D244@@QAEPAV1@H@Z, retail 0x0027D244, 50 bytes.
// Thiscall init of a 0x1C-byte struct: zeroes floats at +0/+4/+8, zeroes
// dwords at +0xC/+0x14, copies global float VA 0x00BC876C to +0x10, stores
// the int arg at +0x18. Caller 0x0027F13C builds the 0x1C struct on the
// stack. Same Common family as neighbours Rva0027D1A4Forward/Rva0027D347.
// No donor: honest address name.
class Rva0027D244
{
public:
	Rva0027D244 *rva0027D244(int v);
private:
	float m_00;
	float m_04;
	float m_08;
	int m_0C;
	float m_10;
	int m_14;
	int m_18;
};

Rva0027D244 *Rva0027D244::rva0027D244(int v)
{
	float t = *(volatile float *)0x00BC876C;
	Rva0027D244 *s = this;
	int u = v;
	s->m_0C = 0;
	s->m_14 = 0;
	s->m_10 = t;
	s->m_18 = u;
	s->m_00 = 0.0f;
	s->m_04 = 0.0f;
	s->m_08 = 0.0f;
	return s;
}
