// cl: /DNDEBUG /MD /O2
// Open-BFME-1 donor at cd32c8ef06dfb0d995b2f47e93e41622e4447092:
// Rva007F3850Constructor.cpp, BFME1 RVA 0x007F3850.
// BFME2 installs the same derived vptr pair as its matched factory at
// 0x00660BB0, with the secondary-base payload at +8.

class Q3MakeBaseA
{
public:
	virtual void primary();
};

class Q3MakeBaseB
{
public:
	virtual void secondary();
	void *m_payload;
	Q3MakeBaseB(void *payload) : m_payload(payload) {}
};

class Rva007F40F0Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007F40F0Object(void *payload);
	virtual void primary();
	virtual void secondary();
};

Rva007F40F0Object::Rva007F40F0Object(void *payload)
	: Q3MakeBaseB(payload)
{
}
