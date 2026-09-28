// cl: /O1 /DNDEBUG /MD
//
// ?rva0039E8EB@Team@@QAEPAVObject@@XZ @0x0039E8EB (20B).
// Team::rva0039E8EB(): returns the first member of the team or null. Retail
// creates the 24-byte iterator via the pinned iterate_TeamMemberList at
// 0x263864 and returns its m_cur. Callers such as 0x003C02D6 pass Team ECX
// from getTeamNamed and null-check the returned Object*.

class Object;

template<class OBJCLASS>
class DLINK_ITERATOR
{
private:
	OBJCLASS *m_cur;
	unsigned char m_targetAbiState[20];

public:
	void advance();
	bool done() const { return m_cur == 0; }
	OBJCLASS *cur() const { return m_cur; }
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
	Object *rva0039E8EB();
	Object *rva0039E968(int bit);
};

Object *Team::rva0039E8EB()
{
	DLINK_ITERATOR<Object> iter = iterate_TeamMemberList();
	return iter.cur();
}

// ?rva0039E968@Team@@QAEPAVObject@@H@Z @0x0039E968 57B chain lane: first
// member whose rowed 0x0028D8EB test is 1 else null; 0x18B iterator via
// rowed iterate plus rowed Rva001705A0 advance; cmp al,1. The test and
// advance live under different iterator spellings (DLINK_ITERATOR vs
// Rva001705A0DlinkIterator, both 0x18B) so the calls go through narrow
// casts; the test class Rva0028D8EB is the honest placeholder for what reads
// as Object+0x3A4 at the call site.
class Rva0028D8EB
{
public:
	int rva0028D8EB(int bit);
};
template<class T> class Rva001705A0DlinkIterator
{
public:
	void advance();
};
Object *Team::rva0039E968(int bit)
{
	DLINK_ITERATOR<Object> iter = iterate_TeamMemberList();
	while (!iter.done()) {
		if ((char)((Rva0028D8EB *)iter.cur())->rva0028D8EB(bit) == 1)
			return iter.cur();
		((Rva001705A0DlinkIterator<Object> *)&iter)->advance();
	}
	return 0;
}
