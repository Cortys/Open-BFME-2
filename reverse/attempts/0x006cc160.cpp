// ??HAptMemoryAllocationsT@@QAE?AU0@ABU0@@Z
// partial score=1.0 date=2026-09-27
// cl: /O2 /MD
// Partial: donor-named identity at target6CC160 needs independent caller evidence.
// Whole body122 bytes and eight32-bit arithmetic fields match the donor.
struct AptMemoryAllocationsT {
    unsigned int nAptUpdateAllocations;
    unsigned int nAptUpdateDeletions;
    unsigned int nAptUpdateAllocationSize;
    unsigned int nAptUpdateDeletionSize;
    unsigned int nAptUpdateAllocationsGC;
    unsigned int nAptUpdateDeletionsGC;
    unsigned int nAptUpdateAllocationGCSize;
    unsigned int nAptUpdateDeletionGCSize;
    AptMemoryAllocationsT operator+(const AptMemoryAllocationsT &other);
};
AptMemoryAllocationsT AptMemoryAllocationsT::operator+(const AptMemoryAllocationsT &other)
{
    AptMemoryAllocationsT sum;
    sum.nAptUpdateAllocations=nAptUpdateAllocations+other.nAptUpdateAllocations;
    sum.nAptUpdateDeletions=nAptUpdateDeletions+other.nAptUpdateDeletions;
    sum.nAptUpdateAllocationsGC=nAptUpdateAllocationsGC+other.nAptUpdateAllocationsGC;
    sum.nAptUpdateDeletionsGC=nAptUpdateDeletionsGC+other.nAptUpdateDeletionsGC;
    sum.nAptUpdateAllocationSize=nAptUpdateAllocationSize+other.nAptUpdateAllocationSize;
    sum.nAptUpdateDeletionSize=nAptUpdateDeletionSize+other.nAptUpdateDeletionSize;
    sum.nAptUpdateAllocationGCSize=nAptUpdateAllocationGCSize+other.nAptUpdateAllocationGCSize;
    sum.nAptUpdateDeletionGCSize=nAptUpdateDeletionGCSize+other.nAptUpdateDeletionGCSize;
    return sum;
}
