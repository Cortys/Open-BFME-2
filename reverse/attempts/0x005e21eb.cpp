// ??0Rva005E21EB@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /MD /EHsc
// ??0Rva005E21EB@@QAE@XZ @0x005E21EB 59B: ctor stores vtable 0x00877AB8 then clears +0x0C via rowed Rva000AD6F4::clear then calls rowed apply setter; caller 0x005E25B4 28B plus thunk; prev Rva005E2138 next Rva005E2D74; no donor.
class Rva000AD6F4
{
public:
	void clear();
	~Rva000AD6F4();
};

class Rva0004E84A4DwordImmSetter
{
public:
	void apply() throw();
};

class Rva005E21EB
{
public:
	virtual ~Rva005E21EB();
	Rva005E21EB();
private:
	int m_04;
	int m_08;
	Rva000AD6F4 m_0C;
};

// ??0Rva005E21EB@@QAE@XZ present-unmatched
Rva005E21EB::Rva005E21EB()
{
	m_0C.clear();
	((Rva0004E84A4DwordImmSetter *)this)->apply();
}
