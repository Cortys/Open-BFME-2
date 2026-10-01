// cl: /Ireference/shims/bfme2renderobj /arch:SSE /G7 /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
// Target evidence: RenderObjClass vftable VA 0x00BD2F68 slot 41 points to
// RVA 0x000B3FD0, whose retail body is the one-byte RET. This address is
// folded with the existing ?validate@?$StringBase@D@@ABEXXZ row.
// Donor provenance: Open-BFME-1 WW3D2/rendobj.cpp at 071013b3c6f1228dfda315732197bed0fd191209
// defines this default virtual as empty; the donor behavior agrees with retail.

#include "rendobj.h"

void RenderObjClass::Update_Sub_Object_Transforms(void)
{
}
