// ?rva00202633@Rva00202633@@QAEXH@Z
// partial score=0.92 date=2026-09-29
// ?rva00202633@Rva00202633@@QAEXH@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/reference/shims/ini /Ireference/open-bfme-1/reference/shims/gamelod /Ireference/open-bfme-1/reference/shims/ini_noinline /Ireference/open-bfme-1/reference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib
// ?rva00202633@Rva00202633@@QAEXH@Z 0x00202633 69B GameLODManager apply helper: copies 16B-stride LOD entry (0x1cc/0x1d0/0x1d4) to 0x1790/0x1798/0x179c, zeroes 0x178c/0x1794. Caller 0x0020276C stores level at +0x176c.
class Rva00202633
{
public:
	void rva00202633(int level);
	char m_pad[0x17a0];
};

// ?rva00202633@Rva00202633@@QAEXH@Z present-unmatched
void Rva00202633::rva00202633(int level)
{
	unsigned int a;
	unsigned int lvl = (unsigned int)level;
	*(int *)((char *)this + 0x178c) = 0;
	a = *(unsigned int *)((char *)this + lvl * 16 + 0x1cc);
	*(int *)((char *)this + 0x1794) = 0;
	lvl += 29u;
	*(unsigned int *)((char *)this + 0x1790) = a;
	lvl *= 16u;
	const unsigned int b = *(unsigned int *)((char *)this + lvl);
	*(unsigned int *)((char *)this + 0x1798) = b;
	*(int *)((char *)this + 0x179c) = *(int *)((char *)this + level * 16 + 0x1d4);
}
