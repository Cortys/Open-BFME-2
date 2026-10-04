// cl: /O1 /DNDEBUG /MD
//
// ??_GTAiData@@UAEPAXI@Z, retail 0x002FE041 (28 bytes): slot 0
// of vtable 0x00C071E4, whose slot-2 name getter returns "TAiData" (the only
// vtable using that getter). Scalar deleting destructor: calls the
// destructor at 0x002FDF72 and then the global operator delete when bit 0 of
// the flags is set. That destructor re-stores vtable 0x00C071E4, which
// identifies it as TAiData::~TAiData (pinned in reverse/symbols.csv).
// Class shape from Zero Hour's GameLogic/AI.h (public ~TAiData).
// BFME 2's form frees through the global operator delete.
// The destructor is declared, not defined, so the call resolves to the pin;
// the dummy tag constructor (no retail counterpart) only makes this TU emit
// the vtable and with it the deleting destructor.

struct EmitVtableTag;

class TAiData
{
public:
	TAiData(EmitVtableTag *);
	virtual ~TAiData();
};

// ?<TAiData::TAiData> absent-from-retail
TAiData::TAiData(EmitVtableTag *)
{
}
