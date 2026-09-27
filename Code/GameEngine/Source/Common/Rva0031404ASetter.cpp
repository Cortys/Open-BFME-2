// cl: /O1 /MD
// ?rva0031404A@Rva0031404A@@QAEHH@Z, retail 0x0031404A, 12 bytes.
// Honest int-field setter at +0x34 returning 0. Evidence: unlock lane with two
// direct callers; prev/next in the same 00314xxx page are small Common helpers.

class Rva0031404A
{
public:
	int rva0031404A(int v);

private:
	char m_pad[0x34];
	int m_34;
};

int Rva0031404A::rva0031404A(int v)
{
	m_34 = v;
	return 0;
}
