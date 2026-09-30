// cl: /O1 /EHs /MD
// ?rva003833BB@Rva003833BB@@QAEXPAURva003833BBNode@@@Z 0x003833BB 53B
// Rb _M_erase: recurse-right via +12 walk-left via +8 destroy value at +16 via rowed CameraMarker dtor 0x29D7C2 and free 0x30830 ret 4.
// Evidence: callees 0x29D7C2 plus 0x30830 both rowed; caller clear 0x383A28 pushes root at +4 and resets header; same 53B shape as landed erases 0x380EB1 and 0x4D1B38.
extern "C" void __cdecl free(void *block);

struct CameraMarker
{
	~CameraMarker();
};

struct Rva003833BBNode
{
	unsigned int m_color;
	Rva003833BBNode *m_parent;
	Rva003833BBNode *m_left;
	Rva003833BBNode *m_right;
};

class Rva003833BB
{
public:
	void rva003833BB(Rva003833BBNode *node);
};

void Rva003833BB::rva003833BB(Rva003833BBNode *node)
{
	while (node)
	{
		rva003833BB(node->m_right);
		Rva003833BBNode *left = node->m_left;
		((CameraMarker *)(node + 1))->~CameraMarker();
		free(node);
		node = left;
	}
}
