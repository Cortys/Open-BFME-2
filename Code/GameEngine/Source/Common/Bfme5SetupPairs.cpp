// Trimmed port of reference/open-bfme-1/Code/GameEngine/Source/Common/
// Bfme5SetupPairs.cpp: only the 007E9860 stub is carried; sibling stubs stay
// with the donor until rows land.

struct BfmeSetupRecord
{
	void bfmeBegin(void);					// retail 0x00655B50
	void bfmeWrite(const char *text, int value);		// retail 0x00655AA0
	void bfmeWriteAlt(const char *text, int value);		// retail 0x00655960

	char m_bfmeHead[0x1C];
	unsigned int m_bfmeTag;					// +0x1C
};

extern int TheBfmeSetupGlobal007E9860;
// TheBfmeSetupGlobal007E9860: matched references place it at VA 0xe09ebc (zero-filled .bss).
int TheBfmeSetupGlobal007E9860;
extern int TheBfmeSetupGlobal007F26A0;
// TheBfmeSetupGlobal007F26A0: matched references place it at VA 0xe0a0d0 (zero-filled .bss).
int TheBfmeSetupGlobal007F26A0;

// ?bfmeSetupPair_007E9860@@YGXPAUBfmeSetupRecord@@H@Z
void __stdcall bfmeSetupPair_007E9860(BfmeSetupRecord *record, int second)
{
	int value = TheBfmeSetupGlobal007E9860;

	record->bfmeBegin();

	record->m_bfmeTag = 0x61636374;					// 'acct'

	record->bfmeWrite("TXN", value);
	record->bfmeWrite("name", second);
}

// ?bfmeSetupPair_007F26A0@@YGXPAUBfmeSetupRecord@@H@Z
void __stdcall bfmeSetupPair_007F26A0(BfmeSetupRecord *record, int second)
{
	int value = TheBfmeSetupGlobal007F26A0;

	record->bfmeBegin();

	record->m_bfmeTag = 0x72616E6B;					// 'rank'

	record->bfmeWrite("TXN", value);
	record->bfmeWriteAlt("numberOfReporters", second);
}
