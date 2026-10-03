// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z
// partial score=0.65 date=2026-10-03
// ?rva002FE8CC@Rva002FE8CC@@QAEXPAX@Z @0x002FE8CC 116B
// cl: /O1 /DNDEBUG /MD
// Linked-list registration: walk the list at +0xF8 for a node whose +4 name
// compares equal to the incoming node's; on a hit, move the incoming node's
// data pointer into the existing node, clear the incoming node and release it
// through its virtual.  With no match, link the incoming node at the head.
// Evidence: 0x004069D6 is the rowed StringBase::compare (its `this` is the
// INCOMING node's +4 name and its pushed argument is the CURSOR's +4 name,
// which fixes the compare direction as have->compare(*want)), and each release
// is `call dword ptr [eax]` with a zero argument followed by 0x0042FD60.
// Layout is TU-local; identity unproven, so address-named.
//
// Improvement this pass: 0x0042FD60 is declared __stdcall on one pointer, not
// ::operator delete.  Retail emits `call 0x42FD60 / pop ecx`; a cdecl
// ::operator delete makes the caller pop the return address itself and cl
// rewrites the block, which moved every instruction after the first delete.
// With the stdcall declaration the two release blocks now match retail's
// instruction-for-instruction and the compare call site matches exactly.
//
// Remaining gap: register allocation.  Retail keeps ebx=this, esi=cursor,
// edi=arg, ebp=arg's name, with `mov ebx,ecx` as the very first instruction.
// This spelling lets cl choose ebp=this and reassign the rest; the compare
// sequence still lines up but the prologue and the three cursor loads differ.
// Refuted: renaming the locals (identical output), splitting the head load from
// the walk, reloading the head at the link site, do-while vs while vs for(;;).
template <typename T> struct StringInlineData { int m_refCount; int m_length; T m_text[1]; };
template <typename T> class StringBase { public: int compare(const StringBase<T> &other) const; private: StringInlineData<T> *m_data; };

// Retail pushes the pointer and pops the return address itself (pop ecx after
// the call), i.e. one stack argument, stdcall cleanup.
extern void __stdcall bfmeDelete42FD60(void *p);

struct DataVirt { virtual void *f(int x); };
struct Subsystem { StringBase<char> m_name04; DataVirt *m_08; Subsystem *m_next0C; virtual void *g(int x); };
class Rva002FE8CC { public: void rva002FE8CC(void *arg); char m_padF8[0xF8]; Subsystem *m_headF8; };

void Rva002FE8CC::rva002FE8CC(void *arg)
{
	Subsystem *head = m_headF8;
	Subsystem *cur = head;
	if (cur != 0) {
		Subsystem *incoming = (Subsystem *)arg;
		StringBase<char> *want = (StringBase<char> *)((char *)incoming + 4);
		do {
			StringBase<char> *have = (StringBase<char> *)((char *)cur + 4);
			if (have->compare(*want) == 0) {
				DataVirt *d = cur->m_08;
				if (d != 0) {
					void *p = d->f(0);
					bfmeDelete42FD60(p);
				}
				cur->m_08 = incoming->m_08;
				int zero = 0;
				incoming->m_08 = (DataVirt *)zero;
				incoming->m_next0C = (Subsystem *)zero;
				void *q = incoming->g(zero);
				bfmeDelete42FD60(q);
				return;
			}
			cur = cur->m_next0C;
		} while (cur != 0);
	}
	Subsystem *incoming = (Subsystem *)arg;
	incoming->m_next0C = head;
	m_headF8 = incoming;
}