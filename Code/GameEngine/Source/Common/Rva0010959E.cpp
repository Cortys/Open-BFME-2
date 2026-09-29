// cl: /O1 /DNDEBUG /MD
// ?rva0010959E@Rva0010959E@@QAEXXZ @0x0010959E 20B
// Calls rowed W3DProjectedShadow::rva00108951 at +0x58 then tail-jmps it at
// +0x5C; caller at 0x0010BA18; chain from 0x00108951.
class W3DProjectedShadow
{
public:
	void rva00108951();
};
class Rva0010959E
{
public:
	void rva0010959E();
private:
	char m_pad[0x58];
	W3DProjectedShadow *m_58;
	W3DProjectedShadow *m_5c;
};
void Rva0010959E::rva0010959E()
{
	m_58->rva00108951();
	return m_5c->rva00108951();
}
