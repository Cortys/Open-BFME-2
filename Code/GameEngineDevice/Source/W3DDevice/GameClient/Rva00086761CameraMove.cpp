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

class Rva00086761CameraMove
{
public:
 void rva00086761(Rva00089894Point *pLoc);
 void rva0008690A(int value);
private:
 char m_padding0000[0x1DC];
 bool m_doingRotateCamera;
 char m_padding1dd[0x280-0x1DD];
 Rva0089971 m_cameraPath;
 char m_padding22f4[0x2354-0x22F4];
 int m_cameraMovementMode;
};

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
// ?Rva00086761CameraMove::rva0008690A present-unmatched
void Rva00086761CameraMove::rva0008690A(int value)
{
 if (value<=1) value=1;
 m_cameraPath.m_28=value;
}
