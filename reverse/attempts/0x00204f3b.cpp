// ?bfmeRunZC@BfmeOwnZC@@QAEPAXVBfmeRoomZC@@PAX@Z
// partial score=0.99 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc
#include "ascii_string.h"

// ?bfmeRunZC@BfmeOwnZC@@QAEPAXVBfmeRoomZC@@PAX@Z @0x00204F3B (128B): resolve room
// name via base resolveName, find its ScriptList, fetch nodes+4 through rowed
// 0x003B6911, copy resolved into extra when both present. Evidence: chain from
// just-landed 0x003B6911, rowed Find 0x00204E64, pinned resolveName 0x002046C0,
// callers in BfmeRoomForwarder; BfmeRoomZC carries AsciiString at +0.

class Rva002046C0Owner
{
public:
	AsciiString resolveName(const AsciiString &name);
};

class BfmeRoomZC
{
public:
	AsciiString m_name; // +0x00
};

class ScriptList;

class ScriptList
{
public:
	void *rva003B6911(const StringBase<char> &key);
};

class BfmeOwnZC : public Rva002046C0Owner
{
public:
	ScriptList *findForRun(const AsciiString &name);
	void *bfmeRunZC(BfmeRoomZC name, void *extra);
};

// ?bfmeRunZC@BfmeOwnZC@@QAEPAXVBfmeRoomZC@@PAX@Z present-unmatched
void *BfmeOwnZC::bfmeRunZC(BfmeRoomZC name, void *extra)
{
	AsciiString resolved = resolveName(name.m_name);
	ScriptList *list = findForRun(resolved);
	void *result;
	if (list != 0) {
		result = list->rva003B6911(*(const StringBase<char> *)&name.m_name);
		if (result != 0 && extra != 0)
			((StringBase<char> *)extra)->set(*(const StringBase<char> *)&resolved);
	} else
		result = 0;
	return result;
}
