// cl: /O1 /MD
// ??1AISpecialPowerUpdateModuleData@@UAE@XZ @0x004B300F, 48B.
// Virtual dtor slot evidence: ??_G at 0x004B2FF3 (rowed, slot 0 of vtable
// 0x00C4A298? caller) calls here. Destroys AsciiString at +0x08 via pinned
// 0x00036410 then restores base vtable 0x00BBB554 with trivial base inlined
// (no base call). Layout from ctor (string +0x08, factory news) and INI
// table. UpgradeModuleDataDtor / SlavedUpdateModuleDataDtor precedent
// (novtable suppresses derived store).
class Snapshot
{
public:
	virtual ~Snapshot();
};

inline Snapshot::~Snapshot()
{
	*(const void **)this = reinterpret_cast<const void *>(0x00BBB554);
}

class AsciiString
{
public:
	~AsciiString();

private:
	void *m_data;
};

class __declspec(novtable) AISpecialPowerUpdateModuleData : public Snapshot
{
public:
	virtual ~AISpecialPowerUpdateModuleData();

private:
	unsigned char m_pad[0x08 - 4];
	AsciiString m_name; // +0x08
};

AISpecialPowerUpdateModuleData::~AISpecialPowerUpdateModuleData()
{
}
