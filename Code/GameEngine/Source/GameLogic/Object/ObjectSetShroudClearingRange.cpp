// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?setShroudClearingRange@Object@@QAEXM@Z, retail 0x0028BB65, 33 bytes.
// Object::setShroudClearingRange writes the float at +0x1B4 when it differs
// and calls makeDirty. Evidence: BFME1 donor Object.cpp:5648 same if-differ
// plus makeDirty shape with +0x198/+0x3B0; BFME2 +0x1B4 proven by the pinned
// ?getShroudClearingRange@Object@@QBEMXZ at 0x0028DE87 reading [esi+0x1B4];
// partition makeDirty at +0x4C4 via the rowed ?makeDirty@Object@@QAEXXZ;
// callers at 0x00497ADE 0x00493938 pass ModuleData floats then refresh cells.
class Object
{
public:
	void setShroudClearingRange(float value);
	void makeDirty();

private:
	char m_pad[0x1B4];
	float m_shroudClearingRange;
};

void Object::setShroudClearingRange(float value)
{
	if (value != m_shroudClearingRange)
	{
		m_shroudClearingRange = value;
		makeDirty();
	}
}
