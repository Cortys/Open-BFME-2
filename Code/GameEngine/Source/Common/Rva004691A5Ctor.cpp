// cl: /O1 /arch:SSE /MD
// ??0Rva004691A5@@QAE@XZ 0x004691A5 18B evidence: and-or inc O1 idioms plus movss; caller 0x474431 constructs 0x1C-byte stack record
class Rva004691A5
{
public:
	Rva004691A5();

private:
	int m_00;
	char m_pad04[0x10];
	float m_14;
	int m_18;
};

Rva004691A5::Rva004691A5() : m_00(0), m_14(0.0f), m_18(-1)
{
}

class Rva00469155
{
public:
	Rva00469155();

private:
	float m_00;
	float m_04;
	float m_08;
	int m_0C;
};

Rva00469155::Rva00469155() : m_0C(0)
{
	m_00 = 0.0f;
	m_04 = 0.0f;
	m_08 = 0.0f;
}
