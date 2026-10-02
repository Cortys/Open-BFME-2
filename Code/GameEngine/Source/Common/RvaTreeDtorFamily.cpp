// cl: /O1 /MD /EHs
//
// Destructors of STLport red-black trees, one per instantiation, with the shape
// of the rowed ??1Rva0046A93E (56 bytes: clear the tree through its rowed clear,
// then free the header through the inline holder). Found by searching .text for
// that shape with call displacements and the EH handler record masked; the clear
// each calls names its owner, whose tree is not otherwise recovered.

extern "C" void __cdecl free(void *block);

struct RvaTreeFamilyHeader;
struct RvaTreeFamilyHolder
{
	RvaTreeFamilyHeader *m_ptr;
	~RvaTreeFamilyHolder()
	{
		if (m_ptr != 0)
			free(m_ptr);
	}
};

// ??1Rva00053DC5@@QAE@XZ @0x000554FA 56B -> Rva00053DC5::rva00054B9A
class Rva00053DC5
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00054B9A();
	~Rva00053DC5();
};

Rva00053DC5::~Rva00053DC5()
{
	rva00054B9A();
}

// ??1Rva00056CF8@@QAE@XZ @0x000589FB 56B -> Rva00056CF8::rva00057B74
class Rva00056CF8
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00057B74();
	~Rva00056CF8();
};

Rva00056CF8::~Rva00056CF8()
{
	rva00057B74();
}

// ??1Rva00072FE6@@QAE@XZ @0x000730DE 56B -> Rva00072FE6::rva00072FE6
class Rva00072FE6
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00072FE6();
	~Rva00072FE6();
};

Rva00072FE6::~Rva00072FE6()
{
	rva00072FE6();
}

// ??1Rva0007E971@@QAE@XZ @0x0007FE1B 56B -> Rva0007E971::rva0007FAC1
class Rva0007E971
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0007FAC1();
	~Rva0007E971();
};

Rva0007E971::~Rva0007E971()
{
	rva0007FAC1();
}

// ??1Rva0006F318@@QAE@XZ @0x0008A612 56B -> Rva0006F318::rva0006FA70
class Rva0006F318
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0006FA70();
	~Rva0006F318();
};

Rva0006F318::~Rva0006F318()
{
	rva0006FA70();
}

// ??1Rva000B646B@@QAE@XZ @0x000BB65C 56B -> Rva000B646B::rva000B92FB
class Rva000B646B
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva000B92FB();
	~Rva000B646B();
};

Rva000B646B::~Rva000B646B()
{
	rva000B92FB();
}

// ??1Rva001DD70F@@QAE@XZ @0x001DD9BB 56B -> Rva001DD70F::rva001DD846
class Rva001DD70F
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva001DD846();
	~Rva001DD70F();
};

Rva001DD70F::~Rva001DD70F()
{
	rva001DD846();
}

// ??1Rva001E6731@@QAE@XZ @0x001E6F27 56B -> Rva001E6731::rva001E6731
class Rva001E6731
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva001E6731();
	~Rva001E6731();
};

Rva001E6731::~Rva001E6731()
{
	rva001E6731();
}

// ??1Rva001F050B@@QAE@XZ @0x001F0657 56B -> Rva001F050B::rva001F050B
class Rva001F050B
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva001F050B();
	~Rva001F050B();
};

Rva001F050B::~Rva001F050B()
{
	rva001F050B();
}

// ??1Rva00206667@@QAE@XZ @0x002076E7 56B -> Rva00206667::rva00206F6B
class Rva00206667
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00206F6B();
	~Rva00206667();
};

Rva00206667::~Rva00206667()
{
	rva00206F6B();
}

// ??1Rva00206706@@QAE@XZ @0x0020779E 56B -> Rva00206706::rva00206FE6
class Rva00206706
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00206FE6();
	~Rva00206706();
};

Rva00206706::~Rva00206706()
{
	rva00206FE6();
}

// ??1Rva0021119B@@QAE@XZ @0x00211F05 56B -> Rva0021119B::rva00211DD2
class Rva0021119B
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00211DD2();
	~Rva0021119B();
};

Rva0021119B::~Rva0021119B()
{
	rva00211DD2();
}

// ??1Rva002294A3@@QAE@XZ @0x0022C917 56B -> Rva002294A3::rva0022C409
class Rva002294A3
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0022C409();
	~Rva002294A3();
};

Rva002294A3::~Rva002294A3()
{
	rva0022C409();
}

// ??1Rva002294D0@@QAE@XZ @0x0022C94F 56B -> Rva002294D0::rva0022C432
class Rva002294D0
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0022C432();
	~Rva002294D0();
};

Rva002294D0::~Rva002294D0()
{
	rva0022C432();
}

// ??1Rva00439325@@QAE@XZ @0x002418E2 56B -> Rva00439325::rva00240C60
class Rva00439325
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00240C60();
	~Rva00439325();
};

Rva00439325::~Rva00439325()
{
	rva00240C60();
}

// ??1Rva00255CA8@@QAE@XZ @0x00256429 56B -> Rva00255CA8::rva00255CA8
class Rva00255CA8
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00255CA8();
	~Rva00255CA8();
};

Rva00255CA8::~Rva00255CA8()
{
	rva00255CA8();
}

// ??1Rva00255CD1@@QAE@XZ @0x00256461 56B -> Rva00255CD1::rva00255CD1
class Rva00255CD1
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00255CD1();
	~Rva00255CD1();
};

Rva00255CD1::~Rva00255CD1()
{
	rva00255CD1();
}

// ??1Rva0027F4CB@@QAE@XZ @0x002819CE 56B -> Rva0027F4CB::rva00280AB6
class Rva0027F4CB
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00280AB6();
	~Rva0027F4CB();
};

Rva0027F4CB::~Rva0027F4CB()
{
	rva00280AB6();
}

// ??1Rva0028881C@@QAE@XZ @0x00288B51 56B -> Rva0028881C::rva002889BB
class Rva0028881C
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva002889BB();
	~Rva0028881C();
};

Rva0028881C::~Rva0028881C()
{
	rva002889BB();
}

// ??1Rva002913EB@@QAE@XZ @0x002923A7 56B -> Rva002913EB::rva002913EB
class Rva002913EB
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva002913EB();
	~Rva002913EB();
};

Rva002913EB::~Rva002913EB()
{
	rva002913EB();
}
