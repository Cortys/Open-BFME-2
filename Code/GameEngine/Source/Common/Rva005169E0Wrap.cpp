// cl: /O2 /Ob0 /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1
//
// Ported from Open-BFME-1 GameEngine/Source/Common/Rva005169E0Wrap.cpp
// (donor revision 6d9434269164392c5ba62aaa7c15a86b5b020d76, donor flags plus /O1). Compiled that way each body
// places uniquely on unclaimed game.dat .text by masked whole-.text search:
//   ?wrap@Rva005169E0@@QAEEH@Z 0x00444208 (20B)
// Callee addresses are read off retail call sites (reverse/symbols.csv).

class Gen00024B7C
{
public:
	unsigned char handle(int a);
};

extern Gen00024B7C *g_Va012F7730;

class Rva005169E0
{
public:
	unsigned char wrap(int a);
};

unsigned char Rva005169E0::wrap(int a)
{
	if (g_Va012F7730)
		return g_Va012F7730->handle(a);
	return 0;
}
