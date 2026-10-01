// ?rva0048B256@DynamicShroudClearingRangeUpdate@@QAEXXZ
// partial score=0.95 date=2026-09-30
// ?rva0048B256@DynamicShroudClearingRangeUpdate@@QAEXXZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /GX /arch:SSE
// ?rva0048B256@DynamicShroudClearingRangeUpdate@@QAEXXZ @0x0048B256 233B: grid-decal ring update.
// Same class/flags as neighbours CreateGridDecals and Xfer. Reads m_totalFrames 0x28
// m_stateCountDown 0x24 m_currentClearingRange 0x4C m_nativeClearingRange 0x48,
// object pos +0x38, writes m_gridDecal[30] at +0x50 via setPosition 0x00330DFD
// setOpacity 0x00330DDB rowed, ji sin-cos 0x629216 0x62920A rowed, ftol2 rowed,
// g_Va00BBB8D8 rowed, step 0.20943951f (2*PI/30 bytes PwV> Float-ref).
// Callers 0x0048B458 0x0048B4B3 in 0x0048B33F unclaimed.
#include <math.h>

typedef int Int;
struct Coord3D { float x; float y; float z; };
class RadiusDecal {
public:
	void setPosition(const Coord3D &pos);
	void setOpacity(float opacity);
private:
	const void *m_template;
	void *m_decal;
	unsigned char m_empty;
	unsigned char m_pad_09[3];
	float m_unknown0C;
};
class Thing;
class ModuleData;
class Object;
class UpdateModule {
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	~UpdateModule();
};
extern float g_Va00BBB8D8;
class DynamicShroudClearingRangeUpdate : public UpdateModule {
public:
	void rva0048B256();
private:
	const void *m_vtable;
	const ModuleData *m_moduleData;
	Object *m_object;
	const void *m_secondary0C;
	const void *m_secondary10;
	unsigned int m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_reserved1C;
	int m_state;
	int m_stateCountDown;
	int m_totalFrames;
	unsigned int m_growStartDeadline;
	unsigned int m_sustainDeadline;
	unsigned int m_shrinkStartDeadline;
	unsigned int m_doneForeverFrame;
	unsigned int m_changeIntervalCountdown;
	bool m_decalsCreated;
	unsigned char m_pad_41[3];
	float m_visionChangePerInterval;
	float m_nativeClearingRange;
	float m_currentClearingRange;
	RadiusDecal m_gridDecal[30];
};
void DynamicShroudClearingRangeUpdate::rva0048B256()
{
	int span = m_totalFrames - m_stateCountDown;
	float *objPos = (float *)((char *)m_object + 0x38);
	float radius = (float)(span + span) + m_currentClearingRange;
	float ratio = m_currentClearingRange / m_nativeClearingRange;
	float fade = g_Va00BBB8D8 - ratio;
	float angle = 0.0f;
	RadiusDecal *decal = m_gridDecal;
	int left = 30;
	Coord3D pos;
	pos.z = 0.0f;
	do {
		double c = cos(angle);
		double s = sin(angle);
		double fx = c * (double)radius + (double)objPos[0];
		double fy = s * (double)radius + (double)objPos[1];
		double dx = fx - (double)((int)fx % 23);
		double dy = dx - (double)((int)dx % 23);
		pos.x = (float)dx;
		pos.y = (float)dy;
		decal->setPosition(pos);
		decal->setOpacity(fade);
		angle += 0.20943951f;
		++decal;
	} while (--left != 0);
}
