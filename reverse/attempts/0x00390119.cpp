// ??0PhysicsBehaviorModuleData@@QAE@XZ
// partial score=0.99 date=2026-09-29
// ??0PhysicsBehaviorModuleData@@QAE@XZ
// partial score=0.99 date=2026-09-29
// cl: /O1 /arch:SSE /GX /DNDEBUG /MD
// BANKED PARTIAL 2026-09-29 (score 0.99): 176/176B, 38/38 insns, stores exact.
// SOLE WALL: retail hoists 4 float-pool loads (1.3/.33/.66/5.0) to top into
// xmm0-xmm3 plus xor-ecx before first store; this TU hoists 3 (1.3/0.66/5.0)
// with 0.33 on demand in xmm0 (reused), xor after [8] not before, 1.0 late.
// PROVEN 2026-09-29 (6-variant box: baseline grouped, interleave, retailorder,
// barrier, volatile, hybrid): retail store order (1.3x4, 0, bools, vtable,
// 0.33/0.66 pair, 2, 5.0, 0.33/0.66 pairs, 1.0, G-triple) plus marking EVERY
// scalar member volatile pins all 25 stores exact (shape-lever guide 0x009A45A0
// recipe); interleave alone hoists 4 but scrambles stores; barrier blocks all
// hoisting (1 left); hybrid re-scrambles stores. Old 13-variant refutes still
// hold (/O2 /Ot /Ob2 /Og /Oy /Oi /G5 /G6 /G7 /GB /arch:SSE2 /Op /Os /Ob0,
// init-list, float locals, multi-declarator).
// DIAGNOSIS: overlapping 0.33/0.66 live ranges need 4 regs at top, but 0.33
// (3 uses, earliest first-use) stays on demand while 0.66/5.0 hoist; volatile
// stores pin order yet still allow 3 hoists, so 0.33 needs its own lever.
// Missing: construct keeping 0.33 live from top without stack traffic.
// LAYOUT (retail-proven, all 25 stores exact incl. frame/epilogue/G-triple
// with 3x reload + add-ecx-ecx and gate-filled pool/G/vtable addresses):
// INI table 0x00C19DE8 gives every member name/offset; factory 0x24E774
// news 0x5C; float bits read from image (1.3f/0.33f/0.66f/5.0f/1.0f exact);
// G = extern const int at VA 0xDBA4E4 (=5); +0x28 unnamed (5.0, no INI
// field); +0x04 untouched gap (Topple/Tornado precedent); vtable linkable
// extern array g_00C4ED70 (byte-identical, hook-clean).
// NEXT: force 0.33 hoist to xmm1 (shifting 0.66 to xmm2, 5.0 to xmm3) plus xor
// before [8] and 1.0 load at 0x59; try tag-volatile read or const-global angle.
// t=35 model=muse-spark score=0.99 stash=reverse/attempts/0x00390119.cpp

//
// ??0PhysicsBehaviorModuleData@@QAE@XZ, retail 0x00390119, 176 bytes.
// Bounce/tumble behavior ModuleData: the own INI table at 0x00C19DE8
// (landed buildFieldParse row) proves every member below -- FirstHeight at
// +0x08, SecondHeight at +0x0C, First/SecondPercentIndent at +0x10/+0x14,
// ShockStunnedTimeLow/High/StandingTime at +0x18/+0x1C/+0x20, BounceCount
// at +0x24, BounceFirst/SecondHeight at +0x2C/+0x30,
// BounceFirst/SecondPercentIndent at +0x34/+0x38, CurveFlattenMinDist at
// +0x3C, TumbleRandomly at +0x40, OrientToFlightPath at +0x41,
// IgnoreTerrainHeight at +0x42, First/SecondPercentHeight at +0x44/+0x48,
// GravityMult at +0x4C, GroundHitFX/GroundBounceFX at +0x50/+0x54,
// AllowBouncing at +0x58 and KillWhenRestingOnGround at +0x59. The factory
// at 0x0024E774 (landed PhysicsBehaviorModuleDataFriendNew.cpp) news 0x5C
// and calls this ctor as its sole raw caller, fixing the class size.
// BFME2 deltas vs the ZH PhysicsUpdate donor: all height defaults are 1.3,
// all percent defaults are 0.33/0.66, shock times come from the 0x00DBA4E4
// pool (5/10/5) and the +0x28 slot (5.0, no INI field) is left unnamed.
// Body order follows retail stores (1.3x4, 0, bools, vtable, 0.33/0.66,
// 2, 5.0, 0.33/0.66, 0.33/0.66, 1.0, G-triple); volatile members pin it.

