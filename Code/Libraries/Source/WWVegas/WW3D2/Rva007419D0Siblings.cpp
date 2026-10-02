// cl: /arch:SSE /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ?rva007419D0@Rva007419D0Streak@@QAEXM@Z @0x007419D0 37B.
// Recovered from the ?Set_Texture@StreakLineClass@@QAEXPAVTextureClass@@@Z
// recipe at 0x00741880. Same operand-masked shape: a one-argument setter that
// forwards through the sub-renderers at +0x100 and +0x150, in that order, then
// returns. Only the two REL32 callees differ: retail calls the rowed
// SegLineRendererClass::Set_Texture_Tile_Factor 0x00191230 and
// SegLineTileFactorAltClass::Set_Texture_Tile_Factor 0x00743030, so this is the
// tile-factor sibling of the template's texture setter. Offsets and argument
// shape (one pushed dword, ret 4) are identical.
class SegLineRendererClass
{
public:
	void Set_Texture_Tile_Factor(float factor);
};

class SegLineTileFactorAltClass
{
public:
	void Set_Texture_Tile_Factor(float factor);
};

class Rva007419D0Streak
{
public:
	void rva007419D0(float factor);

private:
	char m_prefix[0x100];	// +0x000
	char m_line[0x50];	// +0x100: line renderer sub-object
	char m_streak;		// +0x150: streak renderer sub-object
};

void Rva007419D0Streak::rva007419D0(float factor)
{
	((SegLineRendererClass *)(void *)m_line)->Set_Texture_Tile_Factor(factor);
	((SegLineTileFactorAltClass *)(void *)&m_streak)->Set_Texture_Tile_Factor(factor);
}
