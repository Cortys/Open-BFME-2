// ??0Rva0055BF4B@@QAE@ABVRvaSmartPtr12@@PBURva0055BF4BSrc@@@Z
// partial score=0.93 date=2026-10-03
// cl: /DNDEBUG /MD /EHsc /O1 /Ob2 /arch:SSE
// ??0Rva0055BF4B@@QAE@ABVRvaSmartPtr12@@PBURva0055BF4BSrc@@@Z @0x0055BF4B 181B
// Ctor via rowed base 0x0055BF21 plus member 0x0055BC39 plus 8x struct copy plus rowed setRange.
// Evidence: thiscall 2 args ret 8; calls rowed ??0Rva0055BF21@@QAE@ABVRvaSmartPtr12@@H@Z 0x0055BF21 and ??0DefaultColorModuleInfo@FXParticleSystem@@QAE@XZ 0x0055BC39 and ?setRange@GameClientRandomVariable@@QAEXMMW4DistributionType@1@@Z 0x002341E7; vtable VA 0x00C1D60C plus member VA 0x00C1D628 plus s_slot3E4first; caller 0x003ABCC0; neighbours 0x0055BF21 0x0055C000 same FXParticleSystem.
class RvaSmartPtr12
{
public:
	RvaSmartPtr12(const RvaSmartPtr12 &that);
	~RvaSmartPtr12();
private:
	void *m_ptr;
	int m_pad04;
	int m_pad08;
};

class Rva0055BF21
{
public:
	Rva0055BF21(const RvaSmartPtr12 &smart, int i);
	virtual ~Rva0055BF21();
private:
	char m_pad[0x1C - 4];
};

namespace FXParticleSystem
{
class Xfer;
class Snapshot
{
public:
	Snapshot() {}
	Snapshot(const Snapshot &that);
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer) {}
	virtual void loadPostProcess() {}
	virtual void xfer(Xfer *xfer) {}
};
class RGBColorKeyframe
{
public:
	RGBColorKeyframe();
private:
	char m_data[0x10];
};
class GameClientRandomVariable
{
public:
	enum DistributionType { CONSTANT, UNIFORM, GAUSSIAN, TRIANGULAR, LOW_BIAS, HIGH_BIAS };
	GameClientRandomVariable();
	void setRange(float low, float high, DistributionType type = UNIFORM);
private:
	DistributionType m_type;
	float m_low;
	float m_high;
};
class DefaultColorModuleInfo : public Snapshot
{
public:
	DefaultColorModuleInfo();
	virtual ~DefaultColorModuleInfo();
public:
	RGBColorKeyframe m_keys[8];
	GameClientRandomVariable m_trailing;
};
}

struct Rva0055BF4BSrcElem
{
	char m_data[0x10];
};

struct Rva0055BF4BSrc
{
	char m_pad[0x0C];
	Rva0055BF4BSrcElem m_elems[8];
	char m_pad2[0x04];
	float m_f90;
	float m_f94;
};

extern const void *const g_00C1D60C[];
extern const void *const g_00C1D628[];
extern "C" char s_slot3E4first[2];
extern const float g_00BBB8F0;

class Rva0055BF4B : public Rva0055BF21
{
public:
	Rva0055BF4B(const RvaSmartPtr12 &smart, const Rva0055BF4BSrc *src);
	~Rva0055BF4B();
private:
	FXParticleSystem::DefaultColorModuleInfo m_member;
};

// ??0Rva0055BF4B@@QAE@ABVRvaSmartPtr12@@PBURva0055BF4BSrc@@@Z present-unmatched
Rva0055BF4B::Rva0055BF4B(const RvaSmartPtr12 &smart, const Rva0055BF4BSrc *src)
	: Rva0055BF21(smart, (int)src)
{
	*(const void **)this = g_00C1D60C;
	*(void **)((char *)this + 0x14) = (void *)&s_slot3E4first[0];
	*(void **)((char *)this + 0x18) = (void *)(&s_slot3E4first[1] - 1);
	*(const void **)&m_member = g_00C1D628;
	for (int i = 0; i < 8; ++i)
		m_member.m_keys[i] = (const FXParticleSystem::RGBColorKeyframe &)src->m_elems[i];
	m_member.m_trailing.setRange(src->m_f90 * g_00BBB8F0, src->m_f94 * g_00BBB8F0);
}
