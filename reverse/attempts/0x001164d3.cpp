// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z
// partial score=0.9 date=2026-09-27
// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z
// partial score=0.90 date=2026-09-27
// cl: /O1 /MD
//
// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z retail 0x001164D3 34 bytes.
// Base ctor called by 12 derived ctors at 0x0010EE4F 0x0010EE67 0x0010EE86
// 0x0010EECE 0x0010EEF1 0x0010EF14 0x0010EF42 0x0010EF61 0x0010EF8B etc.
// Each caller forwards the same string arg then overwrites vtable with its own
// 0x007CFA4C..0x007CFAB8. This body stores vtable 0x007CFB38 at +0 zeroes +4
// and copy-constructs the +8 Rva0036CA00Str via rowed 0x000A8C7C.
// Callee row Code/GameEngine/Source/Common/Rva0036CA00StrCopy.cpp.
// Current body is exact size 34 with correct push prolog vtable reloc call
// reloc and ret 4. Remaining diff is scheduling only: retail is lea ecx [esi+8]
// then mov [esi+4] 0 then vtable; this body is mov [esi+4] 0 then lea then
// vtable. Volatile forces mov under /O1; flat volatile puts vtable in the
// middle; base volatile puts vtable last but mov before lea. Float gives the
// right lea-mov-vtable order but emits fldz-fstp instead of mov.

class Rva0036CA00Str {
    void *m_item;
public:
    __declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &other);
    ~Rva0036CA00Str();
};

class Base04 {
public:
    Base04() : m_04(0) {}
    volatile int m_04;
};

class Rva001164D3 : public Base04 {
public:
    virtual void dummy();
    Rva0036CA00Str m_08;
    Rva001164D3(const Rva0036CA00Str &s);
};

Rva001164D3::Rva001164D3(const Rva0036CA00Str &s) : Base04(), m_08(s) {
}
