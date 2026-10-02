// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /DNDEBUG /MD
//
// ?init@FontLibrary@@UAEXXZ, retail 0x00217561, 89 bytes.
// FontLibrary subsystem init: virtual slot 1 (offset 0x4) of vtable 0x007E5AD0.
// Stack INI (0x87C) plus one loadFile("data\\ini\\fontsubstitution.ini",
// INI_LOAD_OVERWRITE, 0) via rowed StringBase<char> ctor 0x00037BA0 and pinned
// INI ctor 0x0002CDB0 / loadFile 0x0002DC75 / dtor 0x0002CE5B. ZH donor
// GameFont.h declares virtual void init; ZH/BFME1 bodies are empty, BFME2 adds
// the font-substitution load. Retail ignores this.

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

#include "ascii_string.h"


class Xfer;

enum INILoadType
{
	INI_LOAD_INVALID = 0,
	INI_LOAD_OVERWRITE = 1,
	INI_LOAD_CREATE_OVERRIDES = 2
};

class INI
{
public:
	INI();
	~INI();
	void loadFile(AsciiString filename, INILoadType loadType, Xfer *xfer);
private:
	char m_storage[0x87C];
};

class SubsystemInterface
{
public:
	SubsystemInterface();
	~SubsystemInterface();
	virtual void init();
	void setName(AsciiString name);

private:
	unsigned char m_bfmeBasePad[8];
};

class FontLibrary : public SubsystemInterface
{
public:
	FontLibrary();
	~FontLibrary();
	virtual void init();

private:
	void *m_fontList;
	int m_count;
	unsigned char m_tables[0x18];
};

void FontLibrary::init()
{
	INI ini;
	ini.loadFile("data\\ini\\fontsubstitution.ini", INI_LOAD_OVERWRITE, 0);
}

// ?init@ControlBarResizer@@QAEXXZ, retail 0x001DB71C, 89 bytes.
// Zero Hour's ControlBarResizer::init (ControlBarResizer.cpp): the same stack INI
// and one load of "Data\\INI\\ControlBarResizer.ini", a path nothing else loads.
// Retail places it directly after the rowed ResizerWindow constructor (0x001DB6FD,
// 31 bytes), and nothing calls or references it. Its home unit,
// ControlBarResizer.cpp, links, and the INI ctor, loadFile and dtor are not
// defined yet; this unit already carries those three names, so it lands here.
class ControlBarResizer
{
public:
	void init();
};

void ControlBarResizer::init()
{
	INI ini;
	ini.loadFile("Data\\INI\\ControlBarResizer.ini", INI_LOAD_OVERWRITE, 0);
}

// ?rva00425F10@Rva00425F10@@UAEXXZ, retail 0x00425F10, 89 bytes.
// The same body loading "Data\\INI\\Stances.ini", in slot 1 of vtable 0xC3C2AC
// (the slot FontLibrary::init fills in its vtable). The constructor and
// destructor that install that vtable (0x004260B6, 0x004261D7) are unrowed, so
// the class is not identified and keeps this address.
class Rva00425F10
{
public:
	virtual void rva00425F10();
};

void Rva00425F10::rva00425F10()
{
	INI ini;
	ini.loadFile("Data\\INI\\Stances.ini", INI_LOAD_OVERWRITE, 0);
}
