// cl: /O1 /Oy- /DNDEBUG /MD /EHsc /Oi- /arch:SSE2
// ?Rva00314AE0@@YGXPAVImage@@HHHHH@Z, retail 0x00314AE0, 72 bytes.
// Int-coordinate drawImage wrapper that forwards to the float W3DDisplay
// helper 0x0004D6B3 with mode=2 (alpha). Evidence: chain lane (calls the
// just-landed ?rva0004D6B3@W3DDisplay@@QAEXPAVImage@@MMMMHH@Z); this=TheDisplay
// global 0x00DFE9D8 for the callee; four int args converted via cvtsi2ss to
// floats; vtable slot 66 of 0x007C7C90 in the packet.

class Image;
class Display;
extern Display *TheDisplay;

class W3DDisplay
{
public:
	void rva0004D6B3(Image *image, float x0, float y0, float x1, float y1, int color, int mode);
};

void __stdcall Rva00314AE0(Image *image, int x0, int y0, int x1, int y1, int color)
{
	((W3DDisplay *)TheDisplay)->rva0004D6B3(image, (float)x0, (float)y0, (float)x1, (float)y1, color, 2);
}
