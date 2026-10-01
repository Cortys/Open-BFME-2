// ??0Locomotor@@QAE@PBVLocomotorTemplate@@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Locomotor@@QAE@PBVLocomotorTemplate@@@Z @0x005C96EB 104B
// Locomotor ctor: base 0x313847 rowed BfmeAptScreenBase plus member 0x524B7A rowed Rva00524B7A; vtable g_00C74B70; caller newLocomotor 0x5C9886; BFME1 donor LocomotorConstructor.cpp
class LocomotorTemplate;

class BfmeAptScreenBase
{
public:
	BfmeAptScreenBase(void *ctx);
	~BfmeAptScreenBase();
	virtual void slot0();
protected:
	void *m_anchor;
	int m_status;
private:
	char m_rest[0x20C];
};

class Rva00524B7A
{
public:
	Rva00524B7A();
private:
	void *m_vtable;
	char m_basePad[8];
	void *m_0C;
	int m_10;
	int m_14;
	int m_18;
	int m_1C;
	int m_20;
	unsigned char m_24;
	char m_pad25[3];
	int m_28;
	int m_2C;
	int m_30;
	int m_34;
	int m_38;
};

extern const void *const g_00C74B70[];

class Locomotor : public BfmeAptScreenBase
{
public:
	Locomotor(const LocomotorTemplate *tmpl);
private:
	Rva00524B7A m_218;
	int m_254;
	int m_258;
	int m_25C;
	int m_260;
	int m_264;
	unsigned char m_268;
	char m_pad[3];
};

// ??0Locomotor@@QAE@PBVLocomotorTemplate@@@Z present-unmatched
Locomotor::Locomotor(const LocomotorTemplate *tmpl) : BfmeAptScreenBase((void *)tmpl)
{
	m_258 = 0;
	m_25C = 0;
	m_260 = 0;
	m_264 = 0;
	m_status |= 0x640;
	m_254 = m_status;
	m_268 = 0;
}
