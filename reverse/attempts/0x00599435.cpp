// ?Rva00599435Insert@@YAPAUKeyframe@@PAU1@IIPAX@Z
// partial score=0.95 date=2026-09-29
// ?Rva00599435Insert@@YAPAUKeyframe@@PAU1@IIPAX@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /GX- /arch:SSE2
// ?Rva00599435Insert@@YAPAUKeyframe@@PAU1@IIPAX@Z 0x00599435 49B
// Sorted Keyframe insert: shift 8B elements down while value > prev, then store value+frame.
// Evidence: callers 0x5994BC 0x599A16 with 4 pushes and add esp 0x10; Keyframe layout from FXParticleSystem.cpp.
struct Keyframe
{
	float m_value;
	unsigned int m_frame;
};

Keyframe *__cdecl Rva00599435Insert(Keyframe *dst, unsigned int valueBits, unsigned int frame, void *unused)
{
	float value = *(float *)&valueBits;
	Keyframe *p = dst;
	Keyframe *q = p - 1;
loop:
	if (!(value > q->m_value))
		goto done;
	*p = *q;
	p = q;
	--q;
	goto loop;
done:
	*(unsigned int *)&p->m_value = valueBits;
	p->m_frame = frame;
	return p;
}
