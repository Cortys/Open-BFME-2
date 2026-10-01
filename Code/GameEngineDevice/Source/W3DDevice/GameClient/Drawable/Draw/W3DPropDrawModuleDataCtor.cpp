// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
//
// W3DPropDrawModuleData file-unit: parse proc and constructor.
//
// ??0W3DPropDrawModuleData@@QAE@XZ, retail 0x000CEF2B, 17 bytes (pinned;
// called by the data factory 0x00064D1D). Stores vtable 0x00BCD420, nulls
// m_modelName at +0x08 and sets the byte at +0x0C to 1; the rowed dtor next
// door (0x000CEF3C, W3DPropDrawModuleDataDtor.cpp) uses the same vtable and
// string slot. The Snapshot base constructor is inline and its vtable store
// is overwritten.
//
// ?buildFieldParse@W3DPropDrawModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x000CEF72, 17 bytes. Single-table parse proc (table 0x00BCD4A8)
// through the rowed MultiIniFieldParse::add at 0x2BC6E. Row supersedes the
// parse pin.

class MultiIniFieldParse;
struct FieldParse;

class MultiIniFieldParse
{
public:
	void add(const FieldParse *parseTable, unsigned int extraOffset);
};

#include "ascii_string.h"

class Snapshot
{
public:
	virtual ~Snapshot();
};

class W3DPropDrawModuleData : public Snapshot
{
public:
	W3DPropDrawModuleData();
	virtual ~W3DPropDrawModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
private:
	int m_04;
	AsciiString m_modelName;
	bool m_0C;
};

// ??0W3DPropDrawModuleData@@QAE@XZ @0x000CEF2B
W3DPropDrawModuleData::W3DPropDrawModuleData() : m_0C(true)
{
}

// ?buildFieldParse@W3DPropDrawModuleData@@SAXAAVMultiIniFieldParse@@@Z @0x000CEF72
void W3DPropDrawModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	parse.add(reinterpret_cast<const FieldParse *>(0x00BCD4A8), 0);
}
