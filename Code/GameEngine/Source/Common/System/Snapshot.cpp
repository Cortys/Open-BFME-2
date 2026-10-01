// cl: /O1 /Ireference/shims/moduledata

#include "Common/Snapshot.h"

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
