// A global list lookup.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5NinetyTwo.cpp); trimmed to the single T1
// body the sweep places.

class BfmeRecJD
{
public:
	int m_bfmeWords[7];
};

extern BfmeRecJD *g_bfmeBeginJD;
extern BfmeRecJD *g_bfmeEndJD;

BfmeRecJD * __stdcall bfmeSlotAt(int index)
{
	if (index >= 0 && index < (int)(g_bfmeEndJD - g_bfmeBeginJD))
		return g_bfmeBeginJD + index;
	return 0;
}
// ?g_bfmeEndJD@@3PAVBfmeRecJD@@A: the global at VA 0xe0abb8 is ?g_bfmeVideoTableEnd@@3PAUVideo@@A.
#pragma comment(linker, "/alternatename:?g_bfmeEndJD@@3PAVBfmeRecJD@@A=?g_bfmeVideoTableEnd@@3PAUVideo@@A")
// ?g_bfmeBeginJD@@3PAVBfmeRecJD@@A: the global at VA 0xe0abb4 is ?g_bfmeVideoTableBegin@@3PAUVideo@@A.
#pragma comment(linker, "/alternatename:?g_bfmeBeginJD@@3PAVBfmeRecJD@@A=?g_bfmeVideoTableBegin@@3PAUVideo@@A")
