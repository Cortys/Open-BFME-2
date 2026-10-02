// cl: /O1 /DNDEBUG /MD /GX
//
// STLport vector destructors, one per element type, with the shape of the rowed
// ??1?$vector@UPrereqUnitRec@ProductionPrerequisite@@... at 0x002D040C (63 bytes:
// destroy [start, finish) through the element range destructor, then the base
// frees the storage). Found by searching .text for that shape with call
// displacements and the EH handler record masked. Each copy calls __EH_prolog,
// one rowed range destructor and free (0x00030830). Copies of different
// element types can share an ICF-folded range destructor, so the vector itself
// is not identified and each keeps its own address.

extern "C" void __cdecl free(void *block);

namespace _STL
{
template <class I> void __cdecl _Destroy(I first, I last);
}

template <class E> struct RvaVectorFamilyBase
{
	E *m_start;
	E *m_finish;
	E *m_endOfStorage;
	~RvaVectorFamilyBase()
	{
		if (m_start)
			free(m_start);
	}
};

class Rva002DFC30;

// ??1Rva000C0417@@QAE@XZ @0x000C0417 63B -> ??$_Destroy@PAVRva002DFC30@@@_STL@@YAXPAVRva002DFC30@@0@Z
struct Rva000C0417 : RvaVectorFamilyBase<Rva002DFC30>
{
	~Rva000C0417();
};

Rva000C0417::~Rva000C0417()
{
	_STL::_Destroy(m_start, m_finish);
}

struct RvaPair0032C0CA;

void __cdecl Rva0032C0CADestroyPairs(RvaPair0032C0CA *, RvaPair0032C0CA *);

// ??1Rva000C0456@@QAE@XZ @0x000C0456 63B -> ?Rva0032C0CADestroyPairs@@YAXPAURvaPair0032C0CA@@0@Z
struct Rva000C0456 : RvaVectorFamilyBase<RvaPair0032C0CA>
{
	~Rva000C0456();
};

Rva000C0456::~Rva000C0456()
{
	Rva0032C0CADestroyPairs(m_start, m_finish);
}

class CameraMarker;

// ??1Rva000C0495@@QAE@XZ @0x000C0495 63B -> ??$_Destroy@PAVCameraMarker@@@_STL@@YAXPAVCameraMarker@@0@Z
struct Rva000C0495 : RvaVectorFamilyBase<CameraMarker>
{
	~Rva000C0495();
};

Rva000C0495::~Rva000C0495()
{
	_STL::_Destroy(m_start, m_finish);
}

void __cdecl Rva00405337Clear(void *, void *);

// ??1Rva000C04D4@@QAE@XZ @0x000C04D4 63B -> ?Rva00405337Clear@@YAXPAX0@Z
struct Rva000C04D4 : RvaVectorFamilyBase<void>
{
	~Rva000C04D4();
};

Rva000C04D4::~Rva000C04D4()
{
	Rva00405337Clear(m_start, m_finish);
}

struct RvaPair000BDCEF;

void __cdecl Rva000BDCEFDestroy(RvaPair000BDCEF *, RvaPair000BDCEF *);

// ??1Rva000C055C@@QAE@XZ @0x000C055C 63B -> ?Rva000BDCEFDestroy@@YAXPAURvaPair000BDCEF@@0@Z
struct Rva000C055C : RvaVectorFamilyBase<RvaPair000BDCEF>
{
	~Rva000C055C();
};

Rva000C055C::~Rva000C055C()
{
	Rva000BDCEFDestroy(m_start, m_finish);
}

class Rva000B9AAA;

void __cdecl Rva000BDD08Destroy(Rva000B9AAA *, Rva000B9AAA *);

// ??1Rva000C1BE1@@QAE@XZ @0x000C1BE1 63B -> ?Rva000BDD08Destroy@@YAXPAVRva000B9AAA@@0@Z
struct Rva000C1BE1 : RvaVectorFamilyBase<Rva000B9AAA>
{
	~Rva000C1BE1();
};

Rva000C1BE1::~Rva000C1BE1()
{
	Rva000BDD08Destroy(m_start, m_finish);
}

struct Rva0052BF33Elem;

void __cdecl Rva005A6EDADestroyRange(Rva0052BF33Elem *, Rva0052BF33Elem *);

// ??1Rva001501CA@@QAE@XZ @0x001501CA 63B -> ?Rva005A6EDADestroyRange@@YAXPAURva0052BF33Elem@@0@Z
struct Rva001501CA : RvaVectorFamilyBase<Rva0052BF33Elem>
{
	~Rva001501CA();
};

