// cl: /O1 /MD
// ?rva00406FBF@Rva00406FBF@@QAEXPAE@Z @0x00406FBF 29B: thiscall CRC updater setting byte at +4 then storing CRC::Memory(data 4 old) at +0. Callee rowed 0x00619AC0. Callers 0x00407093 0x004070B0 pass stack pointer. Owner unknown so honest-address name.
class CRC
{
public:
	static unsigned long __cdecl Memory(unsigned char *data, unsigned long len, unsigned long crc);
};
class Rva00406FBF
{
	unsigned long m_crc;
	bool m_flag;
public:
	void rva00406FBF(unsigned char *data);
};
void Rva00406FBF::rva00406FBF(unsigned char *data)
{
	m_flag = true;
	m_crc = CRC::Memory(data, 4, m_crc);
}
