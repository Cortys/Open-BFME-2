// ?Rva003064CBXfer@@YAXPAVXfer@@PAI@Z
// partial score=0.96 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc
// ?Rva003064CBXfer@@YAXPAVXfer@@PAI@Z present-unmatched
// Retail 0x003064CB 350B: upgrade-bitmask helper called from 5 free functions.
// Evidence: Version1 row 0x000053EE plus IsStoring slot 0x08 guard (store vs
// load), TheUpgradeCenter global _TheUpgradeCenter, findUpgrade row 0x0026F26D,
// getFirstTemplate ICF-twin of getParticleType row 0x001DB0A8 at +0x0C,
// AsciiString set row 0x000366F0 plus releaseBuffer row 0x00036410,
// _bfmeFormatText row 0x0060C36E plus _CxxThrowException pin plus
// g_guardTargetTypeThrowInfo, memset 0x80 bytes via import thunk.
#include "ascii_string.h"
#include <cstring>

class Xfer;
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

class UpgradeTemplate
{
public:
	char m_pad0[8]; // +0x00 so m_name lands at +0x08 per retail lea [esi+8]
	AsciiString m_name; // +0x08
	char m_pad1[0x38 - 0x0C]; // +0x0C..0x37
	unsigned int m_bitIndex; // +0x38
	char m_pad2[0x64 - 0x3C]; // +0x3C..0x63
	UpgradeTemplate *m_next; // +0x64
};

class UpgradeCenter
{
public:
	const UpgradeTemplate *findUpgrade(const AsciiString &name) const;
	const UpgradeTemplate *getFirstTemplate() const;
};

extern "C" UpgradeCenter *TheUpgradeCenter;
extern "C" void __cdecl _bfmeFormatText(char *buf, const char *fmt, int dummy);
extern int g_guardTargetTypeThrowInfo;
struct _s__ThrowInfo;
extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);

namespace FXParticleSystem
{
class ParticleSystemTemplate
{
public:
	int getParticleType() const;
};
}

// ?Rva003064CBXfer@@YAXPAVXfer@@PAI@Z
void __cdecl Rva003064CBXfer(Xfer *xfer, unsigned int *bits)
{
	Xfer *x = xfer;
	unsigned int *b = bits;
	x->Version1();
	if (x->IsStoring()) {
		AsciiString tmp;
		unsigned short count = 0;
		const UpgradeTemplate *t = TheUpgradeCenter->getFirstTemplate();
		while (t) {
			unsigned int bit = t->m_bitIndex;
			unsigned int mask = 1u << (bit & 31);
			if (b[bit >> 5] & mask)
				count++;
			t = t->m_next;
		}
		*x == count;
		t = TheUpgradeCenter->getFirstTemplate();
		while (t) {
			unsigned int bit = t->m_bitIndex;
			unsigned int mask = 1u << (bit & 31);
			if (b[bit >> 5] & mask) {
				tmp.set(t->m_name);
				*x == tmp;
			}
			t = t->m_next;
		}
	} else {
		AsciiString tmp;
		unsigned short count;
		*x == count;
		memset(b, 0, 0x80);
		if (count > 0) {
			unsigned short i = 0;
			do {
				*x == tmp;
				const UpgradeTemplate *up = TheUpgradeCenter->findUpgrade(tmp);
				if (!up) {
					char buf[8];
					_bfmeFormatText(buf, 0, 0);
					_CxxThrowException(buf, (const _s__ThrowInfo *)&g_guardTargetTypeThrowInfo);
					__assume(0);
				}
				unsigned int bit = up->m_bitIndex;
				unsigned int mask = 1u << (bit & 31);
				b[bit >> 5] |= mask;
				++i;
			} while (i < count);
		}
	}
}
