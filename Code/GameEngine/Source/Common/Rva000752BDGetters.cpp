// cl: /GX-
// ?Rva000752BDGet@@YAHXZ @ 0x000752BD (6B): global dword getter reading
// 0x00E08D30 (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape).
// First of a four-deep adjacent run (0x752BD/C3/C9/CF); dedicated TU so no
// caller inlines the load (Rva007EB810Get precedent).

extern int g_Va00E08D30;
// ?g_Va00E08D30@@3HA: the global at this VA is ?ProcessorManufacturer@CPUDetectClass@@0W4ProcessorManufacturerType@1@A; this name is an alias for it.
#pragma comment(linker, "/alternatename:?g_Va00E08D30@@3HA=?ProcessorManufacturer@CPUDetectClass@@0W4ProcessorManufacturerType@1@A")

int Rva000752BDGet(void)
{
	return g_Va00E08D30;
}

// ?Rva000752C3Get@@YAHXZ @ 0x000752C3 (6B): same shape over 0x00E08CA8.

extern int g_Va00E08CA8;
// ?g_Va00E08CA8@@3HA: the global at this VA is ?IntelProcessor@CPUDetectClass@@0W4IntelProcessorType@1@A; this name is an alias for it.
#pragma comment(linker, "/alternatename:?g_Va00E08CA8@@3HA=?IntelProcessor@CPUDetectClass@@0W4IntelProcessorType@1@A")

int Rva000752C3Get(void)
{
	return g_Va00E08CA8;
}

// ?Rva000752C9Get@@YAHXZ @ 0x000752C9 (6B): same shape over 0x00E08CF4.

extern int g_Va00E08CF4;
// ?g_Va00E08CF4@@3HA: the global at this VA is ?AMDProcessor@CPUDetectClass@@0W4AMDProcessorType@1@A; this name is an alias for it.
#pragma comment(linker, "/alternatename:?g_Va00E08CF4@@3HA=?AMDProcessor@CPUDetectClass@@0W4AMDProcessorType@1@A")

int Rva000752C9Get(void)
{
	return g_Va00E08CF4;
}

// ?Rva000752CFGet@@YAHXZ @ 0x000752CF (6B): same shape over 0x00E08D20.

extern int g_Va00E08D20;
// ?g_Va00E08D20@@3HA: the global at this VA is ?ProcessorSpeed@CPUDetectClass@@0HA; this name is an alias for it.
#pragma comment(linker, "/alternatename:?g_Va00E08D20@@3HA=?ProcessorSpeed@CPUDetectClass@@0HA")

int Rva000752CFGet(void)
{
	return g_Va00E08D20;
}
