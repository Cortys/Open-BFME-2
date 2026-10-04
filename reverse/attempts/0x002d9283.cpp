// ??1ImageCollection@@UAE@XZ
// partial score=0.95 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ??1ImageCollection@@UAE@XZ, retail 0x002D9283 (115B).
// ImageCollection dtor: iterates m_imageMap at +0xC behind 12-byte
// GameEngineDeletingBase, destroys each Image via virtual dtor and frees via
// operator delete. Donor BFME1 Image.cpp ImageCollection::~ImageCollection.
// Vtable 0x00C03878, base dtor row 0x001B4E74, map at +0xC.
#include <map>
#include "ascii_string.h"

class Image
{
public:
	virtual ~Image();
};

typedef _STL::map<unsigned int, Image *> ImageNameMap;

class AsciiStringMember
{
public:
	~AsciiStringMember();
};

class GameEngineDeletingBase
{
public:
	GameEngineDeletingBase() throw();
	virtual ~GameEngineDeletingBase();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

class ImageCollection : public GameEngineDeletingBase
{
public:
	virtual ~ImageCollection();

private:
	ImageNameMap m_imageMap;
};

// ??1ImageCollection@@UAE@XZ present-unmatched
ImageCollection::~ImageCollection(void)
{
  for (ImageNameMap::iterator i=m_imageMap.begin();i!=m_imageMap.end();++i)
  {
    if (i->second)
      i->second->~Image();
    ::operator delete(i->second);
  }
}
