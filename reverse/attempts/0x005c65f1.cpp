// ?Rva005C65F1Update@Rva005C65F1Class@@QAEXXZ
// partial score=0.97 date=2026-09-27
// ?Rva005C65F1Update@Rva005C65F1Class@@QAEXXZ
// partial score=0.97 date=2026-09-27
// cl: /O1 /MD
// ?Rva005C65F1Update@Rva005C65F1Class@@QAEXXZ retail 0x005C65F1 (75B).
// Evidence: free leaf (all callees rowed: abs via gen-small import row,
// virtual slot 4 indirect, EH_prolog row); two tail-jump callers
// (0x00577969 slot-2 wrapper, 0x0053EDEF) readjust this and forward here.
// Layout from retail: vptr +0, flag byte +4, ints +C/+10; virtual at +0x10
// fills two ints at [ebp-8]/[ebp-4]; Manhattan distance >2 commits them.

extern "C" int __cdecl abs(int value);

class Rva005C65F1Class
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void GetPos(int *out);
	void Rva005C65F1Update();

private:
	bool m_moved;
	char m_pad[7];
	int m_x;
	int m_y;
};

// ?Rva005C65F1Update@Rva005C65F1Class@@QAEXXZ present-unmatched
void Rva005C65F1Class::Rva005C65F1Update()
{
	int pos[2];
	GetPos(pos);
	int dy = abs(m_y - pos[1]);
	int dx = abs(m_x - pos[0]);
	if (dy + dx > 2) {
		m_x = pos[0];
		m_y = pos[1];
		m_moved = true;
	}
}
