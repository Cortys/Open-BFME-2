// ?rva0035B6B8@Rva0035B6B8@@QAEHH@Z retail 0x0035B6B8 16B
// Array indexer returning m_234[index]. Evidence: unlock lane plus 6 callers
// plus ecx-first thiscall shape with ret-4 honest address name.

class Rva0035B6B8
{
public:
	int rva0035B6B8(int index);

private:
	char m_pad[0x234];
	int *m_arr;
};

int Rva0035B6B8::rva0035B6B8(int index)
{
	return m_arr[index];
}
