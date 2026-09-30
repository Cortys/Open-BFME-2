// cl: /O1 /GX /DNDEBUG /MD
// ??0Rva00253A78@@QAE@XZ @0x00253A78 26B derived ctor.
// Retail calls base ??0Rva00253510@@QAE@XZ, zeroes +0x38, stores vtable
// 0x0084ED70, sets +0x3C to 1. Evidence: leaf lane; vtable store;
// base size 0x38 from Rva00253510Ctor TU; flags from neighbours;
// explicit-vtable pattern from ToggleHiddenSpecialAbilityUpdateCtor TU.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

static int s_vtable;

class __declspec(novtable) Rva00253510
{
public:
	Rva00253510();
protected:
	const void *m_vtable;
	unsigned char m_pad[0x38 - 4];
};

class Rva00253A78 : public Rva00253510
{
public:
	Rva00253A78();
private:
	int m_38;
	bool m_3C;
};

Rva00253A78::Rva00253A78()
	: Rva00253510()
{
	m_38 = 0;
	_ReadWriteBarrier();
	m_vtable = &s_vtable;
	m_3C = true;
}
