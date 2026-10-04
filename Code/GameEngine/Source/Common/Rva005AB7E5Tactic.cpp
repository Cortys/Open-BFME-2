// cl: /O1 /MD /GX /DNDEBUG /Ireference/shims/bfme2_ascii
//
// The "StructureCreep" skirmish-AI tactic (vtable 0x008722EC; ctor 0x005AB91D
// in Rva004ECECDTacticCtors.cpp, slot 9 0x005AB9AF in
// Rva004ECECDTacticCreate.cpp). Base chain, all address-derived: Rva005DCC24
// (ctor 0x005DCC0A, dtor 0x005DCC24) over Rva005DC73C over the AITactic.cpp
// object Rva004ECECD. Layout: +0x58 an ObjectID, +0x5C, +0x64, +0x68
// counters, +0x60 the owned build order (Rva00573B23, 0x40 bytes), +0x6C the
// index of the structure name last picked from the owner's list.
//
//   0x005AB7E5  dtor: abandon (0x0055ADBA) and ::delete the build order
//   0x005AB993  scalar deleting dtor (slot 0)
//   0x005AB843  slot 5: xfer: the AITactic's, the id, the counters, whether
//               there is an order and the order itself (restarted on load
//               when it had not begun)
//   0x005AB9EE  (not here yet) whether the object's template name is one of the owner's
//               creep structure names (record +0x160, +0x98 vector)
//   0x005ABA59  the next creep structure name: a random one first, then
//               round-robin
#include "ascii_string.h"

// BFME2's Xfer: operator== overloads, grouped by cl at the first overload
// slot in reverse declaration order (Rva004E0513Xfer.cpp has the same view).
class UnicodeString;
class PooledString;
struct XferUnknown11;
class ICoord3D;
class Region3D;
class IRegion3D;
class Coord2D;
class ICoord2D;
class Region2D;
class IRegion2D;
class RealRange;
class RGBColor;
class RGBAColorReal;
class RGBAColorInt;
class Snapshot;
struct Coord3DBase;

class Xfer
{
public:
	class Version;

	Xfer();
	virtual ~Xfer();

	virtual bool IsLoading() const;
	virtual bool IsStoring() const;
	virtual bool IsCRC() const;
	virtual bool IsLightCRC() const;

	virtual void v5() = 0;
	virtual void v6() = 0;
	virtual void v7() = 0;

	virtual void SkipBadBlock(Snapshot &snapshot, unsigned int size);
	virtual Xfer &XferRawBytes(void *data, unsigned int size);
	virtual Xfer &operator==(bool &value);
	virtual Xfer &operator==(char &value);
	virtual Xfer &operator==(unsigned char &value);
	virtual Xfer &operator==(short &value);
	virtual Xfer &operator==(unsigned short &value);
	virtual Xfer &operator==(int &value);
	virtual Xfer &operator==(unsigned int &value);
	virtual Xfer &operator==(__int64 &value);
	virtual Xfer &operator==(float &value);
	virtual Xfer &operator==(AsciiString &value);
	virtual Xfer &operator==(UnicodeString &value);
	virtual Xfer &operator==(PooledString &value);
	virtual Xfer &operator==(Coord3DBase &value);
	virtual Xfer &operator==(ICoord3D &value);
	virtual Xfer &operator==(Region3D &value);
	virtual Xfer &operator==(IRegion3D &value);
	virtual Xfer &operator==(Coord2D &value);
	virtual Xfer &operator==(ICoord2D &value);
	virtual Xfer &operator==(Region2D &value);
	virtual Xfer &operator==(IRegion2D &value);
	virtual Xfer &operator==(RealRange &value);
	virtual Xfer &operator==(RGBColor &value);
	virtual Xfer &operator==(RGBAColorReal &value);
	virtual Xfer &operator==(RGBAColorInt &value);
	virtual Xfer &operator==(Snapshot &value);
	virtual Xfer &operator==(XferUnknown11 &value) = 0;
	virtual Xfer &operator==(Version &value);

	virtual Xfer &XferEnum(const char *name, void *data, unsigned int size);

protected:
	virtual void XferData(unsigned int type, void *data, unsigned int size) = 0;
};

class Xfer::Version
{
public:
	Version(unsigned char current, unsigned char minimum)
		: m_current(current), m_minimum(minimum) {}

