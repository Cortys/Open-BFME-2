// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?winTextLabelToText@GameWindowManager@@QAE?AVUnicodeString@@VAsciiString@@@Z @0x002C1EED 130B
// GameWindowManager::winTextLabelToText; BFME1 donor GameWindowManager.cpp verbatim TEMPORARY shape; empty AsciiString returns UnicodeString::TheEmptyString else translate; vtable 0x7C7C90 slot 75.

typedef int Int;
typedef bool Bool;

#include "ascii_string.h"


class UnicodeString
{
public:
	static const UnicodeString TheEmptyString;

	UnicodeString() {}
	void translate(const AsciiString &source);

private:
	StringBase<unsigned short> m_data;
};

class GameWindowManager
{
public:
	UnicodeString winTextLabelToText(AsciiString label);
};

UnicodeString GameWindowManager::winTextLabelToText(AsciiString label)
{
	if (label.isEmpty())
		return UnicodeString::TheEmptyString;

	UnicodeString tmp;
	tmp.translate(label);
	return tmp;
}
