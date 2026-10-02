// ?xfer@Rva003A3959@@MAEXPAVXfer@@@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
// ?xfer@Rva003A3959@@MAEXPAVXfer@@@Z @0x003A2AA6 210B: slot 3 xfer of vtable 0x0081ADFC, IsLightCRC early-out then Version1 then count word at +0x14.
// Evidence: chain from rowed 0x003A3959 ctor vtable 81ADFC; Xfer slot 0x10 early-out plus Version1 0x53EE plus slot 0x80 count plus slot 8 branch; store loop via rowed hashtable begin 0x427195 plus XferRelationship 0x305C32; load loop via rowed findSlot 0x41F4E5.
#include <hash_map>
#include <cstddef>

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

void __cdecl XferRelationship(Xfer *xfer, int *value);

class GameWindow;
class WindowVideo;

class WindowVideoManager
{
public:
	struct hashConstGameWindowPtr
	{
		size_t operator()(const GameWindow *p) const;
	};
};

typedef _STL::pair<const GameWindow *const, WindowVideo *> GameWindowVideoPair;
typedef _STL::hashtable<
	GameWindowVideoPair,
	const GameWindow *,
	WindowVideoManager::hashConstGameWindowPtr,
	_STL::_Select1st<GameWindowVideoPair>,
	_STL::equal_to<const GameWindow *>,
	_STL::allocator<GameWindowVideoPair> > GameWindowVideoHashtable;

class ObjectLookupMap
{
public:
	Object **findSlot(int *key);
};

class Rva003A3959
{
public:
	virtual ~Rva003A3959();
	virtual void crc();
	virtual void loadPostProcess();
protected:
	virtual void xfer(Xfer *xfer);
private:
	char m_pad4[0x10];
	unsigned short m_count;
};

// ?xfer@Rva003A3959@@MAEXPAVXfer@@@Z present-unmatched
void Rva003A3959::xfer(Xfer *xfer)
{
	if (xfer->IsLightCRC())
		return;
	xfer->Version1();
	unsigned short cnt = m_count;
	*xfer == cnt;
	if (xfer->IsStoring())
	{
		GameWindowVideoHashtable::iterator it;
		it = ((GameWindowVideoHashtable *)m_pad4)->begin();
		for (; it._M_cur != 0; ++it)
		{
			unsigned int key = (unsigned int)(*it).first;
			*xfer == key;
			int val = (int)(*it).second;
			XferRelationship(xfer, &val);
		}
	}
	else
	{
		for (unsigned short i = 0; i < cnt; ++i)
		{
			unsigned int key;
			*xfer == key;
			int val;
			XferRelationship(xfer, &val);
			int ikey = (int)key;
			Object **slot = ((ObjectLookupMap *)m_pad4)->findSlot(&ikey);
			*slot = (Object *)val;
		}
	}
}
