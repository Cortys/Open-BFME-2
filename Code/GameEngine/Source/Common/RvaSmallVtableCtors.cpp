// cl: /O1 /DNDEBUG /MD
//
// Small constructors that install a vtable, in two shapes of rowed bodies:
//   18 bytes as ??0Rva005CB22A (V3PolyCopyCtors.cpp): store the vtable, then the
//     pointer argument at +4;
//   13 bytes as ??0NetCommandWrapperList: zero +4, then store the vtable, the
//     order an inlined base constructor followed by the derived vtable store gives.
// Each copy differs from its template only in the vtable it installs. One class
// per copy names that vtable; its destructor is inline and empty so the vtable
// the compiler emits resolves in this unit. The owning classes are not
// recovered, so each keeps its address.

struct RvaSmallVtableZeroBase
{
	virtual ~RvaSmallVtableZeroBase() {}
	void *m_04;
	RvaSmallVtableZeroBase() : m_04(0) {}
};

// ??0Rva000ABD56@@QAE@PAX@Z @0x000ABD56 18B, vtable VA 0xbc957c
class Rva000ABD56
{
public:
	Rva000ABD56(void *p);
	virtual ~Rva000ABD56() {}
private:
	void *m_04;
};

Rva000ABD56::Rva000ABD56(void *p) : m_04(p)
{
}

// ??0Rva00222A19@@QAE@PAX@Z @0x00222A19 18B, vtable VA 0xbe6d5c
class Rva00222A19
{
public:
	Rva00222A19(void *p);
	virtual ~Rva00222A19() {}
private:
	void *m_04;
};

Rva00222A19::Rva00222A19(void *p) : m_04(p)
{
}

// ??0Rva00040ECE@@QAE@XZ @0x00040ECE 13B, vtable VA 0xbc16b8
class Rva00040ECE : public RvaSmallVtableZeroBase
{
public:
	Rva00040ECE();
	virtual ~Rva00040ECE() {}
};

Rva00040ECE::Rva00040ECE()
{
}

// ??0Rva000421C8@@QAE@XZ @0x000421C8 13B, vtable VA 0xbc26e0
class Rva000421C8 : public RvaSmallVtableZeroBase
{
public:
	Rva000421C8();
	virtual ~Rva000421C8() {}
};

Rva000421C8::Rva000421C8()
{
}

// ??0Rva000657D9@@QAE@XZ @0x000657D9 13B, vtable VA 0xbc5c6c
class Rva000657D9 : public RvaSmallVtableZeroBase
{
public:
	Rva000657D9();
	virtual ~Rva000657D9() {}
};

Rva000657D9::Rva000657D9()
{
}

// ??0Rva0007DF07@@QAE@XZ @0x0007DF07 13B, vtable VA 0xbc6f20
class Rva0007DF07 : public RvaSmallVtableZeroBase
{
public:
	Rva0007DF07();
	virtual ~Rva0007DF07() {}
};

Rva0007DF07::Rva0007DF07()
{
}

// ??0Rva000A882D@@QAE@XZ @0x000A882D 13B, vtable VA 0xbc93a0
class Rva000A882D : public RvaSmallVtableZeroBase
{
public:
	Rva000A882D();
	virtual ~Rva000A882D() {}
};

Rva000A882D::Rva000A882D()
{
}

// ??0Rva000FBA4A@@QAE@XZ @0x000FBA4A 13B, vtable VA 0xbcf364
class Rva000FBA4A : public RvaSmallVtableZeroBase
{
public:
	Rva000FBA4A();
	virtual ~Rva000FBA4A() {}
};

Rva000FBA4A::Rva000FBA4A()
{
}

// ??0Rva00217497@@QAE@XZ @0x00217497 13B, vtable VA 0xbe5aa8
class Rva00217497 : public RvaSmallVtableZeroBase
{
public:
	Rva00217497();
	virtual ~Rva00217497() {}
};

Rva00217497::Rva00217497()
{
}

// ??0Rva002390F8@@QAE@XZ @0x002390F8 13B, vtable VA 0xbed684
class Rva002390F8 : public RvaSmallVtableZeroBase
{
public:
	Rva002390F8();
	virtual ~Rva002390F8() {}
};

Rva002390F8::Rva002390F8()
{
}

// ??0Rva0026FFB1@@QAE@XZ @0x0026FFB1 13B, vtable VA 0xbfad1c
class Rva0026FFB1 : public RvaSmallVtableZeroBase
{
public:
	Rva0026FFB1();
	virtual ~Rva0026FFB1() {}
};

Rva0026FFB1::Rva0026FFB1()
{
}

// ??0Rva0030D346@@QAE@XZ @0x0030D346 13B, vtable VA 0xc089ec
class Rva0030D346 : public RvaSmallVtableZeroBase
{
public:
	Rva0030D346();
	virtual ~Rva0030D346() {}
};

Rva0030D346::Rva0030D346()
{
}

// ??0Rva003E3C0C@@QAE@XZ @0x003E3C0C 13B, vtable VA 0xc35b28
class Rva003E3C0C : public RvaSmallVtableZeroBase
{
public:
	Rva003E3C0C();
	virtual ~Rva003E3C0C() {}
};

Rva003E3C0C::Rva003E3C0C()
{
}

// ??0Rva0048B664@@QAE@XZ @0x0048B664 13B, vtable VA 0xc4bf78
class Rva0048B664 : public RvaSmallVtableZeroBase
{
public:
	Rva0048B664();
	virtual ~Rva0048B664() {}
};

Rva0048B664::Rva0048B664()
{
}

// ??0Rva004B236E@@QAE@XZ @0x004B236E 13B, vtable VA 0xc56930
class Rva004B236E : public RvaSmallVtableZeroBase
{
public:
	Rva004B236E();
	virtual ~Rva004B236E() {}
};

Rva004B236E::Rva004B236E()
{
}

// ??0Rva0051489D@@QAE@XZ @0x0051489D 13B, vtable VA 0xc65ee0
class Rva0051489D : public RvaSmallVtableZeroBase
{
public:
	Rva0051489D();
	virtual ~Rva0051489D() {}
};

Rva0051489D::Rva0051489D()
{
}

// ??0Rva0052510C@@QAE@XZ @0x0052510C 13B, vtable VA 0xc67e50
class Rva0052510C : public RvaSmallVtableZeroBase
{
public:
	Rva0052510C();
	virtual ~Rva0052510C() {}
};

Rva0052510C::Rva0052510C()
{
}
