// cl: /O1 /DNDEBUG /MD
// ??0Rva004FAC6B@@QAE@XZ @0x004FAC6B 21B: honest ctor with member at +4.
// Evidence: calls rowed Rva00330757Member ctor 0x00330757 for member at +4; installs vtable 0x008633C0; called by derived ctor 0x004FADF4 which overrides vtable to 0x008633FC; prev row is dtor in same subsystem.
class Rva00330757Member
{
public:
	Rva00330757Member();
};

class __declspec(novtable) Rva004FAC6BBase0
{
public:
	virtual void base0();
};

class Rva004FAC6B : public Rva004FAC6BBase0, public Rva00330757Member
{
public:
	Rva004FAC6B();
	virtual ~Rva004FAC6B();
};

Rva004FAC6B::Rva004FAC6B()
{
}
