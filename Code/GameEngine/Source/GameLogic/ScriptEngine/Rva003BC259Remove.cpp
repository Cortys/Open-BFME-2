// cl: /O1
// ?Rva003BC259Remove@@YGXPAVParameter@@@Z @0x003BC259 34B: script action removing sequential scripts for a named unit.
// Evidence: calls rowed getUnitNamed 0x003588E7 with Parameter* then rowed ScriptEngine::rva0020517D 0x0020517D on the Object*; same g_Va009FE16C global and stdcall shape as Rva003BE26DGrantUpgrade; caller 0x003CCE3E in dispatch.
class Parameter;
class Object;

class ScriptEngine
{
public:
	Object *getUnitNamed(Parameter *param);
	void rva0020517D(Object *obj);
};

extern ScriptEngine *g_Va009FE16C;

void __stdcall Rva003BC259Remove(Parameter *param)
{
	Object *obj = g_Va009FE16C->getUnitNamed(param);
	if (obj == 0)
		return;
	g_Va009FE16C->rva0020517D(obj);
}
