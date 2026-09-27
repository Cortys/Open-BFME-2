// cl: /O1 /Ireference/shims/bfmeterraintracks /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// stlport
//
// Size-optimised (/O1) emission of the TerrainTracksRenderObjClass::edgeInfo constructor.
//
#define Matrix4x4 Matrix4  // BFME renamed it
#include "W3DDevice/GameClient/W3DTerrainTracks.h"
#include "W3DDevice/GameClient/heightmap.h"
#include "Common/PerfTimer.h"
#include "common/GlobalData.h"
#include "common/Debug.h"
#include "texture.h"
#include "colmath.h"
#include "coltest.h"
#include "rinfo.h"
#include "camera.h"
#include "assetmgr.h"
#include "WW3D2/DX8Wrapper.h"
#include "WW3D2/Scene.h"
#include "GameLogic/TerrainLogic.h"
#include "GameLogic/Object.h"
#include "GameClient/Drawable.h"
#ifdef _INTERNAL
#endif
#define BRIDGE_OFFSET_FACTOR	0.25f	//amount to raise tracks above bridges.
#pragma optimize("s", on)

// edgeInfo is a protected nested type, so the anchor is a static member of a
// derived helper that is never instantiated.
struct BfmeTrackEdgeInfoAnchor : public TerrainTracksRenderObjClass
{
	static void anchor(edgeInfo *e);
};
#pragma inline_depth(0)
// ?anchor@BfmeTrackEdgeInfoAnchor@@ absent-from-retail
void BfmeTrackEdgeInfoAnchor::anchor(edgeInfo *e)
{
	e->edgeInfo::edgeInfo();
}
#pragma inline_depth()
