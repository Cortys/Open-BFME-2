// ?xfer@W3DTornadoDraw@@MAEXPAVXfer@@@Z
// partial score=0.95 date=2026-09-29
// ?xfer@W3DTornadoDraw@@MAEXPAVXfer@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD
// ?xfer@W3DTornadoDraw@@MAEXPAVXfer@@@Z @0x000D1776 68B slot 3 of 0x007CE218 base DrawModule::xfer then bool then decal list via 0x00330F7D
// stlport
#include <list>
class Thing;
class ModuleData;
class Xfer
{
public:
	Xfer();
	virtual ~Xfer();
	void Version1();
	virtual bool IsLoading() const;
	virtual bool IsStoring() const;
	virtual bool IsCRC() const;
	virtual bool IsLightCRC() const;
	virtual void v5() = 0;
	virtual void v6() = 0;
	virtual void v7() = 0;
	virtual void SkipBadBlock(class Snapshot &snapshot, unsigned int size);
	virtual Xfer &XferRawBytes(void *data, unsigned int size);
	virtual Xfer &operator==(bool &value);
};
class DrawModule
{
protected:
	virtual void xfer(Xfer *xfer);
private:
	char m_pad08[8];
};
class RadiusDecal
{
public:
	void rva00330F7D(Xfer *xfer);
};
class Rva000B19A1 : public DrawModule
{
public:
	Rva000B19A1(Thing *thing, const ModuleData *moduleData);
	virtual ~Rva000B19A1();
};
class W3DTornadoDraw : public Rva000B19A1
{
public:
	W3DTornadoDraw(Thing *thing, const ModuleData *moduleData);
protected:
	virtual void xfer(Xfer *xfer);
private:
	_STL::list<int> m_boneIndices;
};
// ?xfer@W3DTornadoDraw@@MAEXPAVXfer@@@Z present-unmatched
void W3DTornadoDraw::xfer(Xfer *xfer)
{
	DrawModule::xfer(xfer);
	struct TwoBools { bool a; bool b; } s = { true, true };
	*xfer == s.a;
	for (_STL::list<int>::iterator it = m_boneIndices.begin(); it != m_boneIndices.end(); ++it) {
		RadiusDecal *decal = reinterpret_cast<RadiusDecal *>(*it);
		decal->rva00330F7D(xfer);
	}
}
