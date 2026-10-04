// cl: /O1 /MD
// ?rva003F8090@Rva003F8090@@QAEXXZ, retail 0x003F8090 (31B).
// Evidence: chain lane calls rowed 0x003F7F30; offsets +0xc begin +0x10 end +0x18 flag.
class Rva003F7F30
{
public:
	void rva003F7F30();
};

class Rva003F8090
{
public:
	void rva003F8090();
private:
	char m_00[0xc];
	Rva003F7F30 **m_0c;
	Rva003F7F30 **m_10;
	char m_14[4];
	int m_18;
};

void Rva003F8090::rva003F8090()
{
	m_18 = -1;
	Rva003F7F30 **p = m_0c;
	Rva003F7F30 **e = m_10;
	while (p != e)
	{
		(*p)->rva003F7F30();
		++p;
	}
}
