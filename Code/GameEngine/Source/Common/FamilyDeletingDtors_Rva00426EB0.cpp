// cl: /O1 /MD
//
// ??_GRva00426EB0@@UAEPAXI@Z, retail 0x00426E94, 28 bytes. Deleting dtor for
// Rva00426EB0 whose ??1 is rowed at 0x00426EB0. Calls ??1Rva00426EB0@@UAE@XZ
// then operator delete ??3@YAXPAX@Z at 0x0002FD60 when flag set.
// Evidence: call to rowed 0x00426EB0; test [esp+8] flag; ret 4; chain from
// 0x00426EB0 landing. Placeholder ~Rva00426EB0 duplicates the real ??1.
class Rva00426EB0
{
public:
	__declspec(noinline) virtual ~Rva00426EB0();
private:
	int m_famgen;
};
// ??1Rva00426EB0@@UAE@XZ present-unmatched
Rva00426EB0::~Rva00426EB0() { m_famgen = 0; }
// ?famgenDelete@@YAXPAVRva00426EB0@@@Z present-unmatched
void famgenDelete(Rva00426EB0 *p) { delete p; }
