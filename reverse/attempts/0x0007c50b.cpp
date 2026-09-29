// ??0Rva0007C50B@@QAE@XZ
// partial score=0.92 date=2026-09-29
// ??0Rva0007C50B@@QAE@XZ
// partial score=0.92 date=2026-09-29
// cl: /O1 /EHsc /MD /arch:SSE
// stlport
//
// ?rva0007C50B@Rva0007C50B@@QAE@XZ @0x0007C50B 174B: dual-new ctor newing Rva007C454 (0x408) and CameraClass (0x3FC).
// Callers: 0x9A892 in FUN_0049a710. Callees rowed: EH_prolog new 0x2FDA0 Rva007C454 0x7C3CD CameraClass 0x134AB0.
#include <vector>
struct BfmeE16 { float x, y, z, w; };
class CamBase0 { public: CamBase0(); ~CamBase0(); virtual void f0(); private: int m_04; };
class CamBase1 { public: CamBase1(); virtual void g0(); };
class CameraClass : public CamBase0, public CamBase1 {
public: CameraClass(); ~CameraClass();
  char m_pad0[0xC4 - 12];
  int m_c4;
  char m_pad1[0xFC - 0xC4 - 4];
  unsigned char m_fc;
  char m_pad2[0x3FC - 0xFC - 1];
};
class Rva007C454 : public CameraClass {
public: Rva007C454();
private: _STL::vector<BfmeE16> m_3FC;
};
class Rva0007C50B {
public: Rva0007C50B();
private:
  Rva007C454 *m_a;
  CameraClass *m_b;
  float m_c, m_d, m_e;
  int m_f, m_g, m_h, m_i, m_j;
  bool m_k;
};
// ??0Rva0007C50B@@QAE@XZ present-unmatched
Rva0007C50B::Rva0007C50B()
{
  m_a = new Rva007C454;
  m_b = new CameraClass;
  m_c = 0.0f;
  m_d = 0.0f;
  m_e = 1.0f;
  m_f = 0; m_g = 0; m_h = 0; m_i = 0; m_j = 0;
  m_k = true;
  m_a->m_c4 = 1;
  m_a->m_fc = 0;
}
