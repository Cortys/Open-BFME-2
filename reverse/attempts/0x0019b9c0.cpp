// ?Create_Decal@HLodClass@@UAEXPAVDecalGeneratorClass@@_N@Z
// partial score=0.95402299 date=2026-10-04
// ?Create_Decal@HLodClass@@UAEXPAVDecalGeneratorClass@@_N@Z
// partial score=0.95402299 date=2026-09-27
// cl: /Ireference/shims/bfme2htree /Ireference/shims/bfme2renderobj /Ireference/shims /Ireference/shims/bfmerendobj /G7 /arch:SSE /DNDEBUG /MD /Ireference/shims/bfmevector /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// Partial: retail RVA 0x0019B9C0, 87 bytes, HLod table 0x007D6780 slot 0x1F0.
// Donor supplies the method identity; retail supplies the virtual enumeration.
// Four register-allocation bytes differ: retail caches the second argument.
#include "rendobj.h"
#include <htree.h>
#include "hlod.h"

void HLodClass::Create_Decal(DecalGeneratorClass * generator, bool unk)
{
    const int count = Get_Num_Sub_Objects();
    for (int i = 0; i < count; ++i) {
        RenderObjClass *object = Get_Sub_Object(i);
        object->Create_Decal(generator, unk);
        object->Release_Ref();
    }
}
