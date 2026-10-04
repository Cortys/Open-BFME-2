// cl: /O1 /EHs-c-
// ??0Rva003ADD31@@QAE@ABV0@@Z @0x003ADD31 108B copy ctor via rowed bases 0x003ADDCD and 0x003ADD9D with derived stores and 28B tail. Evidence: callees rowed; caller 0x003ADD0B; same MI null-check shape as 0x003ADC75.
class Rva0055BCD2
{
public:
	Rva0055BCD2(const Rva0055BCD2 &other);
private:
	char m_pad[12];
};
class Rva0055BC8B
{
public:
	Rva0055BC8B(const Rva0055BC8B &other);
private:
	char m_pad[136];
};
extern const void *const g_00C1D17C[];
extern "C" char s_slot3E4first;
class Rva003ADD31 : public Rva0055BCD2, public Rva0055BC8B
{
public:
	Rva003ADD31(const Rva003ADD31 &other);
private:
	struct Block12
	{
		unsigned int a;
		unsigned int b;
		unsigned int c;
	};
	Block12 m_94;
	Block12 m_a0;
	unsigned int m_ac;
};
Rva003ADD31::Rva003ADD31(const Rva003ADD31 &other)
	: Rva0055BCD2(other)
	, Rva0055BC8B(other)
{
	*(const char **)((char *)this + 12) = "HZz";
	*(const void **)this = g_00C1D17C;
	*(void **)((char *)this + 8) = (void *)&s_slot3E4first;
	m_94 = other.m_94;
	m_a0 = other.m_a0;
	m_ac = other.m_ac;
}
#pragma comment(linker, "/alternatename:_s_slot3E4first=?vftable_0112B89C@@3HA")
