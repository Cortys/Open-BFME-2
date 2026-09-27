// ?setConditionType@Condition@@QAEXW4ConditionType@1@@Z
// partial score=0.93 date=2026-09-27
// ?setConditionType@Condition@@QAEXW4ConditionType@1@@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /GX-
// probe setConditionType

template <typename T>
class StringBase
{
public:
	StringBase() : m_data(0) {}
	~StringBase();
private:
	T *m_data;
};

class Parameter
{
public:
	enum ParameterType
	{
		INT = 0
	};
	Parameter(ParameterType type, int val = 0);
public:
	ParameterType m_paramType;
	bool m_initialized;
	char m_pad[3];
	int m_int;
	float m_real;
	StringBase<char> m_string;
	float m_coordX;
	float m_coordY;
	float m_coordZ;
	unsigned int m_status0;
	unsigned int m_status1;
};

class Template
{
public:
	Parameter::ParameterType getParameterType(int ndx) const;
	int getNumParameters() const { return m_numParameters; }
private:
	char m_pad[0x48];
	int m_numParameters;
	Parameter::ParameterType m_parameters[12];
};

class ConditionTemplate : public Template
{
};

class ScriptEngine
{
public:
	const ConditionTemplate *getConditionTemplate(int id);
};
extern ScriptEngine *TheScriptEngine;

class Condition
{
public:
	enum ConditionType
	{
		CONDITION_FALSE = 0
	};
	void setConditionType(ConditionType type);
	virtual ~Condition();
private:
	ConditionType m_conditionType;
	int m_numParms;
	Parameter *m_parms[12];
	Condition *m_nextAndCondition;
	int m_hasWarnings;
	int m_customData;
	unsigned int m_customFrame;
	unsigned char m_extraA;
	unsigned char m_extraB;
	char m_tailPad[2];
};

// ?setConditionType@Condition@@QAEXW4ConditionType@1@@Z present-unmatched
void Condition::setConditionType(ConditionType type)
{
	int i;
	for (i = 0; i < m_numParms; i++) {
		Parameter *p = m_parms[i];
		if (p) {
			p->m_string.~StringBase<char>();
			::operator delete(p);
		}
		m_parms[i] = 0;
	}
	m_conditionType = type;
	const ConditionTemplate *pTemplate = TheScriptEngine->getConditionTemplate(m_conditionType);
	m_numParms = pTemplate->getNumParameters();
	for (i = 0; i < m_numParms; i++) {
		m_parms[i] = new Parameter(pTemplate->getParameterType(i));
	}
}
