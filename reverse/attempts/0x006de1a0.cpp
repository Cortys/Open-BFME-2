// ??0Rva006DE1A0@@QAE@XZ
// partial score=0.94 date=2026-09-30
// ??0Rva006DE1A0@@QAE@XZ
// partial score=0.94 date=2026-09-30
// cl: /O2 /EHsc /MD
// ??0Rva006DE1A0@@QAE@XZ @ 0x006DE1A0 107B Apt ctor with hash member.
// Evidence: neighbours AptValuePtrStackTop plus Rva006DE2B0Slot7 share /O2 /MD; EH prolog with scopetable so plus /EHsc; rowed AptNativeHash ctor 0x0070A740 with 8; vptrs 0x008EA228 then 0x008EB150; flags and 0xFFFFFFDF plus m_1C zero; unblocks 5.
class AptNativeHash
{
public:
	AptNativeHash(int n);
};
class Rva006DE1A0Base
{
public:
	Rva006DE1A0Base() : m_04((m_04 & 1) | 0x38000030) {}
	virtual ~Rva006DE1A0Base();
protected:
	int m_04;
};
class Rva006DE1A0 : public Rva006DE1A0Base
{
public:
	Rva006DE1A0();
	virtual ~Rva006DE1A0();
private:
	AptNativeHash m_08;
	char m_pad[0x1C - 0x08 - 4];
	int m_1C;
};
// ??0Rva006DE1A0@@QAE@XZ present-unmatched
Rva006DE1A0::Rva006DE1A0() : Rva006DE1A0Base(), m_08(8)
{
	m_04 &= ~0x20;
	m_1C = 0;
}
