// ?rva001FAA8D@Rva001FAA8D@@QAEXPAVXfer@@@Z
// partial score=0.98 date=2026-10-03
// cl: /O1 /MD
// ?rva001FAA8D@Rva001FAA8D@@QAEXPAVXfer@@@Z 0x001FAA8D 145B
// Evidence: chain via rowed 0x001FA7AC; xfer shape with IsLightCRC early-out via slot 0x10 then Version1 via rowed 0x000053EE then base rva001F37C4 on this then m_94 chain call then uint at +0x88 via slot 0x78 then Coord3DBase at +0x48 via slot 0x60 then uints at +0x54/+0x58 via slot 0x78 then ParticleSystemID via rowed XferParticleSystemID 0x0030600A. Xfer declaration copied verbatim from PoisonedBehaviorXfer.cpp (slot-3 recipe). Honest Rva names.
class AsciiString;
class UnicodeString;
class PooledString;
struct XferUnknown11;
class Coord3DBase;
class ICoord3D;
class Region3D;
class IRegion3D;
class Coord2D;
class ICoord2D;
class Region2D;
class IRegion2D;
class RealRange;
class RGBColor;
class RGBAColorReal;
class RGBAColorInt;
class Snapshot;
class Thing;
class ModuleData;
class Object;

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Xfer
{
public:
	class Version;

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

	virtual void SkipBadBlock(Snapshot &snapshot, unsigned int size);
	virtual Xfer &XferRawBytes(void *data, unsigned int size);
	virtual Xfer &operator==(bool &value);
	virtual Xfer &operator==(char &value);
	virtual Xfer &operator==(unsigned char &value);
	virtual Xfer &operator==(short &value);
	virtual Xfer &operator==(unsigned short &value);
	virtual Xfer &operator==(int &value);
	virtual Xfer &operator==(unsigned int &value);
	virtual Xfer &operator==(__int64 &value);
	virtual Xfer &operator==(float &value);
	virtual Xfer &operator==(AsciiString &value);
	virtual Xfer &operator==(UnicodeString &value);
	virtual Xfer &operator==(PooledString &value);
	virtual Xfer &operator==(Coord3DBase &value);
	virtual Xfer &operator==(ICoord3D &value);
	virtual Xfer &operator==(Region3D &value);
	virtual Xfer &operator==(IRegion3D &value);
	virtual Xfer &operator==(Coord2D &value);
	virtual Xfer &operator==(ICoord2D &value);
	virtual Xfer &operator==(Region2D &value);
	virtual Xfer &operator==(IRegion2D &value);
	virtual Xfer &operator==(RealRange &value);
	virtual Xfer &operator==(RGBColor &value);
	virtual Xfer &operator==(RGBAColorReal &value);
	virtual Xfer &operator==(RGBAColorInt &value);
	virtual Xfer &operator==(Snapshot &value);
	virtual Xfer &operator==(XferUnknown11 &value) = 0;
	virtual Xfer &operator==(Version &value);

	virtual Xfer &XferEnum(const char *name, void *data, unsigned int size);

protected:
	virtual void XferData(unsigned int type, void *data, unsigned int size) = 0;
};

void XferParticleSystemID(Xfer *xfer, int *value);

class Coord3DBase
{
public:
	float x;
	float y;
	float z;
};

class ParticleSystem
{
public:
	char m_pad[0xA8];
	int m_a8;
};

ParticleSystem *Make001FCBD7();

struct BfmeParticleSystemHandle
{
	ParticleSystem *m_system;
	void *m_prev;
	void *m_next;
	operator bool() const { return m_system != 0; }
	ParticleSystem *operator->() const
	{
		return m_system ? m_system : Make001FCBD7();
	}
};

class Rva001F37C4
{
public:
	void rva001F37C4(Xfer *xfer);
};

class Rva001FA7AC
{
public:
	void rva001FA7AC(int x);
};

class Rva001FAA8D
{
public:
	void rva001FAA8D(Xfer *xfer);
private:
	char m_pad0[0x48];
	Coord3DBase m_48;
	unsigned int m_54;
	unsigned int m_58;
	char m_pad5C[0x78 - 0x5C];
	BfmeParticleSystemHandle m_78;
	char m_pad84[0x88 - 0x84];
	unsigned int m_88;
	char m_pad8C[0x94 - 0x8C];
};
// ?rva001FAA8D@Rva001FAA8D@@QAEXPAVXfer@@@Z present-unmatched
void Rva001FAA8D::rva001FAA8D(Xfer *xfer)
{
	if (xfer->IsLightCRC())
		return;
	xfer->Version1();
	((Rva001F37C4 *)this)->rva001F37C4(xfer);
	((Rva001FA7AC *)((char *)this + 0x94))->rva001FA7AC((int)xfer);
	*xfer == m_88;
	*xfer == m_48;
	*xfer == m_54;
	*xfer == m_58;
	int id = 0;
	if (m_78)
	{
		_ReadWriteBarrier();
		id = m_78->m_a8;
	}
	XferParticleSystemID(xfer, &id);
}
