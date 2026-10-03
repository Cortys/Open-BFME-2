// ?rva007B6850Cleanup@@YAXXZ
// partial score=1.0 date=2026-10-03
// cl: /O2 /MD
// Retail 0x7B6850/10: named-global pool cleanup wrapper, ECX=0xDA60E8,
// tail call to independently recovered pool-clear 0x1EAF7B/32.
// The 24-byte pool-clear view and behavior-member initializer29FB3B prove
// the pool's role; the original pool type/name is unknown. No donor identity
// is carried from the queue's unrelated ios teardown or Debug initializer.
class Rva001EAF7B { public: bool rva001EAF7B(); };
extern unsigned char g_BfmeBehaviorFreelistPool[24];
void rva007B6850Cleanup() {
 reinterpret_cast<Rva001EAF7B *>(g_BfmeBehaviorFreelistPool)->rva001EAF7B();
}
