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
};

Object *Team::rva0039E8EB()
{
	DLINK_ITERATOR<Object> iter = iterate_TeamMemberList();
	return iter.cur();
}
