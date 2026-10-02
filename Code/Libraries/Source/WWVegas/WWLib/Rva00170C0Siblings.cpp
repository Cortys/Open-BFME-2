// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// 23 scalar deleting destructors of the ??_G?$basic_filebuf@DV?$char_traits@D@_STL@@@_STL@@UAEPAXI@Z
// shape (30 B). Each retail body calls its class dtor then the rowed scalar operator delete
// 0x0002FD60 under the (this, flags) ABI. The class identities are unproven, so each is an
// address-derived local model whose dtor symbol is pinned to the retail call target; the
// deleting destructor is compiler-emitted and names that model.
//
// 0x000170C0 -> dtor 0x00016B60
// 0x00118640 -> dtor 0x006C5930
// 0x0011CC10 -> dtor 0x00174753
// 0x00122110 -> dtor 0x00120FB0
// 0x0012A620 -> dtor 0x0012A4D0
// 0x0013C860 -> dtor 0x006154D0
// 0x00141C10 -> dtor 0x00141C30
// 0x0014BB70 -> dtor 0x0014A5B0
// 0x00156840 -> dtor 0x00155330
// 0x00157110 -> dtor 0x00156750
// 0x00157AB0 -> dtor 0x00157390
// 0x00157E60 -> dtor 0x00157C20
// 0x001811B0 -> dtor 0x001811D0
// 0x00188320 -> dtor 0x001880D0
// 0x001977B0 -> dtor 0x001976F0
// 0x0019F990 -> dtor 0x0019EF70
// 0x00616490 -> dtor 0x006162B0
// 0x00626D90 -> dtor 0x00625800
// 0x00663410 -> dtor 0x0066C730
// 0x006C0B60 -> dtor 0x006C09A0
// 0x007396E0 -> dtor 0x0073E3F0
// 0x0073AAC0 -> dtor 0x0073A900
// 0x007581C0 -> dtor 0x0075A080

class Rva00016B60Dtor
{
public:
	virtual ~Rva00016B60Dtor();
};

__declspec(noinline) Rva00016B60Dtor::~Rva00016B60Dtor()
{
}

class Rva006C5930Dtor
{
public:
	virtual ~Rva006C5930Dtor();
};

__declspec(noinline) Rva006C5930Dtor::~Rva006C5930Dtor()
{
}

class Rva00174753Dtor
{
public:
	virtual ~Rva00174753Dtor();
};

__declspec(noinline) Rva00174753Dtor::~Rva00174753Dtor()
{
}

class Rva00120FB0Dtor
{
public:
	virtual ~Rva00120FB0Dtor();
};

__declspec(noinline) Rva00120FB0Dtor::~Rva00120FB0Dtor()
{
}

class Rva0012A4D0Dtor
{
public:
	virtual ~Rva0012A4D0Dtor();
};

__declspec(noinline) Rva0012A4D0Dtor::~Rva0012A4D0Dtor()
{
}

class Rva006154D0Dtor
{
public:
	virtual ~Rva006154D0Dtor();
};

__declspec(noinline) Rva006154D0Dtor::~Rva006154D0Dtor()
{
}

class Rva00141C30Dtor
{
public:
	virtual ~Rva00141C30Dtor();
};

__declspec(noinline) Rva00141C30Dtor::~Rva00141C30Dtor()
{
}

class Rva0014A5B0Dtor
{
public:
	virtual ~Rva0014A5B0Dtor();
};

__declspec(noinline) Rva0014A5B0Dtor::~Rva0014A5B0Dtor()
{
}

class Rva00155330Dtor
{
public:
	virtual ~Rva00155330Dtor();
};

__declspec(noinline) Rva00155330Dtor::~Rva00155330Dtor()
{
}

class Rva00156750Dtor
{
public:
	virtual ~Rva00156750Dtor();
};

__declspec(noinline) Rva00156750Dtor::~Rva00156750Dtor()
{
}

class Rva00157390Dtor
{
public:
	virtual ~Rva00157390Dtor();
};

__declspec(noinline) Rva00157390Dtor::~Rva00157390Dtor()
{
}

class Rva00157C20Dtor
{
public:
	virtual ~Rva00157C20Dtor();
};

__declspec(noinline) Rva00157C20Dtor::~Rva00157C20Dtor()
{
}

class Rva001811D0Dtor
{
public:
	virtual ~Rva001811D0Dtor();
};

__declspec(noinline) Rva001811D0Dtor::~Rva001811D0Dtor()
{
}

class Rva001880D0Dtor
{
public:
	virtual ~Rva001880D0Dtor();
};

__declspec(noinline) Rva001880D0Dtor::~Rva001880D0Dtor()
{
}

class Rva001976F0Dtor
{
public:
	virtual ~Rva001976F0Dtor();
};

__declspec(noinline) Rva001976F0Dtor::~Rva001976F0Dtor()
{
}

class Rva0019EF70Dtor
{
public:
	virtual ~Rva0019EF70Dtor();
};

__declspec(noinline) Rva0019EF70Dtor::~Rva0019EF70Dtor()
{
}

class Rva006162B0Dtor
{
public:
	virtual ~Rva006162B0Dtor();
};

__declspec(noinline) Rva006162B0Dtor::~Rva006162B0Dtor()
{
}

class Rva00625800Dtor
{
public:
	virtual ~Rva00625800Dtor();
};

__declspec(noinline) Rva00625800Dtor::~Rva00625800Dtor()
{
}

class Rva0066C730Dtor
{
public:
	virtual ~Rva0066C730Dtor();
};

__declspec(noinline) Rva0066C730Dtor::~Rva0066C730Dtor()
{
}

class Rva006C09A0Dtor
{
public:
	virtual ~Rva006C09A0Dtor();
};

__declspec(noinline) Rva006C09A0Dtor::~Rva006C09A0Dtor()
{
}

class Rva0073E3F0Dtor
{
public:
	virtual ~Rva0073E3F0Dtor();
};

__declspec(noinline) Rva0073E3F0Dtor::~Rva0073E3F0Dtor()
{
}

class Rva0073A900Dtor
{
public:
	virtual ~Rva0073A900Dtor();
};

__declspec(noinline) Rva0073A900Dtor::~Rva0073A900Dtor()
{
}

class Rva0075A080Dtor
{
public:
	virtual ~Rva0075A080Dtor();
};

__declspec(noinline) Rva0075A080Dtor::~Rva0075A080Dtor()
{
}
