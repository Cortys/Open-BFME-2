// cl: /O1

class Xfer;

// Snapshot carries no state of its own - both constructors do nothing but
// install the vtable at 0x00BBB554, and the copy constructor ignores its
// argument entirely.
class Snapshot
{
public:
    Snapshot();
    Snapshot(const Snapshot &that);

    virtual ~Snapshot();
    virtual void crc(Xfer *xfer) = 0;
    virtual void loadPostProcess() = 0;
    // Slot 3: Xfer's transfer operator for a Snapshot calls [vtable+0x0C] with
    // the Xfer as its only argument, which is what puts this one last.
    virtual void xfer(Xfer *xfer) = 0;
};

inline Snapshot::Snapshot()
{
}

inline Snapshot::Snapshot(const Snapshot &that)
{
}

// One vtable store, and the linker folds it together with every FXParticleSystem
// info destructor - which is what proves they all share Snapshot's table.
inline Snapshot::~Snapshot()
{
}

// The generated assignment: nothing to copy, not even the vtable.
typedef Snapshot &(Snapshot::*SnapshotAssign)(const Snapshot &);

SnapshotAssign g_snapshotAssign = &Snapshot::operator=;

// Snapshot's constructors and destructor are header inlines: 145 other units
// emit them as select-any copies, which plain definitions here collided
// with. The anchor keeps this unit's copies for the rows; it is not retail
// code.
#pragma inline_depth(0)
// ?_bfmeSnapshotInlineAnchor@@YAXPAVSnapshot@@@Z absent-from-retail
void _bfmeSnapshotInlineAnchor(Snapshot *snapshot)
{
    snapshot->Snapshot::Snapshot();
    snapshot->Snapshot::Snapshot(*snapshot);
    snapshot->Snapshot::~Snapshot();
}
#pragma inline_depth()
