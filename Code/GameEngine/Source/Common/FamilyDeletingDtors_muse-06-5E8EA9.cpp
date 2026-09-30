// cl: /O1 /MD
// ??_GRva005E8EA1@@QAEPAXI@Z @0x005E8EA9 28B: scalar deleting dtor calls the rowed ??1 at 0x005E8EA1 plus rowed operator delete 0x0002FD60.
class Rva005E8EA1 {
public:
	~Rva005E8EA1();
};

void Rva005E8EA1_Delete(Rva005E8EA1 *p) { delete p; }
