// Retail 0x00758CC0 (30 B): true when the +0x08 and +0x0C words of two records
// agree. Open-BFME-1 lands two byte-identical twins of this body
// (Rva009A2F40.cpp: Rva009A2F40::method and Rva009A2F70::method, BFME 1
// 0x009A2F40 / 0x009A2F70, each followed by a 12-byte key getter); game.dat
// holds one copy, so it lands once under a name derived from its own address.
// IDENTITY IS NOT RECOVERED.
class Rva00758CC0
{
public:
 unsigned int m_00, m_04;
 int m_a, m_b; // retail offsets +0x08 and +0x0C
 unsigned char method(const Rva00758CC0 *other);
};
unsigned char Rva00758CC0::method(const Rva00758CC0 *other)
{
 if (m_a == other->m_a && m_b == other->m_b) return 1;
 return 0;
}
