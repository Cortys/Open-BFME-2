// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
//
// ?rva00330D3E@RadiusDecalTemplate@@QAEMI@Z @0x00330D3E 83B
// Unlock lane: lerp between +0x20/+0x24 over count +0x28 with clamp to max.
// (max-min)/count step, t=(index-1)*step+min, if t>max return max.
// Callers 0x00330E3E 0x003312B3.
class AsciiString
{
public:
	AsciiString();
	AsciiString(const AsciiString &other);
	~AsciiString();
	static AsciiString TheEmptyString;
private:
	void *m_data;
};
class RadiusDecalTemplate
{
public:
	float rva00330D3E(unsigned int index);
private:
	AsciiString m_name; // +0x00
	AsciiString m_secondName; // +0x04
	int m_shadowType; // +0x08
	float m_minOpacity; // +0x0C
	float m_maxOpacity; // +0x10
	float m_opacityThrobTime; // +0x14
	unsigned int m_color; // +0x18
	bool m_onlyVisibleToOwningPlayer; // +0x1C
	float m_unmodelled20; // +0x20
	float m_unmodelled24; // +0x24
	unsigned int m_unmodelled28; // +0x28
	float m_unmodelled2C; // +0x2C
	float m_unmodelled30; // +0x30
};

float RadiusDecalTemplate::rva00330D3E(unsigned int index)
{
	float step = (m_unmodelled24 - m_unmodelled20) / (float)m_unmodelled28;
	unsigned int i = index - 1;
	float t = (float)i * step + m_unmodelled20;
	if (t > m_unmodelled24)
		t = m_unmodelled24;
	return t;
}
