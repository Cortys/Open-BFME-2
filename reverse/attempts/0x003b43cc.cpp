// ??1ScriptAction@@UAE@XZ
// partial score=0.91 date=2026-10-03
// cl: /O1 /DNDEBUG /MD
// ??1ScriptAction@@UAE@XZ @0x003B43CC (92B): ScriptAction dtor with vtable 0x00C1F3FC plus parms cleanup via Parameter dtor plus next chain via virtual delete. Evidence: caller 0x003B53FA deleting dtor pattern; rowed Parameter dtor 0x000B9AAA delete 0x0002FD60; ret void thiscall from retail bytes.
class Rva000B9AAA
{
public:
	~Rva000B9AAA();
};

class ScriptAction
{
public:
	virtual ~ScriptAction();
private:
	int m_actionType; // +4
	int m_numParms; // +8
	Rva000B9AAA *m_parms[12]; // +0x0C
	ScriptAction *m_nextAction; // +0x3C
};

// ??1ScriptAction@@UAE@XZ present-unmatched
ScriptAction::~ScriptAction()
{
	int i;
	for (i = 0; i < m_numParms; i++) {
		if (m_parms[i]) {
			delete m_parms[i];
		}
		m_parms[i] = 0;
	}
	ScriptAction *head = m_nextAction;
	while (head) {
		ScriptAction *nxt = head->m_nextAction;
		head->m_nextAction = 0;
		delete head;
		head = nxt;
	}
}
