// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0004D6B3@W3DDisplay@@QAEXPAVImage@@MMMMHH@Z, retail 0x0004D6B3, 78 bytes.
// W3DDisplay float-coordinate drawImage with mode (Image*, Real x0, Real y0,
// Real x1, Real y1, Int color, Int mode). Evidence: TheDisplay global
// 0x00DFE9D8 as this in three direct callers (0x0031F89E/0x0025C829/0x00099462,
// all push -1,2 for the last two args); W3DMouse::draw proves the Display
// float drawImage ABI (const Image*, Real*4, Int, Int) with (-1,2) defaults;
// pre/middle/post virtuals at +0xD4/+0xF8/+0x100 (begin/draw/end) shared with
// sibling wrappers 0x0004263F/0x0004D664.

class Image;

class W3DDisplay
{
public:
	virtual void unused00();
	virtual void unused01();
	virtual void unused02();
	virtual void unused03();
	virtual void unused04();
	virtual void unused05();
	virtual void unused06();
	virtual void unused07();
	virtual void unused08();
	virtual void unused09();
	virtual void unused10();
	virtual void unused11();
	virtual void unused12();
	virtual void unused13();
	virtual void unused14();
	virtual void unused15();
	virtual void unused16();
	virtual void unused17();
	virtual void unused18();
	virtual void unused19();
	virtual void unused20();
	virtual void unused21();
	virtual void unused22();
	virtual void unused23();
	virtual void unused24();
	virtual void unused25();
	virtual void unused26();
	virtual void unused27();
	virtual void unused28();
	virtual void unused29();
	virtual void unused30();
	virtual void unused31();
	virtual void unused32();
	virtual void unused33();
	virtual void unused34();
	virtual void unused35();
	virtual void unused36();
	virtual void unused37();
	virtual void unused38();
	virtual void unused39();
	virtual void unused40();
	virtual void unused41();
	virtual void unused42();
	virtual void unused43();
	virtual void unused44();
	virtual void unused45();
	virtual void unused46();
	virtual void unused47();
	virtual void unused48();
	virtual void unused49();
	virtual void unused50();
	virtual void unused51();
	virtual void unused52();
	virtual void beginImageDraw();
	virtual void unused54();
	virtual void unused55();
	virtual void unused56();
	virtual void unused57();
	virtual void unused58();
	virtual void unused59();
	virtual void unused60();
	virtual void unused61();
	virtual void drawImageCore(Image *image, float x0, float y0, float x1, float y1, int color, int mode);
	virtual void unused63();
	virtual void endImageDraw();

	void rva0004D6B3(Image *image, float x0, float y0, float x1, float y1, int color, int mode);
};

void W3DDisplay::rva0004D6B3(Image *image, float x0, float y0, float x1, float y1, int color, int mode)
{
	beginImageDraw();
	drawImageCore(image, x0, y0, x1, y1, color, mode);
	endImageDraw();
}
