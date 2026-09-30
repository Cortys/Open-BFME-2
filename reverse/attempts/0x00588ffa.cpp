// ??0Rva00588FFA@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.93 date=2026-09-30
// ??0Rva00588FFA@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
//
// ??0PillageModule@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x00484F0D, 46 bytes.
// Pillage behavior ctor over the pinned Rva00588FFA base (sole-caller
// opaque (Thing*,ModuleData*) base over rowed BehaviorModule 0x253330,
// vtable 0x00C700C4): and-zeroes the unknown member at +0x18, then
// installs vtable 0x00C4A51C at +0 and rewrites the folded slots at +0xC
// (0x00C70008, shared with the base) and +0x10 (0x00C4A514). All three
// immediates are link-time constants kept literal. Pool key 0x484F76;
// behavior instance factory 0x24C77B news 0x1C (sole caller). Row
// supersedes the ctor pin.

class Thing;
class ModuleData;

extern const void *const g_008700C4[];
extern const void *const g_00870008[];
extern const void *const g_0084A50C[];
extern const void *const g_0086FFFC[];

class BehaviorModule
{
public:
	BehaviorModule(Thing *thing, const ModuleData *data);
private:
	unsigned char m_pad[0x10];
};

class Rva00588FFA : public BehaviorModule
{
public:
	Rva00588FFA(Thing *thing, const ModuleData *data);

private:
	const void *m_10; // +0x10, init g_0086FFFC then overwritten g_0084A50C
	int m_14; // +0x14, and-zeroed
};

class PillageModule : public Rva00588FFA
{
public:
	PillageModule(Thing *thing, const ModuleData *data);

private:
	int m_bfme18; // +0x18 unknown member, and-zeroed
};

// ??0PillageModule@@QAE@PAVThing@@PBVModuleData@@@Z @0x484F0D
PillageModule::PillageModule(Thing *thing, const ModuleData *data)
	: Rva00588FFA(thing, data)
{
	*(unsigned int *)this = 0x00C4A51C;
	*(unsigned int *)((char *)this + 0x0C) = 0x00C70008;
	*(unsigned int *)((char *)this + 0x10) = 0x00C4A514;
	m_bfme18 = 0;
}

// ??0Rva00588FFA@@QAE@PAVThing@@PBVModuleData@@@Z present-unmatched
Rva00588FFA::Rva00588FFA(Thing *thing, const ModuleData *data)
	: BehaviorModule(thing, data)
{
	*(volatile unsigned *)&m_10 = (unsigned)g_0086FFFC;
	m_14 = 0;
	*(const void **)this = g_008700C4;
	*(const void **)((char *)this + 0x0C) = g_00870008;
	*(const void **)((char *)this + 0x10) = g_0084A50C;
}
