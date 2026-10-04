// cl: /O1 /MD
// ?xfer@W3DSailModelDraw@@MAEXPAVXfer@@@Z @0x000D0816 72B via slot3 xfer with base W3DScriptedModelDraw plus Version 1 1 plus float 2E8 plus bool 2EC
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
class DamageInfo;

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

class Thing;
class ModuleData;

class W3DScriptedModelDraw
{
protected:
    virtual void xfer(Xfer *xfer);
private:
    unsigned char m_pad[0x2E4];
};

class W3DSailModelDraw : public W3DScriptedModelDraw
{
protected:
    virtual void xfer(Xfer *xfer);
private:
    float m_2E8;
    bool m_flag2EC;
};

void W3DSailModelDraw::xfer(Xfer *xfer)
{
    W3DScriptedModelDraw::xfer(xfer);
    Xfer::Version version(1, 1);
    *xfer == version;
    *xfer == m_2E8;
    *xfer == m_flag2EC;
}
