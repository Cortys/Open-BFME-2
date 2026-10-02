// cl: /O1 /MD
//
// ?rva0057FD6E@Rva0057FD6E@@QAEXXZ, retail 0x0057FD6E, 13 bytes.
// Forwards to rowed 0x005AFC92 when +0x64 non-null, else return.
// Evidence: chain packet calls just-landed 0x005AFC92; caller 0x0057FF87
// ignores return; tail-jmp shape.
class Rva005AFC92
{
public:
	bool rva005AFC92();
};

class Rva0057FD6E
{
public:
	void rva0057FD6E();
private:
	char m_pad[100];
	Rva005AFC92 *m_64;
};

void Rva0057FD6E::rva0057FD6E()
{
	if (m_64 != 0) {
		m_64->rva005AFC92();
	}
}
