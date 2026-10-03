// ?rva003E4921@ScriptConditions@@QAE_NPAVParameter@@@Z
// partial score=0.97 date=2026-10-03
// ?rva003E4921@ScriptConditions@@QAE_NPAVParameter@@@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /EHsc
// ?rva003E4921@ScriptConditions@@QAE_NPAVParameter@@@Z @0x003E4921 151B gate condition via rowed getUnitNamed 0x003588E7 plus rowed nameToKey 0x00148E1A plus rowed findModule 0x0028B6D6.
// Evidence: vslot slot 17 of 0x00835B38; caller none; static GateOpenAndCloseBehavior key; donor BFME1 ScriptActionsGates.
class AsciiString;
enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class Parameter;
class Object;
class Module;

class ScriptEngine
{
public:
	Object *getUnitNamed(Parameter *parameter);
};
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};
#define TheNameKeyGenerator (*(NameKeyGenerator **)0x00DF36A4)

class Module
{
public:
	virtual void moduleSlot();
};

class Object
{
	friend class ScriptConditions;
protected:
	Module *findModule(NameKeyType key) const;
};

class GateOpenAndCloseBehaviorView
{
public:
	virtual void slot00() = 0;
	virtual void slot01() = 0;
	virtual void slot02() = 0;
	virtual void slot03() = 0;
	virtual void slot04() = 0;
	virtual void slot05() = 0;
	virtual bool stateIsOne() = 0;
	virtual void slot07() = 0;
	virtual void slot08() = 0;
	virtual void slot09() = 0;
	virtual bool isReady() = 0;
	virtual void slot11() = 0;
	virtual void slot12() = 0;
	int m_pad40[15];
	int m_state40;
};

class ScriptConditions
{
public:
	bool rva003E4921(Parameter *param);
};

bool ScriptConditions::rva003E4921(Parameter *param)
{
	Object *object = TheScriptEngine->getUnitNamed(param);
	bool result;
	if (object)
	{
		static NameKeyType gateKey = TheNameKeyGenerator->nameToKey("GateOpenAndCloseBehavior");
		Module *module = object->findModule(gateKey);
		GateOpenAndCloseBehaviorView *gate = module ? (GateOpenAndCloseBehaviorView *)((char *)module - 4) : 0;
		result = gate != 0 && gate->isReady() && (gate->m_state40 <= 0 || gate->stateIsOne());
	}
	else
		result = false;
	return result;
}
