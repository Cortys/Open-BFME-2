// cl: /O1 /MD /GX /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// The 0x2C-byte elements the skirmish-AI object Rva00506B74 owns in its +0x0C
// vector (Rva00506B74Tactic.cpp builds them with operator new and this ctor,
// deletes them, and calls their pinned members). Layout from the ctor:
//   +0x00 vector of owned Rva005DCE08 (non-virtual dtor 0x005DCE08)
//   +0x0C the element's index, +0x10 cleared, +0x14 the owner
//   +0x18 Coord3D and +0x24 float, both zeroed
//   +0x28 an owned polymorphic object
//
//   0x005AD9FF  ctor (index, owner)
//   0x005ADA40  dtor: delete every item, ::delete the +0x28 object, free
//               the vector
//   0x005AD9C0  the first item hit (0x005DCC86) by the argument
//   0x005ADC63  update: retire the +0x28 object once done (0x004E9378), or
//               start one (0x005ADAB2); then update every item
#include <vector>

struct Coord3DBase
{
	float x;
	float y;
	float z;
};

struct Coord3D : public Coord3DBase
{
	void zero() { x = 0.0f; y = 0.0f; z = 0.0f; }
};

class Rva005AD9C0Hit;

class Rva005DCE08
{
public:
	~Rva005DCE08();
	Rva005AD9C0Hit *rva005DCC86(void *arg);
	void rva005DCCFB();
};

class Rva004E9378
{
public:
	bool rva004E9378();
};

class Rva00506FE9Hit
{
public:
	void rva0055ADBA(void *owner);
};

class Rva005ADA40Owned
{
public:
	virtual ~Rva005ADA40Owned();
};

class Rva005ADA40
{
public:
	Rva005ADA40(unsigned int index, void *owner);
	~Rva005ADA40();
	Rva005AD9C0Hit *rva005AD9C0(void *arg);
	void rva005ADAB2();
	void rva005ADC63();
private:
	_STL::vector<Rva005DCE08 *> m_items;	// +0x00
	unsigned int m_index;			// +0x0C
	int m_10;				// +0x10
	void *m_owner;				// +0x14
	Coord3D m_point;			// +0x18
	float m_angle;				// +0x24
	Rva005ADA40Owned *m_owned;		// +0x28
};

Rva005ADA40::Rva005ADA40(unsigned int index, void *owner)
{
	m_10 = 0;
	m_index = index;
	m_owner = owner;
	m_point.zero();
	m_owned = 0;
	m_angle = 0.0f;
}

Rva005ADA40::~Rva005ADA40()
{
	for (Rva005DCE08 **it = m_items.begin(); it != m_items.end(); ++it)
		delete *it;
	if (m_owned) {
		::delete m_owned;
		m_owned = 0;
	}
}

Rva005AD9C0Hit *Rva005ADA40::rva005AD9C0(void *arg)
{
	Rva005AD9C0Hit *hit = 0;
	for (Rva005DCE08 **it = m_items.begin(); it != m_items.end(); ++it) {
		hit = (*it)->rva005DCC86(arg);
		if (hit)
			break;
	}
	return hit;
}

void Rva005ADA40::rva005ADC63()
{
	Rva005ADA40Owned *owned = m_owned;
	if (owned) {
		if (((Rva004E9378 *)owned)->rva004E9378()) {
			((Rva00506FE9Hit *)owned)->rva0055ADBA(m_owner);
			::delete m_owned;
			m_owned = 0;
		}
	} else {
		rva005ADAB2();
	}
	for (Rva005DCE08 **it = m_items.begin(); it != m_items.end(); ++it)
		(*it)->rva005DCCFB();
}
