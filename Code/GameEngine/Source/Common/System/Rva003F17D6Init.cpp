// cl: /O1 /Oy- /DNDEBUG /MD /GX-
// ?rva003F17D6@Rva003F17D6@@QAEPAU1@PAX0@Z @0x003F17D6 141B
// Obfuscated 8-int init sibling of Rva0056EF65 141B per Rva0056EDBAPick.cpp
// precedent: picks pair via rowed Rva003F10D0Pick 0x003F10D0 into p/q,
// stores p at +0, constants 0x10AC50C0/0x14804842/0x004241A4F at +4/+8/+0c,
// derefs void* args into +0x10/+0x14, then imul/xor chain with q.
// Evidence: caller 0x003F1D56; callee rowed; prev shares flags.
void __cdecl Rva003F10D0Pick(int *out1, int *out2);
struct Rva003F17D6
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva003F17D6 *rva003F17D6(void *a1, void *a2);
};
Rva003F17D6 *Rva003F17D6::rva003F17D6(void *a1, void *a2)
{
	int p;
	int q;
	Rva003F10D0Pick(&p, &q);
	m_00 = p;
	m_04 = 0x10AC50C0;
	m_08 = 0x14804842;
	m_0c = 0x004241A4F;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x10AC50C0;
	m_04 = e;
	e *= b;
	e ^= 0x14804842;
	m_08 = e;
	e *= b;
	e ^= 0x004241A4F;
	m_0c = e;
	e *= b;
	m_10 ^= e;
	e = m_10;
	e *= b;
	m_14 ^= e;
	e = m_14;
	e *= b;
	m_18 ^= e;
	e = m_18;
	e *= b;
	m_1c ^= e;
	return this;
}
