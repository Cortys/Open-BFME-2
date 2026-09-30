// cl: /O1 /DNDEBUG /MD /arch:SSE
// ??0Rva0056224F@@QAE@XZ @0x0056224F 87B: frameless ctor storing vtable
// 0x81D358, 1.0f at +0x4/+0x8/+0xC via 0x7BB8D8, 0.0f at +0x10..+0x30,
// 1 at +0x34. Called once from 0x562389.

class Rva0056224F
{
public:
	Rva0056224F();
	virtual ~Rva0056224F();

private:
	float m_04;
	float m_08;
	float m_0C;
	float m_10;
	float m_14;
	float m_18;
	float m_1C;
	float m_20;
	float m_24;
	float m_28;
	float m_2C;
	float m_30;
	int m_34;
};

Rva0056224F::Rva0056224F()
{
	m_04 = 1.0f;
	m_08 = 1.0f;
	m_0C = 1.0f;
	m_10 = 0.0f;
	m_14 = 0.0f;
	m_18 = 0.0f;
	m_1C = 0.0f;
	m_20 = 0.0f;
	m_24 = 0.0f;
	m_28 = 0.0f;
	m_2C = 0.0f;
	m_30 = 0.0f;
	m_34 = 1;
}
