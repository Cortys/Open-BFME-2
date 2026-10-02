// Reset helper from the 0x00741730 neighbourhood. A __thiscall member whose
// two sub-objects are reset in sequence: the SegLineRendererClass at +0x100
// (0x00191260) and the Rva00743060Class at +0x150 (0x00743060). Only the first
// 26 bytes belong to this body; the listed extent also spans an unrelated
// function at 0x00741750, which is left for whoever owns that address. Name is
// address-derived. No // cl: line: the default /O2 tail-call shape matches.

class SegLineRendererClass
{
public:
	void Reset_Line();
};

class Rva00743060Class
{
public:
	void Reset_Line();
};

class Rva00741730
{
public:
	void rva00741730();
};

void Rva00741730::rva00741730()
{
	((SegLineRendererClass *)((char *)this + 0x100))->Reset_Line();
	((Rva00743060Class *)((char *)this + 0x150))->Reset_Line();
}
