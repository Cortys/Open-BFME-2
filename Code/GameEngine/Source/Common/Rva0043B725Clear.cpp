// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX /arch:SSE
// ?rva0043B725@Rva0043B725@@QAEXXZ, retail 0x0043B725, 8 bytes.
// Forwards this+4 to Rva0043B2E2 clear 0x0043B334.
// Evidence: jmp target row ?rva0043B334@Rva0043B2E2@@QAEXXZ caller 0x002442A4.
class Rva0043B2E2
{
public:
	void rva0043B334();
private:
	void *m_00Head;
	int m_04Flag;
};

class Rva0043B725
{
public:
	void rva0043B725();
private:
	char m_pad[4];
	Rva0043B2E2 m_tree;
};

void Rva0043B725::rva0043B725()
{
	m_tree.rva0043B334();
}
