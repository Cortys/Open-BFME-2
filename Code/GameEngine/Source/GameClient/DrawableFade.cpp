// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?fadeIn@Drawable@@QAEXI@Z @0x002707A8 82B, ?fadeOut@Drawable@@QAEXI@Z @0x00270756 82B.
// BFME2 Drawable fade pair transferred from BFME1 donor
// reference/open-bfme-1/Code/GameEngine/Source/GameClient/Drawable.cpp
// (fadeIn sets 0.0F mode 1, fadeOut sets 1.0F mode 2, both clear elapsed and
// store frames plus start frame). Retail divergences all measured:
// - zero-frames guard (opaque no-fade for fadeIn, transparent no-fade for fadeOut)
// - start frame at +0x37C via holder at 0xDFE77C slot 0x7C (ScriptEngine_setFrame precedent)
// - 1.0F loads from shared literal 0xBBB8D8, 0.0F via xorps.
// Layout: opacity +0xB0, fadeMode +0x128, elapsed +0x12C, toFade +0x130 (contiguous
// fade triple proven by updater 0x0027566B), start frame +0x37C.
// Callers: 0x00265173 calls fadeOut then selectable(0) vs fadeIn then selectable(1)
// with LogicFrames 0xDBA4E4; 0x00275894 calls fadeIn when mode reaches 5;
// ObjectCreationList debris calls fadeIn/fadeOut with m_fadeFrames.

extern float g_Va00BBB8D8;

class Rva00DFE77CHolder
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(); virtual void slot0A(); virtual void slot0B();
	virtual void slot0C(); virtual void slot0D(); virtual void slot0E(); virtual void slot0F();
	virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
	virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
	virtual void slot18(); virtual void slot19(); virtual void slot1A(); virtual void slot1B();
	virtual void slot1C(); virtual void slot1D(); virtual void slot1E(); virtual int slot1F();
};

#define TheRva00DFE77C (*(Rva00DFE77CHolder **)0x00DFE77C)

class Rva002716Holder
{
public:
	void rva00271601(unsigned char v);
};

class Drawable
{
public:
	void fadeIn(unsigned int frames);
	void fadeOut(unsigned int frames);
	void rva00272D77(unsigned int a, unsigned int b);

private:
	unsigned char m_pad00[0xB0];
	float m_explicitOpacity; // +0xB0
	unsigned char m_padB4[0x128 - 0xB4];
	int m_fadeMode; // +0x128
	int m_timeElapsedFade; // +0x12C
	int m_timeToFade; // +0x130
	int m_134; // +0x134
	unsigned char m_pad138[0x37C - 0x138];
	int m_fadeStartFrame; // +0x37C
};

void Drawable::fadeIn(unsigned int frames)
{
	float opacity;
	if (frames == 0) {
		opacity = g_Va00BBB8D8;
		m_fadeMode &= frames;
	} else {
		opacity = 0.0f;
		m_fadeMode = 1;
	}
	m_timeElapsedFade = 0;
	m_explicitOpacity = opacity;
	m_timeToFade = frames;
	m_fadeStartFrame = TheRva00DFE77C->slot1F();
}

void Drawable::fadeOut(unsigned int frames)
{
	float opacity;
	if (frames == 0) {
		opacity = 0.0f;
		m_fadeMode &= frames;
	} else {
		opacity = g_Va00BBB8D8;
		m_fadeMode = 2;
	}
	m_timeElapsedFade = 0;
	m_explicitOpacity = opacity;
	m_timeToFade = frames;
	m_fadeStartFrame = TheRva00DFE77C->slot1F();
}
// @0x00272D77 (68B): third fade mode 5 setter; holder call with 1 then elapsed 0
// toFade a plus field +0x134 b plus start frame via holder slot1F. Caller 0x0045BEA0.
void Drawable::rva00272D77(unsigned int a, unsigned int b)
{
	((Rva002716Holder *)this)->rva00271601(1);
	m_timeElapsedFade = 0;
	m_timeToFade = a;
	m_fadeMode = 5;
	m_134 = b;
	m_fadeStartFrame = TheRva00DFE77C->slot1F();
}
