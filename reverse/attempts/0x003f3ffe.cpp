// ?rva003F3FFE@Rva003F3FFE@@QAEXAAVXfer@@@Z
// partial score=0.93 date=2026-09-30
// ?rva003F3FFE@Rva003F3FFE@@QAEXAAVXfer@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva003F3FFE@Rva003F3FFE@@QAEXAAVXfer@@@Z @0x003F3FFE 152B
// LivingWorld player-ref xfer: Version(1,1) + 4 ints + IsLoading-gated
// PlayerID resolve via singleton find, else store path.
// Evidence: 152B ebp frame ret 4; Xfer 0x28 (Version) + 4x 0x7C (int) +
// 0x04 (IsLoading); rowed XferLivingWorldPlayerID 0x2034C4 + rowed find
// 0x2B51F8; unblocks 0x3F5CA9; caller 0x3F5D22.
class Snapshot;
struct XferUnknown11;
class AsciiString;
class UnicodeString;
class PooledString;
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
class Thing;
class ModuleData;
class Object;
class DamageInfo;

class Xfer
{
public:
    class Version
    {
    public:
        unsigned char data[2];
    };

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
    virtual Xfer &operator==(char &value);
    virtual Xfer &operator==(unsigned char &value);
    virtual Xfer &operator==(short &value);
    virtual Xfer &operator==(unsigned short &value);
    virtual Xfer &operator==(int &value);
    virtual Xfer &operator==(unsigned int &value);
    virtual Xfer &operator==(__int64 &value);
    virtual Xfer &operator==(float &value);
    virtual Xfer &operator==(class AsciiString &value);
    virtual Xfer &operator==(class UnicodeString &value);
    virtual Xfer &operator==(class PooledString &value);
    virtual Xfer &operator==(class Coord3DBase &value);
    virtual Xfer &operator==(class ICoord3D &value);
    virtual Xfer &operator==(class Region3D &value);
    virtual Xfer &operator==(class IRegion3D &value);
    virtual Xfer &operator==(class Coord2D &value);
    virtual Xfer &operator==(class ICoord2D &value);
    virtual Xfer &operator==(class Region2D &value);
    virtual Xfer &operator==(class IRegion2D &value);
    virtual Xfer &operator==(class RealRange &value);
    virtual Xfer &operator==(class RGBColor &value);
    virtual Xfer &operator==(class RGBAColorReal &value);
    virtual Xfer &operator==(class RGBAColorInt &value);
    virtual Xfer &operator==(class Snapshot &value);
    virtual Xfer &operator==(XferUnknown11 &value) = 0;
    virtual Xfer &operator==(Version &value);

    virtual Xfer &XferEnum(const char *name, void *data, unsigned int size);

protected:
    virtual void XferData(unsigned int type, void *data, unsigned int size) = 0;
};

void XferLivingWorldPlayerID(Xfer *xfer, int *playerID);

class Rva002E2903Player;
class Rva002BA8F1Logic
{
public:
    Rva002E2903Player *find(int id, unsigned int *index);
};
extern Rva002BA8F1Logic *g_009FEF10;

class Rva003F3FFE
{
public:
    void rva003F3FFE(Xfer &xfer);

private:
    Rva002E2903Player *m_player0;
    int m_a4;
    int m_b8;
    int m_cC;
    int m_d10;
};

// ?rva003F3FFE@Rva003F3FFE@@QAEXAAVXfer@@@Z present-unmatched
void Rva003F3FFE::rva003F3FFE(Xfer &xfer)
{
    Xfer::Version v;
    v.data[0] = 1;
    v.data[1] = 1;
    xfer == v;
    xfer == m_a4;
    xfer == m_b8;
    xfer == m_cC;
    xfer == m_d10;
    if (xfer.IsLoading())
    {
        int id;
        XferLivingWorldPlayerID(&xfer, &id);
        m_player0 = g_009FEF10->find(id, 0);
    }
    else
    {
        int pid = -1;
        Rva002E2903Player *p = m_player0;
        if (p != 0)
            pid = *(int *)((char *)p + 0x14);
        XferLivingWorldPlayerID(&xfer, &pid);
    }
}
