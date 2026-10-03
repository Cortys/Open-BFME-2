// ?rva0027434D@Drawable@@QAEHH@Z
// partial score=0.96 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc /Oy- /G7
//
// ?rva00274176@Drawable@@QAEX_N@Z, retail 0x00274176, 104 bytes.
// Drawable apply-pending over condition state at this+0x258 via rowed helper
// 0x00271C8A plus iface vector at this+0x158/0x15C with dirty flag at +0x443.
// Evidence: BFME1 DrawableBFME.cpp applyPendingModelConditionFlags donor plus
// pending clear at +0x2A4 and pending set at +0x2F0 via caller 0x002761F3 plus
// sibling flush shapes 0x0027434D and 0x00275376 plus 27 unblocked callers.
//
class Rva00271C8A
{
public:
	void rva00271C8A(const int *a, const int *b);
	int m_bits[19];
};

class BfmeDrawableClientIface
{
public:
	virtual void replaceModelConditionState(const void *state, bool immediate, int effect);
};

void *__cdecl ji_006291ae(void *dest, int val, unsigned int count);
#pragma comment(linker, "/alternatename:?ji_006291ae@@YAPAXPAXHI@Z=?ji_006291ae@@YAXXZ")

class ElemA274445
{
public:
	virtual void _00() = 0;
	virtual void _01() = 0;
	virtual void _02() = 0;
	virtual void _03() = 0;
	virtual void _04() = 0;
	virtual void _05() = 0;
	virtual void _06() = 0;
	virtual void _07() = 0;
	virtual void _08() = 0;
	virtual void _09() = 0;
	virtual void _10() = 0;
	virtual void _11() = 0;
	virtual void _12() = 0;
	virtual void _13() = 0;
	virtual void _14() = 0;
	virtual void _15() = 0;
	virtual void _16() = 0;
	virtual void _17() = 0;
	virtual void _18() = 0;
	virtual void _19() = 0;
	virtual void _20() = 0;
	virtual void _21() = 0;
	virtual void _22() = 0;
	virtual void _23() = 0;
	virtual void _24() = 0;
	virtual void _25() = 0;
	virtual void _26() = 0;
	virtual void _27() = 0;
	virtual void _28() = 0;
	virtual void _29() = 0;
	virtual void _30() = 0;
	virtual void _31() = 0;
	virtual void _32() = 0;
	virtual void _33() = 0;
	virtual void _34() = 0;
	virtual void _35() = 0;
	virtual void _36() = 0;
	virtual void _37() = 0;
	virtual void _38() = 0;
	virtual void _39() = 0;
	virtual void _40() = 0;
	virtual void _41() = 0;
	virtual void *slot42() = 0;
};

class ElemB274445
{
public:
	virtual void _00() = 0;
	virtual void _01() = 0;
	virtual void _02() = 0;
	virtual void _03() = 0;
	virtual void _04() = 0;
	virtual void _05() = 0;
	virtual void _06() = 0;
	virtual void _07() = 0;
	virtual void _08() = 0;
	virtual void _09() = 0;
	virtual void _10() = 0;
	virtual void _11() = 0;
	virtual void _12() = 0;
	virtual void _13() = 0;
	virtual void _14() = 0;
	virtual void _15() = 0;
	virtual void _16() = 0;
	virtual void _17() = 0;
	virtual void _18() = 0;
	virtual void _19() = 0;
	virtual void slot20(float f) = 0;
};

class ElemB27434D
{
public:
	virtual void _00() = 0;
	virtual void _01() = 0;
	virtual void _02() = 0;
	virtual void _03() = 0;
	virtual void _04() = 0;
	virtual void _05() = 0;
	virtual void _06() = 0;
	virtual void _07() = 0;
	virtual void _08() = 0;
	virtual void _09() = 0;
	virtual void _10() = 0;
	virtual void _11() = 0;
	virtual void _12() = 0;
	virtual void _13() = 0;
	virtual void _14() = 0;
	virtual void _15() = 0;
	virtual void _16() = 0;
	virtual void _17() = 0;
	virtual void _18() = 0;
	virtual void _19() = 0;
	virtual void _20() = 0;
	virtual void _21() = 0;
	virtual void _22() = 0;
	virtual int slot23(int x) = 0;
};

class Drawable
{
public:
	void rva00274176(bool immediate);
	void rva00274445(float f);
	int rva0027434D(int x);
private:
	unsigned char m_pad0[0x158];
	BfmeDrawableClientIface **m_ifaceBegin;
	BfmeDrawableClientIface **m_ifaceEnd;
	unsigned char m_pad1[0x258 - 0x160];
	Rva00271C8A m_conditionState;
	Rva00271C8A m_pendingClear;
	Rva00271C8A m_pendingSet;
	unsigned char m_pad2[0x443 - 0x33C];
	bool m_isModelDirty;
};

void Drawable::rva00274176(bool immediate)
{
	if (!m_isModelDirty && !immediate) {
		return;
	}
	m_conditionState.rva00271C8A(m_pendingClear.m_bits, m_pendingSet.m_bits);
	BfmeDrawableClientIface **end = m_ifaceEnd;
	for (BfmeDrawableClientIface **p = m_ifaceBegin; p != end; ++p) {
		(*p)->replaceModelConditionState(&m_conditionState, immediate, 0);
	}
	m_isModelDirty = false;
}

#pragma optimize("y", on)
void Drawable::rva00274445(float f)
{
	void **arr = *(void ***)((char *)this + 0x14c);
	for (void **p = arr; *p != 0; ++p) {
		ElemA274445 *elem = (ElemA274445 *)*p;
		void *obj = elem->slot42();
		if (obj != 0)
			((ElemB274445 *)obj)->slot20(f);
	}
	ji_006291ae((char *)this + 0x2f0, 0, 0x4c);
	ji_006291ae((char *)this + 0x2a4, 0, 0x4c);
}
#pragma optimize("", on)

// ?rva0027434D@Drawable@@QAEHH@Z present-unmatched
#pragma optimize("y", on)
int Drawable::rva0027434D(int x)
{
	if (m_isModelDirty) {
		m_conditionState.rva00271C8A(m_pendingClear.m_bits, m_pendingSet.m_bits);
		BfmeDrawableClientIface **end = m_ifaceEnd;
		for (BfmeDrawableClientIface **p = m_ifaceBegin; p != end; ++p) {
			(*p)->replaceModelConditionState(&m_conditionState, false, 0);
		}
		m_isModelDirty = false;
	}
	void **arr = *(void ***)((char *)this + 0x14c);
	for (void **p = arr; *p != 0; ++p) {
		ElemA274445 *elem = (ElemA274445 *)*p;
		void *obj = elem->slot42();
		int r = (obj == 0) ? 0 : ((ElemB27434D *)obj)->slot23(x);
		if (r != 0)
			return r;
	}
	return 0;
}
#pragma optimize("", on)
