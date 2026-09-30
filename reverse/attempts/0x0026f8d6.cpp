// ?rva0026F8D6@Rva0026F8D6@@QAEXXZ
// partial score=0.93 date=2026-09-30
// ?rva0026F8D6@Rva0026F8D6@@QAEXXZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /G7 /DNDEBUG /MD /EHsc
// stlport
// ?rva0026F8D6@Rva0026F8D6@@QAEXXZ @0x0026F8D6 102B
// Evidence: after Rva0026F684 deleting dtor; vector AsciiString at +0x10 via rowed erase 0x0002CCFC plus vector ModuleData at +0x1c via rowed reserve 0x002B712E and push_back 0x004DFCB0 plus rowed findUpgrade 0x0026F26D plus global 0x00DFEB60; caller 0x0026F944.
#include <vector>

class AsciiString
{
	void *m_data;
};

class ModuleData
{
};

class UpgradeTemplate : public ModuleData
{
};

class UpgradeCenter
{
public:
	const UpgradeTemplate *findUpgrade(const AsciiString &name) const;
};

extern UpgradeCenter *g_00DFEB60;

class Rva0026F8D6
{
public:
	void rva0026F8D6();
private:
	char m_pad00[0x10];
	_STL::vector<AsciiString> m_10;
	_STL::vector<const ModuleData *> m_1C;
};

void Rva0026F8D6::rva0026F8D6()
{
	_STL::vector<AsciiString> &names = m_10;
	if (names.empty())
		return;
	register unsigned int n = names.size();
	m_1C.reserve(n);
	for (register unsigned int i = 0; i < n; ++i)
	{
		const UpgradeTemplate *t = g_00DFEB60->findUpgrade(names[i]);
		if (t)
			m_1C.push_back(t);
	}
	names.erase(names.begin(), names.end());
}
