// cl: /O1 /MD
// ?rva00238E1B@Rva00238E1B@@QAEHXZ @0x00238E1B 10B post-inc counter at +0x2C returns old value.
// Evidence: unlock lane leaf increment; callers 0x00280176 0x00283642; lea shape not inc.
class Rva00238E1B
{
public:
	int rva00238E1B();
private:
	int m_pad[11];
	int m_counter;
};
int Rva00238E1B::rva00238E1B()
{
	int t = m_counter;
	m_counter = t + 1;
	return t;
}
