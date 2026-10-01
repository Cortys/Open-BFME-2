// cl: /O1 /MD
// ?rva00433FDD@Rva00433FDD@@QAEXXZ, retail 0x00433FDD, 22 bytes.
// Sets +0x27C to 3 if dword at +0x280 is nonzero else 1.
// Evidence: callers at 0x004344E5 0x00435811 share +0x27C +0x280 layout.
class Rva00433FDD
{
public:
	void rva00433FDD();
private:
	char m_pad[0x27C];
	int m_27C;
	int m_280;
};
void Rva00433FDD::rva00433FDD()
{
	m_27C = m_280 ? 3 : 1;
}
