// cl: /O1 /MD
//
// ?rva003628A6@Rva003628A6@@QAEXPAX@Z retail 0x003628A6 45 bytes. Recursive
// list free with same-this child call then free then next. Evidence: caller
// 0x00362AB5 passes node link, rowed _free, ret 4 thiscall 1 ptr arg.

extern "C" void __cdecl free(void *block);

struct Rva003628A6Node
{
	int m_00;
	int m_04;
	Rva003628A6Node *m_08;
	Rva003628A6Node *m_0C;
};

class Rva003628A6
{
public:
	void rva003628A6(void *head);
};

void Rva003628A6::rva003628A6(void *head)
{
	Rva003628A6Node *cur = (Rva003628A6Node *)head;
	if (cur == 0)
		return;
	do
	{
		rva003628A6(cur->m_0C);
		Rva003628A6Node *next = cur->m_08;
		free(cur);
		cur = next;
	} while (cur != 0);
}
