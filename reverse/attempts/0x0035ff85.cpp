// ?init@Rva0035FF76@@UAEXPAVGameWindow@@@Z
// partial score=0.93 date=2026-09-26
// ?init@Rva0035FF76@@UAEXPAVGameWindow@@@Z
// partial score=0.93 date=2026-09-26
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?init@Rva0035FF76@@UAEXPAVGameWindow@@@Z @ 0x0035FF85 (234B):
// slot 1 offset 0x4 of vtable 0x0081670C (class of ??1Rva0035FF76@@UAE@XZ).
// Ported from open-bfme-1 Code/GameEngine/Source/GameClient/GUI/Rva0059F720FadeColorInit.cpp:
// update(m_startFrame) then m_percent 1.0/(m_endFrame-1) then 3x fade color
// floats at +0x30/+0x34/+0x38 times 255 clamped to bytes at +0x3c/+0x3d/+0x3e.
// BFME2 draw fetches display size so no TheDisplay calls here unlike the donor.
// Evidence: vtable 0x0081670C slot 1 plus FadeColor string after vtable plus
// INI FadeColor field at +0x30 plus rowed update slot and __ftol2 0x629228.

typedef int Int;
typedef float Real;
typedef bool Bool;

#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

class GameWindow;

class Rva0035FF76
{
public:
	virtual ~Rva0035FF76();
	virtual void init(GameWindow *win);
	virtual void update(Int frame);
	virtual void reverse();
	virtual void draw();
	virtual void slot5();
	virtual void skip();
	virtual void slot7();

	Int m_frameLength;	// +0x04
	Bool m_isFinished;	// +0x08
	Bool m_isForward;	// +0x09
	Bool m_isReversed;	// +0x0a
	unsigned char m_pad0B;	// +0x0b
	GameWindow *m_win;	// +0x0c
	Int m_startFrame;	// +0x10
	Int m_endFrame;		// +0x14
	Int m_posX;		// +0x18
	Int m_posY;		// +0x1c
	Int m_sizeX;		// +0x20
	Int m_sizeY;		// +0x24
	Real m_percent;		// +0x28
	Int m_drawState;	// +0x2c
	Real m_fadeRed;		// +0x30
	Real m_fadeGreen;	// +0x34
	Real m_fadeBlue;	// +0x38
	unsigned char m_red;	// +0x3c
	unsigned char m_green;	// +0x3d
	unsigned char m_blue;	// +0x3e
};

// ?init@Rva0035FF76@@UAEXPAVGameWindow@@@Z present-unmatched
void Rva0035FF76::init(GameWindow *win)
{
	m_isForward = FALSE;
	update(m_startFrame);
	m_isFinished = FALSE;
	m_isForward = TRUE;
	m_percent = 1.0f / (m_endFrame - 1);

	Real scaled = m_fadeRed;
	scaled *= 255.0f;
	if (!(scaled < 255.0f))
		scaled = 255.0f;
	if (!(scaled > 0.0f))
		scaled = 0.0f;
	unsigned char red = (unsigned char)scaled;

	scaled = m_fadeGreen;
	scaled *= 255.0f;
	m_red = red;
	if (!(scaled < 255.0f))
		scaled = 255.0f;
	if (!(scaled > 0.0f))
		scaled = 0.0f;
	unsigned char green = (unsigned char)scaled;

	scaled = m_fadeBlue;
	scaled *= 255.0f;
	m_green = green;
	if (!(scaled < 255.0f))
		scaled = 255.0f;
	if (!(scaled > 0.0f))
		scaled = 0.0f;
	m_blue = (unsigned char)scaled;
}
