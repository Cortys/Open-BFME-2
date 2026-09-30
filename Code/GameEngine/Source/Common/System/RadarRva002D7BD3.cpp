// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva002D7BD3@Radar@@QAEXXZ @0x002D7BD3 42B Radar invalidate draw cache.
// Evidence: stores 0xFFFF0001 at +0x144C and +0x1450 then 0xFFFF at +0x1454
// and +0x1458 plus 0 at +0x145C; callers 0x002D3297 and 0x002D8867;
// prev newMap and next clearRef share Radar class; no calls or floats.

class Radar
{
public:
	void rva002D7BD3();
private:
	char m_pad[0x144C];
	int m_144C; // +0x144C
	int m_1450; // +0x1450
	int m_1454; // +0x1454
	int m_1458; // +0x1458
	unsigned char m_145C; // +0x145C
};

void Radar::rva002D7BD3()
{
	m_144C = 0xFFFF0001;
	m_1450 = 0xFFFF0001;
	m_1454 = 0xFFFF;
	m_1458 = 0xFFFF;
	m_145C = 0;
}
