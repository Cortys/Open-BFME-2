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

// ??1Rva0029B63A@@QAE@XZ @0x0029FAB7 56B -> Rva0029B63A::rva0029E015
class Rva0029B63A
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0029E015();
	~Rva0029B63A();
};

Rva0029B63A::~Rva0029B63A()
{
	rva0029E015();
}

// ??1Rva0029B667@@QAE@XZ @0x0029FB03 56B -> Rva0029B667::rva0029E03E
class Rva0029B667
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0029E03E();
	~Rva0029B667();
};

Rva0029B667::~Rva0029B667()
{
	rva0029E03E();
}

// ??1Rva002A8B8C@@QAE@XZ @0x002A8CD0 56B -> Rva002A8B8C::rva002A8BEE
class Rva002A8B8C
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva002A8BEE();
	~Rva002A8B8C();
};

Rva002A8B8C::~Rva002A8B8C()
{
	rva002A8BEE();
}

// ??1Rva002D394B@@QAE@XZ @0x002D50AD 56B -> Rva002D394B::rva002D43C6
class Rva002D394B
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva002D43C6();
	~Rva002D394B();
};

Rva002D394B::~Rva002D394B()
{
	rva002D43C6();
}

// ??1Rva002E15E6@@QAE@XZ @0x002E1E19 56B -> Rva002E15E6::rva002E15E6
class Rva002E15E6
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva002E15E6();
	~Rva002E15E6();
};

Rva002E15E6::~Rva002E15E6()
{
	rva002E15E6();
}

// ??1Rva002EE9B7@@QAE@XZ @0x002F0B52 56B -> Rva002EE9B7::rva002EE9B7
class Rva002EE9B7
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva002EE9B7();
	~Rva002EE9B7();
};

Rva002EE9B7::~Rva002EE9B7()
{
	rva002EE9B7();
}

// ??1Rva0032EAA1@@QAE@XZ @0x0032EC26 56B -> Rva0032EAA1::rva0032EB5E
class Rva0032EAA1
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0032EB5E();
	~Rva0032EAA1();
};

Rva0032EAA1::~Rva0032EAA1()
{
	rva0032EB5E();
}

// ??1Rva00372F00@@QAE@XZ @0x00372FBC 56B -> Rva00372F00::rva00372F56
class Rva00372F00
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00372F56();
	~Rva00372F00();
};

Rva00372F00::~Rva00372F00()
{
	rva00372F56();
}

// ??1Rva0038404A@@QAE@XZ @0x00385BE1 56B -> Rva0038404A::rva00384E8E
class Rva0038404A
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00384E8E();
	~Rva0038404A();
};

Rva0038404A::~Rva0038404A()
{
	rva00384E8E();
}

// ??1Rva00388EAE@@QAE@XZ @0x00389354 56B -> Rva00388EAE::rva00389129
class Rva00388EAE
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00389129();
	~Rva00388EAE();
};

Rva00388EAE::~Rva00388EAE()
{
	rva00389129();
}

// ??1Rva00395CEB@@QAE@XZ @0x003968D3 56B -> Rva00395CEB::rva0039611E
class Rva00395CEB
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0039611E();
	~Rva00395CEB();
};

Rva00395CEB::~Rva00395CEB()
{
	rva0039611E();
}

// ??1Rva00395D18@@QAE@XZ @0x0039690B 56B -> Rva00395D18::rva00396147
class Rva00395D18
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00396147();
	~Rva00395D18();
};

Rva00395D18::~Rva00395D18()
{
	rva00396147();
}

// ??1Rva00397C94@@QAE@XZ @0x00399278 56B -> Rva00397C94::rva00398257
class Rva00397C94
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00398257();
	~Rva00397C94();
};

Rva00397C94::~Rva00397C94()
{
	rva00398257();
}

// ??1Rva0039F56E@@QAE@XZ @0x0039FB11 56B -> Rva0039F56E::rva0039F56E
class Rva0039F56E
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0039F56E();
	~Rva0039F56E();
};

Rva0039F56E::~Rva0039F56E()
{
	rva0039F56E();
}

// ??1Rva004070D4@@QAE@XZ @0x004075A8 56B -> Rva004070D4::rva0040748D
class Rva004070D4
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0040748D();
	~Rva004070D4();
};

Rva004070D4::~Rva004070D4()
{
	rva0040748D();
}

// ??1Rva0041331E@@QAE@XZ @0x00413396 56B -> Rva0041331E::rva0041334B
class Rva0041331E
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0041334B();
	~Rva0041331E();
};

Rva0041331E::~Rva0041331E()
{
	rva0041334B();
}

// ??1Rva00421BF7@@QAE@XZ @0x0042263D 56B -> Rva00421BF7::rva00421EEA
class Rva00421BF7
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00421EEA();
	~Rva00421BF7();
};

Rva00421BF7::~Rva00421BF7()
{
	rva00421EEA();
}

// ??1Rva00421C24@@QAE@XZ @0x00422675 56B -> Rva00421C24::rva00421F13
class Rva00421C24
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00421F13();
	~Rva00421C24();
};

Rva00421C24::~Rva00421C24()
{
	rva00421F13();
}

// ??1Rva00421CE9@@QAE@XZ @0x00422717 56B -> Rva00421CE9::rva00421FDE
class Rva00421CE9
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva00421FDE();
	~Rva00421CE9();
};

Rva00421CE9::~Rva00421CE9()
{
	rva00421FDE();
}

// ??1Rva0043EA9C@@QAE@XZ @0x0043FE62 56B -> Rva0043EA9C::rva0043F124
class Rva0043EA9C
{
public:
	RvaTreeFamilyHolder m_header;
	int m_flag;
	void rva0043F124();
	~Rva0043EA9C();
};

Rva0043EA9C::~Rva0043EA9C()
{
	rva0043F124();
}
