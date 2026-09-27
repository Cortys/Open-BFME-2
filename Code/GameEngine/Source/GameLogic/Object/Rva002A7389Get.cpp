// cl: /O1 /DNDEBUG /MD
//
// ?get@Rva002A7389@@QAEHH@Z,
// retail 0x002A7389, 6 bytes. Dedicated TU.
//
// Trivial thiscall dword reader: mov eax,[ecx+8]; ret 4. The single int
// parameter is ignored by the body (every caller pushes one dword; e.g.
// 0x005D787A pushes 1, 0x00048772/0x0004877B in FUN_0044826c). Callers invoke
// it on a +0x60 subobject view (0x005D7860: lea esi,[eax+0x60] after
// ?getControllingPlayer@Object@@QBEPAVPlayer@@XZ, then cvtsi2ss on the int
// result), but the owning class is unproven, so the name claims only the
// address plus the witnessed shape (taskfile honest-name precedent
// ?get@Rva0066B100@@QAEHH@Z). All callees: none, so the gate resolves it.
// Neighbour TU Code/GameEngine/Source/GameLogic/Object/Rva002A73B8Dtor.cpp
// (0x002A73B8/0x002A73E4) supplies the // cl: line.

class Rva002A7389
{
public:
	int get(int);

private:
	char m_lead[8];
	int m_value; // +0x08
};

int Rva002A7389::get(int)
{
	return m_value;
}
