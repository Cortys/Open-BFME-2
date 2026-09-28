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

class Drawable
{
public:
	void rva00274176(bool immediate);
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
