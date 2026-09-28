// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0031D5F8@Rva0031D5F8@@QAEPAXPBVAsciiString@@@Z, retail 0x0031D5F8 (38B).
// Lookup AsciiString key in the Rva00056F61 bucket table at this+0x30 via
// rowed ?rva0041534B@Rva00056F61@@QAE?AURva0041534BIter@@PBVAsciiString@@@Z,
// returning payload at node+8 or NULL when the iterator node is NULL.
// Callers at 0x00219317 0x0031D623 0x0031D914 0x0031DFC7 prove the
// thiscall shape with one AsciiString arg and pointer return used as this.
class AsciiString
{
	char *m_text;
};

class Rva00056F61;
struct Rva0041534BIter
{
	void *m_node;
	Rva00056F61 *m_table;
	Rva0041534BIter(void *n, Rva00056F61 *t) : m_node(n), m_table(t) {}
};

class Rva00056F61
{
public:
	void *rva00056F61(const AsciiString *key);
	Rva0041534BIter rva0041534B(const AsciiString *key);
};

class Rva0031D5F8
{
public:
	void *rva0031D5F8(const AsciiString *key);
	char m_pad[0x30];
	Rva00056F61 m_table;
};

void *Rva0031D5F8::rva0031D5F8(const AsciiString *key)
{
	Rva0041534BIter iter = m_table.rva0041534B(key);
	if (iter.m_node)
		return *(void **)((char *)iter.m_node + 8);
	return 0;
}
