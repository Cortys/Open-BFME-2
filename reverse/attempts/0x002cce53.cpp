// ?rva002CCE53@Weapon@@QBEMXZ
// partial score=0.97 date=2026-10-04
// ?rva002CCE53@Weapon@@QBEMXZ @0x002CCE53 128B evidence: Weapon neighbours
// prev deleting dtor next getStatus plus computeStatus row; float div via
// BfmeZeroRange and 1.0 plus 2pow32 fixup; Rva000B2EB5 precedent flags and externs
//
// Dispatch chain transcribed from the retail test sequence, which keeps BOTH
// the s == 1 and the s <= 1 tests (retail emits `cmp eax,1 / je zero` followed
// by `jle zero`); spelling only `s == OUT_OF_AMMO` lets MSVC7.1 fold the pair
// and drop the chain to six tests. The s == 5 test is spelled as an equality
// that jumps to the shared frame tail so s == 5 falls through, matching
// retail's `cmp eax,5 / jne zero`.
//
// Residual (21 diff lines, size exact at 128B): MSVC lays the ratio block as
// the innermost fallthrough, so `done >= total` lowers to `jl` where retail
// emits `jae`, and retail's `test eax,eax` plus `jmp` around the x87 epilogue
// are reordered. Block placement is a codegen decision, not a spelling one --
// ret_zero/ret_one label order, an explicit ratio block, and the negated
// `!(done < total)` form were all tried and leave the layout unchanged.
// cl: /O1 /DNDEBUG /MD
extern const float BfmeZeroRange;
extern float g_Va00BBB8D8;
extern float g_00BC26EC;
typedef bool Bool;
enum WeaponStatus
{
	READY_TO_FIRE,
	OUT_OF_AMMO,
	BETWEEN_FIRING_SHOTS,
	RELOADING_CLIP,
	PRE_ATTACK,
	WEAPON_STATUS_5
};
class ObjectFilter
{
public:
	bool isValid() const;
};
class WeaponTemplate
{
public:
	char m_pad00[0x78];
	int m_flag78;
	char m_pad7C[0x120 - 0x78 - 4];
	ObjectFilter m_ammo;
};
struct GameLogicFrame
{
	char m_pad00[0x40];
	unsigned int m_frame;
};
class GameLogic
{
public:
	char m_pad00[0x40];
	unsigned int m_frame;
};
extern GameLogic *TheGameLogic;
class Weapon
{
public:
	float rva002CCE53() const;
	WeaponStatus computeStatus(bool *cacheable) const;
private:
	char m_pad00[4];
	WeaponTemplate *m_template;
	char m_pad08[8];
	WeaponStatus m_status;
	int m_pad14;
	unsigned int m_frame18;
	unsigned int m_frame1C;
	unsigned int m_frame20;
	unsigned int m_frame24;
	unsigned int m_frame28;
};
// ?rva002CCE53@Weapon@@QBEMXZ present-unmatched
float Weapon::rva002CCE53() const
{
	WeaponStatus s = computeStatus(0);
	if (s == READY_TO_FIRE)
		goto ret_one;
	if (s == OUT_OF_AMMO)
		goto ret_zero_a;
	if (s <= OUT_OF_AMMO)
		goto ret_zero;
	if (s <= RELOADING_CLIP)
		goto frame;
	if (s == PRE_ATTACK)
		goto ret_zero;
	if (s == WEAPON_STATUS_5)
		goto frame;
	goto ret_zero;
frame:
	{
		unsigned int cur = TheGameLogic->m_frame;
		if (cur >= m_frame18)
			goto ret_one;
		unsigned int total = m_frame18 - m_frame28;
		if (total == 0)
			goto ret_one;
		unsigned int done = total - m_frame18 + cur;
		if (done >= total)
			goto ret_one;
		return (float)done / (float)total;
	}
ret_zero_a:
	return BfmeZeroRange;
ret_zero:
	return BfmeZeroRange;
ret_one:
	return g_Va00BBB8D8;
}