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
	Rva00469155 &operator=(const Rva00469155 &o);

private:
	struct Float3
	{
		float x;
		float y;
		float z;
	};
	Float3 m_pos;
	int m_0C;
};

Rva00469155::Rva00469155() : m_0C(0)
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_pos.z = 0.0f;
}

Rva00469155 &Rva00469155::operator=(const Rva00469155 &o)
{
	m_pos = o.m_pos;
	m_0C = o.m_0C;
	return *this;
}
