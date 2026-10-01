// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva00589135@WeaponModeSpecialPowerUpdateBase@@QAEXH@Z, retail 0x00589135 54B. Vslot 10 of 0x00870108 via rowed BitFlags 0x0023C58B any plus slot0 virtual on this-4 with 5 args. Donor WeaponModeSpecialPowerUpdateBaseCtor plus open-bfme-1 WeaponModeSpecialPowerUpdateCtorThunk.
template<int N>
class BitFlags
{
public:
	bool any() const;
};

struct VirtBase
{
	virtual void vf(void *a, int b, int c, int d, int e);
};

class WeaponModeSpecialPowerUpdateBase
{
public:
	void rva00589135(int arg);
	void rva0058916B(int arg1, int arg2);
private:
	unsigned char m_pad00[8];
	int m_08;
};

void WeaponModeSpecialPowerUpdateBase::rva00589135(int arg)
{
	if (m_08 > 0)
		return;
	void *p1 = *(void *const *)((const char *)this - 0x1c);
	BitFlags<11> *flags = (BitFlags<11> *)((char *)p1 + 0x1c8);
	if (flags->any())
		return;
	void *p2 = *(void *const *)((const char *)this - 0x20);
	VirtBase *vb = (VirtBase *)((char *)this - 4);
	vb->vf(*(void **)((char *)p2 + 8), 0, 0, arg, 0);
}

// ?rva0058916B@WeaponModeSpecialPowerUpdateBase@@QAEXHH@Z, retail 0x0058916B 56B. Vslot 11 of 0x00870108 via rowed BitFlags 0x0023C58B any plus slot0 virtual on this-4 with 5 args. Same pattern as vslot 10 0x00589135 with two int args.
void WeaponModeSpecialPowerUpdateBase::rva0058916B(int arg1, int arg2)
{
	if (m_08 > 0)
		return;
	void *p1 = *(void *const *)((const char *)this - 0x1c);
	BitFlags<11> *flags = (BitFlags<11> *)((char *)p1 + 0x1c8);
	if (flags->any())
		return;
	void *p2 = *(void *const *)((const char *)this - 0x20);
	VirtBase *vb = (VirtBase *)((char *)this - 4);
	vb->vf(*(void **)((char *)p2 + 8), arg1, 0, arg2, 0);
}
