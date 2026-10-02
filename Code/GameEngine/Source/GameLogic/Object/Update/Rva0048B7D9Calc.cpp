// cl: /O1 /MD
//
// ?rva0048B7D9@Rva0048B7D9@@QAEIXZ @0x0048B7D9 36B
// Returns GetGameLogicRandomValue(min max file line) clamped to at least 1.
// Min/max come from the data at +4 (+0xC/+0x10). File literal plus 0x98 are
// the rowed GetGameLogicRandomValue 0x00233FF4 args. Callers 0x0048B924 and
// 0x0048B94E use the result as a wake frame delay.

int __cdecl GetGameLogicRandomValue(int lo, int hi, char *file, int line);

struct Rva0048B7D9Data
{
	char m_pad00[0xC]; // +0..+0xB
	int m_min; // +0xC
	int m_max; // +0x10
};

class Rva0048B7D9
{
public:
	unsigned int rva0048B7D9();

private:
	char m_pad00[4]; // +0..+3
	Rva0048B7D9Data *m_data; // +4
};

unsigned int Rva0048B7D9::rva0048B7D9()
{
	unsigned int r = (unsigned int)GetGameLogicRandomValue(m_data->m_min, m_data->m_max, (char *)"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\Object\\Update\\FireSpreadUpdate.c", 0x98);
	if (r < 1)
		r = 1;
	return r;
}
