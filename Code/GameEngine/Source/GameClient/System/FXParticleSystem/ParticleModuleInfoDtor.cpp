// cl: /O1 /MD
// ??1Rva003AF50D@@UAE@XZ, retail 0x003A983C, 22 bytes.
// Destructor for the Rva003AF50D particle module-info base (copy rowed at
// 0x003AF50D in ParticleModuleInfoCopyCtors.cpp): restores the second-base
// vtable 0x00C1C780 at +0x14 via the null-guarded neg/lea/sbb/and idiom,
// then tail-jmps to the rowed head-base dtor ??1DefaultModuleHeadBase@@UAE@XZ
// at 0x003A57E7. Layout matches the copy (head vptr +0, 12-byte smart at +4,
// int at +0x10, second vptr at +0x14). novtable suppresses the implicit
// derived store so only the manual +0x14 store remains, in retail order.
// Precedent: V3InlineTemplateDtor.cpp uses the same ternary for +8.
// Vtable 0x0081D420 slot 0 is the ??_G at 0x003AE492 which calls here.

class RvaSmartPtr12
{
public:
	RvaSmartPtr12(const RvaSmartPtr12 &other);
	void *m_ptr;
	int m_pad04;
	int m_pad08;
};

class DefaultModuleHeadBase
{
public:
	virtual ~DefaultModuleHeadBase();
	RvaSmartPtr12 m_smart;
	int m_int10;
};

class __declspec(novtable) Rva003AF50D : public DefaultModuleHeadBase
{
public:
	virtual ~Rva003AF50D();
private:
	void *m_v14;
};

Rva003AF50D::~Rva003AF50D()
{
	unsigned char *b14 = this ? (unsigned char *)this + 0x14 : 0;
	*(volatile unsigned int *)b14 = 0x00C1C780;
}
