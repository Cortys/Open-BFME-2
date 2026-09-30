// cl: /O1 /Ireference/shims/bfme2_ascii
// Upstream implementation and layout: Open-BFME-1 ascii_string.h.

#include "ascii_string.h"

// A PooledString is one pointer to a shared entry whose text starts at +8, and
// the entry is never null, so there is no empty-string fallback here.
struct PooledStringEntry
{
    void *m_unknown0;
    PooledStringEntry *m_noCase;
    char m_text[1];
};

AsciiString &AsciiString::operator+=(const PooledString &that)
{
    const PooledStringEntry *entry = *(const PooledStringEntry *const *)&that;

    ((StringBase<char> *)this)->concat(entry->m_text);

    return *this;
}

AsciiString::AsciiString(char character)
{
    ((StringBase<char> *)this)->StringBase<char>::StringBase(character);
}

AsciiString::AsciiString(const char *text, int length)
{
    ((StringBase<char> *)this)->StringBase<char>::StringBase(text, length);
}

AsciiString::AsciiString(const char *text, int start, int length)
{
    ((StringBase<char> *)this)->StringBase<char>::StringBase(text, start, length);
}

AsciiString::AsciiString(const AsciiString &that, int start, int length)
{
    ((StringBase<char> *)this)->StringBase<char>::StringBase(
        *(const StringBase<char> *)&that, start, length);
}

AsciiString &AsciiString::operator=(char character)
{
    char text = character;
    ((StringBase<char> *)this)->set(&text, 1);
    return *this;
}

AsciiString &AsciiString::operator+=(const AsciiString &that)
{
    ((StringBase<char> *)this)->concat(*(const StringBase<char> *)&that);
    return *this;
}

AsciiString &AsciiString::operator+=(char character)
{
    char text = character;
    ((StringBase<char> *)this)->concat(&text, 1);
    return *this;
}

AsciiString &AsciiString::operator+=(const char *text)
{
    ((StringBase<char> *)this)->concat(text);
    return *this;
}

// The default, copy and C-string constructors, the destructor and both
// assignments are inline in ascii_string.h, and retail still keeps an
// out-of-line copy of each (0x00326BE6, 0x001D8F56, 0x0000654A, 0x0048BA39,
// 0x00001733, 0x000065B8): the COMDATs of calls MSVC did not inline. With
// inlining off, these calls emit the same COMDATs here, where their rows live,
// as selectany copies rather than strong definitions that collide with every
// other TU's inline copy in the linked build.
#pragma inline_depth(0)
// ?bfmeEmitAsciiStringInlines@@YAXPAVAsciiString@@ABV1@PBD@Z present-unmatched
void bfmeEmitAsciiStringInlines(AsciiString *out, const AsciiString &that, const char *text)
{
    AsciiString empty;
    AsciiString copy(that);
    AsciiString fromText(text);
    *out = that;
    *out = text;
}
#pragma inline_depth()
