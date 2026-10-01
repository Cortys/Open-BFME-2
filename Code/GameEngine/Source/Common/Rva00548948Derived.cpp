// cl: /O1 /MD
//
// SpecialPowerModuleData is the shared base: matched constructor/xfer TUs
// identify it for Rva00546CAD and Rva00546F61, whose dtors tail-jump to 0x548948.
// Rva00546B29 uses the same tail target; keep all derived names opaque.
// Model only the known 0x18 base extent needed by these destructor bodies.
class Snapshot
{
public:
	virtual ~Snapshot();
};

class SpecialPowerModuleData : public Snapshot
{
public:
	virtual ~SpecialPowerModuleData();

private:
	unsigned char m_pad04[0x14];
};

class Rva00546B29 : public SpecialPowerModuleData
{
public:
	virtual ~Rva00546B29();
};

Rva00546B29::~Rva00546B29()
{
}

class Rva00546CAD : public SpecialPowerModuleData
{
public:
	virtual ~Rva00546CAD();
};

Rva00546CAD::~Rva00546CAD()
{
}

class Rva00546F61 : public SpecialPowerModuleData
{
public:
	virtual ~Rva00546F61();
};

Rva00546F61::~Rva00546F61()
{
}
