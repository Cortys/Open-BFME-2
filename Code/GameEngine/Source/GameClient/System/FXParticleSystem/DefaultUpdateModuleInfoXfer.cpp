// cl: /O1 /MD
// ?xfer@DefaultUpdateModuleInfo@FXParticleSystem@@UAEXPAVXfer@@@Z, retail 0x0055F67C, 148 bytes.
// Evidence: vtable slot 3 of 0x0081BCE0 (DefaultUpdateModuleInfo) DoXfer;
//   8 GameClientRandomVariable plus rotation-typed extra at +0x40.

class Xfer
{
public:
	virtual void r0();
	virtual void r1();
	virtual bool isSaving();
	virtual void r3();
	virtual bool r4();
	virtual void r5();
	virtual void r6();
	virtual void r7();
	virtual void r8();
	virtual void r9();
	virtual void xferVersion(unsigned char *version);
	void Version1();
};

class GameClientRandomVariable
{
public:
	int m_type;
	float m_low;
	float m_high;
};

Xfer &xferRandomVariable(Xfer &xfer, GameClientRandomVariable &var);
void XferRotationType(Xfer *xfer, int *value);

namespace FXParticleSystem
{

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc();
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};

class DefaultUpdateModuleInfo : public Snapshot
{
public:
	DefaultUpdateModuleInfo();
	virtual ~DefaultUpdateModuleInfo();
	virtual void xfer(Xfer *xfer);
private:
	GameClientRandomVariable m_var0;
	GameClientRandomVariable m_var1;
	GameClientRandomVariable m_var2;
	GameClientRandomVariable m_var3;
	GameClientRandomVariable m_var4;
	int m_extra;
	GameClientRandomVariable m_var5;
	GameClientRandomVariable m_var6;
	GameClientRandomVariable m_var7;
};

}

void FXParticleSystem::DefaultUpdateModuleInfo::xfer(Xfer *xfer)
{
	if (xfer->r4())
		return;
	union Ver { int i; unsigned char b[4]; } ver;
	ver.b[0] = 1;
	ver.b[1] = 2;
	xfer->xferVersion(&ver.b[0]);
	xferRandomVariable(*xfer, m_var0);
	xferRandomVariable(*xfer, m_var1);
	xferRandomVariable(*xfer, m_var2);
	xferRandomVariable(*xfer, m_var3);
	xferRandomVariable(*xfer, m_var4);
	XferRotationType(xfer, &m_extra);
	if (ver.b[1] < 2)
		return;
	xferRandomVariable(*xfer, m_var5);
	xferRandomVariable(*xfer, m_var6);
	xferRandomVariable(*xfer, m_var7);
}

class Rva0055F710
{
public:
	virtual void rva0055F710(Xfer *xfer);
private:
	unsigned char m_pad[0x18];
	FXParticleSystem::DefaultUpdateModuleInfo m_info;
};

void Rva0055F710::rva0055F710(Xfer *xfer)
{
	xfer->Version1();
	m_info.FXParticleSystem::DefaultUpdateModuleInfo::xfer(xfer);
}
