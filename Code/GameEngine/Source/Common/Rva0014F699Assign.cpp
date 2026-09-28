// cl: /O1
// ??4Rva0014F699@@QAEAAV0@ABV0@@Z @0x0014F699 127B; copy-assignment over 0x4C-byte element with RefCountPtr at +0x48.
// Retail: mov eax [esp+4] / push esi / mov esi ecx / 17 dword copies +4..+44 / add eax 0x48 / push eax / lea ecx [esi+0x48] / call 0x424D0 RefCountPtr assign / mov eax esi / pop esi / ret 4.
// Target facts: this in ecx; source on stack; +0 vptr not copied; 17 dwords +4..+44 via mov; +48 via rowed ??4?$RefCountPtr@VTextureClass@@@@QAEABV0@ABV0@@Z; returns this; size 0x4C proven by callers 0x0014F746 0x0014FA2A 0x0014FA90 idiv/add loops.
// Callers: 0x0014F76A 0x0014FA37 0x0014FAAC; callees: 0x000424D0.
// Not established: owning class identity; names are address-derived.
class TextureBaseClass
{
public:
	void Add_Ref();
	void Release_Ref();
};

class TextureClass : public TextureBaseClass
{
};

template<class T>
class RefCountPtr
{
public:
	RefCountPtr const &operator=(RefCountPtr const &other);
private:
	T *Referent;
};

class Rva0014F699
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	int m_28;
	int m_2c;
	int m_30;
	int m_34;
	int m_38;
	int m_3c;
	int m_40;
	int m_44;
	RefCountPtr<TextureClass> m_48;
public:
	Rva0014F699 &operator=(const Rva0014F699 &other);
};

Rva0014F699 &Rva0014F699::operator=(const Rva0014F699 &other)
{
	m_04 = other.m_04;
	m_08 = other.m_08;
	m_0c = other.m_0c;
	m_10 = other.m_10;
	m_14 = other.m_14;
	m_18 = other.m_18;
	m_1c = other.m_1c;
	m_20 = other.m_20;
	m_24 = other.m_24;
	m_28 = other.m_28;
	m_2c = other.m_2c;
	m_30 = other.m_30;
	m_34 = other.m_34;
	m_38 = other.m_38;
	m_3c = other.m_3c;
	m_40 = other.m_40;
	m_44 = other.m_44;
	m_48 = other.m_48;
	return *this;
}
