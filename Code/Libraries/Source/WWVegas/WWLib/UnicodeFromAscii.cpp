// Reference: BFME1 unicode_string.cpp constructor and translation family,
// reconciled with BFME2's explicitly exported cross-charset constructor.
// Export ??0UnicodeString@@QAE@ABVAsciiString@@@Z identifies6CB6D0 (91B).
// Masked code also matches the reverse conversion at38250; the export and
// callee translate(const char*)6CB5F0 prove this identity independently.
// cl: /Ireference/shims/bfme2_ascii /O2 /DNDEBUG /MD /EHsc
#include "ascii_string.h"
class UnicodeString:public StringBase<unsigned short> {
public:
    UnicodeString(const AsciiString&);
    void translate(const char*);
};
UnicodeString::UnicodeString(const AsciiString& text) {
    translate(text.str());
}
