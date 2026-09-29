// ?Rva00101E1EConvert@@YAXMMPAH0HH@Z
// partial score=0.95 date=2026-09-29
// ?Rva00101E1EConvert@@YAXMMPAH0HH@Z
// partial score=0.95 date=2026-09-29
// cl: /arch:SSE /Oy- /Os /DNDEBUG /MD /EHsc /DBFME_MODULE_NO_MPO /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ?Rva00101E1EConvert@@YAXMMPAH0HH@Z @0x00101E1E 79B
// Free function 0x00101E1E (79B): screen-projection float-to-int conversion.
// Evidence: callers 0x0008619F (166B) and 0x0009AE98 (248B) with 6 cdecl args; globals 0x7BB8D8 and 0x7C26F0.

extern float Data007BB8D8;
extern float Data007C26F0;

// ?Rva00101E1EConvert@@YAXMMPAH0HH@Z present-unmatched
void __cdecl Rva00101E1EConvert(float a, float b, int *out1, int *out2, int s1, int s2)
{
	float g1 = Data007BB8D8;
	float t1 = g1 + a;
	float t0 = g1 - b;
	float f1 = (float)s1;
	t1 *= f1;
	float g2 = Data007C26F0;
	t1 *= g2;
	*out1 = (int)t1;
	float f2 = (float)s2;
	t0 *= f2;
	t0 *= g2;
	*out2 = (int)t0;
}

