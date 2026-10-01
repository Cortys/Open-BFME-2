// cl: /G7 /Ireference/shims/bfmerendobj /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ?rva004334AF@Rva004334AF@@QAEXM@Z @0x004334AF 12B: or byte [ecx+0xC4],0x80 then tail-jmp to rowed LineGroupClass::Set_Line_UCoord 0x0041FDEE; caller 0x00433A64 passes Dict::getInt result.
class LineGroupClass
{
public:
	void Set_Line_UCoord(float ucoord);
private:
	char _base[0x5C];
};

class Rva004334AF
{
public:
	void rva004334AF(float ucoord);
private:
	LineGroupClass m_group; // +0
	char m_pad[0xC4 - 0x5C]; // +0x5C..+0xC3
	unsigned char m_flag; // +0xC4
};

void Rva004334AF::rva004334AF(float ucoord)
{
	m_flag |= 0x80;
	m_group.Set_Line_UCoord(ucoord);
}
