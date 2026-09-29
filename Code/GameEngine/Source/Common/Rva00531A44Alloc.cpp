// cl: /O1 /MD /G7
//
// ?rva00531A44@Rva00531A44@@QAEAAV1@G@Z, retail 0x00531A44, 79 bytes.
// Honest-address allocator: stores ushort count at +0, clears word at +2,
// new[]s four arrays (short at +4/+C/+10 sized count*2, byte at +8 sized
// count) via the rowed ??_U@YAPAXI@Z, returns *this. Callers at 0x00531FC6
// and 0x005323C2 are unclaimed so owner is unknown. No FP, no EH.
void *__cdecl operator new[](unsigned int size);
class Rva00531A44
{
public:
	Rva00531A44 &rva00531A44(unsigned short count);
private:
	unsigned short m_count;
	unsigned short m_zero;
	unsigned short *m_p4;
	unsigned char *m_p8;
	unsigned short *m_pC;
	unsigned short *m_p10;
};

Rva00531A44 &Rva00531A44::rva00531A44(unsigned short count)
{
	m_zero = 0;
	m_count = count;
	m_p4 = new unsigned short[m_count];
	m_p8 = new unsigned char[m_count];
	m_pC = new unsigned short[m_count];
	m_p10 = new unsigned short[m_count];
	return *this;
}
