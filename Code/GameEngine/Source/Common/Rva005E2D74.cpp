// cl: /O1 /MD
//
// ?rva005E2D74@Rva005E2D74@@QAEHPAD@Z retail 0x005E2D74 22B
// Evidence: unlock lane; callee write 0x000B44F0; unblocks 0x005E306D; prev Rva005E2144 same /O1 MD; members +0 byte +4 pair.
class Rva000B3F84Pair
{
public:
	int write(char *dst);
};
class Rva005E2D74
{
public:
	int rva005E2D74(char *dst);
private:
	char m_byte00;
	char m_pad01[3];
	Rva000B3F84Pair m_pair04;
};
int Rva005E2D74::rva005E2D74(char *dst)
{
	dst[0] = m_byte00;
	return m_pair04.write(dst + 1) + 1;
}
