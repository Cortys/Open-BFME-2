// ?resize@?$hashtable@U?$pair@$$CBVAsciiString@@H@_STL@@VAsciiString@@U?$hash@VAsciiString@@@rts@@U?$_Select1st@U?$pair@$$CBVAsciiString@@H@_STL@@@2@U?$equal_to@VAsciiString@@@5@V?$allocator@U?$pair@$$CBVAsciiString@@H@_STL@@@2@@_STL@@QAEXI@Z
// partial score=0.92 date=2026-09-28
// ?resize@?$hashtable@U?$pair@$$CBVAsciiString@@H@_STL@@VAsciiString@@U?$hash@VAsciiString@@@rts@@U?$_Select1st@U?$pair@$$CBVAsciiString@@H@_STL@@@2@U?$equal_to@VAsciiString@@@5@V?$allocator@U?$pair@$$CBVAsciiString@@H@_STL@@@2@@_STL@@QAEXI@Z
// partial score=0.92 date=2026-09-28
// cl: /O1 /MD /DNDEBUG /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable
// stlport
#include <hash_map>

class AsciiString {
public:
    char *m_text;
};

unsigned int __stdcall Rva00055041AsciiHash(const AsciiString *s) throw();

namespace rts {
template <class T> struct hash {};
template <> struct hash<AsciiString> {
    size_t operator()(const AsciiString &k) const throw() {
        return Rva00055041AsciiHash(&k);
    }
};
template <class T> struct equal_to {};
template <> struct equal_to<AsciiString> {
    bool operator()(const AsciiString &a, const AsciiString &b) const throw() {
        return a.m_text == b.m_text;
    }
};
}

typedef _STL::hash_map<AsciiString, int, rts::hash<AsciiString>, rts::equal_to<AsciiString> > EvaProbeMap2;

void evaProbeResizeAnchor2(EvaProbeMap2 &m, unsigned h) {
    m.resize(h);
}
