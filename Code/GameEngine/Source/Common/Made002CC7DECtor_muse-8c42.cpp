// cl: /O1 /DNDEBUG /MD
// ??0Made002CC7DE@@QAE@XZ @0x0050968B 32B
// Derived of Rva00507823 base 0x0050775B (vtable 0x00864010) overwrites vtable 0x00864588
// zeroes +0x128/+0x12C. Caller parseWeaponOCLNugget 0x002CC803. Sibling Made002CC5E1
// (DamageNugget 0x00507C2D) proves base size 0x128 and derived layout.
class Rva00507823
{
public:
	Rva00507823();
private:
	unsigned char m_pad[0x128];
};

class Made002CC7DE : public Rva00507823
{
public:
	Made002CC7DE();
private:
	int m_128; // +0x128
	int m_12C; // +0x12C
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

Made002CC7DE::Made002CC7DE()
{
	*(unsigned int *)this = 0x00C64588;
	_ReadWriteBarrier();
	m_12C = 0;
	m_128 = 0;
}
