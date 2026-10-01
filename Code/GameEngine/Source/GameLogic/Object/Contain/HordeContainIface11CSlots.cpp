// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /arch:SSE /EHs /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// Two overrides of the interface HordeContain carries at +0x11C (vtable
// 0x00C44C58 installed by the pinned HordeContain ctor 0x0046F543; inherited by
// the matched HorseHordeContain, vtable 0x00C45838). Compiled with the +0x11C
// subobject this (cl 7.1 folds the adjustment into [ecx-0x114] for the Object at
// +8 and [ecx-0x118] for the ModuleData at +4). Names by address.
// Retail 0x0046BB38 (55 bytes), slot 6: true when the other Object +0x274 points
// at our Object, else whether its ID (+0x74, read through a by-value getter, the
// temporary retail stores in the argument slot) is a key of the map<int,int> at
// +0x170 (matched _Rb_tree::_M_find 0x00388F63); written as if/return, the form
// that gives the direct setne.
// Retail 0x0046D1AC (75 bytes), slot 9: the only name of the AsciiString list at
// module data +0xA4, else AsciiString::TheEmptyString, returned by value.
#include "ascii_string.h"
#include <list>
#include <map>
class Object
{
public:
	int getID() const { return m_74; }
	unsigned char m_pad000[0x74];
	int m_74; // +0x74
	unsigned char m_pad078[0xB8 - 0x78];
	float m_B8; // +0xB8
	unsigned char m_padBC[0x274 - 0xBC];
	Object *m_274; // +0x274
};
class HordeContainModuleData
{
public:
	unsigned char m_pad[0xA4];
	_STL::list<AsciiString> m_A4; // +0xA4
};
class ModuleData;
template <int N> class Rva0046BB38Slots : public Rva0046BB38Slots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class Rva0046BB38Slots<0>
{
};
// HordeContain's +0x11C interface (vtable 0x00C44C58): slots 6, 9 and 144.
class Rva0046BB38Iface6 : public Rva0046BB38Slots<6>
{
public:
	virtual bool rva0046BB38(Object *other) = 0;
	virtual void gap7() = 0;
	virtual void gap8() = 0;
	virtual AsciiString rva0046D1AC() = 0;
};
class Rva0046BB38Iface11C : public Rva0046BB38Iface6
{
public:
	virtual void gap10() = 0; virtual void gap11() = 0; virtual void gap12() = 0; virtual void gap13() = 0;
	virtual void gap14() = 0; virtual void gap15() = 0; virtual void gap16() = 0; virtual void gap17() = 0;
	virtual void gap18() = 0; virtual void gap19() = 0; virtual void gap20() = 0; virtual void gap21() = 0;
	virtual void gap22() = 0; virtual void gap23() = 0; virtual void gap24() = 0; virtual void gap25() = 0;
	virtual void gap26() = 0; virtual void gap27() = 0; virtual void gap28() = 0; virtual void gap29() = 0;
	virtual void gap30() = 0; virtual void gap31() = 0; virtual void gap32() = 0; virtual void gap33() = 0;
	virtual void gap34() = 0; virtual void gap35() = 0; virtual void gap36() = 0; virtual void gap37() = 0;
	virtual void gap38() = 0; virtual void gap39() = 0; virtual void gap40() = 0; virtual void gap41() = 0;
	virtual void gap42() = 0; virtual void gap43() = 0; virtual void gap44() = 0; virtual void gap45() = 0;
	virtual void gap46() = 0; virtual void gap47() = 0; virtual void gap48() = 0; virtual void gap49() = 0;
	virtual void gap50() = 0; virtual void gap51() = 0; virtual void gap52() = 0; virtual void gap53() = 0;
	virtual void gap54() = 0; virtual void gap55() = 0; virtual void gap56() = 0; virtual void gap57() = 0;
	virtual void gap58() = 0; virtual void gap59() = 0; virtual void gap60() = 0; virtual void gap61() = 0;
	virtual void gap62() = 0; virtual void gap63() = 0; virtual void gap64() = 0; virtual void gap65() = 0;
	virtual void gap66() = 0; virtual void gap67() = 0; virtual void gap68() = 0; virtual void gap69() = 0;
	virtual void gap70() = 0; virtual void gap71() = 0; virtual void gap72() = 0; virtual void gap73() = 0;
	virtual void gap74() = 0; virtual void gap75() = 0; virtual void gap76() = 0; virtual void gap77() = 0;
	virtual void gap78() = 0; virtual void gap79() = 0; virtual void gap80() = 0; virtual void gap81() = 0;
	virtual void gap82() = 0; virtual void gap83() = 0; virtual void gap84() = 0; virtual void gap85() = 0;
	virtual void gap86() = 0; virtual void gap87() = 0; virtual void gap88() = 0; virtual void gap89() = 0;
	virtual void gap90() = 0; virtual void gap91() = 0; virtual void gap92() = 0; virtual void gap93() = 0;
	virtual void gap94() = 0; virtual void gap95() = 0; virtual void gap96() = 0; virtual void gap97() = 0;
	virtual void gap98() = 0; virtual void gap99() = 0; virtual void gap100() = 0; virtual void gap101() = 0;
	virtual void gap102() = 0; virtual void gap103() = 0; virtual void gap104() = 0; virtual void gap105() = 0;
	virtual void gap106() = 0; virtual void gap107() = 0; virtual void gap108() = 0; virtual void gap109() = 0;
	virtual void gap110() = 0; virtual void gap111() = 0; virtual void gap112() = 0; virtual void gap113() = 0;
	virtual void gap114() = 0; virtual void gap115() = 0; virtual void gap116() = 0; virtual void gap117() = 0;
	virtual void gap118() = 0; virtual void gap119() = 0; virtual void gap120() = 0; virtual void gap121() = 0;
	virtual void gap122() = 0; virtual void gap123() = 0; virtual void gap124() = 0; virtual void gap125() = 0;
	virtual void gap126() = 0; virtual void gap127() = 0; virtual void gap128() = 0; virtual void gap129() = 0;
	virtual void gap130() = 0; virtual void gap131() = 0; virtual void gap132() = 0; virtual void gap133() = 0;
	virtual void gap134() = 0; virtual void gap135() = 0; virtual void gap136() = 0; virtual void gap137() = 0;
	virtual void gap138() = 0; virtual void gap139() = 0; virtual void gap140() = 0; virtual void gap141() = 0;
	virtual void gap142() = 0; virtual void gap143() = 0;
	virtual float rva00468B5B(float value) = 0;
};
class TransportContain
{
public:
	virtual ~TransportContain();
protected:
	const ModuleData *m_moduleData; // +0x04
	Object *m_object; // +0x08
private:
	unsigned char m_pad00C[0x11C - 0x0C];
};
class HordeContain : public TransportContain, public Rva0046BB38Iface11C
{
public:
	virtual bool rva0046BB38(Object *other);
	virtual AsciiString rva0046D1AC();
private:
	unsigned char m_pad120[0x170 - 0x120];
	_STL::map<int, int> m_170; // +0x170
	unsigned char m_pad17C[0x2EC - 0x17C];
	float m_2EC; // +0x2EC
};
bool HordeContain::rva0046BB38(Object *other)
{
	if (other->m_274 == m_object)
		return true;
	if (m_170.find(other->getID()) != m_170.end())
		return true;
	return false;
}
AsciiString HordeContain::rva0046D1AC()
{
	const HordeContainModuleData *data = (const HordeContainModuleData *)m_moduleData;
	return data->m_A4.size() == 1 ? data->m_A4.front() : AsciiString::TheEmptyString;
}