extern const int g_Va00DBA4E4;
extern const void *const g_00C4ED70[];

class UpdateModuleData
{
public:
	UpdateModuleData() {}
	~UpdateModuleData();

private:
};

class PhysicsBehaviorModuleData : public UpdateModuleData
{
public:
	PhysicsBehaviorModuleData();

private:
	// +0x00 vtable (body store in the retail-observed position).
	const void *volatile m_vtable;
	// +0x04 unstored gap.
	unsigned int volatile m_unused04;
	// +0x08 FirstHeight (table offset).
	float volatile m_firstHeight;
	// +0x0C SecondHeight (table offset).
	float volatile m_secondHeight;
	// +0x10 FirstPercentIndent (table offset).
	float volatile m_firstPercentIndent;
	// +0x14 SecondPercentIndent (table offset).
	float volatile m_secondPercentIndent;
	// +0x18 ShockStunnedTimeLow (table offset).
	int volatile m_shockStunnedTimeLow;
	// +0x1C ShockStunnedTimeHigh (table offset).
	int volatile m_shockStunnedTimeHigh;
	// +0x20 ShockStandingTime (table offset).
	int volatile m_shockStandingTime;
	// +0x24 BounceCount (table offset).
	int volatile m_bounceCount;
	// +0x28 unnamed slot (no INI field, retail default 5.0).
	float volatile m_unk28;
	// +0x2C BounceFirstHeight (table offset).
	float volatile m_bounceFirstHeight;
	// +0x30 BounceSecondHeight (table offset).
	float volatile m_bounceSecondHeight;
	// +0x34 BounceFirstPercentIndent (table offset).
	float volatile m_bounceFirstPercentIndent;
	// +0x38 BounceSecondPercentIndent (table offset).
	float volatile m_bounceSecondPercentIndent;
	// +0x3C CurveFlattenMinDist (table offset).
	float volatile m_curveFlattenMinDist;
	// +0x40 TumbleRandomly (table offset).
	bool volatile m_tumbleRandomly;
	// +0x41 OrientToFlightPath (table offset).
	bool volatile m_orientToFlightPath;
	// +0x42 IgnoreTerrainHeight (table offset).
	bool volatile m_ignoreTerrainHeight;
	// +0x44 FirstPercentHeight (table offset).
	float volatile m_firstPercentHeight;
	// +0x48 SecondPercentHeight (table offset).
	float volatile m_secondPercentHeight;
	// +0x4C GravityMult (table offset).
	float volatile m_gravityMult;
	// +0x50 GroundHitFX (table offset).
	void *volatile m_groundHitFX;
	// +0x54 GroundBounceFX (table offset).
	void *volatile m_groundBounceFX;
	// +0x58 AllowBouncing (table offset).
	bool volatile m_allowBouncing;
	// +0x59 KillWhenRestingOnGround (table offset).
	bool volatile m_killWhenRestingOnGround;
};

// ??0PhysicsBehaviorModuleData@@QAE@XZ @0x00390119
PhysicsBehaviorModuleData::PhysicsBehaviorModuleData()
{
	m_firstHeight = 1.3f;
	m_secondHeight = 1.3f;
	m_bounceFirstHeight = 1.3f;
	m_bounceSecondHeight = 1.3f;
	m_curveFlattenMinDist = 0.0f;
	m_tumbleRandomly = false;
	m_orientToFlightPath = false;
	m_ignoreTerrainHeight = false;
	m_groundHitFX = 0;
	m_groundBounceFX = 0;
	m_allowBouncing = false;
	m_killWhenRestingOnGround = false;
	m_vtable = g_00C4ED70;
	m_firstPercentIndent = 0.33f;
	m_secondPercentIndent = 0.66f;
	m_bounceCount = 2;
	m_unk28 = 5.0f;
	m_bounceFirstPercentIndent = 0.33f;
	m_bounceSecondPercentIndent = 0.66f;
	m_firstPercentHeight = 0.33f;
	m_secondPercentHeight = 0.66f;
	m_gravityMult = 1.0f;
	m_shockStunnedTimeLow = g_Va00DBA4E4;
	m_shockStunnedTimeHigh = g_Va00DBA4E4 + g_Va00DBA4E4;
	m_shockStandingTime = g_Va00DBA4E4;
}