	unsigned char m_current;
	unsigned char m_minimum;
};

enum ObjectID
{
	INVALID_ID = 0
};
void XferObjectID(Xfer *xfer, ObjectID *id);

struct Rva005AB7E5Template
{
	char m_pad00[0x64];
	AsciiString m_name;	// +0x64
};

class Object
{
public:
	char m_pad00[4];
	Rva005AB7E5Template *m_04;	// +0x04
};

struct Rva005AB7E5NameList
{
	unsigned int size() const { return m_end - m_begin; }
	AsciiString &operator[](unsigned int i) { return m_begin[i]; }
	AsciiString *m_begin;
	AsciiString *m_end;
	AsciiString *m_capacity;
};

struct Rva005AB7E5Names
{
	char m_pad00[0x98];
	Rva005AB7E5NameList m_names;	// +0x98
};

struct Rva002A8AB1Record
{
	char m_pad000[0x160];
	Rva005AB7E5Names *m_160;	// +0x160
};

class Rva002A8F24
{
public:
	Rva002A8AB1Record *rva002A8AB1(void *owner);
};
extern Rva002A8F24 *g_00DFEEF8;

int GetGameLogicRandomValue(int lo, int hi, char *file, int line);

class Rva00506FE9Hit
{
public:
	void rva0055ADBA(void *owner);
};

class Rva00573B23
{
public:
	Rva00573B23();
	virtual ~Rva00573B23();
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5();
	virtual void start(void *owner, int a);
	virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual void v11();
	virtual void xfer(Xfer *xfer, void *owner);
	char m_pad04[0x10 - 4];
	int m_status;		// +0x10
	char m_pad14[0x40 - 0x14];
};

class Rva004ECECD
{
public:
	virtual ~Rva004ECECD();
	virtual bool appliesTo(void *request);
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void xfer(Xfer *xfer);
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual Rva004ECECD *create();
};

class Rva005DC73C : public Rva004ECECD
{
public:
	virtual ~Rva005DC73C();
	char m_pad04[0x24 - 4];
	void *m_owner;			// +0x24
	char m_pad28[0x58 - 0x28];
};

class Rva005DCC24 : public Rva005DC73C
{
public:
	virtual ~Rva005DCC24();
};

class Rva005AB7E5 : public Rva005DCC24
{
public:
	virtual ~Rva005AB7E5();
	virtual void xfer(Xfer *xfer);
	AsciiString rva005ABA59();
private:
	ObjectID m_58;		// +0x58
	unsigned int m_5C;	// +0x5C
	Rva00573B23 *m_order;	// +0x60
	unsigned int m_64;	// +0x64
	unsigned int m_68;	// +0x68
	int m_next;		// +0x6C
	int m_70;
	int m_74;
	bool m_78;
	bool m_79;
	int m_7C;
};

Rva005AB7E5::~Rva005AB7E5()
{
	if (m_order) {
		((Rva00506FE9Hit *)m_order)->rva0055ADBA(m_owner);
		::delete m_order;
		m_order = 0;
	}
}

void Rva005AB7E5::xfer(Xfer *xfer)
{
	Rva004ECECD::xfer(xfer);
	XferObjectID(xfer, &m_58);
	*xfer == m_5C;
	*xfer == m_64;
	*xfer == m_68;
	bool hasOrder = m_order != 0;
	*xfer == hasOrder;
	if (hasOrder) {
		if (xfer->IsStoring()) {
			m_order->xfer(xfer, m_owner);
		} else if (xfer->IsLoading()) {
			m_order = new Rva00573B23;
			m_order->xfer(xfer, m_owner);
			if (m_order->m_status == 0)
				m_order->start(m_owner, 1);
		}
	}
}

AsciiString Rva005AB7E5::rva005ABA59()
{
	Rva002A8AB1Record *record = g_00DFEEF8->rva002A8AB1(m_owner);
	if (m_next == -1) {
		m_next = GetGameLogicRandomValue(0, record->m_160->m_names.size() - 1,
			"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AITacticalAI\\AITacticsGenerator\\TargetlessTactics\\AIStructureCreepTactic.cpp",
			368);
	} else if ((unsigned int)++m_next >= record->m_160->m_names.size()) {
		m_next = 0;
	}
	return record->m_160->m_names[m_next];
}
