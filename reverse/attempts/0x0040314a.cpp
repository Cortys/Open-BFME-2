// ?rva0040314A@Rva0040314A@@QAEIXZ
// partial score=0.93 date=2026-09-28
// ?rva0040314A@Rva0040314A@@QAEIXZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// ?rva0040314A@Rva0040314A@@QAEIXZ retail 0x0040314A 20B
// Unsigned min with zero guard: if m_0c>0 return min else return m_08.
// Evidence: mov eax-ecx+c test jbe mov ecx-ecx+8 cmp cmovb ret mov ret.
class Rva0040314A
{
public:
	unsigned int rva0040314A();
private:
	char _pad[8];
	unsigned int m_08;
	unsigned int m_0c;
};
// ?rva0040314A@Rva0040314A@@QAEIXZ present-unmatched
unsigned int Rva0040314A::rva0040314A()
{
	if (m_0c > 0)
		return m_08 < m_0c ? m_08 : m_0c;
	return m_08;
}
