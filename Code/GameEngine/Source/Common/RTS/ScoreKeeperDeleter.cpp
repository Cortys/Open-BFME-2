// cl: /O1 /DNDEBUG /MD
//
// ??_GScoreKeeper@@UAEPAXI@Z, retail 0x0039C5E1 (28 bytes): slot 0
// of vtable 0x00C1AD98, whose slot-2 name getter returns "ScoreKeeper" (the only
// vtable using that getter). Scalar deleting destructor: calls the
// destructor at 0x0039C2B5 and then the global operator delete when bit 0 of
// the flags is set. That destructor re-stores vtable 0x00C1AD98, which
// identifies it as ScoreKeeper::~ScoreKeeper (pinned in reverse/symbols.csv).
// Class shape from Zero Hour's Common/ScoreKeeper.h (public ~ScoreKeeper).
// BFME 2's form frees through the global operator delete.
// The destructor is declared, not defined, so the call resolves to the pin;
// the dummy tag constructor (no retail counterpart) only makes this TU emit
// the vtable and with it the deleting destructor.

struct EmitVtableTag;

class ScoreKeeper
{
public:
	ScoreKeeper(EmitVtableTag *);
	virtual ~ScoreKeeper();
};

// ?<ScoreKeeper::ScoreKeeper> absent-from-retail
ScoreKeeper::ScoreKeeper(EmitVtableTag *)
{
}
