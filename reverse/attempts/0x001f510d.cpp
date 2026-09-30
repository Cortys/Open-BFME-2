// ?rva001F510D@Rva001F510D@@QAEMXZ
// partial score=0.93 date=2026-09-30
// ?rva001F510D@Rva001F510D@@QAEMXZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD /arch:SSE /Oy-
//
// ?rva001F510D@Rva001F510D@@QAEMXZ, retail 0x001F510D, 34 bytes.
// Null-checked float getter via holder at +0x1B8 and virtual slot +0x10,
// 0.0f fallback via SSE/x87. Siblings Rva001F4E1BGet. Callers
// 0x1F74F6/0x55F061. Honest Rva names.

class Rva001F510DHelper
{
public:
	virtual ~Rva001F510DHelper();
	virtual void u1();
	virtual void u2();
	virtual void u3();
	virtual float get();
};

class Rva001F510D
{
public:
	float rva001F510D();
private:
	char m_pad00[0x1B8];
	Rva001F510DHelper *m_ptr;
};

float Rva001F510D::rva001F510D()
{
	volatile float zero = 0.0f;
	Rva001F510DHelper *p = m_ptr;
	if (p != 0)
		return p->get();
	return zero;
}
