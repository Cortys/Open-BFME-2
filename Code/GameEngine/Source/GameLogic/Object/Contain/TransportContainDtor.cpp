// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??1TransportContain@@UAE@XZ, retail 0x00467E61, 128 bytes.
// Slot-0 dtor (vtable 0x00C44278 primary) over the pinned OpenContain base
// (0xFC). Restores primary plus secondaries at +0x0C/+0x10/+0x20/+0x24/
// +0x28/+0x2C/+0x30/+0x34 plus derived slot at +0xFC, then vector
// <AsciiString> at +0x110 via rowed 0x0002CC70 (state 0) and base dtor via
// pinned 0x00464692 (??1OpenContain@@UAE@XZ). Layout is the rowed factory
// news 0x11C (TransportContainFriendNew 0x0024B861) plus HordeTransportContain
// ctor 0x00477003 TransportContain base to +0x11D; donor is ZH
// TransportContain.cpp dtor plus BFME1 TransportContainCtorThunk 11-vtbl
// model. Recipe is the CaveContainDtor ten-vptr pattern plus Stealth vector
// EH precedent.
#include <vector>

class Thing;
class ModuleData;
class Object;

#include "ascii_string.h"

class B0 { public: virtual void b0(); private: unsigned char m_pad[8]; };
class B1 { public: virtual void b1(); };
class B2 { public: virtual void b2(); private: unsigned char m_pad[12]; };
class B3 { public: virtual void b3(); };
class B4 { public: virtual void b4(); };
class B5 { public: virtual void b5(); };
class B6 { public: virtual void b6(); };
class B7 { public: virtual void b7(); };
class B8 { public: virtual void b8(); private: unsigned char m_pad[0xC8 - 4]; };

class OpenContain : public B0, public B1, public B2, public B3, public B4, public B5, public B6, public B7, public B8
{
public:
	virtual ~OpenContain();
};

class TransportExtra { public: virtual void transportExtra(); };

class TransportContain : public OpenContain, public TransportExtra
{
public:
	virtual ~TransportContain();

private:
	unsigned char m_pad100[0x10];
	_STL::vector<AsciiString> m_110;
};

TransportContain::~TransportContain()
{
}
