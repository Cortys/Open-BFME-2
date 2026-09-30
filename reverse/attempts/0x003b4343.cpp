// ?setActionType@ScriptAction@@QAEXW4ScriptActionType@1@@Z
// partial score=0.91 date=2026-09-30
// ?setActionType@ScriptAction@@QAEXW4ScriptActionType@1@@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
// ?setActionType@ScriptAction@@QAEXW4ScriptActionType@1@@Z retail 0x003B4343 137 bytes.
// BFME1 donor game/GameEngine/Source/GameLogic/ScriptEngine/Scripts.cpp
// ScriptAction::setActionType: frees old parms, stores type, looks up the
// ActionTemplate via ScriptEngine, reads num params, news each Parameter.
// Retail deltas: plain ::delete inlined to rowed releaseBuffer 0x00036410
// plus rowed ??3 (not pooled deleteInstance); Parameter size 0x28 with the
// AsciiString at +0x10; Template layout from TemplateGetParameterType.cpp
// (m_numParameters +0x48). Caller 0x003B5413 is the ScriptAction ctor
// (vtable 0x0081F3FC) which passes its type arg through.

template <typename T>
class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	__forceinline ~AsciiString() {}
};

void __cdecl operator delete(void *ptr);

class Parameter
{
public:
	enum ParameterType
	{
		INT = 0
	};
	Parameter(ParameterType type, int val = 0) throw();
	__forceinline ~Parameter() {}
	void deleteInstance() { this->~Parameter(); ::operator delete(this); }
private:
	char m_head[0x10];
	AsciiString m_string; // +0x10
	char m_tail[0x28 - 0x14];
};

class Template
{
public:
	int getNumParameters() const throw() { return m_numParameters; }
	Parameter::ParameterType getParameterType(int ndx) const throw();
private:
	char m_pad[0x48];
	int m_numParameters; // +0x48
	Parameter::ParameterType m_parameters[12]; // +0x4C
};

class ActionTemplate : public Template
{
};

class ScriptEngine
{
public:
	const ActionTemplate *getActionTemplate(int type) throw();
};
extern ScriptEngine *g_Va009FE16C;

enum { MAX_PARMS = 12 };

class ScriptAction
{
public:
	enum ScriptActionType
	{
		NO_OP = 5
	};
	void setActionType(ScriptActionType type);
private:
	void *m_vtable; // +0x00
	int m_actionType; // +0x04
	int m_numParms; // +0x08
	Parameter *m_parms[MAX_PARMS]; // +0x0C
};

// ?setActionType@ScriptAction@@QAEXW4ScriptActionType@1@@Z present-unmatched
void ScriptAction::setActionType(ScriptActionType type)
{
	int i;
	for (i = 0; i < m_numParms; i++) {
		if (m_parms[i])
			m_parms[i]->deleteInstance();
		m_parms[i] = 0;
	}
	m_actionType = type;
	const ActionTemplate *pTemplate = g_Va009FE16C->getActionTemplate(m_actionType);
	m_numParms = pTemplate->getNumParameters();
	for (i = 0; i < m_numParms; i++) {
		m_parms[i] = new Parameter(pTemplate->getParameterType(i));
	}
}
