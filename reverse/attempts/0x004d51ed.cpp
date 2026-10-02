// ?rva004D51ED@Transport@@QAEXGPAX@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /G7 /DNDEBUG /MD /EHsc
// ?rva004D51ED@Transport@@QAEXGPAX@Z @0x004D51ED 44B: Transport slot data setter, copies 8 bytes into slot[index] at +0x40E10/+0x40E14 (slot+4/slot+8). Evidence: retail cmp word 8/jae/movzx/imul 0xc plus slot base 0x40E0C per clearSlot 0x004D5133 plus neighbours TransportRva004D5046.cpp and TransportRva004D53B5.cpp; callers at 0x005A79A5 0x005A7FF2 0x005A865A 0x005A8762.
class Transport
{
private:
	struct Message
	{
		char m_bytes[0x40E];
	};
	Message m_outBuffer[128];
	Message m_inBuffer[128];
	bool m_flag40E00;
	char m_pad40E01[3];
	void *m_ptr40E04;
	bool m_winsockActive;
	char m_pad40E09[3];
	struct Rva004D4A80Slot
	{
		void *m_object;
		int m_x;
		int m_y;
	};
	Rva004D4A80Slot m_slots[8];
	int m_int40E6C;
	int m_int40E70;
public:
// ?rva004D51ED@Transport@@QAEXGPAX@Z present-unmatched
	void rva004D51ED(unsigned short index, void *src);
};
void Transport::rva004D51ED(unsigned short index, void *src)
{
	if (index >= 8)
		return;
	unsigned idx = index;
	int *s = (int *)src;
	int v0 = s[0];
	int v1 = s[1];
	m_slots[idx].m_y = v1;
	m_slots[idx].m_x = v0;
}
