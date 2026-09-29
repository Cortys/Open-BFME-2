// ?Check@Rva00261478@@QAEHPAVObject@@@Z
// partial score=0.95 date=2026-09-29
// ?Check@Rva00261478@@QAEHPAVObject@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD
// probe for 0x00261478 chain caller
class Player;
class Object;
bool __stdcall Rva0041C21BIsVisible(Player *player, Object *obj, int unused);

class Rva00261478
{
public:
	int Check(Object *obj);
private:
	char m_pad00[8];
	Player *m_player8;
	unsigned char m_flagC;
	char m_padD[3];
	int m_int10;
};

int Rva00261478::Check(Object *obj)
{
	unsigned char r = Rva0041C21BIsVisible(m_player8, (Object *)(*(volatile int *)0xE030E8, obj), m_int10);
	unsigned char d = (unsigned char)(r - m_flagC);
	return !d;
}

