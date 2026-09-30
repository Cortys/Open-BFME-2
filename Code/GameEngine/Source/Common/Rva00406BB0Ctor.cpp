// cl: /O1 /EHsc /MD
// ??0Rva00406BB0@@QAE@ABV?$StringBase@G@@H@Z @0x00406B6A 70B: ctor with wide string + int.
// Layout from rowed copy ctor 0x00406BB0 in Rva00406BB0CopyCtor.cpp: base with
// declared dtor for EH state 0, StringBase<wchar_t> at +4 via rowed copy ctor
// 0x00037050, int at +8, then rowed Init 0x00220DCD. Vtable 0x00838BA4.
// Caller 0x002169F0.
template <typename T>
class StringBase
{
public:
	StringBase(const StringBase &other);
	~StringBase() { releaseBuffer(); }

private:
	void releaseBuffer();
	void *m_data;
};

class Rva00406BB0Base
{
public:
	Rva00406BB0Base() {}
	Rva00406BB0Base(const Rva00406BB0Base &other) {}
	virtual ~Rva00406BB0Base();
	virtual void keep() {}
};

void __cdecl Rva00220DCDInit();

class Rva00406BB0 : public Rva00406BB0Base
{
public:
	Rva00406BB0(const StringBase<unsigned short> &s, int v);
private:
	StringBase<unsigned short> m_str04;
	int m_08;
};

Rva00406BB0::Rva00406BB0(const StringBase<unsigned short> &s, int v)
	: m_str04(s), m_08(v)
{
	Rva00220DCDInit();
}
