// cl: /O1 /DNDEBUG /MD
// ?Rva00446A71Get@@YAEXZ @0x00446A71 6B
// Byte getter for global 0x00A0335C.
// Evidence: retail mov al [0x00A0335C] ret; caller @0x00248EAA tests al al;
// neighbour ?Rva00446A77Enable@@YAXXZ gates on the same byte.
extern unsigned char g_Va00A0335C;

unsigned char Rva00446A71Get(void)
{
	return g_Va00A0335C;
}
