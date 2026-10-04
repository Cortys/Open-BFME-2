// ?rva00709C10@Rva00709C10Owner@@QAEXHPAVRva8D0D80ValueOwner@@@Z
// partial score=0.88 date=2026-10-04
// cl: /O2 /MD
// Rva00709C10Handler.cpp
//
// 0x00709C10 (129 bytes). SEH-framed Apt handler: scope table 0x00BAA8D8, the
// same handler shape the rowed apt workers carry. It is a virtual entry of the
// Rva00709B80 vtable 0x008EE968 (a derived variant of the 0x008EE8C8 table this
// seat's other body is also a member of), so the receiver is that owner class,
// and the `ret 8` shows it reads one stack dword argument.
//
// Reads a name out of the owner's table at +0x30 indexed by that argument,
// builds an EAStringC from the resulting C string, and hands the pair to the
// global result table's add, destroying the temporary on the way out.
//
// Evidence, per call:
//   0x006FBED0  lazy publish of the global result table at 0x00E1835C: an
//               AptValueGCAllocator block from the 0x00E176F4 pool
//               (?allocBlock@Rva006D2A60@@QAEPAXH@Z, 0x006D29E0) that assigns
//               itself to that global. Guarded by `if (!g_table)`, which is why
//               the read at 0x00709C53 comes back off the global rather than
//               off `this`.
//   0x006D4C80  ??0EAStringC@@QAE@PBD@Z, the rowed C-string ctor.
//   0x0070B410  ?add@Rva8D0D80Table@@QAEXPAVRva8D0D80String@@PAVRva8D0D80Value@@@Z,
//               pinned in reverse/symbols.csv; entered with `this` at global +8,
//               which is what the `add ecx, 8` at 0x00709C5E spells.
//   0x006D3010  ??1EAStringC@@QAE@XZ, the rowed scalar destructor for the temp.
//
// The +8 table entry is the one Rva8D0D80ResultAdd.cpp proves for this same
// callee (Rva8D0D80Table at +8 of the result block); only the entry offset is
// used here, not the member names.

class Rva8D0D80String;
class Rva8D0D80Value;

// The EAStringC rowed API this body drives. Only the C-string ctor and the
// destructor are called from here; IsEmpty and the hash refresh belong to
// 0x0070B410's own body. The leading dword is the data pointer IsEmpty reads at
// 0x006D2F30, and this body hands that same dword to `add` as its value
// argument rather than passing the string object twice.
class EAStringC
{
public:
	EAStringC(const char *s);
	~EAStringC();

private:
	char *m_data;
};

// ?add@Rva8D0D80Table@@QAEXPAVRva8D0D80String@@PAVRva8D0D80Value@@@Z at
// 0x0070B410, pinned in reverse/symbols.csv. The name argument is the EAStringC
// temp's address; the value argument is the temp's leading data dword.
class Rva8D0D80Table
{
public:
	void add(Rva8D0D80String *name, Rva8D0D80Value *value);
};

// The pool-allocated global result-table block: Rva8D0D80Result (an eight-byte
// refcounted value) with Rva8D0D80Table at +8, per Rva8D0D80ResultAdd.cpp. The
// body only reads the table through +8 and only `add` through it.
class Rva8D0D80ResultTableBlock
{
public:
	char m_pad08[8];
	Rva8D0D80Table m_table;
};

// Global published by 0x006FBED0, and the pool its blocks come from.
extern Rva8D0D80ResultTableBlock *g_rva00E1835C;

// The lazy publisher 0x006FBED0 (150 bytes, scope table 0x00BAA23E): allocates
// the block above through ?allocBlock@Rva006D2A60@@QAEPAXH@Z at 0x006D29E0 and
// stores it into the global. Only the call is used here; its own body is not
// rowed, so the declaration stands in for the address.
void rva006FBED0Ctor();

// The second stack dword is read only as the `add` value argument, so it is a
// pointer the caller supplies rather than another index; retail never touches it
// before the call, and that is what the unused declaration records.
class Rva8D0D80ValueOwner;

// The owner's own name table at +0x30, holding C strings indexed by the
// handler's argument.
class Rva00709C10Owner
{
public:
	void rva00709C10(int index, Rva8D0D80ValueOwner *value);

private:
	char m_pad[0x30];
	char *m_names;	// +0x30
};

// The block the owner's +0x30 member points at. Only its +8 dword is read here,
// and it must be read as a full pointer: spelling the member as char** would make
// the load a sign-extended byte rather than the dword retail emits.
struct Rva00709C10NameBlock
{
	char m_pad[8];
	char **m_rows;
};

// Rva00709C10Owner::rva00709C10 @0x00709C10 (129 bytes). Publish the global
// result table if it is not live yet, copy the argument-indexed name out of
// the owner's +0x30 table into an EAStringC, and add that name and its data to
// the global table.
// Evidence: vtable 0x008EE968 slot 0x0097C10; own immediates; callees listed in
// the file header.
// NOT BYTE-EXACT: compiles to the same 129 bytes with every call, immediate and
// branch displacement in place, but retail keeps the row array in ecx and the
// index in edx while this emits them folded as `mov eax,[eax+8]` / `mov
// ecx,[esp+0x18]` / `mov eax,[eax+ecx*4]`. See the banked attempt for what was
// tried; the delta is register allocation only, not shape.
void Rva00709C10Owner::rva00709C10(int index, Rva8D0D80ValueOwner *value)
{
	if (g_rva00E1835C == 0)
		rva006FBED0Ctor();

	char **const rows = reinterpret_cast<const Rva00709C10NameBlock *>(m_names)->m_rows;
	char *const name_text = rows[index];

	EAStringC name(name_text);

	g_rva00E1835C->m_table.add((Rva8D0D80String *)&name, (Rva8D0D80Value *)value);
}
