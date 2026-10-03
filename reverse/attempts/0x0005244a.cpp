// ?Rva0005244ALoop@@YAXH@Z
// partial score=0.97 date=2026-10-03
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /arch:SSE2 /Oi
// ?Rva0005244ALoop@@YAXH@Z @0x0005244A 48B. Null-guarded 3-iter rva00051FFE
// over TheAudio+0x12C stride 0x1C4 with cdecl int arg re-pushed each iter.
// Evidence: rowed callee 0x00051FFE in same class TU, TheAudio 0x009FE6E8
// ?TheAudio@@3PAVAudioManager@@A, prev 0x000523A0 same flags, caller site,
// sibling 0x000524AA stash pattern (0.97 SIB order) with order swapped.
class AudioManager;
extern AudioManager *TheAudio;

class Rva00699180Owner
{
public:
	void rva00051FFE(int b);
};

// ?Rva0005244ALoop@@YAXH@Z present-unmatched
void Rva0005244ALoop(int v)
{
	int i = 0;
	if (TheAudio == 0)
		return;
	for (; i < 0x54C; i += 0x1C4) {
		((Rva00699180Owner *)(i + 0x12C + (unsigned int)TheAudio))->rva00051FFE(v);
	}
}
