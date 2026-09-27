// ?didExit@Object@@QAE_NPAVPolygonTrigger@@@Z
// partial score=0.93 date=2026-09-27
// ?didExit@Object@@QAE_NPAVPolygonTrigger@@@Z
// partial score=0.93 date=2026-09-27
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX
//
// Near miss for ?didExit@Object@@QAE_NPAVPolygonTrigger@@@Z @0x0028D757 (63B).
// Twin of didEnter 0x0028D718 (same 63B shape, only exited byte +5 vs entered
// +4 differ). Donor BFME1 Object::didExit (Object.cpp:3010,
// ObjectFields.cpp:572) via didEnterOrExit (rowed 0x0028D6EB).
// Ours is 63B/24 insns, same size/count; only register allocation differs:
// retail this in edx (mov edx,ecx, push esi after call for index in esi);
// ours this in esi (mov esi,ecx, push esi before call, index in edx). Offsets
// match (triggerInfo +0x3C0 stride 8 with exited at +5, num at +0x43A via
// movsx, arg at [esp+8]). Same flag/shape sweep as didEnter gave no flip.

typedef bool Bool;

class PolygonTrigger;

struct TriggerInfo
{
	PolygonTrigger *m_trigger;
	unsigned char m_entered;
	unsigned char m_exited;
	unsigned char m_pad[2];
};

class Object
{
public:
	Bool didExit(PolygonTrigger *trig);

protected:
	Bool didEnterOrExit() const;

private:
	char m_pad00[0x3C0];
	TriggerInfo m_triggerInfo[5];
	char m_pad3E8[0x43A - 0x3C0 - 5 * 8];
	char m_numTriggerAreasActive;
};

Bool Object::didExit(PolygonTrigger *trig)
{
	if (!didEnterOrExit())
		return false;
	for (int i = 0; i < m_numTriggerAreasActive; ++i)
	{
		if (m_triggerInfo[i].m_exited && m_triggerInfo[i].m_trigger == trig)
			return true;
	}
	return false;
}
