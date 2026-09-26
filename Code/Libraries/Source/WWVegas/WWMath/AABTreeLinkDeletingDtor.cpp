// cl: /O1 /MD
//
// Scalar deleting destructors (28B flag-test ??_G shape) whose owning class
// the image names:
// push esi / mov esi,ecx / call <dtor> / test [esp+8],1 / je / push esi /
// call ??3 (0x2FD60) / pop ecx / mov eax,esi / pop esi / ret 4.
//
// Target facts, per class below: the ??_G bytes; the destructor it calls; the
// vtable holding the ??_G in slot 0; and the evidence tying that vtable to the
// class -- the class's own constructor installs it, and/or other slots of it
// that no other vtable shares already carry the class's name in the ledger.
// Carried from those ledger rows: the class names themselves.
// Not established: each class's layout, bases and destructor body. Every class
// is declared with only the virtual destructor the ??_G needs;
// __declspec(noinline) keeps it out of line so the ??_G calls it through the
// pin, and the empty body is a placeholder, not a claim.

// ??_GAABTreeLinkClass@@UAEPAXI@Z @0x0026EF34 28B: slot 0 of vtable 0x00BFAA9C; calls ??1 at 0x0026EDFF.
// Owner evidence: sole named installer ??0AABTreeLinkClass@@QAE@PAVAABTreeCullSystemClass@@@Z.
class AABTreeLinkClass { public: __declspec(noinline) virtual ~AABTreeLinkClass(); };
// ??1AABTreeLinkClass@@UAE@XZ present-unmatched
AABTreeLinkClass::~AABTreeLinkClass() {}
void AABTreeLinkClass_Delete(AABTreeLinkClass *p) { delete p; }
