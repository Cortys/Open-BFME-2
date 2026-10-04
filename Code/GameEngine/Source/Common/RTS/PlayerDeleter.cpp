// cl: /O1 /DNDEBUG /MD
//
// ??_GPlayer@@UAEPAXI@Z, retail 0x002B14CF (28 bytes): slot 0
// of vtable 0x00BFDF3C, whose slot-2 name getter returns "Player" (the only
// vtable using that getter). Scalar deleting destructor: calls the
// destructor at 0x002B11A7 and then the global operator delete when bit 0 of
// the flags is set. That destructor re-stores vtable 0x00BFDF3C, which
// identifies it as Player::~Player (pinned in reverse/symbols.csv).
// Class shape from Zero Hour's Common/Player.h (public virtual ~Player).
// BFME 2's form frees through the global operator delete.
// The destructor is declared, not defined, so the call resolves to the pin;
// the dummy tag constructor (no retail counterpart) only makes this TU emit
// the vtable and with it the deleting destructor.

struct EmitVtableTag;

class Player
{
public:
	Player(EmitVtableTag *);
	virtual ~Player();
};

// ?<Player::Player> absent-from-retail
Player::Player(EmitVtableTag *)
{
}
