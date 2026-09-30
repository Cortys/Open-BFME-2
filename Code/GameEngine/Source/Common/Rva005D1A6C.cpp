// cl: /O1 /MD
// ??0Rva005D1A6C@@QAE@XZ @0x005D1A6C 13B: ctor storing vtable plus zeroing +4. Evidence: unlock lane; caller 0x0057A748; vtable g_00C42518.
extern const void *const g_00C42518[];
class __declspec(novtable) Rva005D1A6C
{
public:
	Rva005D1A6C();
	virtual void v00();
private:
	int m_04;
};
Rva005D1A6C::Rva005D1A6C() : m_04(0)
{
	*(const void **)this = g_00C42518;
}
