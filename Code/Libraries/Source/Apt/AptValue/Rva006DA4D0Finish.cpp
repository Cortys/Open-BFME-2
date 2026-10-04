// ??0BfmeAptValue006DCD20@@QAE@HPAPAV0@@Z
// cl: /O2 /MD
extern "C" void *__cdecl memmove(void *, const void *, unsigned int);
class BfmeAptValue006DCD20;
class Rva006D6360 { public: Rva006D6360(int type, int size); virtual ~Rva006D6360(); char m_pad[0x18]; };
class Rva006D6470Owner : public Rva006D6360
{
public:
	Rva006D6470Owner(int type, int size) : Rva006D6360(type, size)
	{
		*(unsigned char *)&m_bits = 0;
		m_bits &= 0xFFFFFCFF;
	}
	virtual ~Rva006D6470Owner();
	unsigned int m_bits;
};
class BfmeAptValue006DCD20 : public Rva006D6470Owner
{
public:
	virtual void slot0();
	virtual void slot1();
	int isArray() const;
	BfmeAptValue006DCD20 *rva006DCFA0();
	void rva006D9500(int nCapacity);
	void rva006D8AD0(int nIndex, BfmeAptValue006DCD20 *pNewValue);
	BfmeAptValue006DCD20(int count, BfmeAptValue006DCD20 **pValues);
	BfmeAptValue006DCD20 **m_data;
	int mnCapacity;
	int mnLength;
};
BfmeAptValue006DCD20::BfmeAptValue006DCD20(int count, BfmeAptValue006DCD20 **pValues)
	: Rva006D6470Owner(0x16, count)
{
	mnCapacity = 0;
	m_data = 0;
	mnLength = count;
	rva006D9500(count);
	for (int i = 0; i < mnLength; ++i)
		rva006D8AD0(i, pValues[i]);
}
