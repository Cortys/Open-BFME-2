// _Rva000219C0LocaleName
// partial score=0.85 date=2026-09-29
// Best shape for retail 0x000219C0 (23B), from BFME1 donor twin set
// game/stlport/LocaleCodePageQueries.c b1 0x0084E7B0/0x0084E7D0/0x0084E7F0/
// 0x0084E810/0x0084E830 (all 23B, ICF-folded by lotrbfme.exe).
//
// Compiled under Code/Libraries/Source/WWVegas/WWLib/stlport_LocaleCodePageQueries.c
// with the rowed static ___GetLocaleName (0x000215B0) already pinned:
//
//   target:   8b 4c 24 04 8d 41 04 8b 09 50 8b 44 24 0c e8 dd fb ff ff 83 c4 04 c3
//   compiled: 8b 4c 24 04 8b 54 24 08 8d 41 04 8b 09 52 e8 dd fb ff ff 83 c4 04 c3
//
// Same length (23B) and the same call, push/pop and ret; the residue is pure
// scheduling: this build loads `cp` into edx (from [esp+8]) before computing the
// buffer, where retail pushes the buffer's `lea` first and then loads `cp` into
// eax from [esp+0xc]. Taking the buffer through a named local did not move it.
// Keep the C form below: it documents the argument order and the +0/+4 layout.
typedef struct LocaleCodePageObject_0084EED0
{
    unsigned long locale;
    char codePage[1];
} LocaleCodePageObject_0084EED0;

extern char *__GetLocaleName(unsigned long lcid, const char *cp, char *buf);

char *Rva000219C0LocaleName(LocaleCodePageObject_0084EED0 *object, const char *cp)
{
    char *codePage = object->codePage;
    return __GetLocaleName(object->locale, cp, codePage);
}
