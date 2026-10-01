// ?Rva0055CAEFDraw@@YGXMMM@Z
// partial score=0.93 date=2026-10-01
// ?Rva0055CAEFDraw@@YGXMMM@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /arch:SSE2
// ?Rva0055CAEFDraw@@YGXMMM@Z @0x0055CAEF 86B: free __stdcall (x,y,z) building two 12B points differing in z by g_00BC34F8 then TacticalView slot 0x2c with color 0xccaaffff.
// Evidence: ret 0xc (3 floats); movss copies; fld/fadd qword g_00BC34F8/fstp for z2; pushes color/second/first then call [eax+0x2c] on TheTacticalView; vtable slot 4 refs from 0x0081D00C/0x0081C730.
extern double g_00BC34F8;

struct Rva0055CAEFVec
{
	float x;
	float y;
	float z;
};

class TacticalView
{
public:
	virtual void slot00();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual void slot10();
	virtual void slot11(const Rva0055CAEFVec *a, const Rva0055CAEFVec *b, unsigned int color);
};

extern TacticalView *TheTacticalView;

// ?Rva0055CAEFDraw@@YGXMMM@Z present-unmatched
void __stdcall Rva0055CAEFDraw(float x, float y, float z)
{
	Rva0055CAEFVec a = { x, y, z };
	Rva0055CAEFVec b = { x, y, (float)(z + g_00BC34F8) };
	TheTacticalView->slot11(&a, &b, 0xccaaffff);
}
