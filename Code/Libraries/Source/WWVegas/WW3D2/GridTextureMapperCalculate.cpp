// cl: /G7 /Ireference/shims/bfmerendobj /Ireference/shims/bfmemapper /arch:SSE /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep

// Reference: GeneralsMD WW3D2/mapper.cpp Calculate_Texture_Matrix;
// BFME2 already matched update_temporal_state (0x182590) and
// calculate_uv_offset (0x1825E0) are visible inline, as in the retail body.
// Identity: matched GridTextureMapper constructors install table 0x7D57B4;
// its slot +0x24 points to retail RVA 0x1849A0, 267 bytes (boundary batch12).
// Constructor identity comes from existing donor matches. Retail separately
// establishes the frame timing arithmetic, UV offsets and identity matrix.
// The bfmemapper shim supplies the constructor-verified +4 grid layout shift.

#include "rendobj.h"	// the bfmerendobj shim has to win the include guard
#include "mapper.h"
#include "ini.h"
#include "ww3d.h"
#include "meshmatdesc.h"
#include "dx8wrapper.h"
#include "wwmath.h"
#include "random.h"
#include <stdlib.h>


inline void GridTextureMapperClass::update_temporal_state()
{
	unsigned int now = WW3D::Get_Sync_Time();
	unsigned int delta = now - LastUsedSyncTime;
	Remainder += delta;
	LastUsedSyncTime = now;

	int new_frame = (int)CurrentFrame + ((int)(Remainder / MSPerFrame) * Sign);
	new_frame = (int)((unsigned)new_frame % LastFrame);

	if (new_frame < 0)
		CurrentFrame = LastFrame + new_frame;
	else
		CurrentFrame = (unsigned int)new_frame;
	Remainder = Remainder % MSPerFrame;
}

inline void GridTextureMapperClass::calculate_uv_offset(float * u_offset, float * v_offset)
{
	unsigned int row_mask = ~(0xFFFFFFFF << GridWidthLog2);
	unsigned int col_mask = row_mask << GridWidthLog2;
	unsigned int x = CurrentFrame & row_mask;
	unsigned int y = (CurrentFrame & col_mask) >> GridWidthLog2;
	*u_offset = x * OOGridWidth;
	*v_offset = y * OOGridWidth;
}
void GridTextureMapperClass::Calculate_Texture_Matrix(Matrix4x4 &tex_matrix)
{
	update_temporal_state();

	float u_offset, v_offset;
	calculate_uv_offset(&u_offset, &v_offset);

	// Set up the offset matrix
	tex_matrix.Make_Identity();
	
	// According to the docs this should work since its 2D
	// otherwise change to translate
	tex_matrix[0].Z = u_offset;
	tex_matrix[1].Z = v_offset;
}