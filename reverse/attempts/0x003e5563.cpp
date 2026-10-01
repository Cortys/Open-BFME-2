// ?rva003E5563@Rva003E5563@@QAEXXZ
// partial score=0.94 date=2026-10-01
// ?rva003E5563@Rva003E5563@@QAEXXZ
// retail 0x003E5563, 36 bytes.
// Evidence: leaf __thiscall void no args; zeroes 4 floats at +0..+0xc via movss plus int at +0x10 plus limit 0x7ffffffe at +0x14.
// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /arch:SSE2 /O1

class Rva003E5563
{
public:
	void rva003E5563();

private:
	float m_00;
	float m_04;
	float m_08;
	float m_0c;
	int m_10;
	int m_14;
};

// ?rva003E5563@Rva003E5563@@QAEXXZ present-unmatched
void Rva003E5563::rva003E5563()
{
	Rva003E5563 *self = this;
	self->m_10 = 0;
	self->m_00 = 0.0f;
	self->m_04 = 0.0f;
	self->m_08 = 0.0f;
	self->m_0c = 0.0f;
	self->m_14 = 0x7ffffffe;
}
