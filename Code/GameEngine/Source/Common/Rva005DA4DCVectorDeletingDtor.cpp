// cl: /O1 /MD
//
// ??_ERva005DA4DC@@QAEPAXI@Z, retail 0x0058B5D8, 75 bytes.
// Vector deleting destructor for 0x14-byte Rva005DA4DC whose scalar dtor
// ??1Rva005DA4DC@@QAE@XZ is rowed at 0x005DA4DC (landed this session).
// Retail pushes dtor 0x005DA4DC plus size 0x14 into ??_M 0x00629110 for the
// array branch, frees via rowed vector delete 0x0002FD80, and scalar-frees
// via rowed scalar delete 0x0002FD60. Precedent Rva0035A18DVectorDeletingDtor
// (75B). Evidence: flag bits 2+1, push 0x14, callers at 0x0058B65A.
// The anchor exists only to emit the destructor through delete[].

void operator delete[](void *p);

class Rva005DA4DC
{
public:
	~Rva005DA4DC();

private:
	char m_pad[0x14];
};

// ?Rva005DA4DCDeleteArray@@YAXPAVRva005DA4DC@@@Z present-unmatched
void Rva005DA4DCDeleteArray(Rva005DA4DC *p)
{
	delete[] p;
}
