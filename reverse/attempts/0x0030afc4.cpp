// ??0Rva00985E4@@QAE@XZ
// partial score=0.93 date=2026-09-28
// ??0Rva00985E4@@QAE@XZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /arch:SSE /MD /EHsc /DNDEBUG
// ??0Rva00985E4@@QAE@XZ 0x0030AFC4 55B evidence: vtable 0x7C8318 same as dtor 0x985E4; base ctor 0x1B4E63; caller 0x98667
class AsciiString
{
public:
	AsciiString() : m_data(0) {}
	~AsciiString();

private:
	void *m_data;
};

class SubsystemInterface
{
public:
	SubsystemInterface();
	virtual ~SubsystemInterface();

private:
	int m_04;
	AsciiString m_name;
};

class Rva00985E4 : public SubsystemInterface
{
public:
	Rva00985E4();

private:
	AsciiString m_0C;
	AsciiString m_10;
	int m_14[7];
	int m_30;
	float m_34;
	float m_38;
	int m_3C;
	float m_40;
	float m_44;
};

// ??0Rva00985E4@@QAE@XZ present-unmatched
Rva00985E4::Rva00985E4()
{
	m_30 = 0;
	m_34 = 0.0f;
	m_38 = 0.0f;
	m_3C = 0;
	m_40 = 0.0f;
	m_44 = 0.0f;
}
