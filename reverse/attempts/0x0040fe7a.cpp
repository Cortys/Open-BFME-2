// ?Rva0040FE7AGet@@YAHPAVGameMessage@@@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD
//
// ?Rva0040FE7AGet@@YAHPAVGameMessage@@@Z retail 0x0040FE7A 84 bytes.
// Free __cdecl function taking GameMessage* switching on message type at
// +0x10 (edx = type-3 jump table at 0x0080FECE with 17 entries for types
// 3..19) returning small constants plus arg-dependent 0x13/0x14 via rowed
// getArgument 0x0030F4EA. Evidence: callee row getArgument; callers
// 0x0040FF39 0x004100C3 0x004100FA 0x00432DBC; prev/next same dir.

typedef unsigned char UnsignedByte;

union GameMessageArgumentType
{
	int integer;
	float real;
	int boolean;
	int objectID;
	int drawableID;
	unsigned int teamID;
	struct Loc { float x; float y; float z; } location;
	struct Pix { int x; int y; } pixel;
	struct PixReg { int loX; int loY; int hiX; int hiY; } pixelRegion;
	unsigned int timestamp;
	unsigned short wChar;
};

class GameMessage
{
public:
	const GameMessageArgumentType *getArgument(int argIndex) const;

	char m_pad00[0x10];
	int m_type; // +0x10
};

// ?Rva0040FE7AGet@@YAHPAVGameMessage@@@Z present-unmatched
int __cdecl Rva0040FE7AGet(GameMessage *msg)
{
	switch (msg->m_type) {
	case 3:
		return 0x18;
	case 4:
		return 5;
	case 5:
		return 6;
	case 6:
		return 8;
	case 7:
		return 9;
	case 8:
		return 0x0A;
	case 9:
		return 0x0C;
	case 10:
		return 0x0D;
	case 11:
		return 0x0E;
	case 12:
		return 0x10;
	case 13: {
		const GameMessageArgumentType *a = msg->getArgument(1);
		return 0x13 + (a->integer <= 0);
	}
	case 14:
		return 0;
	case 15:
		return 0;
	case 16:
		return 0;
	case 17:
		return 0;
	case 18:
		return 0;
	case 19:
		return 0;
	default:
		return 0;
	}
}
