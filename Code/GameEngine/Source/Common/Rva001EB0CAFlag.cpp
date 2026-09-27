// cl: /O1 /MD
// ?rva001EB0CA@Rva001EB0CAHolder@@QAEXXZ @0x001EB0CA 15B: null-checked byte set.
// Loads pointer at this+0x10 and stores 1 at pointee+0xC1. Callers at
// 0x003BE6F5 0x003BE7C6 0x003BE8C0. No donor; honest address names.
struct Rva001EB0CAPointee
{
	unsigned char m_pad[0xC1];
	unsigned char m_flag;
};
class Rva001EB0CAHolder
{
public:
	void rva001EB0CA();
private:
	char m_pad[0x10];
	Rva001EB0CAPointee *m_ptr;
};
void Rva001EB0CAHolder::rva001EB0CA()
{
	if (m_ptr)
		m_ptr->m_flag = 1;
}