Rva001501CA::~Rva001501CA()
{
	Rva005A6EDADestroyRange(m_start, m_finish);
}

class Rva0014F3E7;

void __cdecl Rva0014F8AEDestroy(Rva0014F3E7 *, Rva0014F3E7 *);

// ??1Rva00150209@@QAE@XZ @0x00150209 63B -> ?Rva0014F8AEDestroy@@YAXPAVRva0014F3E7@@0@Z
struct Rva00150209 : RvaVectorFamilyBase<Rva0014F3E7>
{
	~Rva00150209();
};

Rva00150209::~Rva00150209()
{
	Rva0014F8AEDestroy(m_start, m_finish);
}

struct BfmeStringRecord002199C8;

// ??1Rva0021DA18@@QAE@XZ @0x0021DA18 63B -> ??$_Destroy@PAUBfmeStringRecord002199C8@@@_STL@@YAXPAUBfmeStringRecord002199C8@@0@Z
struct Rva0021DA18 : RvaVectorFamilyBase<BfmeStringRecord002199C8>
{
	~Rva0021DA18();
};

Rva0021DA18::~Rva0021DA18()
{
	_STL::_Destroy(m_start, m_finish);
}

struct BfmeStringRecord00219A68;

// ??1Rva0021DA57@@QAE@XZ @0x0021DA57 63B -> ??$_Destroy@PAUBfmeStringRecord00219A68@@@_STL@@YAXPAUBfmeStringRecord00219A68@@0@Z
struct Rva0021DA57 : RvaVectorFamilyBase<BfmeStringRecord00219A68>
{
	~Rva0021DA57();
};

Rva0021DA57::~Rva0021DA57()
{
	_STL::_Destroy(m_start, m_finish);
}

// ??1Rva0021DB35@@QAE@XZ @0x0021DB35 63B -> ?Rva0032C0CADestroyPairs@@YAXPAURvaPair0032C0CA@@0@Z
struct Rva0021DB35 : RvaVectorFamilyBase<RvaPair0032C0CA>
{
	~Rva0021DB35();
};

Rva0021DB35::~Rva0021DB35()
{
	Rva0032C0CADestroyPairs(m_start, m_finish);
}

struct Rva0052BF9BElem;

void __cdecl Rva0022C8E3DestroyRange(Rva0052BF9BElem *, Rva0052BF9BElem *);

// ??1Rva0022CAC4@@QAE@XZ @0x0022CAC4 63B -> ?Rva0022C8E3DestroyRange@@YAXPAURva0052BF9BElem@@0@Z
struct Rva0022CAC4 : RvaVectorFamilyBase<Rva0052BF9BElem>
{
	~Rva0022CAC4();
};

Rva0022CAC4::~Rva0022CAC4()
{
	Rva0022C8E3DestroyRange(m_start, m_finish);
}

struct OpaqueRefElement4;

// ??1Rva00239E25@@QAE@XZ @0x00239E25 63B -> ??$_Destroy@PAUOpaqueRefElement4@@@_STL@@YAXPAUOpaqueRefElement4@@0@Z
struct Rva00239E25 : RvaVectorFamilyBase<OpaqueRefElement4>
{
	~Rva00239E25();
};

Rva00239E25::~Rva00239E25()
{
	_STL::_Destroy(m_start, m_finish);
}

struct BfmeStringRecord005DDD40;

// ??1Rva00260826@@QAE@XZ @0x00260826 63B -> ??$_Destroy@PAUBfmeStringRecord005DDD40@@@_STL@@YAXPAUBfmeStringRecord005DDD40@@0@Z
struct Rva00260826 : RvaVectorFamilyBase<BfmeStringRecord005DDD40>
{
	~Rva00260826();
};

Rva00260826::~Rva00260826()
{
	_STL::_Destroy(m_start, m_finish);
}

// ??1Rva00317E7C@@QAE@XZ @0x00317E7C 63B -> ?Rva0032C0CADestroyPairs@@YAXPAURvaPair0032C0CA@@0@Z
struct Rva00317E7C : RvaVectorFamilyBase<RvaPair0032C0CA>
{
	~Rva00317E7C();
};

Rva00317E7C::~Rva00317E7C()
{
	Rva0032C0CADestroyPairs(m_start, m_finish);
}

