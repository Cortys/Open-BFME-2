// ?ReadParameter@Parameter@@SAPAV1@AAVDataChunkInput@@@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /Os /G7 /DNDEBUG /MD /EHsc
// ?ReadParameter@Parameter@@SAPAV1@AAVDataChunkInput@@@Z, retail 0x003B5CA1 (516 bytes).
// BFME2 Parameter::ReadParameter: static factory reading type via DataChunkInput::readInt,
// COORD3D (0x10) reads 3 reals into setCoord3D, else int/real/AsciiString, BODY_STATE (0x29)
// via BitFlags<101>::getSingleBitFromName, KIND_OF (0x1B) via TheKindOfBitNames with
// CRUSHER/CRUSHABLE/OVERLAPPABLE/CASH_GENERATOR->SUPPLY_GATHERING_CENTER/MISSILE->SMALL_MISSILE
// hacks and throw ERROR_BUG. Donor ZH GeneralsMD Scripts.cpp Parameter::ReadParameter,
// BFME2 differences read off retail bytes. Callers 0x003B5EA5/0x003B6D92.

#include "ascii_string.h"

typedef int Int;
typedef bool Bool;

struct Coord3D
{
	float x;
	float y;
	float z;
};

class DataChunkInput
{
public:
	Int readInt();
	float readReal();
	AsciiString rva0030750A();
};

template <unsigned int N>
class BitFlags
{
public:
	static Int getSingleBitFromName(const char *token);
};

extern const char *TheKindOfBitNames[0xDA];
extern const char g_Rva0107301CEmptyString[];

enum ErrorCode
{
	ERROR_BASE = 0xdead0001,
	ERROR_BUG = (ERROR_BASE + 0x0000)
};

enum
{
	COORD3D_PARAM = 0x10,
	KIND_OF_PARAM = 0x1B,
	BODY_STATE_PARAM = 0x29
};

class Parameter
{
public:
	enum ParameterType
	{
		INT_TYPE = 0
	};

	Parameter(ParameterType type, Int val = 0);
	static Parameter *ReadParameter(DataChunkInput &file);

	ParameterType getParameterType() const { return m_paramType; }

protected:
	void setCoord3D(const Coord3D *pLoc);

private:
	ParameterType m_paramType; // +0x00
	Bool m_initialized; // +0x04
	char m_pad[3]; // +0x05
	Int m_int; // +0x08
	float m_real; // +0x0C
	AsciiString m_string; // +0x10
	Coord3D m_coord; // +0x14
	unsigned int m_tail0; // +0x20
	unsigned int m_tail1; // +0x24
};

// ?ReadParameter@Parameter@@SAPAV1@AAVDataChunkInput@@@Z present-unmatched
Parameter *Parameter::ReadParameter(DataChunkInput &file)
{
	Parameter *pParm = new Parameter((ParameterType)file.readInt());
	pParm->m_initialized = true;
	if (pParm->getParameterType() == (ParameterType)COORD3D_PARAM) {
		Coord3D pos;
		pos.x = file.readReal();
		pos.y = file.readReal();
		pos.z = file.readReal();
		pParm->setCoord3D(&pos);
	} else {
		pParm->m_int = file.readInt();
		pParm->m_real = file.readReal();
		((StringBase<char> &)pParm->m_string).set((const StringBase<char> &)file.rva0030750A());
	}

	if (pParm->getParameterType() == (ParameterType)BODY_STATE_PARAM) {
		char *data = *(char **)&pParm->m_string;
		const char *tok = data ? data + 8 : g_Rva0107301CEmptyString;
		pParm->m_int = BitFlags<101>::getSingleBitFromName(tok);
	}

	if (pParm->getParameterType() == (ParameterType)KIND_OF_PARAM) {
		AsciiString &str = pParm->m_string;
		StringBase<char> &s = (StringBase<char> &)str;
		if (!s.isEmpty()) {
			Bool found = false;
			for (Int i = 0; TheKindOfBitNames[i]; ++i) {
				if (s.compareNoCase(TheKindOfBitNames[i]) == 0) {
					pParm->m_int = i;
					return pParm;
				}
				if (s.compareNoCase("CRUSHER") == 0) {
					pParm->m_int = i;
					return pParm;
				}
				if (s.compareNoCase("CRUSHABLE") == 0) {
					pParm->m_int = i;
					return pParm;
				}
				if (s.compareNoCase("OVERLAPPABLE") == 0) {
					pParm->m_int = i;
					return pParm;
				}
				if (s.compareNoCase("CASH_GENERATOR") == 0) {
					str.format("SUPPLY_GATHERING_CENTER");
					found = true;
					break;
				}
				if (s.compareNoCase("MISSILE") == 0) {
					str.format("SMALL_MISSILE");
					for (i = 0; TheKindOfBitNames[i]; ++i) {
						if (s.compareNoCase("SMALL_MISSILE") == 0) {
							pParm->m_int = i;
							found = true;
							break;
						}
					}
				}
			}
			if (!found) {
				throw ERROR_BUG;
			}
		} else {
			s.set(TheKindOfBitNames[pParm->m_int]);
		}
	}

	return pParm;
}
