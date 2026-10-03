// ?rva00086812@Rva00086761CameraMove@@QAEXH@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /G7 /arch:SSE /MD /EHs-c- /DNDEBUG
// Clean BFME1 W3DViewCameraModFinalMoveToBfme at6d9434269164392c5ba62aaa7c15a86b5b020d76
// guides the translation algorithm. Target Ghidra86761/177B/RET4 and
// complete raw byte equality prove guards1DC/2354, signed count22F0,
// three-float prefixes at2AC with20B stride, and iteration2 through count.
// These data offsets agree with the verified owner8990C/89971 at+280.
// Real constructor8B7CF calls owner8990C withECX=this+280. Its primary
// table BC7568 slot39/BC7604 selects this body; no direct E8/E9 callers.
// Original class/method/argument names and complete parent size unknown.
#include "../../../../GameEngine/Include/GameClient/Rva0008990CArrayOwner.h"


void Rva00086761CameraMove::rva00086761(Rva00089894Point *pLoc)
{
	if (m_doingRotateCamera) {
		return;
	}
	if (m_cameraMovementMode == 1) {
		int i;
		Rva00089894Point delta, start;
		start = m_cameraPath.m_arr255[m_cameraPath.m_numValues].m_position;
		delta = *pLoc;
		delta.x -= start.x;
		delta.y -= start.y;
		delta.z -= start.z;
		for (i = 2; i <= m_cameraPath.m_numValues; i++) {
			Rva00089894Point start;
			start.x = m_cameraPath.m_arr255[i].m_position.x;
			start.y = m_cameraPath.m_arr255[i].m_position.y;
			start.z = m_cameraPath.m_arr255[i].m_position.z;
			start.x += delta.x;
			start.y += delta.y;
			start.z += delta.z;
			m_cameraPath.m_arr255[i].m_position = start;
		}
	}
}

// Clean BFME1 Rva0073C420Set at6d943 guides this signed clamp.
// Target8690A21B is between Ghidra86812+248 and8691F; RET4.
// Same primary tableBC7568 slot32/BC75E8 selects this method. The field
// parent2A8 is canonical owner base m_28 at280+28. EAX incidentally holds
// normalized value; original return contract remains unknown.
void Rva00086761CameraMove::rva0008690A(int value)
{
 if (value<=1) value=1;
 m_cameraPath.m_28=value;
}

// ?rva00086812@Rva00086761CameraMove@@QAEXH@Z @0x00086812 248B gap between 86761 and 8690A
// Five gated int stores via byte flags, mode-gated 23D4 store, then float
// cumulative average loop with floor to int array. Flags/stores/divisor/
// arrays/count/mode from retail immediates; doubles BBCC70/BC26F8 via g_
// stopgaps; floor via IAT. Evidence: same TU prev/next, // cl match,
// no direct callers, primary table slot association via neighbours.
extern "C" __declspec(dllimport) double __cdecl floor(double);
extern double g_00BBCC70;
extern double g_00BC26F8;
// BaseType.h verbatim: C cast emits out-of-line _ftol plus qword shape;
// retail holds inline fld/fistp so the helper is load-bearing (x87 blocker).
__forceinline long fast_float2long_round(float f)
{
 long i;
 __asm {
  fld [f]
  fistp [i]
 }
 return i;
}
// ?rva00086812@Rva00086761CameraMove@@QAEXH@Z present-unmatched
void Rva00086761CameraMove::rva00086812(int value)
{
 register Rva00086761CameraMove *me = this;
 int i = 0;
 if (*(unsigned char *)((char *)me + 0x228))
  *(int *)((char *)me + 0x21C) = value;
 if (*(unsigned char *)((char *)me + 0x254))
  *(int *)((char *)me + 0x248) = value;
 if (*(unsigned char *)((char *)me + 0x204))
  *(int *)((char *)me + 0x1F8) = value;
 if (*(unsigned char *)((char *)me + 0x27C))
  *(int *)((char *)me + 0x270) = value;
 if (*(unsigned char *)((char *)me + 0x1DC))
  *(int *)((char *)me + 0x1B8) = value;
 if (*(int *)((char *)me + 0x2354) == 1) {
  float sum = 0.0f;
  if (*(volatile int *)((char *)me + 0x22F0) > 0) {
   float fvalue = (float)value;
   int *dst = (int *)((char *)me + 0x1EF8);
   for (i = 0; i < *(volatile int *)((char *)me + 0x22F0); i++, dst++) {
    sum += *(float *)((char *)dst - 0x414);
    float avg = sum / *(float *)((char *)me + 0x1EE8);
    int old = *dst;
    double d = (g_00BBCC70 - avg) * old + avg * fvalue + g_00BC26F8;
    float f = (float)floor(d);
    *dst = fast_float2long_round(f);
   }
  }
  return;
 }
 *(int *)((char *)me + 0x23D4) = value;
}

// Clean BFME1 W3DViewZoomCameraBfme6d943 O1/G7/SSE/MD guides duration,
// frame and interpolation setup. Target132B/RET16, primary slot59/BC7654,
// unchanged-this call to86CDA and matching fields prove the association.
// Runtime period VA DE204C has genuine zero PE storage; writer4C6C6 and
// startup7AC08C configure it. Their code is not recovered by this unit.
// Original method/global names and complete receiver size remain unknown.
int g_Va00DE204C;

void Rva00086761CameraMove::rva00088EB4(float finalValue, int milliseconds, float easeIn, float easeOut)
{
 int &duration = milliseconds;
 register Rva00086761CameraMove *view = this;
 view->m_228 = true;
 if (duration < 1) duration = 1;
 int frames = duration / g_Va00DE204C;
 if (frames < 1) frames = 1;
 view->m_208 = frames;
 view->m_210 = view->m_3C;
 view->m_214 = finalValue;
 view->m_20C = 0;
 view->m_220.rva0030E51F(easeIn, easeOut, (float)duration);
 if (duration == 1) view->rva00086CDA();
}
