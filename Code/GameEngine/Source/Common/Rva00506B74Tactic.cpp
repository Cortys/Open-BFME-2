// cl: /O1 /MD /GX /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE /Ireference/shims/bfme2_ascii
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
#include "ascii_string.h"

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

class Rva00506FE9Hit;

class Rva005ADA40
{
public:
	~Rva005ADA40();
	void rva005AD99C(const AsciiString &name, _STL::vector<Rva00506FE9Hit *> *hits);
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

// 0x00506FE9's collaborators. Object and RebuildHoleBehaviorInterface stay
// opaque; the views below carry only what that body reads.
class Object;
class RebuildHoleBehaviorInterface;

class RebuildHoleBehavior
{
public:
	static RebuildHoleBehaviorInterface *getRebuildHoleBehaviorInterfaceFromObject(Object *obj);
};

struct Rva00506FE9Template
{
	char m_pad00[0x64];
	AsciiString m_name;		// +0x64
};

class Rva00506FE9RebuildView
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual const Rva00506FE9Template *getRebuildTemplate();	// slot 3
};

struct Rva00506FE9ObjectView
{
	void *m_vptr;
	const Rva00506FE9Template *m_template;	// +0x04
	char m_pad08[0x74 - 8];
	int m_id;				// +0x74
};

class Rva00506FE9Hit
{
public:
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(void *owner, int flag);	// +0x18
	void rva0055ADBA(void *owner);
	float m_04;
	char m_pad08[0x24 - 8];
	int m_24;
};

struct Rva002A8B59Data
{
	char m_pad00[0x88];
	float m_88;
};

class Rva002A8F24
{
public:
	Rva002A8B59Data *rva002A8B59(void *owner);
};

extern Rva002A8F24 *g_00DFEEF8;

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
	void rva00506FE9(Object *obj);
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

// 0x00506FE9: collect the owned elements' hits for the object's template name
// (its rebuild template when it is a rebuild hole), then rescale and re-run
// every hit that belongs to this object.
void Rva00506B74::rva00506FE9(Object *obj)
{
	_STL::vector<Rva00506FE9Hit *> hits;
	AsciiString name;
	RebuildHoleBehaviorInterface *rebuild = RebuildHoleBehavior::getRebuildHoleBehaviorInterfaceFromObject(obj);
	if (rebuild)
		name = ((Rva00506FE9RebuildView *)rebuild)->getRebuildTemplate()->m_name;
	else
		name = ((Rva00506FE9ObjectView *)obj)->m_template->m_name;
	Rva005ADA40 **end = m_0C.end();
	for (Rva005ADA40 **it = m_0C.begin(); it != end; ++it)
		(*it)->rva005AD99C(name, &hits);
	if (!hits.empty()) {
		Rva002A8B59Data *data = g_00DFEEF8->rva002A8B59(m_08);
		for (Rva00506FE9Hit **h = hits.begin(); h != hits.end(); ++h) {
			Rva00506FE9Hit *hit = *h;
			if (hit->m_24 == ((Rva00506FE9ObjectView *)obj)->m_id) {
				hit->rva0055ADBA(m_08);
				float v = hit->m_04;
				hit->m_04 = data->m_88 * v;
				hit->v6(m_08, 0);
			}
		}
	}
}

// 0x00506CC3: the waypoint with this name, walking TheTerrainLogic's list from
// its first-waypoint virtual (+0x84) along the +0x1C links and comparing the
// +0x08 name through AsciiString::compare (0x000069D6). Eight callers in the
// script-engine range (0x0023FDBD..) plus two in this cluster.
class Waypoint
{
public:
	const AsciiString &getName() const { return m_name; }
	Waypoint *getNext() const { return m_pNext; }
private:
	int m_00;
	int m_04;
	AsciiString m_name;		// +0x08
	Coord3DBase m_location;	// +0x0C
	int m_18;
	Waypoint *m_pNext;		// +0x1C
};

class TerrainLogic
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32();
	virtual Waypoint *getFirstWaypoint();	// +0x84
};

extern TerrainLogic *TheTerrainLogic;

Waypoint *Rva00506CC3FindWaypoint(const AsciiString &name)
{
	for (Waypoint *way = TheTerrainLogic->getFirstWaypoint(); way; way = way->getNext()) {
		if (way->getName() == name)
			return way;
	}
	return 0;
}
