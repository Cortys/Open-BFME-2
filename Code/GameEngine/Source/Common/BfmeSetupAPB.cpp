// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHs-c- /Ireference/open-bfme-1/inputs/reference/shims/iniexception
//
// Bodies ported from Open-BFME-1's GameEngine/Source/Common/BfmeSetupAPB.cpp
// (donor revision 6d9434269164392c5ba62aaa7c15a86b5b020d76, donor flags plus
// /O1). Compiled that way each body below places uniquely on unclaimed
// game.dat .text by masked whole-.text search, and ./build.sh reproduces it
// byte for byte: bfmeSetupAPB 0x003B9BE0 (64B). Callee addresses are read off
// retail's call sites (reverse/symbols.csv). Only the placed bodies are
// carried; the donor's other definitions are omitted.

// ?bfmeSetupAPB@@YAHXZ 0x00061380
// The retail body updates g_bfmeFlagsAPB at 0x012A6FA0, marks the second CRC
// mode at 0x012ED4E6, and rejects the mode pair through the shared INIException
// text at 0x01075230 when g_bfmeOnAPB at 0x012ED4E5 is already set.

typedef unsigned int UnsignedInt;

extern UnsignedInt g_bfmeFlagsAPB;
extern bool g_bfmeOnAPB;
extern bool g_bfmeDoneAPB;
#include "Common/INIException.h"

int bfmeSetupAPB(void)
{
	g_bfmeDoneAPB = true;
	g_bfmeFlagsAPB |= 0x20000;
	if (g_bfmeOnAPB)
	{
		throw INIException(3, "Do not specify both -deepCRC and -liteCRC in your commandline arguments.");
	}
	return 1;
}
