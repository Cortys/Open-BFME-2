// cl: /O1 /MD
// ?rva001EDD1C@Rva001EDD1C@@QAEXXZ @0x001EDD1C 100B.
// Triple flag-gated value clamp at +0x4F24..+0x4F7C via push-pop immediates.
// Evidence: no callees; caller 0x001EE0B0 in 0x001EE069; same push-pop shape as /O1 idiom.
class Rva001EDD1C
{
public:
	void rva001EDD1C();
private:
	char m_pad0[0x4F24];
	int m_4F24;
	int m_4F28;
	int m_4F2C;
	int m_4F30;
	int m_4F34;
	int m_4F38;
	int m_4F3C;
	int m_4F40;
	int m_4F44;
	int m_4F48;
	int m_4F4C;
	int m_4F50;
	int m_4F54;
	int m_4F58;
	int m_4F5C;
	int m_4F60;
	int m_4F64;
	int m_4F68;
	int m_4F6C;
	int m_4F70;
	int m_4F74;
	int m_4F78;
	int m_4F7C;
};

void Rva001EDD1C::rva001EDD1C()
{
	if (m_4F24 != 0 && (m_4F64 == 5 || m_4F64 == 8))
		m_4F28 = 8;
	if (m_4F30 != 0 && (m_4F70 == 0xD || m_4F70 == 0x10))
		m_4F34 = 0x10;
	if (m_4F3C != 0 && (m_4F7C == 9 || m_4F7C == 0xC))
		m_4F40 = 0xC;
}
