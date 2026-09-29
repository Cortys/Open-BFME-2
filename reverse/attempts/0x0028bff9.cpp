// ?rva0028BFF9@Object@@QAEXI@Z
// partial score=0.88 date=2026-09-29
// ?rva0028BFF9@Object@@QAEXI@Z
// partial score=0.88 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
// ?rva0028BFF9@Object@@QAEXI@Z, RVA 0x0028BFF9, 38 bytes.
// Object method: private-status bit1 via rowed rva0028AC34 0x0028AC34 from
// (arg > 0) via seta, then helper at +0x238 via rowed
// ObjectDefectionHelper::rva004DF725 0x004DF725 with (arg, false).
// Evidence: cmp [esp+4]0 seta push call plus mov ecx[ecx+238] test je plus
// push 0 push arg call plus ret4 plus caller at 0x001F2620. Flags from
// Object neighbours ObjectLeaveGroup.cpp.
class ObjectDefectionHelper
{
public:
	void rva004DF725(unsigned int arg1, bool arg2);
};

class Object
{
public:
	void rva0028BFF9(unsigned int arg);
	void rva0028AC34(bool on);

private:
	unsigned char m_pad00[0x238];
	ObjectDefectionHelper *m_helper238; // +0x238
};

// ?rva0028BFF9@Object@@QAEXI@Z present-unmatched
void Object::rva0028BFF9(unsigned int arg)
{
	rva0028AC34(arg > 0);
	ObjectDefectionHelper *helper = m_helper238;
	if (helper)
		helper->rva004DF725(arg, false);
}
