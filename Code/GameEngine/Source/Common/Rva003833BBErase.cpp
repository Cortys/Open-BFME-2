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

// ?rva00383A28@Rva00383A28@@QAEXXZ 0x00383A28 41B
// _Tree::clear counterpart to erase 0x003833BB: if count at +4 nonzero erase
// root at header+4 then reset left/parent/right and count.
// Evidence: sole callee 0x003833BB rowed in this TU; callers at 0x383A51
// 0x383EB2 0x38407F 0x385B78; same 41B shape as clear 0x383EEA in BfmeConv802.cpp.
class Rva00383A28
{
public:
	void rva00383A28();
private:
	Rva003833BBNode *m_header;
	unsigned int m_count;
};

void Rva00383A28::rva00383A28()
{
	if (m_count != 0)
	{
		((Rva003833BB *)this)->rva003833BB(m_header->m_parent);
		m_header->m_left = m_header;
		m_header->m_parent = 0;
		m_header->m_right = m_header;
		m_count = 0;
	}
}
