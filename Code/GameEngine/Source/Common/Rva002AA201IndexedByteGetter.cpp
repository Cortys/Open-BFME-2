// ?get@Rva002AA201IndexedByteField@@QBEEH@Z @ 0x002AA201 (14B): indexed byte
// getter (mov eax,[esp+4] / mov al,[eax+ecx+0x340] / ret 4). Caller at 0x003E4C56
// passes [eax+0x54] with ecx=esi and tests al; prev 0x002AA14D is the Bonuses
// ctor and next 0x002AA21C is a disp32 dword getter. Identity unrecovered:
// opaque address-derived holder following the Rva004B0DA0 indexed-byte-clear
// precedent (m_flags[index] shape).
// No // cl: line (defaults match the frameless 14-byte shape).
class Rva002AA201IndexedByteField
{
public:
	unsigned char get(int index) const;
private:
	char m_pad[0x340];
	unsigned char m_flags[1];
};
unsigned char Rva002AA201IndexedByteField::get(int index) const
{
	return m_flags[index];
}
