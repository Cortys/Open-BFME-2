// ?transformPoint@Thing@@QAEXPBUCoord3D@@PAU2@@Z
// partial score=0.93 date=2026-09-28
// ?transformPoint@Thing@@QAEXPBUCoord3D@@PAU2@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /arch:SSE /DNDEBUG /MD /EHsc /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// stlport
// ?transformPoint@Thing@@QAEXPBUCoord3D@@PAU2@@Z 0x0030A812 191B evidence: ZH donor Thing transformPoint null checks plus Thing layout m_transform at +8; callers 0x00460CBA 0x00482C4A 0x00483DA4 transform via ecx matrix; prev Thing.cpp next ThingSetPosition
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include "Common/Thing.h"

void Thing::transformPoint(const Coord3D *in, Coord3D *out)
{
	if (in == NULL || out == NULL)
		return;
	float x = in->x;
	float y = in->y;
	float z = in->z;
	Coord3D tmp;
	tmp.x = m_transform[0][0] * x + m_transform[0][1] * y + m_transform[0][2] * z + m_transform[0][3];
	tmp.y = m_transform[1][0] * x + m_transform[1][1] * y + m_transform[1][2] * z + m_transform[1][3];
	tmp.z = m_transform[2][0] * x + m_transform[2][1] * y + m_transform[2][2] * z + m_transform[2][3];
	*out = tmp;
}
