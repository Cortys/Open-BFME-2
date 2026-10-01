// cl: /O1 /DNDEBUG /MD
// ?Rva0056EDBAPick@@YAXPAH0@Z @0x0056EDBA 46B
// Random pair pick via rdtsc low bits into two parallel int[4] tables.
// Inline asm for rdtsc: MSVC 7.1 has no __rdtsc intrinsic, so __asm is the
// only way to emit 0F 31; the surrounding movs are plain C assignments.
// Unlocks 0x0056F32B 0x0056F2A5.
// Evidence: and [ebp-4]0 rdtsc mov [ebp-4]eax and-3 shl-2 two indexed loads.
// g_Va00DD2A5C: matched references place it at VA 0xdd2a5c (retail .data contents).
int g_Va00DD2A5C[4] = {
	0x17c6e74f, 0x6e41c34f, 0x1a84b34f, -1103415473
};
// g_Va00DD2A6C: matched references place it at VA 0xdd2a6c (retail .data contents).
int g_Va00DD2A6C[4] = {
	0x5bc6af4b, 0x6a41934b, 0x5204e34b, -1430552757
};
void __cdecl Rva0056EDBAPick(int *out1, int *out2);
void __cdecl Rva0056EDBAPick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		rdtsc
		mov t, eax
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD2A6C[i];
	*out2 = g_Va00DD2A5C[i];
}
// g_Va00DD29BC: matched references place it at VA 0xdd29bc (retail .data contents).
int g_Va00DD29BC[4] = {
	-273905649, 0x9e6cf, -1157274225, 0x42b61c4f
};
// g_Va00DD29CC: matched references place it at VA 0xdd29cc (retail .data contents).
int g_Va00DD29CC[4] = {
	-1291022325, 0x48deecb, -1482610805, 0x4e9a144b
};
void __cdecl Rva0056ECDAPick(int *out1, int *out2);
void __cdecl Rva0056ECDAPick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		mov t, esp
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD29CC[i];
	*out2 = g_Va00DD29BC[i];
}
// ?rva0056EF65@Rva0056EF65@@QAEPAU1@PAX0@Z @0x0056EF65 141B chain from 0x0056ECDA
struct Rva0056EF65
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056EF65 *rva0056EF65(void *a1, void *a2);
};
Rva0056EF65 *Rva0056EF65::rva0056EF65(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056ECDAPick(&p, &q);
	m_00 = p;
	m_04 = 0x18245AC1;
	m_08 = 0x18245AC5;
	m_0c = 0x0C24180A;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x18245AC1;
	m_04 = e;
	e *= b;
	e ^= 0x18245AC5;
	m_08 = e;
	e *= b;
	e ^= 0x0C24180A;
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
// ?Rva0056ED34Pick@@YAXPAH0@Z @0x0056ED34 44B gap between 0x0056ECDA and 0x0056EDBA
// g_Va00DD29FC: matched references place it at VA 0xdd29fc (retail .data contents).
int g_Va00DD29FC[4] = {
	0x5539048a, -660880950, -1441106294, -1412547510
};
// g_Va00DD2A0C: matched references place it at VA 0xdd2a0c (retail .data contents).
int g_Va00DD2A0C[4] = {
	0x119148b, -996441141, -1575606645, -203264949
};
void __cdecl Rva0056ED34Pick(int *out1, int *out2);
void __cdecl Rva0056ED34Pick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		mov t, esp
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD2A0C[i];
	*out2 = g_Va00DD29FC[i];
}
// ?Rva0056ED60Pick@@YAXPAH0@Z @0x0056ED60 44B gap between 0x0056ED34 and 0x0056EDBA
// g_Va00DD2A1C: matched references place it at VA 0xdd2a1c (retail .data contents).
int g_Va00DD2A1C[4] = {
	-1869448881, -384734897, -1223762673, 0x1d80d14f
};
// g_Va00DD2A2C: matched references place it at VA 0xdd2a2c (retail .data contents).
int g_Va00DD2A2C[4] = {
	-860474549, -451861685, -1548820725, 0x5d049b4b
};
void __cdecl Rva0056ED60Pick(int *out1, int *out2);
void __cdecl Rva0056ED60Pick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		mov t, esp
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD2A2C[i];
	*out2 = g_Va00DD2A1C[i];
}
// ?Rva0056ED8CPick@@YAXPAH0@Z @0x0056ED8C 46B gap rdtsc pick
// g_Va00DD2A3C: matched references place it at VA 0xdd2a3c (retail .data contents).
int g_Va00DD2A3C[4] = {
	-277978033, -1869448881, -384734897, -1223762673
};
// g_Va00DD2A4C: matched references place it at VA 0xdd2a4c (retail .data contents).
int g_Va00DD2A4C[4] = {
	-203264949, -860474549, -451861685, -1548820725
};
void __cdecl Rva0056ED8CPick(int *out1, int *out2);
void __cdecl Rva0056ED8CPick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		rdtsc
		mov t, eax
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD2A4C[i];
	*out2 = g_Va00DD2A3C[i];
}
// ?Rva0056EDE8Pick@@YAXPAH0@Z @0x0056EDE8 46B gap rdtsc pick
// g_Va00DD2A7C: matched references place it at VA 0xdd2a7c (retail .data contents).
int g_Va00DD2A7C[4] = {
	0x34cbf74f, -273905649, 0x9e6cf, -1157274225
};
// g_Va00DD2A8C: matched references place it at VA 0xdd2a8c (retail .data contents).
int g_Va00DD2A8C[4] = {
	0x2443b54b, -1291022325, 0x48deecb, -1482610805
};
void __cdecl Rva0056EDE8Pick(int *out1, int *out2);
void __cdecl Rva0056EDE8Pick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		rdtsc
		mov t, eax
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD2A8C[i];
	*out2 = g_Va00DD2A7C[i];
}
// ?rva0056F2A5@Rva0056F2A5@@QAEPAU1@PAX0@Z @0x0056F2A5 134B
// Chain from 0x0056EDBA via Rva0056EDBAPick sibling of Rva0056EF65.
// Evidence: same 8-int obfuscated init shape as 0x0056EF65 with two constants 0x0C840885 0x0C840881.
struct Rva0056F2A5
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056F2A5 *rva0056F2A5(void *a1, void *a2);
};
Rva0056F2A5 *Rva0056F2A5::rva0056F2A5(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056EDBAPick(&p, &q);
	m_00 = p;
	m_04 = 0x0C840885;
	m_08 = 0x0C840881;
	m_0c = 0x0C840885;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x0C840885;
	m_04 = e;
	e *= b;
	e ^= 0x0C840881;
	m_08 = e;
	e *= b;
	e ^= 0x0C840885;
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
// ?rva0056F21F@Rva0056F21F@@QAEPAU1@PAX0@Z @0x0056F21F 134B
// Chain from 0x0056ED8C via Rva0056ED8CPick sibling of 0x0056F2A5.
// Evidence: same 8-int obfuscated init shape with two constants 0x18245AC1 0x18245AC5.
struct Rva0056F21F
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056F21F *rva0056F21F(void *a1, void *a2);
};
Rva0056F21F *Rva0056F21F::rva0056F21F(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056ED8CPick(&p, &q);
	m_00 = p;
	m_04 = 0x18245AC1;
	m_08 = 0x18245AC5;
	m_0c = 0x18245AC1;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x18245AC1;
	m_04 = e;
	e *= b;
	e ^= 0x18245AC5;
	m_08 = e;
	e *= b;
	e ^= 0x18245AC1;
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
// ?rva0056F10C@Rva0056F10C@@QAEPAU1@PAX0@Z @0x0056F10C 134B
// Chain from 0x0056ED34 via Rva0056ED34Pick sibling of 0x0056F21F.
// Evidence: same 8-int obfuscated init shape with two constants 0x0C841840 0x14AC1A82.
struct Rva0056F10C
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056F10C *rva0056F10C(void *a1, void *a2);
};
Rva0056F10C *Rva0056F10C::rva0056F10C(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056ED34Pick(&p, &q);
	m_00 = p;
	m_04 = 0x0C841840;
	m_08 = 0x14AC1A82;
	m_0c = 0x0C841840;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x0C841840;
	m_04 = e;
	e *= b;
	e ^= 0x14AC1A82;
	m_08 = e;
	e *= b;
	e ^= 0x0C841840;
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
// ?rva0056F32B@Rva0056F32B@@QAEPAU1@PAX0@Z @0x0056F32B 134B
// Chain from 0x0056EDBA via Rva0056EDBAPick sibling of 0x0056F10C.
// Evidence: same 8-int obfuscated init shape with two constants 0x0C840885 0x100C1887.
struct Rva0056F32B
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056F32B *rva0056F32B(void *a1, void *a2);
};
Rva0056F32B *Rva0056F32B::rva0056F32B(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056EDBAPick(&p, &q);
	m_00 = p;
	m_04 = 0x0C840885;
	m_08 = 0x100C1887;
	m_0c = 0x0C840885;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x0C840885;
	m_04 = e;
	e *= b;
	e ^= 0x100C1887;
	m_08 = e;
	e *= b;
	e ^= 0x0C840885;
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
// ?rva0056F192@Rva0056F192@@QAEPAU1@PAX0@Z @0x0056F192 141B
// Chain from 0x0056ED60 via Rva0056ED60Pick sibling of 0x0056EF65.
// Evidence: same 8-int obfuscated init shape with three constants 0x18245AC1 0x18245AC5 0x488C00C6.
struct Rva0056F192
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056F192 *rva0056F192(void *a1, void *a2);
};
Rva0056F192 *Rva0056F192::rva0056F192(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056ED60Pick(&p, &q);
	m_00 = p;
	m_04 = 0x18245AC1;
	m_08 = 0x18245AC5;
	m_0c = 0x488C00C6;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x18245AC1;
	m_04 = e;
	e *= b;
	e ^= 0x18245AC5;
	m_08 = e;
	e *= b;
	e ^= 0x488C00C6;
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
// ?rva0056F3B1@Rva0056F3B1@@QAEPAU1@PAX0@Z @0x0056F3B1 141B
// Chain from 0x0056EDE8 via Rva0056EDE8Pick sibling of 0x0056F192.
// Evidence: same 8-int obfuscated init shape with three constants 0x18245AC1 0x18245AC5 0x5C80520D.
struct Rva0056F3B1
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	Rva0056F3B1 *rva0056F3B1(void *a1, void *a2);
};
Rva0056F3B1 *Rva0056F3B1::rva0056F3B1(void *a1, void *a2)
{
	int p;
	int q;
	Rva0056EDE8Pick(&p, &q);
	m_00 = p;
	m_04 = 0x18245AC1;
	m_08 = 0x18245AC5;
	m_0c = 0x5C80520D;
	m_10 = *(int *)a1;
	m_14 = *(int *)a2;
	int b = q;
	int e = b;
	e *= b;
	e ^= 0x18245AC1;
	m_04 = e;
	e *= b;
	e ^= 0x18245AC5;
	m_08 = e;
	e *= b;
	e ^= 0x5C80520D;
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
