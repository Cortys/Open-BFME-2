// ?xfer@Rva00342FCD@@MAEXPAVXfer@@@Z
// partial score=0.95 date=2026-09-27
// ?xfer@Rva00342FCD@@MAEXPAVXfer@@@Z
// partial score=0.95 date=2026-09-27
// cl: /O1 /MD
//
// ??0Rva00342FCD@@QAE@PAVStateMachine@@H@Z, retail 0x00342FCD, 37 bytes.
// Chain from 0x0033FE65 (Rva0033FE65 ctor). Derived ctor forwarding
// (machine, 0) to base Rva0033FE65 then storing arg2 at +0x28 then
// installing vtable 0x00812FA0 then zeroing byte at +0x2C. Callers
// 0x003527F3/0x00352823/0x00352855. Layout is base 0x28 plus int plus bool.
// Uses novtable plus explicit store to get store-before-vtable order like
// the State hash ctors.

class StateMachine;

class Xfer;

class Rva0033FE65
{
public:
	Rva0033FE65(StateMachine *machine, int val);
	virtual ~Rva0033FE65();

protected:
	virtual void xfer(Xfer *xfer);

private:
	char m_pad04[0x28 - 0x04];
};

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

class Xfer::Version
{
public:
	Version(unsigned char current, unsigned char minimum)
		: m_current(current), m_minimum(minimum) {}

	unsigned char m_current;
	unsigned char m_minimum;
};

extern "C" char Rva00342FCD_vftable;

class __declspec(novtable) Rva00342FCD : public Rva0033FE65
{
public:
	Rva00342FCD(StateMachine *machine, int val);

protected:
	virtual void xfer(Xfer *xfer);

private:
	int m_28;
	bool m_2C;
};

Rva00342FCD::Rva00342FCD(StateMachine *machine, int val) : Rva0033FE65(machine, 0)
{
	m_28 = val;
	*reinterpret_cast<char **>(this) = &Rva00342FCD_vftable;
	m_2C = false;
}

void Rva00342FCD::xfer(Xfer *xfer)
{
	Rva0033FE65::xfer(xfer);
	Xfer::Version version(1, 1);
	*xfer == version;
	*xfer == m_2C;
}
