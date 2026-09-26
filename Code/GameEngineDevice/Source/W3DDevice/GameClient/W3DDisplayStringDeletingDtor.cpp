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

// ??_GW3DDisplayString@@UAEPAXI@Z @0x0010625B 28B: slot 0 of vtable 0x00BCF900; calls ??1 at 0x00106162.
// Owner evidence: class-unique slots 9 ?setWordWrapCentered@W3DDisplayString@@UAEX_N@Z and 16 ?getWidth@W3DDisplayString@@UAEHH@Z.
class W3DDisplayString { public: __declspec(noinline) virtual ~W3DDisplayString(); };
// ??1W3DDisplayString@@UAE@XZ present-unmatched
W3DDisplayString::~W3DDisplayString() {}
void W3DDisplayString_Delete(W3DDisplayString *p) { delete p; }
