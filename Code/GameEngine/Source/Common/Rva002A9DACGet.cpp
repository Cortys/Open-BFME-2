// ?Rva002A9DACGet@@YAHXZ @ 0x002A9DAC (12B). Unlock lane global-indirect
// dword getter. Evidence: mov eax,[0x009FE758]; mov eax,[eax+0xA5C]; ret.
// Callers at 0x003EA6E5 0x004A0F09 0x004C839D use eax as dword. Global is the
// 0x00DFE758 holder (GlobalData/GameLogic family); offset 0xA5C is opaque.
// Opaque address-derived name; DIR32 global is gate-filled reloc.

struct Rva002A9DACHolder
{
	char _pad[0xA5C];
	int m_value;
};

#define TheRva002A9DAC (*(Rva002A9DACHolder **)0x00DFE758)

int Rva002A9DACGet(void)
{
	return TheRva002A9DAC->m_value;
}
