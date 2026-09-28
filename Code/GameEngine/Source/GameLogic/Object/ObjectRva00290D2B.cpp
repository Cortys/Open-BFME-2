// cl: /O1 /DNDEBUG /MD
// ?rva00290D2B@Object@@QBE_NPBVUpgradeTemplate@@@Z retail 0x00290D2B 23B.
// Object null-guarded UpgradeTemplate bit test via rowed ?rva0028D9E5@Object@@QBE_NH@Z.
// Evidence: same-this preserved-ecx call to rowed Object bit query at 0x00290D3A with int at +0x38;
// UpgradeTemplate mask index at +0x38 per UpgradeCenterFindUpgradeByKey.cpp and UpgradeMuxData TU;
// twin precedent ?rva002AB87D@Player@@QBE_NPBVUpgradeTemplate@@@Z 23B same shape;
// neighbours ?isAbleToAttack@Object (0x00290B73) and ?findSpecialPowerModuleInterface@Object (0x00290E22);
// callers pass Object* in ecx plus UpgradeTemplate* on stack e.g. 0x00294B3C mov ecx ebx push edi.
class UpgradeTemplate
{
public:
	char m_pad[0x38];
	int m_bitIndex;
};

class Object
{
public:
	bool rva0028D9E5(int bit) const;
	bool rva00290D2B(const UpgradeTemplate *tmpl) const;
};

bool Object::rva00290D2B(const UpgradeTemplate *tmpl) const
{
	if (!tmpl)
		return false;
	return rva0028D9E5(tmpl->m_bitIndex);
}
