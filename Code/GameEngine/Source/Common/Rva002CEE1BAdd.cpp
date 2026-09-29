// cl: /O1 /MD
// ?rva002CED84@Rva002CEE1B@@QAEXPAX00@Z @0x002CED84 83B
// Method of Rva002CEE1B (array at +0x0C, 128 x 0x1C from dtor TU) that finds
// first empty slot and fills {ptr + 12B + 12B}. Evidence: ecx+0x0C base with
// 0x80 x 0x1C search matches Rva002CEE1BDtor layout; caller at 0x0004C878
// passes (void* from 0x002CF21B, two 12B float vectors) with ecx=global.
struct Twelve002CED84
{
	int v0, v1, v2;
};

struct Elem002CED84
{
	void *ptr;
	Twelve002CED84 second;
	Twelve002CED84 third;
};

class GameEngineDeletingBase002CED84
{
public:
	virtual ~GameEngineDeletingBase002CED84();
};

class Rva002CEE1B : public GameEngineDeletingBase002CED84
{
public:
	void rva002CED84(void *p1, void *p2, void *p3);

private:
	char m_pad04[0x0C - 4];
	Elem002CED84 m_arr0C[128];
};

void Rva002CEE1B::rva002CED84(void *p1, void *p2, void *p3)
{
	if (p1 == 0)
		return;
	if (p2 == 0)
		return;
	if (p3 == 0)
		return;
	int i = 0;
check:
	if (m_arr0C[i].ptr == 0)
		goto fill;
	i++;
	if (i < 128)
		goto check;
	return;
fill:
	Elem002CED84 *slot = &m_arr0C[i];
	if (slot == 0)
		return;
	slot->ptr = p1;
	slot->second = *(Twelve002CED84 *)p2;
	slot->third = *(Twelve002CED84 *)p3;
}
