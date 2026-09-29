// cl: /O1 /DNDEBUG /MD
// ?Rva00446A77Enable@@YAXXZ @0x00446A77 30B
// Conditionally enables +0x2B9/+0x2BA bytes of the object at global.
// Evidence: gated by byte 0x00A0335C and null-checked pointer 0x00A03354;
// tail-jmps to rowed ?enable@Rva0043DB47DoubleSetter@@QAEXXZ @0x0043DB47
// via outer+0x288; callers @0x004493C7 @0x00582265 and jmp @0x00248D98.
class Rva0043DB47DoubleSetter
{
public:
	void enable();

	char m_lead[0x2B9];
	unsigned char m_a;
	unsigned char m_b;
};

struct Outer00446A77
{
	char m_pad[0x288];
	Rva0043DB47DoubleSetter m_sub;
};

extern unsigned char g_Va00A0335C;
extern Outer00446A77 *g_Va00A03354;

void Rva00446A77Enable(void)
{
	if (g_Va00A0335C == 0)
		return;
	Outer00446A77 *p = g_Va00A03354;
	if (p == 0)
		return;
	return p->m_sub.enable();
}

// ?Rva00248D84Enable@@YAXXZ @0x00248D84 25B unlock lane.
// Null-checked pointer 0x00A03354: null tail-jmps to rowed
// ?Rva00446A77Enable@@YAXXZ @0x00446A77, else tail-jmps to rowed
// ?enable@Rva0043DB47DoubleSetter@@QAEXXZ @0x0043DB47 via outer+0x288.
// Evidence: 6 callers in unclaimed bodies; landing unblocks 5 waiters.
void Rva00248D84Enable(void)
{
	Outer00446A77 *p = g_Va00A03354;
	if (p != 0)
		return p->m_sub.enable();
	return Rva00446A77Enable();
}
