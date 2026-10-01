// ?rva0044EDA6@Rva0044EDA6@@QAE_NH@Z
// partial score=0.93 date=2026-10-01
// ?rva0044EDA6@Rva0044EDA6@@QAE_NH@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
//
// ?rva0044EDA6@Rva0044EDA6@@QAE_NH@Z @0x0044EDA6 97B:
// Outer check: null-checked member at -0x1C, rowed validator at -0x20 via
// ?rva0044E7A8@Rva0044E7A8@@QAE_NH@Z (arg forwarded), Overridable final
// +0x1C must not be 0x27/0x28, else virtual slot 0x114 vs 0x70 unsigned
// compare on member at -0x18 plus 0x250. Callers at 7 sites.
// ?rva0044EDA6@Rva0044EDA6@@QAE_NH@Z present-unmatched
class Overridable
{
public:
	const Overridable *friend_getFinalOverride() const;
	char m_pad00[0x1C];
	int m_val1C;
};

class Rva0044E7A8
{
public:
	bool rva0044E7A8(int arg);
};

class Rva0044EDA6Virt
{
public:
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
	virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
	virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual unsigned int s28();
	virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32();
	virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
	virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
	virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
	virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48();
	virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52();
	virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
	virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
	virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
	virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68();
	virtual unsigned int s69(int v);
};

struct Rva0044EDA6Outer
{
	char m_pad00[0x38];
	Overridable *m_over38; // +0x38
};

class Rva0044EDA6
{
public:
	bool rva0044EDA6(int arg);
};

bool Rva0044EDA6::rva0044EDA6(int arg)
{
	char *base = (char *)this;
	void *p = *(void **)(base - 0x1C);
	if (p == 0 || !((Rva0044E7A8 *)(base - 0x20))->rva0044E7A8(arg))
		return false;
	const Overridable *fin = ((Rva0044EDA6Outer *)p)->m_over38->friend_getFinalOverride();
	int v = fin->m_val1C;
	if (v != 0x28 && v != 0x27)
		return true;
	Rva0044EDA6Virt *virt = *(Rva0044EDA6Virt **)(*(char **)(base - 0x18) + 0x250);
	if (virt == 0)
		return false;
	unsigned int a = virt->s69(0);
	unsigned int b = virt->s28();
	if (a >= b)
		return false;
	return true;
}
