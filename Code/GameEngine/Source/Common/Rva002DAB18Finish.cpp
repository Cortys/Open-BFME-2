// ??0Rva002DAB18@@QAE@XZ
// partial score=0.97 date=2026-09-30
// cl: /O1 /EHsc /MD
//
// ??0Rva002DAB18@@QAE@XZ @0x002DAB18 (70B):
// Multiple-inheritance ctor: primary base SnapBase at +0 installs vtable
// 0x00BBB554 in line, secondary base SubsystemInterface at +4 is constructed
// by the pinned base ctor 0x001B4E63 (twin ??0SubsystemInterface@@QAE@XZ),
// then the derived vtables 0x00C03910 at +0 and 0x00C039A0 at +4 and the
// +0x10 member. Caller 0x00091A83.
// Finishing levers vs the banked attempt: the +4 subobject is a real secondary
// base (its ctor is the pinned 0x001B4E63), so the compiler emits the derived
// vptr stores itself; SnapBase's out-of-line dtor forces the EH prologue, which
// puts the ecx restore right after the base call; and the +0x10 member is a
// struct with an inline zeroing ctor so its store is ordered after the vptr
// stores instead of being hoisted above them.
class SnapBase
{
public:
	virtual void keep();
	virtual ~SnapBase();
};
class SubsystemInterface
{
public:
	SubsystemInterface();
	virtual ~SubsystemInterface();
private:
	char m_pad04[8];
};
struct IntZero
{
	int m_value;
	IntZero() : m_value(0) {}
};
class Rva002DAB18 : public SnapBase, public SubsystemInterface
{
public:
	Rva002DAB18();
	virtual ~Rva002DAB18();
private:
	IntZero m_10;
};
Rva002DAB18::Rva002DAB18()
{
}
