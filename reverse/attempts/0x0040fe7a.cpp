// ?Rva0040FE7AGet@@YAHPAVGameMessage@@@Z
// partial score=0.96 date=2026-10-03
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
	int result = 0;
	switch (msg->m_type) {
	case 3:
		result = 0x18;
		break;
	case 4:
		result = 5;
		break;
	case 5:
		result = 6;
		break;
	case 6:
		result = 8;
		break;
	case 7:
		result = 9;
		break;
	case 8:
		result = 0x0A;
		break;
	case 9:
		result = 0x0C;
		break;
	case 10:
		result = 0x0D;
		break;
	case 11:
		result = 0x0E;
		break;
	case 12:
		result = 0x10;
		break;
	case 13: {
		const GameMessageArgumentType *a = msg->getArgument(1);
		result = 0x13 + (a->integer <= 0);
		break;
	}
	case 14:
		result = 0;
		break;
	case 15:
		result = 0;
		break;
	case 16:
		result = 0;
		break;
	case 17:
		result = 0;
		break;
	case 18:
		result = 0;
		break;
	case 19:
		result = 0;
		break;
	}
	return result;
}
