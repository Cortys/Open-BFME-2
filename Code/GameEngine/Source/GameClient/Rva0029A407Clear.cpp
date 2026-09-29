// cl: /O1 /MD
// ?rva0029A407@Rva0029A407@@QAEXXZ @0x0029A407 19B
// Guarded virtual slot2 clear like release-then-null; callers at 0x0029B53F
// 0x0029D9EB and jmp at 0x0029B346; unlocks 0x0029D9CA 0x0029B53C.
struct Freeable0029A407
{
	virtual ~Freeable0029A407() {}
	virtual void unk0();
	virtual void slot2();
};
class Rva0029A407
{
public:
	void rva0029A407();
private:
	Freeable0029A407 *m_0;
};
void Rva0029A407::rva0029A407()
{
	if (m_0 != 0) {
		m_0->slot2();
		m_0 = 0;
	}
}
