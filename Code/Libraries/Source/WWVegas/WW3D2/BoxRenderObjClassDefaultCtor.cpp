// cl: /arch:SSE2 /Ireference/shims/bfme2renderobj /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ??0BoxRenderObjClass@@QAE@XZ @ 0x00174C80 (155B).
// Dedicated TU so boxrobj.cpp keeps its existing matched bodies.
// Same headers and /arch:SSE2 as BoxRenderObjClassCtor.cpp (retail uses SSE
// math for the color/opacity/center/extent stores), so the class view and
// its COMDAT copies match the kept copies from boxrobj.cpp/composite.cpp.
#include "rendobj.h"
#include "boxrobj.h"
#include <string.h>

// ??0BoxRenderObjClass@@QAE@XZ
BoxRenderObjClass::BoxRenderObjClass(void)
{
	memset(Name, 0, sizeof(Name));
	Color.Set(1, 1, 1);
	Opacity = 0.25f;
	ObjSpaceCenter.Set(0, 0, 0);
	ObjSpaceExtent.Set(1, 1, 1);
}
