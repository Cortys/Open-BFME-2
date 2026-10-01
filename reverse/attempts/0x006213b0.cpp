// ?lookup@Rva006213B0@@QAEPBDI@Z
// partial score=0.8 date=2026-10-01
// cl: /O2 /Ob2 /DNDEBUG /MD /EHsc
// Retail evidence: Ghidra boundary 0x006213B0, 197 bytes; ret 4 at
// 0x00621472..74. The original class and member names remain unknown.
// The body locks this+0x34, hashes its unsigned argument across the pointer
// range at +0x50/+0x54, walks next/key/value nodes, and calls value vslot 0.
// The fallback is the literal "<unknown>". The INI string-anchor lead does
// not establish INIClass identity: its layout and lookup semantics differ.

struct Rva006213B0CriticalSection {
    unsigned long fields[6];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(Rva006213B0CriticalSection *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(Rva006213B0CriticalSection *);

struct Rva006213B0Lock {
    Rva006213B0CriticalSection *section;
    Rva006213B0Lock(Rva006213B0CriticalSection *p) : section(p) { EnterCriticalSection(p); }
    ~Rva006213B0Lock() { LeaveCriticalSection(section); }
};

struct Rva006213B0Value {
    virtual const char *get() = 0;
};
struct Rva006213B0Node {
    Rva006213B0Node *next;
    unsigned key;
    Rva006213B0Value *value;
};
class Rva006213B0 {
    char unknown00[0x34];
    Rva006213B0CriticalSection section;
    unsigned unknown4C;
    Rva006213B0Node **begin;
    Rva006213B0Node **end;
    unsigned index(unsigned key) { return key % (end - begin); }
    Rva006213B0Node *find(unsigned key) {
        for (Rva006213B0Node *node = begin[index(key)]; node; node = node->next) {
            if (node->key == key)
                return node;
        }
        return 0;
    }
public:
    const char *lookup(unsigned key);
};

const char *Rva006213B0::lookup(unsigned key)
{
    Rva006213B0Lock lock(&section);
    Rva006213B0Node *node = find(key);
    if (!node)
        return "<unknown>";
    return node->value->get();
}
