// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0029B1C2@Rva0029B1C2@@QAEXXZ 0x0029B1C2 22B evidence: chain via rowed 0x002707FA; clears byte at +8 after forwarding 0
class Rva002707FA
{
public:
	void rva002707FA(unsigned char value);
};

class Rva0029B1C2
{
	Rva002707FA *m00;
	char _p04[4];
	unsigned char m08;
public:
	void rva0029B1C2();
};

void Rva0029B1C2::rva0029B1C2()
{
	if (m00 != 0)
		m00->rva002707FA(0);
	m08 = 0;
}
