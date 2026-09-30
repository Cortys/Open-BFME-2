// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva00235A21@@QAE@XZ @0x00235A21 22B
// Default ctor constructing 22-element 24B array at +0 via vector ctor
// iterator 0x00001423. Evidence: unlock lane unblocks 0x002CA88B; count
// 0x16 size 0x18 ctor 0x00235A0E; callers 0x002369BA 0x002CA8BA.
struct Rva00235A0EElem
{
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
	Rva00235A0EElem();
};

// ??0Rva00235A0EElem@@QAE@XZ present-unmatched
Rva00235A0EElem::Rva00235A0EElem()
{
}

class Rva00235A21
{
public:
	Rva00235A21();
private:
	Rva00235A0EElem m_arr[22];
};

Rva00235A21::Rva00235A21()
{
}
