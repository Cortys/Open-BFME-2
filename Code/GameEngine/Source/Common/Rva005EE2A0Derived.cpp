// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva005EE2A0::~
// Rva005EE2A0 at 0x005EE2A0 (row in Rva005EE30CChain.cpp). Each class below
// stores its own vtable and tail-calls the base destructor; the base itself
// is only declared here (defined once in Rva005EE30CChain.cpp), because a
// same-TU definition would capture the call locally instead of at the ledger
// address. Owner identities are unproven (opaque Rva names). One ledger row
// per destructor, landed one commit at a time.

class Rva005EE2A0
{
public:
	Rva005EE2A0();
	virtual ~Rva005EE2A0();
};

class Rva005D719C : public Rva005EE2A0
{
public:
	Rva005D719C();
	virtual ~Rva005D719C();
};

// ??0Rva005D719C@@QAE@XZ @0x005D718A 18B: base ctor 0x005EE28C then vtable
// 0x00875C80. Evidence: vtable store at [this]; caller 0x0058AC93.
Rva005D719C::Rva005D719C()
{
}

Rva005D719C::~Rva005D719C()
{
}

class Rva005D724B : public Rva005EE2A0
{
public:
	Rva005D724B();
	virtual ~Rva005D724B();
};

// ??0Rva005D724B@@QAE@XZ @0x005D7239 18B: base ctor 0x005EE28C then vtable
// 0x00875CA4. Evidence: vtable store at [this]; caller 0x0058AC78.
Rva005D724B::Rva005D724B()
{
}

Rva005D724B::~Rva005D724B()
{
}

class Rva005D72FA : public Rva005EE2A0
{
public:
	Rva005D72FA();
	virtual ~Rva005D72FA();
};

// ??0Rva005D72FA@@QAE@XZ @0x005D72E8 18B: base ctor 0x005EE28C then vtable
// 0x00875CC8. Evidence: vtable store at [this]; caller 0x0058AC59.
Rva005D72FA::Rva005D72FA()
{
}

Rva005D72FA::~Rva005D72FA()
{
}

class Rva005D8964 : public Rva005EE2A0
{
public:
	virtual ~Rva005D8964();
};

Rva005D8964::~Rva005D8964()
{
}

class Rva005D8BD5 : public Rva005EE2A0
{
public:
	virtual ~Rva005D8BD5();
};

Rva005D8BD5::~Rva005D8BD5()
{
}

class Rva005D9BA5 : public Rva005EE2A0
{
public:
	virtual ~Rva005D9BA5();
};

Rva005D9BA5::~Rva005D9BA5()
{
}

class Rva005DA353 : public Rva005EE2A0
{
public:
	virtual ~Rva005DA353();
};

Rva005DA353::~Rva005DA353()
{
}
