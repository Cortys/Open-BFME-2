// ?rva005F0647@Rva005F0647@@QAEPAXI@Z @0x005F0647 37B.
// Deleting-dtor shape: releases holder target via rowed fastcall Release at 0x0007DEEF
// then conditionally deletes this when flag bit0 is set and returns this.
// Unblocks 0x005F0C39. TU-local honest-address views.
// cl: /O1 /MD
struct TargetRef00217D4C { virtual void *destroy(unsigned int); int references; };
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *);
void operator delete(void *);
struct Rva005F0647Holder { char pad[4]; TargetRef00217D4C target; };
struct Rva005F0647 { Rva005F0647Holder *holder; void *rva005F0647(unsigned int); };
void *Rva005F0647::rva005F0647(unsigned int flags)
{
    if (holder)
        ReleaseTreeHintRef00217D4C(&holder->target);
    if (flags & 1)
        ::operator delete(this);
    return this;
}

void Rva005F0C39Destroy(Rva005F0647 *begin, Rva005F0647 *end)
{
    for (; begin != end; ++begin)
        begin->rva005F0647(0);
}

class UnicodeString
{
public:
	UnicodeString(const UnicodeString &o) throw() : m_data(o.m_data) {}
	~UnicodeString() throw() {}
	void *m_data;
};

struct RGBColor { float red, green, blue; };

class Mouse
{
public:
	void rva001EEA6D(UnicodeString tooltip, int delay, const RGBColor *color, float width) throw();
};

class GameTextInterface
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
	virtual void v30(); virtual void v34(); virtual void v38();
	virtual UnicodeString fetch(const char *label, bool *exists = 0) throw();
};

#define TheGameText (*(GameTextInterface **)0x00DFF0BC)
#define TheMouse (*(Mouse **)0x00DFDCA0)

struct Rva005F06EF
{
	char m_pad[0x2D];
	bool m_flag;
	void rva005F06EF();
};

void Rva005F06EF::rva005F06EF()
{
	if (m_flag)
		TheMouse->rva001EEA6D(TheGameText->fetch((const char *)0x00C78CB8), -1, 0, 1.0f);
}
