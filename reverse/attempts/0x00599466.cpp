// ?Rva00599466HeapSiftUp@@YAXPAUKeyframe@@HHMIH@Z
// partial score=0.9 date=2026-09-30
// ?Rva00599466HeapSiftUp@@YAXPAUKeyframe@@HHMIH@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /GX- /arch:SSE2
// ?Rva00599466HeapSiftUp@@YAXPAUKeyframe@@HHMIH@Z @0x00599466 69B: heap
// sift-up for Keyframe array (float value plus frame). Parent is
// (hole-1)/2 with cdq/sub/sar; shifts while parent value > new value.
// Evidence: movss/comiss/xmm0 plus cdq/sub/sar divide plus 8-byte element
// moves plus caller 0x005994CF pushing 6 with add esp 0x18 (cdecl); Keyframe
// layout per FXParticleSystem.cpp; neighbours 0x005993CD/0x00599F51.
struct Keyframe
{
	float m_value;
	unsigned int m_frame;
};

// ?Rva00599466HeapSiftUp@@YAXPAUKeyframe@@HHMIH@Z present-unmatched
void __cdecl Rva00599466HeapSiftUp(Keyframe *keys, int index, int start, float value, unsigned int frame, int unused)
{
	int hole = index;
	int parent = hole - 1;
	parent /= 2;
	while (hole > start)
	{
		float parentVal = keys[parent].m_value;
		if (parentVal <= value)
			break;
		keys[hole] = keys[parent];
		hole = parent;
		parent = hole - 1;
		parent /= 2;
	}
	keys[hole].m_value = value;
	keys[hole].m_frame = frame;
}
