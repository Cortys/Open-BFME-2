// ?rva0031917A@Rva0031917A@@QAEXXZ
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva0031917A@Rva0031917A@@QAEXXZ @0x0031917A 55B via indexed field clear plus 8-byte vector loop
// Evidence: this+0x78 field plus +0x40/+0x44 8-byte entries; rowed get 0x0040CB2C plus and [eax+0xb8],0; caller 0x00319202
class Rva0040CB2CIndexedField
{
public:
	int get(int index) const;
private:
	char m_pad[0x40];
public:
	char *m_begin;
	char *m_end;
};
class Rva0031917A
{
public:
	void rva0031917A();
private:
	char m_pad[0x78];
	Rva0040CB2CIndexedField *m_field;
};
struct Rva0031917AEntry
{
	char m_pad[0xb8];
	int m_flag;
};
// ?rva0031917A@Rva0031917A@@QAEXXZ present-unmatched
void Rva0031917A::rva0031917A()
{
	for (int i = 0; i < (m_field->m_end - m_field->m_begin >> 3); ++i) {
		Rva0031917AEntry *obj = (Rva0031917AEntry *)m_field->get(i);
		obj->m_flag = 0;
	}
}
