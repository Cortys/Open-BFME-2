// cl: /O1 /MD
// ?rva00431A4D@Rva00431A4D@@QAEXPAVGameMessage@@@Z @0x00431A4D 23B: thiscall flag setter testing GameMessage+0x10 == 6 then byte this+4 else byte this+5. Evidence: unlock lane unblocks 0x00431F0C 0x004320B1; GameMessage+0x10 layout from neighbours Rva00431AEC Rva00431B76; prev Rva00431978 next Rva00431AEC same dir same flags.
class GameMessage
{
public:
	char m_pad[0x10];
	int m_10;
};

class Rva00431A4D
{
	char m_00[4];
	unsigned char m_04;
	unsigned char m_05;
public:
	void rva00431A4D(GameMessage *msg);
};

void Rva00431A4D::rva00431A4D(GameMessage *msg)
{
	if (msg->m_10 == 6)
		m_04 = 1;
	else
		m_05 = 1;
}
