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
struct Rva00506909Request;

struct Rva00506909Item
{
	virtual ~Rva00506909Item();
	void rva004EDF03();
	void rva004ECE1C();
	void rva004ED81D(Rva00506909Request *request, void *arg);
	void rva004ED955(void *owner);
	void rva004ED6D2(struct Rva005059A1Unit *unit);
	void rva004EDD4D(struct Rva005059A1Unit *unit);
	char m_pad04[0x30 - 4];
	int m_id;	// +0x30
};

// The five objects 0x00505E5D seeds +0x04 with when empty, in order; the
// vector holds them through one base pointer.
// Generators: slot 1 asks whether one applies to a request (with the
// request's argument parked at +0x24 for the call) and slot 9 builds the
// item it stands for.
struct Rva00506909Gen
{
	virtual ~Rva00506909Gen();
	virtual bool appliesTo(Rva00506909Request *request);
	virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual Rva00506909Item *create();
	virtual bool isRequired();	// slot 10
	unsigned char m_pad04[0x24 - 4];
	void *m_arg;	// +0x24
};

#define RVA00506909_GEN(name, size) \
	class name : public Rva00506909Gen \
	{ \
	public: \
		name(); \
	private: \
		unsigned char m_data[size - sizeof(Rva00506909Gen)]; \
	};

RVA00506909_GEN(Rva005AA6B4, 0x58)
RVA00506909_GEN(Rva005AA23E, 0x5C)
RVA00506909_GEN(Rva005A9D33, 0x60)
RVA00506909_GEN(Rva005A9C1E, 0x60)
RVA00506909_GEN(Rva005A9988, 0x58)

// ... and the six 0x00506020 seeds +0x4C with.
RVA00506909_GEN(Rva005ACF38, 0x64)
RVA00506909_GEN(Rva005AC7EC, 0x68)
RVA00506909_GEN(Rva005AB91D, 0x80)
RVA00506909_GEN(Rva005AB3BE, 0x68)
RVA00506909_GEN(Rva005AB1B4, 0x58)
RVA00506909_GEN(Rva005AABC6, 0x5C)

// What 0x00505F80 and 0x00505FD0 seed +0x1C and +0x34 with when empty.
RVA00506909_GEN(Rva005AA7DF, 0x58)
RVA00506909_GEN(Rva005AA9DB, 0x60)

struct Rva00506909Request
{
	void *m_00;
	int m_kind;		// +0x04
};

struct Rva005059A1Team
{
	char m_pad00[0x2D8];
	int m_id;	// +0x2D8
};

struct Rva005059A1Owner
{
	char m_pad00[0x2EC];
	struct Rva005059A1Unit *m_unit;	// +0x2EC
};

struct Rva005059A1Unit
{
	Rva005059A1Owner *rva0039D7CF();
	void rva0039E9E0();
	char m_pad00[0x30];
	Rva005059A1Team *m_team;	// +0x30
};

class Rva00506909
{
public:
	void rva005059A1(Rva005059A1Unit *unit);
	void rva00505A56(Rva005059A1Unit *unit);
	Rva00506909(void *owner);
	~Rva00506909();
	void rva005069B4();
	bool rva005069CE(Rva00506909Request *request, void *arg);
private:
	void rva00505E5D();
	void rva00505F80();
	void rva00505FD0();
	void rva00505924();
	void rva00506020();
	void rva00505AF1();
	bool rva00506411(void *owner);
	bool rva00506178(Rva00506909Request *request, void *arg);
	bool rva00506265(Rva00506909Request *request, void *arg);
	bool rva0050633B(Rva00506909Request *request, void *arg);

