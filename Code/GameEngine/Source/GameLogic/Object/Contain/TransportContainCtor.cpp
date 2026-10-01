// cl: /O1 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0TransportContain@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x00468559,
// 254 bytes (pinned; instance factory 0x0024B861). Over the rowed OpenContain
// ctor 0x004649F8 (its dtor 0x00464692 is state 0 of retail's unwind map):
// the +0xFC interface base installs its own vtable (0x00C1C780) and then the
// class installs all ten of its vtables; four BFME2 fields at +0x100..+0x10C
// are cleared; and the name of every 12-byte entry of the module data's
// vector at +0x180 is copied into the AsciiString vector at +0x110 (state 1)
// through the pinned push_back 0x0002DBE6. OpenContain's nine polymorphic
// subobjects (+0x00/+0x0C/+0x10/+0x20..+0x34) are positional stand-ins; the
// Zero Hour body (clearing extra slots and exit frame) does not carry over.
#include <vector>
class Thing;
class ModuleData;
class Object;

class AsciiString
{
public:
	AsciiString(const AsciiString &other);
	~AsciiString();
private:
	void *m_data;
};

class OCBase00 { public: virtual void b00(); protected: const ModuleData *m_moduleData; Object *m_object; };
class OCBase0C { public: virtual void b0C(); };
class OCBase10 { public: virtual void b10(); private: unsigned char m_pad[0x0C]; };
class OCBase20 { public: virtual void b20(); };
class OCBase24 { public: virtual void b24(); };
class OCBase28 { public: virtual void b28(); };
class OCBase2C { public: virtual void b2C(); };
class OCBase30 { public: virtual void b30(); };
class OCBase34 { public: virtual void b34(); private: unsigned char m_pad[0xFC - 0x38]; };

class OpenContain : public OCBase00, public OCBase0C, public OCBase10, public OCBase20, public OCBase24,
	public OCBase28, public OCBase2C, public OCBase30, public OCBase34
{
public:
	OpenContain(Thing *thing, const ModuleData *moduleData);
	virtual ~OpenContain();
};

class TransportInterface
{
public:
	virtual void transportAnchor();
};

struct TransportPayloadEntry
{
	AsciiString m_name;
	int m_04;
	int m_08;
};

class TransportContainModuleData
{
public:
	unsigned char m_pad[0x180];
	_STL::vector<TransportPayloadEntry> m_payload;	// +0x180
};

class TransportContain : public OpenContain, public TransportInterface
{
public:
	TransportContain(Thing *thing, const ModuleData *moduleData);
	virtual void b00(); virtual void b0C(); virtual void b10(); virtual void b20(); virtual void b24();
	virtual void b28(); virtual void b2C(); virtual void b30(); virtual void b34();
	virtual void transportAnchor();
	const TransportContainModuleData *getTransportContainModuleData() const { return (const TransportContainModuleData *)m_moduleData; }
private:
	int m_100;
	int m_104;
	int m_108;
	bool m_10C;
	_STL::vector<AsciiString> m_names;		// +0x110
};

TransportContain::TransportContain(Thing *thing, const ModuleData *moduleData)
	: OpenContain(thing, moduleData)
{
	const _STL::vector<TransportPayloadEntry> &payload = getTransportContainModuleData()->m_payload;
	m_100 = 0;
	m_104 = 0;
	m_108 = 0;
	m_10C = false;
	for (unsigned int i = 0; i < payload.size(); ++i)
		m_names.push_back(payload[i].m_name);
}
