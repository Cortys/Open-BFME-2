// ?Rva00204032Update@@YAXXZ
// partial score=0.97 date=2026-09-28
// ?Rva00204032Update@@YAXXZ
// partial score=0.97 date=2026-09-28
// cl: /O1
//
// ?Rva00204032Update@@YAXXZ @0x00204032 98B: free function lazily creating the
// 0xC debug-window holder at 0x009FE154 (vtable 0x007E39F4, +4=0, +8=0) then
// driving host virtuals slot3(holder), slot2(other+0x50), tail slot4. Evidence:
// rowed operator new 0x0002FDA0; ScriptEngine_dtor names 0x009FE154 the
// debug-window holder; unblocks 0x0020D065.

class DebugHolder
{
public:
	virtual void slot0();
	int m_value; // +0x04
	bool m_flag; // +0x08
	char m_pad[3]; // +0x09..0x0B keeps size 0x0C

	DebugHolder() : m_value(0), m_flag(false) {}
};

class Host
{
public:
	virtual void slot0();
	virtual void slot1();
	virtual void slot2(int value);
	virtual void slot3(DebugHolder *holder);
	virtual void slot4();
};

extern Host *TheHost;
extern DebugHolder *TheHolder;

struct Other
{
	char m_pad[0x50];
	int m_value; // +0x50
};

#define TheOther (*(Other **)0x00DFDD04)

void Rva00204032Update()
{
	if (!TheHost)
		return;
	if (!TheHolder) {
		DebugHolder *holder = new DebugHolder;
		TheHolder = holder;
		TheHost->slot3(holder);
	}
	TheHost->slot2(TheOther->m_value);
	return TheHost->slot4();
}
