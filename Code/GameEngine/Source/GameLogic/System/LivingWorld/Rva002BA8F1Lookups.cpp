// Retail RVA 0x002B6AEC (96 bytes) and 0x002E18C3 (65 bytes), Ghidra boundaries.
// Both are direct callees of the AddPlayer candidate at RVA 0x002BA8F1.
// The former searches vector +8C for an entry string at +20 and optionally
// writes its index. The latter searches vector +C for an entry string at +0.
// String identity/ABI is supported by their calls to the byte-verified
// StringBase<char>::compare at RVA 0x000069D6 (existing AsciiString alias).
// The collections' original class/element identities remain unproven.
// Declaration views match Rva002BA8F1AddPlayer.cpp; definitions stay separate
// to preserve the retail translation-unit call boundary.
// TU-local layout views; unnamed fields and address-qualified types are intentional.
// The bytecode proves offsets/operations, not original EA type names or full layouts.
// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc
// stlport
#include <vector>
class AsciiString { public: int compare(const AsciiString &) const; private: void *data; };
struct Rva002BA8F1Input {
    char at00[8]; AsciiString at08, at0C, at10;
    int at14, at18; char at1C[8]; bool at24;
};
class Rva002E18C3Lookup {
public: AsciiString *find(const AsciiString &);
private: char at00[0xc]; _STL::vector<AsciiString *> entries;
};
extern Rva002E18C3Lookup *Va00DFF0B0Lookup, *Va00E03140Lookup;
struct Rva002000D7Config { char at00[0x34]; int at34; };
class Rva002000D7Store { public: Rva002000D7Config *get(int); };
extern Rva002000D7Store *Va00DFE0ECStore;
struct Va00DFE78CState { char at00[0x114]; int at114; };
extern Va00DFE78CState *Va00DFE78CStatePointer;
struct Rva002BA8F1Slot { char at00[0x4c]; int at4C; };
struct Rva002BA8F1Listener { char opaque[4]; };
class Rva005A0B4CList { public: void append(Rva002BA8F1Listener *); char opaque[12]; };
class Rva002E2903Player {
public:
    Rva002E2903Player(Rva002BA8F1Input *, void *);
    void setAt1C4(int);
    void setColor(int);
    void state0(); void state1(); void state2();
    void attach(void *);
    void initialize();
    char at00[4]; Rva005A0B4CList listeners; char at10[4]; int at14;
    char at18[8]; AsciiString name; char remaining[0x3c8-0x24];
};
typedef _STL::vector<Rva002E2903Player *> Rva002BA8F1PlayerList;
struct Rva002BA8F1Primary { char opaque[0x18]; };
class Rva002BA8F1Logic : public Rva002BA8F1Primary, public Rva002BA8F1Listener {
public:
    Rva002E2903Player *find(const AsciiString &, unsigned int *);
    Rva002E2903Player *find(int, unsigned int *);
    void setLocal(Rva002E2903Player *);
    void addPlayer(Rva002BA8F1Input *, bool, int, Rva002BA8F1Slot *);
    char gap[0x8c-0x1c]; Rva002BA8F1PlayerList players;
};

Rva002E2903Player *Rva002BA8F1Logic::find(const AsciiString &name, unsigned int *index)
{
    for (unsigned int i = 0; i < players.size(); ++i) {
        if (players[i]->name.compare(name) == 0) {
            if (index) *index = i;
            return players[i];
        }
    }
    return 0;
}

AsciiString *Rva002E18C3Lookup::find(const AsciiString &name)
{
    for (unsigned int i = 0; i < entries.size(); ++i) {
        if (entries[i]->compare(name) == 0) return entries[i];
    }
    return 0;
}

// ?find@Rva002BA8F1Logic@@QAEPAVRva002E2903Player@@HPAI@Z @0x002B51F8 94B.
// Id lookup over the same +0x8C player vector as the string find above.
// Compares entry +0x14 against the id with -1 early-out and optional index out.
// Callers use the 0x00DFEF10 singleton and unblock 67 functions.
Rva002E2903Player *Rva002BA8F1Logic::find(int id, unsigned int *index)
{
    if (id == -1)
        return 0;
    for (unsigned int i = 0; i < players.size(); ++i) {
        if (players[i]->at14 == id) {
            if (index)
                *index = i;
            return players[i];
        }
    }
    return 0;
}
