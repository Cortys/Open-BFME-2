// cl: /O1 /MD /GX /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// The skirmish-AI object built at 0x00506909 (caller 0x002C616A), in the
// range whose asserts name AITacticsGenerator.cpp (0x005061FD..). No RTTI or
// donor, so it keeps an address-derived name.
//
// Target evidence:
//   0x00506909  ctor: owner at +0x00, eight empty vectors at +0x04..+0x58
//               (folded _Vector_base ctor 0x00211E58, EH states 0..7), then
//               four setup members 0x00505E5D, 0x00505F80, 0x00505FD0,
//               0x00506020.
//   0x005069B4  per-update pass: 0x00505AF1, 0x00505924, then 0x00506411 with
//               the owner (caller 0x002C6790).
//   0x005069CE  dispatch on the request's +0x04 kind: 0 and 2 -> 0x00506178,
//               1 -> 0x00506265, 3 -> 0x0050633B, else false (caller
//               0x002C67B4).
#include <vector>

// Elements of the four vectors at +0x10/+0x28/+0x40/+0x58: each gets
// 0x004EDF03 then 0x004ECE1C from the 0x00505924 pass (both in the
// AITactic.cpp range).
struct Rva00506909Item
{
	void rva004EDF03();
	void rva004ECE1C();
};

// The five objects 0x00505E5D seeds +0x04 with when empty, in order; the
// vector holds them through one base pointer.
struct Rva00506909Gen
{
};

#define RVA00506909_GEN(name, size) \
	class name : public Rva00506909Gen \
	{ \
	public: \
		name(); \
	private: \
		unsigned char m_data[size]; \
	};

RVA00506909_GEN(Rva005AA6B4, 0x58)
RVA00506909_GEN(Rva005AA23E, 0x5C)
RVA00506909_GEN(Rva005A9D33, 0x60)
RVA00506909_GEN(Rva005A9C1E, 0x60)
RVA00506909_GEN(Rva005A9988, 0x58)

// What 0x00505F80 and 0x00505FD0 seed +0x1C and +0x34 with when empty.
class Rva005AA7DF
{
public:
	Rva005AA7DF();
private:
	unsigned char m_data[0x58];
};

class Rva005AA9DB
{
public:
	Rva005AA9DB();
private:
	unsigned char m_data[0x60];
};

struct Rva00506909Request
{
	void *m_00;
	int m_kind;		// +0x04
};

class Rva00506909
{
public:
	Rva00506909(void *owner);
	void rva005069B4();
	bool rva005069CE(Rva00506909Request *request, void *arg);
private:
	void rva00505E5D();
	void rva00505F80();
	void rva00505FD0();
	void rva00505924();
	void rva00506020();
	void rva00505AF1();
	void rva00506411(void *owner);
	bool rva00506178(Rva00506909Request *request, void *arg);
	bool rva00506265(Rva00506909Request *request, void *arg);
	bool rva0050633B(Rva00506909Request *request, void *arg);

	void *m_owner;					// +0x00
	_STL::vector<Rva00506909Gen *> m_04;
	_STL::vector<Rva00506909Item *> m_10;
	_STL::vector<Rva005AA7DF *> m_1C;
	_STL::vector<Rva00506909Item *> m_28;
	_STL::vector<Rva005AA9DB *> m_34;
	_STL::vector<Rva00506909Item *> m_40;
	_STL::vector<Rva00506909Item *> m_4C;
	_STL::vector<Rva00506909Item *> m_58;
};

Rva00506909::Rva00506909(void *owner)
	: m_owner(owner)
{
	rva00505E5D();
	rva00505F80();
	rva00505FD0();
	rva00506020();
}

void Rva00506909::rva005069B4()
{
	rva00505AF1();
	rva00505924();
	rva00506411(m_owner);
}

bool Rva00506909::rva005069CE(Rva00506909Request *request, void *arg)
{
	switch (request->m_kind) {
	case 0:
	case 2:
		return rva00506178(request, arg);
	case 1:
		return rva00506265(request, arg);
	case 3:
		return rva0050633B(request, arg);
	}
	return false;
}

void Rva00506909::rva00505924()
{
	Rva00506909Item **it;
	for (it = m_10.begin(); it != m_10.end(); ++it) {
		Rva00506909Item *item = *it;
		item->rva004EDF03();
		item->rva004ECE1C();
	}
	for (it = m_28.begin(); it != m_28.end(); ++it) {
		Rva00506909Item *item = *it;
		item->rva004EDF03();
		item->rva004ECE1C();
	}
	for (it = m_40.begin(); it != m_40.end(); ++it) {
		Rva00506909Item *item = *it;
		item->rva004EDF03();
		item->rva004ECE1C();
	}
	for (it = m_58.begin(); it != m_58.end(); ++it) {
		Rva00506909Item *item = *it;
		item->rva004EDF03();
		item->rva004ECE1C();
	}
}

void Rva00506909::rva00505F80()
{
	if (m_1C.empty())
		m_1C.push_back(new Rva005AA7DF);
}

void Rva00506909::rva00505FD0()
{
	if (m_34.empty())
		m_34.push_back(new Rva005AA9DB);
}

void Rva00506909::rva00505E5D()
{
	if (m_04.empty()) {
		m_04.push_back(new Rva005AA6B4);
		m_04.push_back(new Rva005AA23E);
		m_04.push_back(new Rva005A9D33);
		m_04.push_back(new Rva005A9C1E);
		m_04.push_back(new Rva005A9988);
	}
}
