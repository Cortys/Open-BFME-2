// cl: /O1 /MD /GX /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// The skirmish-AI object behind vtable 0x00863FAC, newed by 0x004EC430 in the
// AITactic.cpp range (its assert path is at 0x00862968; the neighbouring
// asserts at 0x005061FD.. name AITacticsGenerator.cpp). No RTTI and no donor:
// the class keeps the address-derived name its matched member 0x00506B74
// already carries (Rva00506B74CopyCompare.cpp).
//
// Target evidence for the layout:
//   +0x00 base Rva00506B1B (ctor 0x00506B1B, dtor 0x00506B28, vtable
//         0x00863F9C with __purecall in slots 1 and 2)
//   +0x08 the pointer the ctor is given
//   +0x0C vector of owned pointers: slot 2 (0x005071A1) runs each through
//         dtor 0x005ADA40 plus operator delete, then erase 0x0031BD55
//   +0x18 Coord3D, +0x24 flag, +0x28 Coord3D, both points seeded from the
//         -1 triple at 0x00DD0870 (Gen00DD0870)
#include <vector>

struct Coord3DBase
{
	float x;
	float y;
	float z;
};

struct Coord3D : public Coord3DBase
{
	bool equals(const Coord3DBase &that) const;
	void set(const Coord3DBase *that) { x = that->x; y = that->y; z = that->z; }
};

extern Coord3DBase Gen00DD0870;

class Rva005AD9C0Hit
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3(void *arg);
};

class Rva005ADA40
{
public:
	~Rva005ADA40();
	void rva005ADC63();
	Rva005AD9C0Hit *rva005AD9C0(void *arg);
};

class Rva00506B1B
{
public:
	Rva00506B1B();
	virtual ~Rva00506B1B();
	virtual void v1() = 0;
	virtual void v2() = 0;
private:
	bool m_04;
};

Coord3D __cdecl Rva00506CF5(void *owner, Coord3D *point);

class Rva00506B74 : public Rva00506B1B
{
public:
	Rva00506B74(void *owner);
	virtual ~Rva00506B74();
	virtual void v1();
	virtual void v2();
	bool rva00506B74(Coord3D *out);
	void rva0050722A(Coord3D *point);
	void rva00506B96(const Coord3D *point);
	Rva005AD9C0Hit *rva00506BF7(void *arg);
	bool rva00506C39(void *arg);
	Rva005ADA40 *rva00506C64(unsigned int index);
	void rva00507522();
private:
	void *m_08;
	_STL::vector<Rva005ADA40 *> m_0C;
	Coord3D m_18;
	bool m_24;
	Coord3D m_28;
};

// ??0Rva00506B74@@QAE@PAX@Z
Rva00506B74::Rva00506B74(void *owner)
	: m_08(owner)
{
	m_18.set(&Gen00DD0870);
	m_24 = false;
	m_28.set(&Gen00DD0870);
	m_28 = Rva00506CF5(m_08, &m_18);
}

// ??1Rva00506B74@@UAE@XZ
Rva00506B74::~Rva00506B74()
{
	v2();
}

// Slot 1 (0x00506BDC).
void Rva00506B74::v1()
{
	for (Rva005ADA40 **it = m_0C.begin(), **end = m_0C.end(); it != end; ++it)
		(*it)->rva005ADC63();
}

// Slot 2 (0x005071A1): free every element, then empty the vector.
void Rva00506B74::v2()
{
	for (Rva005ADA40 **it = m_0C.begin(), **end = m_0C.end(); it != end; ++it)
		delete *it;
	m_0C.clear();
}

void Rva00506B74::rva00506B96(const Coord3D *point)
{
	if (!m_24)
		m_18 = *point;
}

Rva005AD9C0Hit *Rva00506B74::rva00506BF7(void *arg)
{
	Rva005ADA40 **end = m_0C.end();
	for (Rva005ADA40 **it = m_0C.begin(); it != end; ++it) {
		Rva005AD9C0Hit *hit = (*it)->rva005AD9C0((char *)arg + 0xC);
		if (hit) {
			hit->v3(arg);
			return hit;
		}
	}
	return 0;
}

bool Rva00506B74::rva00506C39(void *arg)
{
	for (Rva005ADA40 **it = m_0C.begin(), **end = m_0C.end(); it != end; ++it) {
		if ((*it)->rva005AD9C0(arg))
			return true;
	}
	return false;
}

Rva005ADA40 *Rva00506B74::rva00506C64(unsigned int index)
{
	if (index < m_0C.size())
		return m_0C[index];
	return 0;
}

void Rva00506B74::rva00507522()
{
	if (!m_24) {
		if (rva00506B74(&m_28))
			rva0050722A(&m_28);
	}
	m_24 = true;
}
