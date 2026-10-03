// ?Rva000524AALoop@@YAXXZ
// partial score=0.97 date=2026-10-03
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /arch:SSE2 /Oi
// ?Rva000524AALoop@@YAXXZ retail 0x000524AA 44B
// Unlock: null-guarded 3-iter refreshAll over TheAudio+0x12c stride 0x1C4.
// Evidence: callers at 0x000524DD 0x000524E9 plus rowed 0x0005202C plus prev 0x000523A0 next 0x00052917.
class AudioManager;
extern AudioManager *TheAudio;

class Rva00699180Owner
{
public:
	void refreshAll();
};

// ?Rva000524AALoop@@YAXXZ present-unmatched
void Rva000524AALoop()
{
	int i = 0;
	if (TheAudio == 0)
		return;
	for (; i < 0x54C; i += 0x1C4) {
		((Rva00699180Owner *)(i + (unsigned int)TheAudio + 0x12C))->refreshAll();
	}
}
