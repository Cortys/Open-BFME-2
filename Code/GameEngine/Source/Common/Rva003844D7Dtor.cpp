// cl: /O1 /MD /EHs
// ??1Rva003844D7@@QAE@XZ @0x003844D7 119B derived dtor: 5 members at
// +0x154/+0x160/+0x16c/+0x178/+0x184 via rowed 0x00383276/0x0038323E/0x003832AE
// then base ??1Rva00383D71 at +0 rowed in Rva00383D71Dtor.cpp. Callers
// 0x0038535F 0x0038539E unclaimed thiscall. No vptr store so non-virtual QAE.
class Rva0038201D
{
public:
	~Rva0038201D();
private:
	char m_pad[12];
};

class Rva0038204A
{
public:
	~Rva0038204A();
private:
	char m_pad[12];
};

class Rva00382077
{
public:
	~Rva00382077();
private:
	char m_pad[12];
};

class Rva00383D71
{
public:
	~Rva00383D71();
private:
	char m_pad[0x154];
};

class Rva003844D7 : public Rva00383D71
{
public:
	~Rva003844D7();
private:
	Rva00382077 m_154;
	Rva0038201D m_160;
	Rva0038201D m_16c;
	Rva0038204A m_178;
	Rva0038204A m_184;
};

Rva003844D7::~Rva003844D7()
{
}
