// ?rva0034BA20@Rva0034BA20@@QAEPAVRva0034B952@@XZ
// partial score=0.95 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc
class AsciiString
{
public:
	void *m_data;
};
class Object;
class Rva004D759C
{
public:
	Rva004D759C(Object *owner, AsciiString name, bool flag);
	virtual ~Rva004D759C();
	char m_pad[0x3c - 4];
};
class Rva0034B952 : public Rva004D759C
{
public:
	Rva0034B952(Object *owner, AsciiString name);
};
static AsciiString MakeName()
{
	AsciiString n = { (void *)0x72383AF5 };
	return n;
}
class Rva0034BA20
{
public:
	Rva0034B952 *rva0034BA20();
private:
	char m_pad[0x14];
	Object *m_owner;
};
// ?rva0034BA20@Rva0034BA20@@QAEPAVRva0034B952@@XZ present-unmatched
Rva0034B952 *Rva0034BA20::rva0034BA20()
{
	return new Rva0034B952(m_owner, MakeName());
}
