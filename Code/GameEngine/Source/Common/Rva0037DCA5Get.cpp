// cl: /O1 /DNDEBUG /MD
// ?rva0037DCA5@Rva0037DCA5@@QAEHXZ, retail 0x0037DCA5 (39B).
// Lookup via TheThingFactory global 0x00DFF000 plus AsciiString at +0x4 through
// rowed 0x002D06CA. Returns 0 when lookup misses else template dword at +0x618
// times int at +0x90. Sibling of rowed 0x0037E270 (same global and callee via
// Rva0037E270Lookup.cpp) and unclaimed 0x0037DC52 (same +0x4 lookup shape).
// Callers at 0x002B369C 0x002B36A5 0x002B6C58 0x0031906A 0x0040CFAC.
class AsciiString
{
	char *m_text;
};
class Rva002D06CA
{
public:
	void *rva002D06CA(const AsciiString *key);
};
#define TheThingFactory (*(Rva002D06CA **)0x00DFF000)
struct Rva0037DCA5Template
{
	char m_pad[0x618];
	int m_cost;
};
class Rva0037DCA5
{
	char m_pad0[4];
	AsciiString m_name;
	char m_pad8[0x90 - 8];
	int m_count;
public:
	int rva0037DCA5();
	void *rva0037DC52();
};
int Rva0037DCA5::rva0037DCA5()
{
	void *found = TheThingFactory->rva002D06CA(&m_name);
	if (found == 0)
		return 0;
	return ((Rva0037DCA5Template *)found)->m_cost * m_count;
}
// ?rva0037DC52@Rva0037DCA5@@QAEPAXXZ @0x0037DC52 16B same +0x4 lookup via 0x002D06CA and global 0x00DFF000.
void *Rva0037DCA5::rva0037DC52()
{
	return TheThingFactory->rva002D06CA(&m_name);
}