	void *m_owner;					// +0x00
	_STL::vector<Rva00506909Gen *> m_04;
	_STL::vector<Rva00506909Item *> m_10;
	_STL::vector<Rva00506909Gen *> m_1C;
	_STL::vector<Rva00506909Item *> m_28;
	_STL::vector<Rva00506909Gen *> m_34;
	_STL::vector<Rva00506909Item *> m_40;
	_STL::vector<Rva00506909Gen *> m_4C;
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

void Rva00506909::rva00506020()
{
	if (m_4C.empty()) {
		m_4C.push_back(new Rva005ACF38);
		m_4C.push_back(new Rva005AC7EC);
		m_4C.push_back(new Rva005AB91D);
		m_4C.push_back(new Rva005AB3BE);
		m_4C.push_back(new Rva005AB1B4);
		m_4C.push_back(new Rva005AABC6);
	}
}

// 0x00506178 / 0x00506265 / 0x0050633B: let one applicable generator of the
// pool at +0x04 / +0x1C / +0x34, chosen at random, add its item to
// +0x10 / +0x28 / +0x40. The first also needs the 0x0058AEB6 object to
// accept the argument.
int Rva0058AEB6Get();
int GetGameLogicRandomValue(int lo, int hi, char *file, int line);

class Rva0058AFB3
{
public:
	bool rva0058AFB3(void *arg);
};

bool Rva00506909::rva00506178(Rva00506909Request *request, void *arg)
{
	if (((Rva0058AFB3 *)Rva0058AEB6Get())->rva0058AFB3(arg)) {
		_STL::vector<Rva00506909Gen *> candidates;
		for (Rva00506909Gen **it = m_04.begin(); it != m_04.end(); ++it) {
			Rva00506909Gen *gen = *it;
			gen->m_arg = arg;
			if (gen->appliesTo(request))
				candidates.push_back(gen);
			gen->m_arg = 0;
		}
		if (!candidates.empty()) {
			int pick = GetGameLogicRandomValue(0, candidates.size() - 1, "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AITacticalAI\\AITacticsGenerator\\AITacticsGenerator.cpp", 326);
			Rva00506909Item *item = candidates[pick]->create();
			item->rva004ED81D(request, arg);
			m_10.push_back(item);
			return true;
		}
	}
	return false;
}

bool Rva00506909::rva00506265(Rva00506909Request *request, void *arg)
{
	_STL::vector<Rva00506909Gen *> candidates;
	for (Rva00506909Gen **it = m_1C.begin(); it != m_1C.end(); ++it) {
		Rva00506909Gen *gen = *it;
		gen->m_arg = arg;
		if (gen->appliesTo(request))
			candidates.push_back(gen);
		gen->m_arg = 0;
	}
	if (!candidates.empty()) {
		int pick = GetGameLogicRandomValue(0, candidates.size() - 1, "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AITacticalAI\\AITacticsGenerator\\AITacticsGenerator.cpp", 357);
		Rva00506909Item *item = candidates[pick]->create();
		item->rva004ED81D(request, arg);
		m_28.push_back(item);
		return true;
	}
	return false;
}

bool Rva00506909::rva0050633B(Rva00506909Request *request, void *arg)
{
	_STL::vector<Rva00506909Gen *> candidates;
	for (Rva00506909Gen **it = m_34.begin(); it != m_34.end(); ++it) {
		Rva00506909Gen *gen = *it;
		gen->m_arg = arg;
		if (gen->appliesTo(request))
			candidates.push_back(gen);
		gen->m_arg = 0;
	}
	if (!candidates.empty()) {
		int pick = GetGameLogicRandomValue(0, candidates.size() - 1, "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AITacticalAI\\AITacticsGenerator\\AITacticsGenerator.cpp", 388);
		Rva00506909Item *item = candidates[pick]->create();
		item->rva004ED81D(request, arg);
		m_40.push_back(item);
		return true;
	}
	return false;
}

// 0x00506411: every +0x4C generator that applies to the owner either must run
// (slot 10) or joins the optional pool, one of which is drawn at random
// (line 426); each chosen generator's new item is set up for the owner and
// pushed to +0x58. True when anything was chosen.
bool Rva00506909::rva00506411(void *owner)
{
	_STL::vector<Rva00506909Gen *> optional;
	_STL::vector<Rva00506909Gen *> chosen;
	for (Rva00506909Gen **it = m_4C.begin(); it != m_4C.end(); ++it) {
		Rva00506909Gen *gen = *it;
		gen->m_arg = owner;
		if (gen->appliesTo(0)) {
			if (gen->isRequired())
				chosen.push_back(gen);
			else
				optional.push_back(gen);
		}
		gen->m_arg = 0;
	}
	if (!optional.empty())
		chosen.push_back(optional[GetGameLogicRandomValue(0, optional.size() - 1, "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AITacticalAI\\AITacticsGenerator\\AITacticsGenerator.cpp", 426)]);
	for (Rva00506909Gen **c = chosen.begin(); c != chosen.end(); ++c) {
		Rva00506909Item *item = (*c)->create();
		item->rva004ED955(owner);
		m_58.push_back(item);
	}
	return !chosen.empty();
}

// 0x005059A1 / 0x00505A56: hand the unit to the item, in any of the four
// item lists, that belongs to its team.
void Rva00506909::rva005059A1(Rva005059A1Unit *unit)
{
	if (unit == unit->rva0039D7CF()->m_unit)
		return;
	Rva00506909Item **it;
	for (it = m_10.begin(); it != m_10.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004ED6D2(unit);
			return;
		}
	}
	for (it = m_28.begin(); it != m_28.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004ED6D2(unit);
			return;
		}
	}
	for (it = m_40.begin(); it != m_40.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004ED6D2(unit);
			return;
		}
	}
	for (it = m_58.begin(); it != m_58.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004ED6D2(unit);
			return;
		}
	}
	unit->rva0039E9E0();
}

void Rva00506909::rva00505A56(Rva005059A1Unit *unit)
{
	Rva00506909Item **it;
	for (it = m_10.begin(); it != m_10.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004EDD4D(unit);
			return;
		}
	}
	for (it = m_28.begin(); it != m_28.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004EDD4D(unit);
			return;
		}
	}
	for (it = m_40.begin(); it != m_40.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004EDD4D(unit);
			return;
		}
	}
	for (it = m_58.begin(); it != m_58.end(); ++it) {
		Rva00506909Item *item = *it;
		if (item->m_id == unit->m_team->m_id) {
			item->rva004EDD4D(unit);
			return;
		}
	}
}

// 0x00505BBA: delete every generator, then every item, then the lists.
Rva00506909::~Rva00506909()
{
	Rva00506909Gen **gen;
	for (gen = m_04.begin(); gen != m_04.end(); ++gen)
		::delete *gen;
	for (gen = m_1C.begin(); gen != m_1C.end(); ++gen)
		::delete *gen;
	for (gen = m_34.begin(); gen != m_34.end(); ++gen)
		::delete *gen;
	for (gen = m_4C.begin(); gen != m_4C.end(); ++gen)
		::delete *gen;
	Rva00506909Item **item;
	for (item = m_10.begin(); item != m_10.end(); ++item)
		::delete *item;
	for (item = m_28.begin(); item != m_28.end(); ++item)
		::delete *item;
	for (item = m_40.begin(); item != m_40.end(); ++item)
		::delete *item;
	for (item = m_58.begin(); item != m_58.end(); ++item)
		::delete *item;
}
