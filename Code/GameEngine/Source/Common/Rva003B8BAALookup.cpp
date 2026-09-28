// cl: /O1 /MD
// ?rva003B8BAA@Rva003B8BAA@@QAEPAXXZ @0x003B8BAA 30B.
// Guard on the 0x00DFEF10 singleton byte +0xB4, then index/array chase +0x10/+0x14/[+0x20].
// Evidence: retail mov eax,[0xDFEF10]; cmp [eax+0xB4],0; jne; xor eax,eax; ret; else mov eax,[ecx+0x10];
// mov ecx,[ecx+0x14]; mov eax,[ecx+eax*4]; mov eax,[eax+0x20]; ret. Callers at 0x002B2655 0x002B2681
// 0x002B27F3 0x002B281B 0x002B2C6E load ecx from 0x00E02D6C then call/jmp here and use eax as
// vtable object (+0x28/+0x38). Singleton +0xB4 proven by Rva0023C6A4Check and Rva002BA8F1Logic finds.
struct Rva003B8BAAElem
{
	char m_pad[0x20];
	void *m_ptr20;
};

class Rva003B8BAA
{
	char m_pad[0x10];
	int m_index10;
	Rva003B8BAAElem **m_array14;
public:
	void *rva003B8BAA();
	void *rva003B8BF9(int index);
};

struct Rva00DFEF10Global
{
	char m_pad[0xB4];
	unsigned char m_flagB4;
};
#define TheRva00DFEF10 (*(Rva00DFEF10Global **)0x00DFEF10)

void *Rva003B8BAA::rva003B8BAA()
{
	if (TheRva00DFEF10->m_flagB4 == 0)
		return 0;
	Rva003B8BAAElem *elem = m_array14[m_index10];
	return elem->m_ptr20;
}

// ?rva003B8BF9@Rva003B8BAA@@QAEPAXH@Z @0x003B8BF9 13B.
// Index-arg array fetch from the same +0x14 array: mov eax,[ecx+0x14]; mov ecx,[esp+4];
// mov eax,[eax+ecx*4]; ret 4. Callers at 0x00522434 0x0056DB3B 0x0057D286.
void *Rva003B8BAA::rva003B8BF9(int index)
{
	return m_array14[index];
}
