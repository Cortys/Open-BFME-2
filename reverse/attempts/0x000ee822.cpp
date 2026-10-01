// ?addPropType@W3DPropBuffer@@QAEHABVAsciiString@@_N@Z
// partial score=0.91 date=2026-10-01
// ?addPropType@W3DPropBuffer@@QAEHABVAsciiString@@_N@Z
// partial score=0.91 date=2026-10-01
// ?addPropType@W3DPropBuffer@@QAEHABVAsciiString@@_N@Z, retail 0x000EE822, 223 bytes.
// Evidence: ZH donor W3DPropBuffer::addPropType (same MAX_TYPES 96, same
// Create_Render_Obj null-check returning 0/-1, same m_robjName set and
// Get_Bounding_Sphere copy); retail adds second bool arg gating byte at
// RenderObj+0xBD and uses rowed Create_Render_Obj 0x00136175 and
// StringBase<char>::set 0x000366F0; __thiscall int method returning index.

#include "ascii_string.h"

struct SphereClass
{
	float x;
	float y;
	float z;
	float w;
};

class RenderObjClass
{
public:
	virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
	virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
	virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
	virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
	virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
	virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
	virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
	virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
	virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
	virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
	virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
	virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
	virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
	virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55();
	virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
	virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63();
	virtual void d64();
	virtual const SphereClass &Get_Bounding_Sphere();
	char _pad[0xBD - 4];
	unsigned char m_flagBD; // +0xBD cleared when bool arg is false
};

extern RenderObjClass *__cdecl Create_Render_Obj(const char *name);

struct TPropType
{
	RenderObjClass *m_robj;
	AsciiString m_robjName;
	SphereClass m_bounds;
};

class W3DPropBuffer
{
public:
	int addPropType(const AsciiString &modelName, bool flag);
private:
	char m_pad[0x2EE18];
	TPropType m_propTypes[96]; // +0x2EE18, each 0x18
	int m_numPropTypes; // +0x2F718
};

// ?addPropType@W3DPropBuffer@@QAEHABVAsciiString@@_N@Z present-unmatched
int W3DPropBuffer::addPropType(const AsciiString &modelName, bool flag)
{
	if (m_numPropTypes >= 96)
		return 0;
	m_propTypes[m_numPropTypes].m_robj = Create_Render_Obj(modelName.str());
	if (m_propTypes[m_numPropTypes].m_robj == NULL)
		return -1;
	if (!flag)
		m_propTypes[m_numPropTypes].m_robj->m_flagBD = 0;
	m_propTypes[m_numPropTypes].m_robjName.set(modelName);
	m_propTypes[m_numPropTypes].m_bounds = m_propTypes[m_numPropTypes].m_robj->Get_Bounding_Sphere();
	m_numPropTypes++;
	return m_numPropTypes - 1;
}
