// ?rva0031E7F0@Rva0031E7F0@@QAE_NPAE@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /GX- /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfme2_ascii /Ireference/shims/bfme_windowvideo /Ireference/open-bfme-1/Code/GameEngine/Source/Common/System /Ireference/open-bfme-1/Code/GameEngine/Source/GameClient /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
// stlport
// ?rva0031E7F0@Rva0031E7F0@@QAE_NPAE@Z @0x0031E7F0 137B
// Evidence: chain lane calls 0x00409FCC now ready; SubsystemInterface slot2 Bool at +8
// (loadIniFilesFromLegend); InGameUI message UnicodeString slot 0x40 __cdecl this-on-stack;
// hashtable GameWindow->WindowVideo begin 0x00427195 at +0x30; Rva00409FFA 0x00409FCC
// on node+8; Rva000411084 next 0x00411084; Rva0031AC39 0x0031AC39 with this; flag +0x28;
// globals g_00E01D0C g_00C0CCC0 TheInGameUI.
#include "ascii_string.h"
#include "unicode_string.h"
extern unsigned char g_00E01D0C;
extern const unsigned short g_00C0CCC0[];
class InGameUI {
public:
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
  virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
  virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
  virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
  virtual void __cdecl message(UnicodeString, ...);
};
extern InGameUI *TheInGameUI;
class Rva00409FFA { public: void rva00409FCC(); };
class Rva000411084 { public: void *next(); void *m_cur; void *m_own; };
class Rva0031AC39 { public: void rva0031AC39(); };
#include <hash_map>
class GameWindow; class WindowVideo;
struct H { size_t operator()(const GameWindow *p) const { return (size_t)p; } };
typedef _STL::hash_map<const GameWindow*, WindowVideo*, H, _STL::equal_to<const GameWindow*> > MyMap;
class Rva0031E7F0 {
public:
  virtual void v0(); virtual void v1(); virtual bool v2();
  char pad[0x24];
  unsigned char f28; char p29[3]; void *l2c;
  MyMap t30;
// ?rva0031E7F0@Rva0031E7F0@@QAE_NPAE@Z present-unmatched
  bool rva0031E7F0(unsigned char *o);
};
bool Rva0031E7F0::rva0031E7F0(unsigned char *o) {
  bool b = false;
  g_00E01D0C = b;
  if (!v2()) return b;
  TheInGameUI->message(UnicodeString(g_00C0CCC0));
  MyMap::iterator it = t30.begin();
  while (((Rva000411084*)&it)->m_cur != 0) {
    Rva00409FFA *p = *(Rva00409FFA**)((char*)((Rva000411084*)&it)->m_cur + 8);
    p->rva00409FCC();
    ((Rva000411084*)&it)->next();
  }
  ((Rva0031AC39*)this)->rva0031AC39();
  f28 = 1;
  b = true;
  if (g_00E01D0C != 0) { *o = 1; g_00E01D0C = 0; }
  return b;
}
