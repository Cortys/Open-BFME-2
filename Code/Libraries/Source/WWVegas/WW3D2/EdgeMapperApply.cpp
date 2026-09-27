// cl: /G7 /Ireference/shims/bfmerendobj /Ireference/shims/bfmemapper /arch:SSE /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep

// Reference: EA GeneralsMD WW3D2/mapper.cpp, EdgeMapperClass::Apply;
// DX8Wrapper::Set_Transform(Matrix4x4) from the BFME1 reference header.
// Target: game.dat RVA 0x00184FD0, 1288 bytes (discovery batch 5).
// Identity: the already matched EdgeMapperClass constructors at 0x183410
// and 0x1834D0 install vtable 0x7D5738, whose Apply slot (+0x14) points here.
// Their class names are inherited from the ledger's donor identifications.
// Retail independently establishes Stage at +8, UseReflect at +0x18,
// Calculate_Texture_Matrix dispatch at +0x24, and the two texture-state calls.
// Other unused members/virtual declarations below follow donor ABI context;
// the unknown +0x20 virtual is reserved without asserting its signature.
// The transform projection branch writes the same transpose into two globals
// (VA 0xDEDC30 then 0xDEDBF0). Only ProjectionMatrix carries a donor name;
// the second global is address-labelled, not assigned an invented EA identity.
// /G7 and /arch:SSE reproduce all 1288 bytes. No shared headers are changed.

#include "refcount.h"
#include "matrix4.h"
#include "vector2.h"
#include "vector3.h"
#define VERTEXMAPPER_H

// TU-only mapper ABI. Slot 0x20 is present in the target but is not named here.
class TextureMapperClass : public RefCountClass {
public:
    virtual ~TextureMapperClass();
    virtual int Mapper_ID() const;
    virtual TextureMapperClass *Clone() const;
    virtual bool Is_Time_Variant();
    virtual void Apply(int uv_array_index);
    virtual void Reset();
    virtual bool Needs_Normals();
    virtual void RetailSlot20();
    virtual void Calculate_Texture_Matrix(Matrix4x4 &matrix);
protected:
    unsigned int Stage;
};
class EdgeMapperClass : public TextureMapperClass {
public:
    virtual void Apply(int uv_array_index);
protected:
    unsigned int LastUsedSyncTime;
    float VSpeed, VOffset;
    bool UseReflect;
};
#include "rendobj.h"
#include "ww3d.h"
#include "dx8wrapper.h"
extern Matrix4x4 g_mapperProjectionCopy_009EDC30;
// Access shim only: no runtime instances or claim of a retail derived class.
struct MapperTransformAccess : DX8Wrapper {
    enum { WORLD_CHANGED=1, VIEW_CHANGED=2, WORLD_IDENTITY=1<<18, VIEW_IDENTITY=1<<19 };
    static __forceinline void SetTransform(D3DTRANSFORMSTATETYPE transform, const Matrix4x4 &m) {
        switch ((int)transform) {
        case D3DTS_WORLD:
            render_state.world=m.Transpose();
            render_state_changed=(render_state_changed & ~(unsigned)WORLD_IDENTITY) | (unsigned)WORLD_CHANGED;
            break;
        case D3DTS_VIEW:
            render_state.view=m.Transpose();
            render_state_changed=(render_state_changed & ~(unsigned)VIEW_IDENTITY) | (unsigned)VIEW_CHANGED;
            break;
        case D3DTS_PROJECTION:
            ProjectionMatrix=g_mapperProjectionCopy_009EDC30=m.Transpose();
            ZFar=0.0f;
            ZNear=0.0f;
            DX8CALL(SetTransform(D3DTS_PROJECTION,(D3DMATRIX*)&ProjectionMatrix));
            break;
        default:
            DX8_RECORD_MATRIX_CHANGE();
            Matrix4x4 m2=m.Transpose();
            DX8CALL(SetTransform(transform,(D3DMATRIX*)&m2));
            break;
        }
    }
};

void EdgeMapperClass::Apply(int uv_array_index)
{
	// Set up the texture matrix
	Matrix4x4 m;
	Calculate_Texture_Matrix(m);
	MapperTransformAccess::SetTransform((D3DTRANSFORMSTATETYPE) (D3DTS_TEXTURE0+Stage),m);

	// Get camera reflection vector
	if (UseReflect)
		DX8Wrapper::Set_DX8_Texture_Stage_State(Stage,D3DTSS_TEXCOORDINDEX,D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR);
	else
		DX8Wrapper::Set_DX8_Texture_Stage_State(Stage,D3DTSS_TEXCOORDINDEX,D3DTSS_TCI_CAMERASPACENORMAL);

	// Tell rasterizer to expect 2D matrices
	DX8Wrapper::Set_DX8_Texture_Stage_State(Stage,D3DTSS_TEXTURETRANSFORMFLAGS,D3DTTFF_COUNT2);
	
}
