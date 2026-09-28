// cl: /O1 /MD
// ?Rva0007912DGet@@YAHXZ @ 0x0007912D (26B): clamped LOD index from
// [0xDFE144]+0x1788. Returns ([global]+0x1788)-1 clamped to 0..2 (dec/jns
// zero path plus push-2/pop-2 cap). Callers 0x79147/0x79157/0x79176 index
// the W3DHordeModelDrawModuleData triple at +0x188 stride 0x14 (bool/int/
// float at +0/+4/+0xC per W3DHordeModelDrawModuleDataCtor.cpp); 0x7A5BF
// compares the same slot against 4. Global models the OptionPreferences
// TheRva00DFE144 struct extended to 0x1788.

struct Rva00DFE144Globals
{
	char m_pad[0x1788];
	int m_1788;
};

extern Rva00DFE144Globals *TheRva00DFE144;

int Rva0007912DGet(void)
{
	int v = TheRva00DFE144->m_1788 - 1;
	if (v < 0)
		return 0;
	if (v > 2)
		return 2;
	return v;
}
