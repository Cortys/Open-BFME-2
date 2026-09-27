// cl: /O1 /MD /DNDEBUG
//
// ??0Rva0004584D@@QAE@ABVBfmeFixedStorage0004543D@@0@Z @0x0004584D 43B
// Two-storage holder ctor: vtable 0x00BC2908 (3 slots) at +0, int zero at +4
// via and, two 28B FixedStorage members at +8/+0x24 through the rowed copy
// at 0x0004543D, ret 8. Callers 0x0004AFC6 and 0x0010CE97 share one stack
// slot: they push 0x00DFEFA4 plus two ints for the BitSet ctor at 0x00045411
// (ret 8 leaves DFEFA4), then push eax (the BitSet at ebp-0x68/-0xD0) and call
// here; both params feed the same FixedStorage copy, sizes 28B each. Sibling
// tail at 0x004CCE67 stores the same vtable. Honest Rva class; virtual dummy
// carries the vptr without emitting a deleting dtor.
class BfmeFixedStorage0004543D
{
public:
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other) throw();

private:
	unsigned char m_bytes[28];
};

class Rva0004584D
{
public:
	Rva0004584D(const BfmeFixedStorage0004543D &a, const BfmeFixedStorage0004543D &b);
	virtual void dummy();

private:
	int m_04;
	BfmeFixedStorage0004543D m_08;
	BfmeFixedStorage0004543D m_24;
};

// ??0Rva0004584D@@QAE@ABVBfmeFixedStorage0004543D@@0@Z
Rva0004584D::Rva0004584D(const BfmeFixedStorage0004543D &a, const BfmeFixedStorage0004543D &b)
	: m_04(0)
	, m_08(a)
	, m_24(b)
{
}
