// ?Rva003BD679Play@@YGXPAVParameter@@PAVOpaqueRefCounted@@@Z
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /ICode/GameEngine/Include /O1 /EHsc /MD /DNDEBUG
// ?Rva003BD679Play@@YGXPAVParameter@@PAVOpaqueRefCounted@@@Z @0x003BD679 182B.
// Script action audio event: TerrainLogic slot 0x88 resolves position holder
// from second arg, Audio slot 0x12c fills Opaque ref from first arg, then
// BfmeAudioEventPrefix136 from Opaque+pos+0 with PlayerList id at +0x6C,
// posted via addAudioEvent slot 0x64. Callers: dispatch at 0x003CB173.
// Callees rowed: ctor 0x002D982A, set 0x0033F15D, dtor 0x002D9A43,
// Release_Ref 0x00050ED3. Evidence: immediates TheTerrainLogic TheAudio
// ThePlayerList, ret 8 stdcall, chain from 0x002D982A.
#include "Common/BfmeAudioEventPrefix136.h"

class Parameter;

class TerrainPosHolder
{
public:
	char m_pad[12];
	BfmeEventPositionView m_view;
};

class TerrainLogic
{
public:
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04();
	virtual void s05(); virtual void s06(); virtual void s07(); virtual void s08(); virtual void s09();
	virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
	virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
	virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
	virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
	virtual TerrainPosHolder *slot34(void *arg);
};
extern TerrainLogic *TheTerrainLogic;

class AudioManager
{
public:
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04();
	virtual void s05(); virtual void s06(); virtual void s07(); virtual void s08(); virtual void s09();
	virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
	virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
	virtual void addAudioEvent(const BfmeAudioEventPrefix136 *ev);
	virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30();
	virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
	virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
	virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
	virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
	virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
	virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
	virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
	virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70();
	virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
	virtual void slot75(OpaqueRefCounted **out, Parameter *in);
};
extern AudioManager *TheAudio;

class PlayerListInner
{
public:
	char m_pad[0x54];
	int m_val54;
};

class PlayerList
{
public:
	char m_pad[0x10];
	PlayerListInner *m_p10;
};
extern PlayerList *ThePlayerList;

class Rva0033F15DDwordSlot
{
public:
	void set(int value);
};

// ?Rva003BD679Play@@YGXPAVParameter@@PAVOpaqueRefCounted@@@Z present-unmatched
void __stdcall Rva003BD679Play(Parameter *p1, OpaqueRefCounted *p2)
{
	TerrainPosHolder *holder = TheTerrainLogic->slot34(p2);
	if (holder == 0)
		return;
	TheAudio->slot75(&p2, p1);
	if (p2 == 0)
		return;
	{
		BfmeAudioEventPrefix136 evt(*(const OpaqueRefElement4 *)&p2, holder->m_view, 0);
		((Rva0033F15DDwordSlot *)&evt)->set(ThePlayerList->m_p10->m_val54);
		TheAudio->addAudioEvent(&evt);
	}
	if (p2 != 0)
		p2->Release_Ref();
}
