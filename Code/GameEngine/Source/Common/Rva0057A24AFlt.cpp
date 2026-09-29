// ?rva0057A24A@Rva0057A24A@@QBEMXZ @0x0057A24A 22B
// Float getter via global 0x009FE4CC slot 15 then * m_20 at +0x20;
// callers at 0x0057ABF4 0x0057AC05 0x0057B047 0x0057B2CE; unlock.
struct RetObj
{
	char m_pad[4];
	float m_4;
};
struct GlobalObj
{
	virtual ~GlobalObj() {}
	virtual void *d1(); virtual void *d2(); virtual void *d3(); virtual void *d4();
	virtual void *d5(); virtual void *d6(); virtual void *d7(); virtual void *d8();
	virtual void *d9(); virtual void *d10(); virtual void *d11(); virtual void *d12();
	virtual void *d13(); virtual void *d14();
	virtual RetObj *slot15();
};
#define TheGlobal0057A24A (*(GlobalObj **)0x00DFE4CC)
class Rva0057A24A
{
public:
	float rva0057A24A() const;
private:
	char m_pad[0x20];
	float m_20;
};
float Rva0057A24A::rva0057A24A() const
{
	return TheGlobal0057A24A->slot15()->m_4 * m_20;
}
