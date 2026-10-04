// cl: /O1 /EHs-c-
// ??0Rva003ADC75@@QAE@ABV0@@Z @0x003ADC75 82B MI copy via rowed bases 0x003ADDCD and 0x003ADCC7 with three derived vptrs and three dwords at +0x50. Evidence: callees rowed; caller 0x003ADC56; same MI null-check shape as 0x003ADF21; chain from just-landed 0x003ADCC7 0x003ADDCD.
struct Keyframe003ADC75
{
	float m_value;
	unsigned int m_frame;
};
struct Block003ADC75
{
	Keyframe003ADC75 k[8];
};
class V3First003ADC75
{
public:
	virtual void s0();
	virtual ~V3First003ADC75() {}
	int m04;
};
class V3Second003ADC75
{
public:
	virtual void s0();
	virtual ~V3Second003ADC75() {}
};
class Rva0055BCD2 : public V3First003ADC75, public V3Second003ADC75
{
public:
	Rva0055BCD2(const Rva0055BCD2 &other);
};
class Rva0055B32B
{
public:
	virtual ~Rva0055B32B();
	Rva0055B32B(const Rva0055B32B &other);
private:
	Block003ADC75 m_b;
};
class Rva003ADC75 : public Rva0055BCD2, public Rva0055B32B
{
public:
	Rva003ADC75(const Rva003ADC75 &other);
private:
	int m_50;
	int m_54;
	int m_58;
};
Rva003ADC75::Rva003ADC75(const Rva003ADC75 &other)
	: Rva0055BCD2(other)
	, Rva0055B32B(other)
	, m_50(other.m_50)
	, m_54(other.m_54)
	, m_58(other.m_58)
{
}
