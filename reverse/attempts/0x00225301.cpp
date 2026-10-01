// ?bfmeSetText@BfmeAptWindowManager@@QAEXABVAsciiString@@ABVUnicodeString@@_N@Z
// partial score=0.5 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
#include "ascii_string.h"
#include "unicode_string.h"

class Rva00222CCB;
class Rva0022300F;

class AptBindingMap
{
public:
	Rva0022300F *lookup(const AsciiString &key);
};

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &key, const UnicodeString &text, bool usePlaceholder);

private:
	char m_pad[0x48];
	AptBindingMap m_bindings;
};

class Rva0022300F
{
public:
	Rva00222CCB **m_begin;
	Rva00222CCB **m_end;
	Rva00222CCB **m_capacity;
	UnicodeString m_text;
};

class Rva00222719Temp
{
public:
	Rva00222719Temp(const UnicodeString &text);
	UnicodeString m_str;
};

UnicodeString Rva00222CCBBuild(Rva00222CCB **begin, Rva00222CCB **end,
	Rva00222719Temp initial);

void BfmeAptWindowManager::bfmeSetText(const AsciiString &key,
	const UnicodeString &text, bool usePlaceholder)
{
	Rva0022300F *binding = m_bindings.lookup(key);
	if (usePlaceholder && text.compare(UnicodeString::TheEmptyString) == 0)
		binding->m_text.set(L" ");
	else
		binding->m_text.set(text);

	Rva00222719Temp temporary(binding->m_text);
	register Rva00222CCB **end = binding->m_end;
	register Rva00222CCB **begin = binding->m_begin;
	Rva00222CCBBuild(begin, end, temporary);
}
