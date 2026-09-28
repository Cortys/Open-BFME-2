// ?rva006C1AA0@Rva006C1F60@@QAEPAUSlot64@@I@Z
// partial score=0.9 date=2026-09-27
// ?rva006C1AA0@Rva006C1F60@@QAEPAUSlot64@@I@Z
// partial score=0.90 date=2026-09-27
// ?rva006C1AA0@Rva006C1F60@@QAEPAUSlot64@@I@Z @ 0x006C1AA0 168B chain of 0x00030DF0 Release
// Array-slot duplicator for the lock-guarded pool: copies template fields
// +0x570/+0x574/+0x578/+0x57c/+0x580/+0x584/+0x5a0/+0x5a4 from slot 0 to slot
// index with stride 64 then returns &slot[index]. Evidence: calls AddRef
// 0x00030DD0 Release 0x00030DF0 rowed; same +0x4e4 lock layout as setter
// 0x006C1EB0 in same TU Rva006C1F60.cpp; shl 6 for *64 lea edx,[eax+0x16] for
// +0x580=+22*64 reproduced faithfully; caller at 0x0004883C. Honest
// address-derived method of Rva006C1F60. Current body is 169B/46ins vs 168B/46ins
// with only index reg swap (eax vs ecx) and add scheduling left; see align_diff.
struct Rva00030DD0Lock;
int Rva00030DD0AddRef(Rva00030DD0Lock *lock);
int Rva00030DF0Release(Rva00030DD0Lock *lock);
struct Slot64 {
	int f0,f1,f2,f3,f4,f5;
	unsigned char pad1[24];
	int f12,f13;
	unsigned char pad2[8];
};
class Rva006C1F60
{
public:
	Slot64 *rva006C1AA0(unsigned int index);
private:
	unsigned char m_pad0[0x4e4];
	Rva00030DD0Lock *m_lock;
	unsigned char m_pad1[0x514 - 0x4e4 - 4];
	int m_flags;
	unsigned char m_pad2[0x534 - 0x514 - 4];
	float m_scale;
	unsigned int m_min;
	unsigned int m_max;
	unsigned char m_pad3[0x570 - 0x540];
	Slot64 m_slots[16];
};
Slot64 *Rva006C1F60::rva006C1AA0(unsigned int index)
{
	Rva00030DD0Lock *lock = m_lock;
	if (lock != 0)
		Rva00030DD0AddRef(lock);
	if (index != 0) {
		m_slots[index].f0 = m_slots[0].f0;
		m_slots[index].f1 = m_slots[0].f1;
		m_slots[index].f2 = m_slots[0].f2;
		m_slots[index].f3 = m_slots[0].f3;
		m_slots[index].f4 = m_slots[0].f4;
		m_slots[index].f5 = m_slots[0].f5;
		m_slots[index].f12 = m_slots[0].f12;
		m_slots[index].f13 = m_slots[0].f13;
	}
	Slot64 *ret = &m_slots[index];
	if (lock != 0)
		Rva00030DF0Release(lock);
	return ret;
}
