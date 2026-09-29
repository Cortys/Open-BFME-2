// cl: /O1 /G7 /DNDEBUG /MD
// ?rva005DB98E@Rva005DB98E@@QAEPAXGG@Z 0x005DB98E 46B
// Bounds-checked 2D index into 20B elements at +0x218.
// Evidence: callers 0x5A6D0A 0x5DB570 etc.; unblocks 8.
struct Elem005DB98E
{
	char m_data[20];
};

class Rva005DB98E
{
	char m_pad0[0x18];
	int m_arr2[81];
	char m_pad1[0x218 - 0x18 - 81 * 4];
	Elem005DB98E m_arr[81];
public:
	void* rva005DB98E(unsigned short x, unsigned short y);
	int rva005DB9BC(unsigned short x, unsigned short y);
};

void* Rva005DB98E::rva005DB98E(unsigned short x, unsigned short y)
{
	if (x > 8)
		return 0;
	if (y > 8)
		return 0;
	return &m_arr[y + x * 8];
}

int Rva005DB98E::rva005DB9BC(unsigned short x, unsigned short y)
{
	if (x > 8)
		return 0;
	if (y > 8)
		return 0;
	return m_arr2[y + x * 8];
}
