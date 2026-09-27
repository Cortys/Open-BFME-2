// ?get@Rva002AA245MovzxByteChaseField@@QBEIXZ @ 0x002AA245 (18B): null-checked
// movzx byte-chase getter (mov eax,[ecx+0x34] / test eax,eax / je null /
// movzx eax,byte [eax+0x151] / ret / xor eax,eax / ret). Callers at 0x0004A1E4,
// 0x0004AB54, 0x00281B3C and 18 more; prev 0x002AA22A and next 0x002AA257 are
// disp32 family neighbours in the same dir. Identity unrecovered: opaque
// address-derived holder.
// No // cl: line (defaults match the frameless shape, like the neighbours).
class Rva002AA245MovzxByteChaseField
{
public:
	unsigned int get() const;
	char m_lead[0x34];
	void *m_ptr;
};
unsigned int Rva002AA245MovzxByteChaseField::get() const
{
	if (m_ptr)
		return *(unsigned char *)((char *)m_ptr + 0x151);
	return 0;
}
