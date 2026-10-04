// cl: /O1
//
// Ported from Open-BFME-1 GameEngine/Source/Common/BfmeConv485.cpp
// (donor revision 6d9434269164392c5ba62aaa7c15a86b5b020d76, donor flags plus /O1). Compiled that way each body
// places uniquely on unclaimed game.dat .text by masked whole-.text search:
//   ?bfmeGoBLD@@YGXPAX@Z 0x0029ACE3 (24B)
// Callee addresses are read off retail call sites (reverse/symbols.csv).
class BfmeSinkBLD
{
public:
	void bfmeDoBLD(void *what, int flag);
};

extern BfmeSinkBLD *g_bfmeSinkBLD;

void __stdcall bfmeGoBLD(void *what)
{
	BfmeSinkBLD *sink = g_bfmeSinkBLD;
	if (sink != 0)
		sink->bfmeDoBLD(what, 0);
}
