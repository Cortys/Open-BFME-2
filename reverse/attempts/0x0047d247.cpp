// ??0HordeSiegeEngineContain@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.9 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHs /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <list>
#include <map>
class Thing;
class ModuleData;
class Object;
struct Iface00 { virtual void f00(); const ModuleData *m_moduleData; Object *m_object; };
struct Iface0C { virtual void f0C(); };
struct Iface10 { virtual void f10(); unsigned char m_pad[12]; };
struct Iface20 { virtual void f20(); };
struct Iface24 { virtual void f24(); };
struct Iface28 { virtual void f28(); };
struct Iface2C { virtual void f2C(); };
struct Iface30 { virtual void f30(); };
struct Iface34 { virtual void f34(); unsigned char m_pad[0xFC - 0x38]; };
struct IfaceFC { virtual void fFC(); };
class TransportContain
	: public Iface00
	, public Iface0C
	, public Iface10
	, public Iface20
	, public Iface24
	, public Iface28
	, public Iface2C
	, public Iface30
	, public Iface34
	, public IfaceFC
{
public:
	TransportContain(Thing *thing, const ModuleData *moduleData);
	virtual ~TransportContain();
private:
	unsigned char m_pad100[0x11C - 0x100];
};
class HordeTransportContain : public TransportContain
{
public:
	HordeTransportContain(Thing *thing, const ModuleData *moduleData);
private:
	unsigned char m_pad11C[0x128 - 0x11C];
};
class Object
{
public:
	void rva0028AE6D();
	unsigned char m_pad000[0x124];
	unsigned int m_status; // +0x124
};
class HordeSiegeEngineContain : public HordeTransportContain
{
public:
	HordeSiegeEngineContain(Thing *thing, const ModuleData *moduleData);
	virtual ~HordeSiegeEngineContain();
	virtual void f00();
	virtual void f20();
	virtual void f30();
	virtual void f34();
private:
	_STL::list<int> m_list128;
	int m_12C;
	bool m_130;
	_STL::map<int, void *> m_map134;
	_STL::list<int> m_list140;
};

HordeSiegeEngineContain::HordeSiegeEngineContain(Thing *thing, const ModuleData *moduleData)
	: HordeTransportContain(thing, moduleData)
{
	Object *object = m_object;
	m_12C = 0;
	m_130 = false;
	unsigned int statusBit = 0x20000;
	if ((object->m_status & statusBit) == 0)
	{
		object->m_status |= statusBit;
		object->rva0028AE6D();
	}
}
