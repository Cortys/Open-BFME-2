// cl: /O1 /DNDEBUG /MD /G7
//
// RadarUpgrade::upgradeImplementation, retail 0x004B488F (68 bytes): slot 10
// of the +0x10 UpgradeMux vtable 0x00C57848 installed by the matched
// RadarUpgrade ctor. The body is the Zero Hour RadarUpgrade.cpp one: the
// controlling player's addRadar (pinned 0x002AA91F) with the module data
// disable-proof bool (+0x118), then the object's RadarUpdate module, found by
// the RadarUpdate name key, extends its radar (rowed 0x004A0D0F).
// /G7: retail pushes the bool without the P6 partial-register xor.
typedef bool Bool;
enum NameKeyType
{
	NAMEKEY_INVALID = 0
};
class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};
extern NameKeyGenerator *TheNameKeyGenerator;
class Player
{
public:
	void addRadar(Bool disableProof);
};
class Module;
class UpdateModule;
class Object
{
public:
	Player *getControllingPlayer() const;
	UpdateModule *findUpdateModule(NameKeyType key) const { return (UpdateModule *)findModule(key); }
protected:
	Module *findModule(NameKeyType key) const;
};
class RadarUpdate
{
public:
	void extendRadar();
};
class RadarUpgradeModuleData
{
public:
	unsigned char m_pad[0x118];
	Bool m_isDisableProof; // +0x118
};
class ModuleData;
class ObjectModuleBase
{
public:
	virtual ~ObjectModuleBase();
protected:
	Object *getObject() const { return m_object; }
	const ModuleData *m_moduleData; // +0x04
	Object *m_object; // +0x08
};
class UpgradeModuleInterface
{
public:
	virtual void upgradeModuleInterfaceAnchor();
};
template <int N> class RadarUpgradeMuxSlots : public RadarUpgradeMuxSlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class RadarUpgradeMuxSlots<0>
{
};
// UpgradeMux interface at +0x10: slot 8 upgradeRemovalImplementation, slot 9
// setUpgradeExecuted, slot 10 upgradeImplementation.
class UpgradeMuxIface : public RadarUpgradeMuxSlots<8>
{
protected:
	virtual void upgradeRemovalImplementation() = 0;
	virtual void setUpgradeExecuted(Bool executed) = 0;
	virtual void upgradeImplementation() = 0;
};
class UpgradeModule : public ObjectModuleBase, public UpgradeModuleInterface, public UpgradeMuxIface
{
};
class RadarUpgrade : public UpgradeModule
{
protected:
	virtual void upgradeImplementation();
private:
	const RadarUpgradeModuleData *getRadarUpgradeModuleData() const { return (const RadarUpgradeModuleData *)m_moduleData; }
};
void RadarUpgrade::upgradeImplementation()
{
	const RadarUpgradeModuleData *data = getRadarUpgradeModuleData();
	Player *player = getObject()->getControllingPlayer();

	// update the radar count
	player->addRadar(data->m_isDisableProof);

	// find the radar update module of this object
	NameKeyType radarUpdateKey = TheNameKeyGenerator->nameToKey("RadarUpdate");
	RadarUpdate *radarUpdate = (RadarUpdate *)getObject()->findUpdateModule(radarUpdateKey);
	if (radarUpdate)
		radarUpdate->extendRadar();
}
