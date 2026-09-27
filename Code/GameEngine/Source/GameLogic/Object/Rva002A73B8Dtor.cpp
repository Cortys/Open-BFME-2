// cl: /O1 /DNDEBUG /MD
//
// ??1Rva002A73B8@@QAE@XZ,
// retail 0x002A73B8, 8 bytes. Dedicated TU.
//
// Forwarder dtor: add ecx,8 then tail-jmp to the rowed member dtor
// ??1Rva00360D26Member@@QAE@XZ at 0x00360D26
// (Code/GameEngine/Source/GameLogic/Object/ObjectFilterRelease.cpp).
// Identity is address-honest: the containing class is unproven, so the name
// claims only the dtor pattern plus address (taskfile honest-name precedent
// ??1Rva004B4CDF@@UAE@XZ). Callers include the 28B scalar-deleting shape at
// 0x002A73E4 plus array loops at 0x002A752F/0x002A7604.

class Rva00360D26Member
{
public:
	~Rva00360D26Member();
};

class Rva002A73B8
{
public:
	~Rva002A73B8();

private:
	int m_pad0;
	int m_pad4;
	Rva00360D26Member m_member8; // +0x08
};

Rva002A73B8::~Rva002A73B8()
{
}

void *operator new(unsigned int size);
void operator delete(void *p);

// Anchor: new/delete calls the scalar deleting dtor directly (non-virtual,
// so devirtualization is a direct ??_G call), emitting the COMDAT for
// ??_GRva002A73B8@@QAEPAXI@Z at 0x002A73E4. Operator new/delete resolve to
// their rows at 0x0002FDA0/0x0002FD60.
void Rva002A73B8_Anchor()
{
	Rva002A73B8 *p = new Rva002A73B8;
	delete p;
}
