// cl: /O1
// PlayerTemplate image getters via TheMappedImageCollection (0x00DFF078).
// ?rva001FD1FB@PlayerTemplate@@QBEPBVImage@@XZ @0x001FD1FB 19B (AsciiString at +0x170)
// ?rva001FD221@PlayerTemplate@@QBEPBVImage@@XZ @0x001FD221 19B (AsciiString at +0x174)
// ?rva001FD23F@PlayerTemplate@@QBEPBVImage@@XZ @0x001FD23F 19B (AsciiString at +0x1D8)
// BFME1 PlayerTemplate.cpp getHeadWaterMarkImage/getFlagWaterMarkImage/getSideIconImage/
// getGeneralImage/getEnabledImage all do TheMappedImageCollection->findImageByName(member).
// Retail class proven by callers derefing Player+0x34 (getPlayerTemplate): 0x001FD221 used by
// GadgetButtonSetEnabledImage at 0x0050E135/0x0050E321, 0x001FD1FB by winSetEnabledImage at
// 0x0050E66B, 0x001FD23F on PlayerTemplate from getControllingPlayer at 0x005294C7.
// Sibling offsets 0x170/0x174 are adjacent AsciiStrings and 0x1D8 closes the 0x1DC object.
class AsciiString
{
	void *m_data;
};

class Image;

class ImageCollection
{
public:
	const Image *findImageByName(const AsciiString &name);
};

#define TheMappedImageCollection (*(ImageCollection **)0x00DFF078)

class PlayerTemplate
{
public:
	const Image *rva001FD1FB() const;
	const Image *rva001FD221() const;
	const Image *rva001FD23F() const;

private:
	char m_pad170[0x170];
	AsciiString m_170;
	AsciiString m_174;
	char m_pad178[0x1D8 - 0x178];
	AsciiString m_1D8;
};

const Image *PlayerTemplate::rva001FD1FB() const
{
	return TheMappedImageCollection->findImageByName(m_170);
}

const Image *PlayerTemplate::rva001FD221() const
{
	return TheMappedImageCollection->findImageByName(m_174);
}

const Image *PlayerTemplate::rva001FD23F() const
{
	return TheMappedImageCollection->findImageByName(m_1D8);
}
