// ?Add_Lod_Model@HLodClass@@UAEXHPAVRenderObjClass@@H@Z
// partial score=0.8672566372 date=2026-09-27
// cl: /Ireference/shims/bfme2renderobj /Ireference/shims /Ireference/shims/bfmerendobj /G7 /arch:SSE /DNDEBUG /MD /Ireference/shims/bfmevector /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
// Banked Add_Lod_Model candidate: target 0x0019F2B0..0x0019F4AF (511 bytes).
// Identity: recovered HLod definition ctor call19FE42 and table7D6780 slot234.
// EA/BFME1 hlod.cpp supplies the model attachment semantics. Retail consumes
// BFME2 pivot quaternion/translation at +30/+40, stride58; expands it into
// a temporary Matrix3D before Set_Transform; then zeros newnode.Offset.
// Pivot field offsets corroborated by HTreePivotClass.cpp. Rotation formulas
// reconstructed from target SSE arithmetic; field block names are descriptive.
// Emits506 bytes, first diff+54: SSE register allocation/scheduling remains.
// This is a partial, not verified progress.
#define Matrix4x4 Matrix4
#include <sweep/winbase_shim.h>
#include <string.h>
#define _CRTIMP
#include "rendobj.h"
#include "winbase_shim.h"
#include "hlod.h"
#include "assetmgr.h"
#include "hmdldef.h"
#include "w3derr.h"
#include "chunkio.h"
#include "predlod.h"
class CameraClass;
#include "rinfo.h"
#include "sphere.h"
#include "boxrobj.h"

struct HlodTransformView { float X,Y,Z,W; Vector3 Position; };
struct HlodPivotView
{
    unsigned char unaccessed[0x30];
    HlodTransformView Transform;
    int Index;
    bool IsVisible;
    unsigned char tail[7];
};
typedef char HlodPivotStride[(sizeof(HlodPivotView) == 0x58) ? 1 : -1];
struct HlodTreeView
{
    char Name[16];
    int NumPivots; // +0x10
    HlodPivotView *Pivot; // +0x14
};
static __forceinline bool pivotVisible(const HTreeClass *tree, int index)
{
    return reinterpret_cast<const HlodTreeView *>(tree)->Pivot[index].IsVisible;
}

static __forceinline Matrix3D &pivotMatrix(const HlodTransformView &q, Matrix3D &m)
{
 float xx=q.X*q.X*2.0f, yy=q.Y*q.Y*2.0f, zz=q.Z*q.Z*2.0f;
 float xy=q.X*q.Y*2.0f, xz=q.Z*q.X*2.0f, yz=q.Z*q.Y*2.0f;
 float wx=q.W*q.X*2.0f, wy=q.W*q.Y*2.0f, wz=q.W*q.Z*2.0f;
 m[0][0]=1.0f-yy-zz; m[0][1]=xy-wz; m[0][2]=xz+wy;
 m[1][0]=xy+wz; m[1][1]=1.0f-zz-xx; m[1][2]=yz-wx;
 m[2][0]=xz-wy; m[2][1]=yz+wx; m[2][2]=1.0f-yy-xx;
 m[0][3]=q.Position.X; m[1][3]=q.Position.Y; m[2][3]=q.Position.Z;
 return m;
}
void HLodClass::Add_Lod_Model(int lod, RenderObjClass * robj, int boneindex)
{		
	WWASSERT(robj != NULL);

	// (gth) survive the case where the skeleton for this object no longer has
	// the bone that we're trying to use.  This happens when a skeleton is re-exported
	// but the models that depend on it aren't re-exported...
	if (boneindex >= HTree->Num_Pivots()) {
		WWDEBUG_SAY(("ERROR: Model %s tried to use bone %d in skeleton %s.  Please re-export!\n",Get_Name(),boneindex,HTree->Get_Name()));
		boneindex = 0;
	}
	
	ModelNodeClass newnode;
	newnode.Model = robj;
	newnode.Model->Add_Ref();
	newnode.BoneIndex = boneindex;
	newnode.Model->Set_Container(this);
	Matrix3D transform;
	newnode.Model->Set_Transform(pivotMatrix(reinterpret_cast<const HlodTreeView *>(HTree)->Pivot[boneindex].Transform,transform));
	newnode.Offset.X = newnode.Offset.Y = newnode.Offset.Z = 0.0f;

	if (Is_In_Scene() && lod == CurLod) {
		newnode.Model->Notify_Added(Scene);
	}
	Lod[lod].Add(newnode);
}


