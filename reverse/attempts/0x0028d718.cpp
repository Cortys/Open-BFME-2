// ?didEnter@Object@@QAE_NPAVPolygonTrigger@@@Z
// partial score=0.93 date=2026-09-27
// ?didEnter@Object@@QAE_NPAVPolygonTrigger@@@Z
// partial score=0.93 date=2026-09-27
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX
//
// Near miss for ?didEnter@Object@@QAE_NPAVPolygonTrigger@@@Z @0x0028D718 (63B).
// Donor BFME1 Object::didEnter (Object.cpp:2990, ObjectFields.cpp:557) via
// didEnterOrExit (rowed 0x0028D6EB) then triggerInfo scan. Same TU shape as
// didExit 0x0028D757 (only +4 entered vs +5 exited differ).
// Ours is 63B/24 insns, same size/count as retail; only register allocation
// differs: retail keeps this in edx (mov edx,ecx, no push before call, push
// esi after for the loop index in esi); ours keeps this in esi (mov esi,ecx,
// push esi before call, loop index in edx). All offsets match (triggerInfo
// +0x3C0 stride 8 with entered at +4, num at +0x43A via movsx, arg at
// [esp+8] after push). Tried /O1 /O2 /G7 /Os and local-shape variants (extra
// cnt local, Int vs int, Bool vs uchar) with no change; flags do not flip the
// this/index assignment.

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
	Bool didEnter(PolygonTrigger *trig);

protected:
	Bool didEnterOrExit() const;

private:
	char m_pad00[0x3C0];
	TriggerInfo m_triggerInfo[5];
	char m_pad3E8[0x43A - 0x3C0 - 5 * 8];
	char m_numTriggerAreasActive;
};

Bool Object::didEnter(PolygonTrigger *trig)
{
	if (!didEnterOrExit())
		return false;
	for (int i = 0; i < m_numTriggerAreasActive; ++i)
	{
		if (m_triggerInfo[i].m_entered && m_triggerInfo[i].m_trigger == trig)
			return true;
	}
	return false;
}
