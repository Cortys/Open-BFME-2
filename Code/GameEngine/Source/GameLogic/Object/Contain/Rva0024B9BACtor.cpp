// cl: /O1 /MD /DNDEBUG
//
// ??0Rva0024B9BA@@QAE@XZ @0x0024B9BA 18B.
// Frameless derived ctor over rowed HordeContainModuleData base 0x00475C9A;
// installs vtable 0x00C465F8 explicitly (same VA as AODHordeContainModuleData
// vtable; Defector law: no virtuals so compiler emits no store of its own).
// Chain lane: calls 0x00475C9A landed this session. Sits between
// HorseHordeContain (0x0024B97F) and HordeTransportContain (0x0024B9CC)
// instance factories; honest Rva name since AOD default ctor already rowed
// at 0x0047A2E1.

class HordeContainModuleData
{
public:
	HordeContainModuleData();
};

class Rva0024B9BA : public HordeContainModuleData
{
public:
	Rva0024B9BA();
};

Rva0024B9BA::Rva0024B9BA()
	: HordeContainModuleData()
{
	*(unsigned int *)this = 0x00C465F8;
}
