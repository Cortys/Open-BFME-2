// ?Rva0020E354Cast@@YG_NPAVRenderObjClass@@ABVVector3@@1@Z
// partial score=0.94 date=2026-09-30
// ?Rva0020E354Cast@@YG_NPAVRenderObjClass@@ABVVector3@@1@Z
// partial score=0.94 date=2026-09-30
// cl: /O1
// ?Rva0020E354Cast@@YG_NPAVRenderObjClass@@ABVVector3@@1@Z, retail 0x0020E354, 32 bytes.
// Stdcall wrapper forwarding obj/start/dir to rowed Rva002BF198Cast with
// out 0 collisionType 1 checkHidden 1. Caller at 0x0020F9C5.
class RenderObjClass;
class Vector3
{
public:
	float X;
	float Y;
	float Z;
};

bool __stdcall Rva002BF198Cast(RenderObjClass *obj, const Vector3 &start, const Vector3 &dir, Vector3 *out, int collisionType, bool checkHidden);

extern volatile int g_00DFEF18;

bool __stdcall Rva0020E354Cast(RenderObjClass *obj, const Vector3 &start, const Vector3 &dir)
{
	(void)g_00DFEF18;
	return Rva002BF198Cast(obj, start, dir, 0, 1, 1);
}
