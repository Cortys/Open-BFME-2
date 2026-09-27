// cl: /O1 /DNDEBUG /MD
//
// ?rva004C8DE2@HordeDispatchSpecialPower@@MAEHXZ @0x004C8DE2 96B.
// vslot 20 (offset 0x50) of vtable 0x0085E88C (class of
// ??0HordeDispatchSpecialPower@@QAE@PAVThing@@PBVModuleData@@@Z in
// SupplyTruckAIUpdateCtor.cpp). No donors (BFME1 has no HordeDispatch).
// No callers. Global at 0x00DFE754 (4B before TheGlobalData 0x00DFE758).
// Callees rowed via Rva00758210Thunks.cpp (0x00758230 WindowManager::set
// and 0x00758240 Owner::apply). Secondary this at object+0x10 gives
// m_object at -8 and m_moduleData at -0xC with bools at +0x14/+0x15
// (object+0x24/+0x25 like CritterEmitterUpdate m_24/m_25). Returns
// [m_moduleData+0x20] on the set path else 1. Recipe: ternary plus70
// via neg-sbb-and under /O1 with xor-inc for return 1.

struct Rva009A29A0Window;
class Rva00758230
{
public:
	void rva00758230(Rva009A29A0Window *window);
};

class Rva009A36F0Param;
class Rva00758240
{
public:
	void rva00758240(Rva009A36F0Param *param);
};

#define TheThunk230 (*(Rva00758230 **)0x00DFE754)
#define TheThunk240 (*(Rva00758240 **)0x00DFE754)

class HordeDispatchSpecialPower
{
protected:
	virtual int rva004C8DE2();
};

int HordeDispatchSpecialPower::rva004C8DE2()
{
	char *self = (char *)this;
	if (*(self + 0x14))
	{
		Rva00758240 *mgr = TheThunk240;
		if (mgr)
		{
			char *obj = *(char **)(self - 8);
			char *arg = obj ? obj + 0x70 : 0;
			mgr->rva00758240((Rva009A36F0Param *)arg);
		}
		char *d = *(char **)(self - 0xc);
		*(self + 0x14) = 0;
		*(self + 0x15) = 0;
		return *(int *)(d + 0x20);
	}
	else
	{
		if (*(self + 0x15))
			return 1;
		Rva00758230 *mgr = TheThunk230;
		if (!mgr)
			return 1;
		char *obj = *(char **)(self - 8);
		char *arg = obj ? obj + 0x70 : 0;
		mgr->rva00758230((Rva009A29A0Window *)arg);
		return 1;
	}
}
