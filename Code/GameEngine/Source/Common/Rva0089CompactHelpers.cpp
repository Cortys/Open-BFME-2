// cl: /DNDEBUG /MD /O2
//
// Ported from Open-BFME-1's game/GameEngine/Source/Common/Rva0089CompactHelpers.cpp
// (donor revision: reference/open-bfme-1 @ a38d345e) by tools/bfme1_sweep.py:
// 8 bodies byte-identical between lotrbfme.exe and game.dat once relocation
// slots are set aside, tier T1 "clean transfer", cl: /DNDEBUG /MD /O2.
//
// The donor was held at copy-tier S -- it defines 21 functions and the sweep
// placed only 8, so find_declared_unmatched refused the whole file. This TU
// carries the 7 that are both placed and cleanly named:
//
//   0x006D1420  36B  Rva00896360Handle::Rva00896360Handle(const&, int)
//   0x006CFEB0  20B  Rva00894F00Pair::Rva00894F00Pair(const int*, int)
//   0x006CFE80  19B  Rva00894E80Ref::Rva00894E80Ref(const&)
//   0x006CD560  18B  Rva00892620NotEqual(const int*, int)
//   0x006CFED0  18B  Rva00894F60Equal(const int*, int)
//   0x006CFE60  17B  Rva00894E60Ref::Rva00894E60Ref(int*)
//   0x0003CD10  17B  Rva0088D990Owner::set(Rva0088D990Inner*)
//
// The eighth placement (0x0003CCE0, `Rva0088D960Owner::set`) is deliberately
// NOT carried: it is tier T3 because lotrbfme.exe folded it, so the name is a
// guess, and AGENTS.md forbids spending a guessed name on a folded address.
//
// No reverse/symbols.csv pin is needed -- every one of these bodies is
// self-contained and reaches no global and no callee.

bool Rva00892620NotEqual(const int *value, int other)
{
	return *value != other;
}

bool Rva00894F60Equal(const int *value, int other)
{
	return *value == other;
}

struct Rva00894E60Ref
{
	int *m_pointer;
	Rva00894E60Ref(int *pointer);
};
Rva00894E60Ref::Rva00894E60Ref(int *pointer) : m_pointer(pointer)
{
	if (pointer) ++*pointer;
}

struct Rva00894E80Ref
{
	int *m_pointer;
	Rva00894E80Ref(const Rva00894E80Ref &other);
};
Rva00894E80Ref::Rva00894E80Ref(const Rva00894E80Ref &other) : m_pointer(other.m_pointer)
{
	if (m_pointer) ++*m_pointer;
}

struct Rva00894F00Pair
{
	int m_pointer;
	int m_extra;
	Rva00894F00Pair(const int *pointer, int extra);
};
Rva00894F00Pair::Rva00894F00Pair(const int *pointer, int extra) : m_pointer(*pointer), m_extra(extra) {}

struct Rva00896360Handle
{
	int *m_pointer;
	int m_extra;
	Rva00896360Handle(const Rva00896360Handle &other, int extra);
};
Rva00896360Handle::Rva00896360Handle(const Rva00896360Handle &other, int extra)
{
	m_pointer = other.m_pointer;
	if (m_pointer) {
		++*m_pointer;
		m_extra = extra;
		return;
	}
	m_extra = extra;
}

struct Rva0088D990Inner
{
	unsigned char m_value;
};
class Rva0088D990Owner
{
public:
	Rva0088D990Owner *set( Rva0088D990Inner *src );

private:
	char m_pad[0x9F54];
	unsigned char m_copy;
};
Rva0088D990Owner *Rva0088D990Owner::set( Rva0088D990Inner *src )
{
	m_copy = src->m_value;
	return this;
}
