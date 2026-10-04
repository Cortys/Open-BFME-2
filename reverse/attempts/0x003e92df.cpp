// ?evaluateNamedUnitRankLevel@ScriptConditions@@IAE_NPAVParameter@@0@Z
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /arch:SSE2 /O1
// ?evaluateNamedUnitRankLevel@ScriptConditions@@IAE_NPAVParameter@@0@Z @0x003E92DF 148B
// Target evidence: retail pushes Parameter* to rowed getUnitNamed 0x003588E7,
// warn-once byte at 0x00E02E34, string at 0x00835B8C, rowed concat 0x00006987,
// rowed AppendDebugMessage 0x00205263, Object+0x264 null-checked then +0x24
// compared >= with second Parameter+0x08, ret 8. Donor: BFME1
// game/GameEngine/Source/GameLogic/ScriptEngine/ScriptConditionsNamedUnit.cpp
// evaluateNamedUnitRankLevel (same name/mangled/shape, Body+0x28 rank there).
// Target layout from Rva003E514F/Rva003BC96F siblings: Object+0x264 inner
// with rank at +0x24, not donor +0x210/+0x28.
#include "ascii_string.h"

class Parameter
{
public:
	const AsciiString &getString() const { return m_string; }
	int getInt() const { return m_int; }
	unsigned char m_beforeInt[8];
	int m_int;
	float m_real;
	AsciiString m_string;
	unsigned char m_afterString[8];
};

class ObjectInner003E92DF
{
public:
	unsigned char m_beforeRank[0x24];
	int m_rankLevel;
};

class Object
{
public:
	unsigned char m_beforeBody[0x264];
	ObjectInner003E92DF *m_body;
};

class ScriptEngine
{
public:
	Object *getUnitNamed(Parameter *);
	void AppendDebugMessage(const AsciiString &, bool);
};
extern ScriptEngine *g_Va009FE16C;
extern bool g_00E02E34;

class ScriptConditions
{
protected:
	bool evaluateNamedUnitRankLevel(Parameter *, Parameter *);
};

// ?evaluateNamedUnitRankLevel@ScriptConditions@@IAE_NPAVParameter@@0@Z present-unmatched
bool ScriptConditions::evaluateNamedUnitRankLevel(Parameter *pUnitParm, Parameter *pRankParm)
{
	Object *pUnit = g_Va009FE16C->getUnitNamed(pUnitParm);
	if (pUnit == 0) {
		if (!g_00E02E34) {
			g_00E02E34 = true;
			AsciiString message("ScriptConditions::evaluateNamedUnitRankLevel: Unit not found: ");
			message += pUnitParm->getString();
			g_Va009FE16C->AppendDebugMessage(message, false);
		}
		return false;
	}
	ObjectInner003E92DF *body = pUnit->m_body;
	if (body == 0)
		return false;
	return body->m_rankLevel >= pRankParm->getInt();
}
