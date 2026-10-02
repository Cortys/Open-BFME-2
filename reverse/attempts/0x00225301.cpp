// ?bfmeSetText@BfmeAptWindowManager@@QAEXABVAsciiString@@ABVUnicodeString@@_N@Z
// partial score=0.5 date=2026-10-02
// ?bfmeSetText@BfmeAptWindowManager@@QAEXABVAsciiString@@ABVUnicodeString@@_N@Z
// partial score=0.5 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// Identity/boundary: retail 0x00225301, 116B; manager+0x48 key lookup,
// binding+0xC UnicodeString update, Build call and ret 0xC match the retail
// call-site evidence in build/logs/settext_notes.md.
// Best clean-C++ attempt uses the correct rowed Build ABI (UnicodeString by
// value) and rowed temp constructor. It still adds EH/copy setup; see the
// attempt log for the byte/codegen gap.
#include "ascii_string.h"
#include "unicode_string.h"

class Rva00222CCB;

class Rva0022300F
{
public:
    Rva00222CCB **m_begin;
    Rva00222CCB **m_end;
    Rva00222CCB **m_capacity;
    UnicodeString m_text;
};

class Rva00224BDBMap
{
public:
    Rva0022300F &rva00224BDB(const AsciiString &key);
};

class Rva00222719Temp
{
public:
    Rva00222719Temp(const UnicodeString &text);
    UnicodeString m_str;
};

UnicodeString Rva00222CCBBuild(Rva00222CCB **begin, Rva00222CCB **end,
                               UnicodeString initial);

class BfmeAptWindowManager
{
public:
    void bfmeSetText(const AsciiString &key, const UnicodeString &text,
                     bool usePlaceholder);

private:
    char m_pad[0x48];
    Rva00224BDBMap m_bindings;
};

void BfmeAptWindowManager::bfmeSetText(const AsciiString &key,
                                      const UnicodeString &text,
                                      bool usePlaceholder)
{
    Rva0022300F &binding = m_bindings.rva00224BDB(key);
    if (usePlaceholder && text.compare(UnicodeString::TheEmptyString) == 0)
        binding.m_text.set(L" ");
    else
        binding.m_text.set(text);

    Rva00222CCBBuild(binding.m_begin, binding.m_end,
                     Rva00222719Temp(binding.m_text).m_str);
}
