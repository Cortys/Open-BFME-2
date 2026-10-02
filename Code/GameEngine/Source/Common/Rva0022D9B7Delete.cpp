// cl: /O1 /MD
// ?rva0022D9B7@Rva0022DB29@@QAEXPAURva0022D9B7Node@@@Z @0x0022D9B7 28B: node delete calls rowed ??1Rva0022CFE6 at 0x0022CFE6 for +4 then rowed _free 0x00030830. Evidence: chain packet you-just-landed callee plus 28B lea-ecx+4 call-test-je free shape; caller 0x0022DB29 passes own this in ecx plus node push for linked-list traversal via +0.
class Rva0022CFE6
{
public:
	~Rva0022CFE6();
};
extern "C" void __cdecl free(void *);
struct Rva0022D9B7Node
{
	Rva0022D9B7Node *m_next;
	Rva0022CFE6 m_val;
};
class Rva0022DB29
{
public:
	void rva0022D9B7(Rva0022D9B7Node *node);
};
void Rva0022DB29::rva0022D9B7(Rva0022D9B7Node *node)
{
	node->m_val.~Rva0022CFE6();
	if (node)
		free(node);
}
