// cl: /O1 /GX-
//
// Retail RVA 0x0059B7CB, Ghidra boundary 25 bytes. It installs vtable
// VA 0x00C70EBC and copies two four-byte arguments to +4 and +8, returning
// this with ret 8. The vtable's slot 0 reaches the shared deleting body
// at 0x004A10FD; that folded body does not identify this class's owner.
// The class, argument types and field meanings remain unknown. In
// particular this is not Gdiplus::Image, whose vtable is VA 0x00BBB524.

class Rva0059B7CB
{
public:
	Rva0059B7CB(unsigned int field04, unsigned int field08);
	virtual void slot00();

private:
	unsigned int m_field04;
	unsigned int m_field08;
};

Rva0059B7CB::Rva0059B7CB(unsigned int field04, unsigned int field08)
{
	m_field04 = field04;
	m_field08 = field08;
}
