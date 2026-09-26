// cl: /O1 /MD
//
// Emitted scalar deleting destructors (28B flag-test shape), batch B01.
// Same recipe as OpaqueScalarDeletingDtors.cpp: each retail ??_G body is
// push esi / mov esi,ecx / call <dtor> / test [esp+8],1 / call ??3 / ret 4,
// and the called destructor is pinned opaquely at the call target read from
// those retail bytes (a Ghidra-inventoried function start with no other pin
// or ledger row). The three-vptr MI model keeps the in-class destructor out
// of line so the ??_G calls through the pin. Owner identities are unproven:
// names are derived from the destructor address.

class Rva0049B47C
{
public:
	virtual ~Rva0049B47C();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva000C2980_B2
{
public:
	virtual void f2();
};

class Rva000C2980 : public Rva0049B47C, public MiBase1, public Rva000C2980_B2
{
public:
	virtual ~Rva000C2980()
	{
	}
};

void Rva000C2980_Anchor(Rva000C2980 *p)
{
	p->Rva000C2980::~Rva000C2980();
}

class Rva000CA8BC_B2
{
public:
	virtual void f2();
};

class Rva000CA8BC : public Rva0049B47C, public MiBase1, public Rva000CA8BC_B2
{
public:
	virtual ~Rva000CA8BC()
	{
	}
};

void Rva000CA8BC_Anchor(Rva000CA8BC *p)
{
	p->Rva000CA8BC::~Rva000CA8BC();
}

class Rva000CDE73_B2
{
public:
	virtual void f2();
};

class Rva000CDE73 : public Rva0049B47C, public MiBase1, public Rva000CDE73_B2
{
public:
	virtual ~Rva000CDE73()
	{
	}
};

void Rva000CDE73_Anchor(Rva000CDE73 *p)
{
	p->Rva000CDE73::~Rva000CDE73();
}

class Rva000CE960_B2
{
public:
	virtual void f2();
};

class Rva000CE960 : public Rva0049B47C, public MiBase1, public Rva000CE960_B2
{
public:
	virtual ~Rva000CE960()
	{
	}
};

void Rva000CE960_Anchor(Rva000CE960 *p)
{
	p->Rva000CE960::~Rva000CE960();
}

class Rva000CF1A6_B2
{
public:
	virtual void f2();
};

class Rva000CF1A6 : public Rva0049B47C, public MiBase1, public Rva000CF1A6_B2
{
public:
	virtual ~Rva000CF1A6()
	{
	}
};

void Rva000CF1A6_Anchor(Rva000CF1A6 *p)
{
	p->Rva000CF1A6::~Rva000CF1A6();
}

class Rva000CFA42_B2
{
public:
	virtual void f2();
};

class Rva000CFA42 : public Rva0049B47C, public MiBase1, public Rva000CFA42_B2
{
public:
	virtual ~Rva000CFA42()
	{
	}
};

void Rva000CFA42_Anchor(Rva000CFA42 *p)
{
	p->Rva000CFA42::~Rva000CFA42();
}

class Rva000D0B69_B2
{
public:
	virtual void f2();
};

class Rva000D0B69 : public Rva0049B47C, public MiBase1, public Rva000D0B69_B2
{
public:
	virtual ~Rva000D0B69()
	{
	}
};

void Rva000D0B69_Anchor(Rva000D0B69 *p)
{
	p->Rva000D0B69::~Rva000D0B69();
}

class Rva000D146B_B2
{
public:
	virtual void f2();
};

class Rva000D146B : public Rva0049B47C, public MiBase1, public Rva000D146B_B2
{
public:
	virtual ~Rva000D146B()
	{
	}
};

void Rva000D146B_Anchor(Rva000D146B *p)
{
	p->Rva000D146B::~Rva000D146B();
}

class Rva000D1713_B2
{
public:
	virtual void f2();
};

class Rva000D1713 : public Rva0049B47C, public MiBase1, public Rva000D1713_B2
{
public:
	virtual ~Rva000D1713()
	{
	}
};

void Rva000D1713_Anchor(Rva000D1713 *p)
{
	p->Rva000D1713::~Rva000D1713();
}

class Rva000D18AB_B2
{
public:
	virtual void f2();
};

class Rva000D18AB : public Rva0049B47C, public MiBase1, public Rva000D18AB_B2
{
public:
	virtual ~Rva000D18AB()
	{
	}
};

void Rva000D18AB_Anchor(Rva000D18AB *p)
{
	p->Rva000D18AB::~Rva000D18AB();
}

class Rva000D1E88_B2
{
public:
	virtual void f2();
};

class Rva000D1E88 : public Rva0049B47C, public MiBase1, public Rva000D1E88_B2
{
public:
	virtual ~Rva000D1E88()
	{
	}
};

void Rva000D1E88_Anchor(Rva000D1E88 *p)
{
	p->Rva000D1E88::~Rva000D1E88();
}

class Rva000D1BA6_B2
{
public:
	virtual void f2();
};

class Rva000D1BA6 : public Rva0049B47C, public MiBase1, public Rva000D1BA6_B2
{
public:
	virtual ~Rva000D1BA6()
	{
	}
};

void Rva000D1BA6_Anchor(Rva000D1BA6 *p)
{
	p->Rva000D1BA6::~Rva000D1BA6();
}

class Rva00142FE0_B2
{
public:
	virtual void f2();
};

class Rva00142FE0 : public Rva0049B47C, public MiBase1, public Rva00142FE0_B2
{
public:
	virtual ~Rva00142FE0()
	{
	}
};

void Rva00142FE0_Anchor(Rva00142FE0 *p)
{
	p->Rva00142FE0::~Rva00142FE0();
}

class Rva000E19A3_B2
{
public:
	virtual void f2();
};

class Rva000E19A3 : public Rva0049B47C, public MiBase1, public Rva000E19A3_B2
{
public:
	virtual ~Rva000E19A3()
	{
	}
};

void Rva000E19A3_Anchor(Rva000E19A3 *p)
{
	p->Rva000E19A3::~Rva000E19A3();
}

class Rva000E3B41_B2
{
public:
	virtual void f2();
};

class Rva000E3B41 : public Rva0049B47C, public MiBase1, public Rva000E3B41_B2
{
public:
	virtual ~Rva000E3B41()
	{
	}
};

void Rva000E3B41_Anchor(Rva000E3B41 *p)
{
	p->Rva000E3B41::~Rva000E3B41();
}

class Rva000E5033_B2
{
public:
	virtual void f2();
};

class Rva000E5033 : public Rva0049B47C, public MiBase1, public Rva000E5033_B2
{
public:
	virtual ~Rva000E5033()
	{
	}
};

void Rva000E5033_Anchor(Rva000E5033 *p)
{
	p->Rva000E5033::~Rva000E5033();
}

class Rva000E59D3_B2
{
public:
	virtual void f2();
};

class Rva000E59D3 : public Rva0049B47C, public MiBase1, public Rva000E59D3_B2
{
public:
	virtual ~Rva000E59D3()
	{
	}
};

void Rva000E59D3_Anchor(Rva000E59D3 *p)
{
	p->Rva000E59D3::~Rva000E59D3();
}

class Rva000E6387_B2
{
public:
	virtual void f2();
};

class Rva000E6387 : public Rva0049B47C, public MiBase1, public Rva000E6387_B2
{
public:
	virtual ~Rva000E6387()
	{
	}
};

void Rva000E6387_Anchor(Rva000E6387 *p)
{
	p->Rva000E6387::~Rva000E6387();
}

class Rva000E6C6F_B2
{
public:
	virtual void f2();
};

class Rva000E6C6F : public Rva0049B47C, public MiBase1, public Rva000E6C6F_B2
{
public:
	virtual ~Rva000E6C6F()
	{
	}
};

void Rva000E6C6F_Anchor(Rva000E6C6F *p)
{
	p->Rva000E6C6F::~Rva000E6C6F();
}

class Rva000E9BAC_B2
{
public:
	virtual void f2();
};

class Rva000E9BAC : public Rva0049B47C, public MiBase1, public Rva000E9BAC_B2
{
public:
	virtual ~Rva000E9BAC()
	{
	}
};

void Rva000E9BAC_Anchor(Rva000E9BAC *p)
{
	p->Rva000E9BAC::~Rva000E9BAC();
}

class Rva000EDA94_B2
{
public:
	virtual void f2();
};

class Rva000EDA94 : public Rva0049B47C, public MiBase1, public Rva000EDA94_B2
{
public:
	virtual ~Rva000EDA94()
	{
	}
};

void Rva000EDA94_Anchor(Rva000EDA94 *p)
{
	p->Rva000EDA94::~Rva000EDA94();
}

class Rva000EEEF4_B2
{
public:
	virtual void f2();
};

class Rva000EEEF4 : public Rva0049B47C, public MiBase1, public Rva000EEEF4_B2
{
public:
	virtual ~Rva000EEEF4()
	{
	}
};

void Rva000EEEF4_Anchor(Rva000EEEF4 *p)
{
	p->Rva000EEEF4::~Rva000EEEF4();
}

class Rva00613B90_B2
{
public:
	virtual void f2();
};

class Rva00613B90 : public Rva0049B47C, public MiBase1, public Rva00613B90_B2
{
public:
	virtual ~Rva00613B90()
	{
	}
};

void Rva00613B90_Anchor(Rva00613B90 *p)
{
	p->Rva00613B90::~Rva00613B90();
}

class Rva000EFC45_B2
{
public:
	virtual void f2();
};

class Rva000EFC45 : public Rva0049B47C, public MiBase1, public Rva000EFC45_B2
{
public:
	virtual ~Rva000EFC45()
	{
	}
};

void Rva000EFC45_Anchor(Rva000EFC45 *p)
{
	p->Rva000EFC45::~Rva000EFC45();
}

class Rva000F1B8F_B2
{
public:
	virtual void f2();
};

class Rva000F1B8F : public Rva0049B47C, public MiBase1, public Rva000F1B8F_B2
{
public:
	virtual ~Rva000F1B8F()
	{
	}
};

void Rva000F1B8F_Anchor(Rva000F1B8F *p)
{
	p->Rva000F1B8F::~Rva000F1B8F();
}

class Rva000F26DC_B2
{
public:
	virtual void f2();
};

class Rva000F26DC : public Rva0049B47C, public MiBase1, public Rva000F26DC_B2
{
public:
	virtual ~Rva000F26DC()
	{
	}
};

void Rva000F26DC_Anchor(Rva000F26DC *p)
{
	p->Rva000F26DC::~Rva000F26DC();
}

class Rva000F2797_B2
{
public:
	virtual void f2();
};

class Rva000F2797 : public Rva0049B47C, public MiBase1, public Rva000F2797_B2
{
public:
	virtual ~Rva000F2797()
	{
	}
};

void Rva000F2797_Anchor(Rva000F2797 *p)
{
	p->Rva000F2797::~Rva000F2797();
}

class Rva00102188_B2
{
public:
	virtual void f2();
};

class Rva00102188 : public Rva0049B47C, public MiBase1, public Rva00102188_B2
{
public:
	virtual ~Rva00102188()
	{
	}
};

void Rva00102188_Anchor(Rva00102188 *p)
{
	p->Rva00102188::~Rva00102188();
}

class Rva001041D8_B2
{
public:
	virtual void f2();
};

class Rva001041D8 : public Rva0049B47C, public MiBase1, public Rva001041D8_B2
{
public:
	virtual ~Rva001041D8()
	{
	}
};

void Rva001041D8_Anchor(Rva001041D8 *p)
{
	p->Rva001041D8::~Rva001041D8();
}

class Rva00104DB0_B2
{
public:
	virtual void f2();
};

class Rva00104DB0 : public Rva0049B47C, public MiBase1, public Rva00104DB0_B2
{
public:
	virtual ~Rva00104DB0()
	{
	}
};

void Rva00104DB0_Anchor(Rva00104DB0 *p)
{
	p->Rva00104DB0::~Rva00104DB0();
}

class Rva00104E03_B2
{
public:
	virtual void f2();
};

class Rva00104E03 : public Rva0049B47C, public MiBase1, public Rva00104E03_B2
{
public:
	virtual ~Rva00104E03()
	{
	}
};

void Rva00104E03_Anchor(Rva00104E03 *p)
{
	p->Rva00104E03::~Rva00104E03();
}

class Rva00106162_B2
{
public:
	virtual void f2();
};

class Rva00106162 : public Rva0049B47C, public MiBase1, public Rva00106162_B2
{
public:
	virtual ~Rva00106162()
	{
	}
};

void Rva00106162_Anchor(Rva00106162 *p)
{
	p->Rva00106162::~Rva00106162();
}

class Rva00109C7F_B2
{
public:
	virtual void f2();
};

class Rva00109C7F : public Rva0049B47C, public MiBase1, public Rva00109C7F_B2
{
public:
	virtual ~Rva00109C7F()
	{
	}
};

void Rva00109C7F_Anchor(Rva00109C7F *p)
{
	p->Rva00109C7F::~Rva00109C7F();
}

class Rva00109BEB_B2
{
public:
	virtual void f2();
};

class Rva00109BEB : public Rva0049B47C, public MiBase1, public Rva00109BEB_B2
{
public:
	virtual ~Rva00109BEB()
	{
	}
};

void Rva00109BEB_Anchor(Rva00109BEB *p)
{
	p->Rva00109BEB::~Rva00109BEB();
}

class Rva001095B2_B2
{
public:
	virtual void f2();
};

class Rva001095B2 : public Rva0049B47C, public MiBase1, public Rva001095B2_B2
{
public:
	virtual ~Rva001095B2()
	{
	}
};

void Rva001095B2_Anchor(Rva001095B2 *p)
{
	p->Rva001095B2::~Rva001095B2();
}

class Rva00109610_B2
{
public:
	virtual void f2();
};

class Rva00109610 : public Rva0049B47C, public MiBase1, public Rva00109610_B2
{
public:
	virtual ~Rva00109610()
	{
	}
};

void Rva00109610_Anchor(Rva00109610 *p)
{
	p->Rva00109610::~Rva00109610();
}

class Rva0010C785_B2
{
public:
	virtual void f2();
};

class Rva0010C785 : public Rva0049B47C, public MiBase1, public Rva0010C785_B2
{
public:
	virtual ~Rva0010C785()
	{
	}
};

void Rva0010C785_Anchor(Rva0010C785 *p)
{
	p->Rva0010C785::~Rva0010C785();
}

class Rva0010F0C4_B2
{
public:
	virtual void f2();
};

class Rva0010F0C4 : public Rva0049B47C, public MiBase1, public Rva0010F0C4_B2
{
public:
	virtual ~Rva0010F0C4()
	{
	}
};

void Rva0010F0C4_Anchor(Rva0010F0C4 *p)
{
	p->Rva0010F0C4::~Rva0010F0C4();
}

class Rva0010F7EE_B2
{
public:
	virtual void f2();
};

class Rva0010F7EE : public Rva0049B47C, public MiBase1, public Rva0010F7EE_B2
{
public:
	virtual ~Rva0010F7EE()
	{
	}
};

void Rva0010F7EE_Anchor(Rva0010F7EE *p)
{
	p->Rva0010F7EE::~Rva0010F7EE();
}

class Rva0010F83E_B2
{
public:
	virtual void f2();
};

class Rva0010F83E : public Rva0049B47C, public MiBase1, public Rva0010F83E_B2
{
public:
	virtual ~Rva0010F83E()
	{
	}
};

void Rva0010F83E_Anchor(Rva0010F83E *p)
{
	p->Rva0010F83E::~Rva0010F83E();
}
