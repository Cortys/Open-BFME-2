// cl: /O1 /DNDEBUG /MD
//
// ??_GTeamTemplateInfo@@UAEPAXI@Z, retail 0x003A287B (28 bytes): slot 0
// of vtable 0x00C1AE70, whose slot-2 name getter returns "TeamTemplateInfo" (the only
// vtable using that getter). Scalar deleting destructor: calls the
// destructor at 0x0039EAED and then the global operator delete when bit 0 of
// the flags is set. A class's compiler-generated deleting destructor calls
// that class's destructor, so the callee is TeamTemplateInfo::~TeamTemplateInfo (pinned in
// reverse/symbols.csv; its SEH body does not re-store the vtable).
// Class shape from Zero Hour's Common/Team.h (implicit public destructor).
// BFME 2's form frees through the global operator delete.
// The destructor is declared, not defined, so the call resolves to the pin;
// the dummy tag constructor (no retail counterpart) only makes this TU emit
// the vtable and with it the deleting destructor.

struct EmitVtableTag;

class TeamTemplateInfo
{
public:
	TeamTemplateInfo(EmitVtableTag *);
	virtual ~TeamTemplateInfo();
};

// ?<TeamTemplateInfo::TeamTemplateInfo> absent-from-retail
TeamTemplateInfo::TeamTemplateInfo(EmitVtableTag *)
{
}