class Rva0032A3A9Element;

// ??1Rva0032BE80@@QAE@XZ @0x0032BE80 63B -> ??$_Destroy@PAVRva0032A3A9Element@@@_STL@@YAXPAVRva0032A3A9Element@@0@Z
struct Rva0032BE80 : RvaVectorFamilyBase<Rva0032A3A9Element>
{
	~Rva0032BE80();
};

Rva0032BE80::~Rva0032BE80()
{
	_STL::_Destroy(m_start, m_finish);
}

class Rva00329D0E;

void __cdecl Rva0032AF56Destroy(Rva00329D0E *, Rva00329D0E *);

// ??1Rva0032C3A3@@QAE@XZ @0x0032C3A3 63B -> ?Rva0032AF56Destroy@@YAXPAVRva00329D0E@@0@Z
struct Rva0032C3A3 : RvaVectorFamilyBase<Rva00329D0E>
{
	~Rva0032C3A3();
};

Rva0032C3A3::~Rva0032C3A3()
{
	Rva0032AF56Destroy(m_start, m_finish);
}

// ??1Rva0032CA4E@@QAE@XZ @0x0032CA4E 63B -> ?Rva0032C0CADestroyPairs@@YAXPAURvaPair0032C0CA@@0@Z
struct Rva0032CA4E : RvaVectorFamilyBase<RvaPair0032C0CA>
{
	~Rva0032CA4E();
};

Rva0032CA4E::~Rva0032CA4E()
{
	Rva0032C0CADestroyPairs(m_start, m_finish);
}

// ??1Rva003321D8@@QAE@XZ @0x003321D8 63B -> ??$_Destroy@PAVRva002DFC30@@@_STL@@YAXPAVRva002DFC30@@0@Z
struct Rva003321D8 : RvaVectorFamilyBase<Rva002DFC30>
{
	~Rva003321D8();
};

Rva003321D8::~Rva003321D8()
{
	_STL::_Destroy(m_start, m_finish);
}

// ??1Rva00381AE0@@QAE@XZ @0x00381AE0 63B -> ??$_Destroy@PAUBfmeStringRecord005DDD40@@@_STL@@YAXPAUBfmeStringRecord005DDD40@@0@Z
struct Rva00381AE0 : RvaVectorFamilyBase<BfmeStringRecord005DDD40>
{
	~Rva00381AE0();
};

Rva00381AE0::~Rva00381AE0()
{
	_STL::_Destroy(m_start, m_finish);
}

// ??1Rva0039C151@@QAE@XZ @0x0039C151 63B -> ?Rva0022C8E3DestroyRange@@YAXPAURva0052BF9BElem@@0@Z
struct Rva0039C151 : RvaVectorFamilyBase<Rva0052BF9BElem>
{
	~Rva0039C151();
};

Rva0039C151::~Rva0039C151()
{
	Rva0022C8E3DestroyRange(m_start, m_finish);
}

class LivingWorldRegionConnection;

void __cdecl Rva003F0CA1_DestroyRange(LivingWorldRegionConnection *, LivingWorldRegionConnection *);

// ??1Rva003F1797@@QAE@XZ @0x003F1797 63B -> ?Rva003F0CA1_DestroyRange@@YAXPAVLivingWorldRegionConnection@@0@Z
struct Rva003F1797 : RvaVectorFamilyBase<LivingWorldRegionConnection>
{
	~Rva003F1797();
};

Rva003F1797::~Rva003F1797()
{
	Rva003F0CA1_DestroyRange(m_start, m_finish);
}

// ??1Rva00405350@@QAE@XZ @0x00405350 63B -> ?Rva00405337Clear@@YAXPAX0@Z
struct Rva00405350 : RvaVectorFamilyBase<void>
{
	~Rva00405350();
};

Rva00405350::~Rva00405350()
{
	Rva00405337Clear(m_start, m_finish);
}

struct DestroyElem0040B52E;

void __cdecl Rva0040B52EDestroy(DestroyElem0040B52E *, DestroyElem0040B52E *);

// ??1Rva0040B560@@QAE@XZ @0x0040B560 63B -> ?Rva0040B52EDestroy@@YAXPAUDestroyElem0040B52E@@0@Z
struct Rva0040B560 : RvaVectorFamilyBase<DestroyElem0040B52E>
{
	~Rva0040B560();
};

Rva0040B560::~Rva0040B560()
{
	Rva0040B52EDestroy(m_start, m_finish);
}
