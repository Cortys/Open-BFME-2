// ?tossEmitters@W3DTankDraw@@IAEXXZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /MD
// ?tossEmitters@W3DTankDraw@@IAEXXZ @0x000CE7B4 131B: two-handle toss of debris emitters at +0x2E8/+0x2F4; ported from BFME1 W3DTankDraw.cpp tossEmitters with BFME2 12B handles; volatile get preserves Make chases like W3DTankTruckDraw 0xCB5C3; callees rowed Make001FCBD7 set 0x1F3C43 destroy 0x1F462C handle-dtor 0x4CBC0; caller 0xCEA39 slot1
// ?tossEmitters@W3DTankDraw@@IAEXXZ present-unmatched
struct Rva001F3C43Arg {
	char m_pad[0x74];
	int m_value;
};
class Rva001F3C43Slot {
public:
	void set(const Rva001F3C43Arg *arg);
};
class ParticleSystem : public Rva001F3C43Slot {
public:
	void destroy();
};
ParticleSystem *Make001FCBD7();
struct BfmeParticleSystemHandle {
	~BfmeParticleSystemHandle();
	ParticleSystem *volatile m_system;
	void *m_prev;
	void *m_next;
};
class W3DTankDraw {
protected:
	void tossEmitters();
	char m_pad0[0x2E8];
	BfmeParticleSystemHandle m_debrisLeft;
	BfmeParticleSystemHandle m_debrisRight;
};
void W3DTankDraw::tossEmitters()
{
	if (m_debrisLeft.m_system) {
		ParticleSystem *p = m_debrisLeft.m_system;
		if (!p)
			p = Make001FCBD7();
		p->set(0);
		ParticleSystem *q = m_debrisLeft.m_system;
		if (!q)
			q = Make001FCBD7();
		q->destroy();
		if (m_debrisLeft.m_system) {
			m_debrisLeft.~BfmeParticleSystemHandle();
			m_debrisLeft.m_system = 0;
		}
	}
	if (m_debrisRight.m_system) {
		ParticleSystem *r = m_debrisRight.m_system;
		if (!r)
			r = Make001FCBD7();
		r->set(0);
		ParticleSystem *s = m_debrisRight.m_system;
		if (!s)
			s = Make001FCBD7();
		s->destroy();
		if (m_debrisRight.m_system) {
			m_debrisRight.~BfmeParticleSystemHandle();
			m_debrisRight.m_system = 0;
		}
	}
}
