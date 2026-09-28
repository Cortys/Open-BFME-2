// cl: /DNDEBUG /MD /O1
// ?rva00528BDD@Rva00528BDD@@QAEXXZ retail 0x00528BDD 36B
// Evidence: UI invoke via 0x00222A8B with HideCostModifierUpgradeInterface plus global 0x009FE4CC; clears +4; callers 0x00528F30 0x0052914B
class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern Rva00222A8BTarget *TheRva00222A8BTarget;

class Rva00528BDD
{
public:
	void rva00528BDD();
private:
	void *m_owner;
	bool m_flag04;
};

void Rva00528BDD::rva00528BDD()
{
	TheRva00222A8BTarget->invoke(m_owner, "HideCostModifierUpgradeInterface", 0, 0, 0, 0, 0, 0);
	m_flag04 = false;
}

class Rva00528B98
{
public:
	void rva00528B98();
private:
	void *m_owner;
	bool m_flag04;
};

void Rva00528B98::rva00528B98()
{
	if (!m_flag04)
		return;
	TheRva00222A8BTarget->invoke(m_owner, "HideRankInterface", 0, 0, 0, 0, 0, 0);
	m_flag04 = false;
}
