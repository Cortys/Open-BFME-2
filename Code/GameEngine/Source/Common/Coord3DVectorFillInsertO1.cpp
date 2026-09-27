// cl: /O1 /G7 /arch:SSE /Ireference/shims/bfmecamera /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/GameEngine/Source/Common/System /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/GameEngine/Source/Common
// stlport
//
// Size-optimised (/O1) instantiation of vector<Coord3D>::_M_fill_insert.
//
#include <vector>
#include "prerts.h"
#include "coord.h"
#include "bezier_segment.h"
#include "bez_fwd_iterator.h"
#include "d3dx8math.h"

extern void (_STL::vector<Coord3D>::*const g_bfmeCoord3DFillInsertAnchor)(Coord3D *, unsigned int, const Coord3D &);
void (_STL::vector<Coord3D>::*const g_bfmeCoord3DFillInsertAnchor)(Coord3D *, unsigned int, const Coord3D &) = &_STL::vector<Coord3D>::_M_fill_insert;
