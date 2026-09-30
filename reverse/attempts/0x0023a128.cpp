// ??0Rva0023A128@@QAE@PAX0H@Z
// partial score=0.92 date=2026-09-30
// ??0Rva0023A128@@QAE@PAX0H@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
extern const void *const g_00BED658[];
extern const void *const g_00BED6C0[];
extern const void *const g_00BED6B8[];
class Rva0042D8D4 { public: Rva0042D8D4(); int m_0; };
struct Rva002BA8F1Listener { char opaque[4]; };
class Rva005A0B4CList { public: void append(Rva002BA8F1Listener *p); char m_pad[12]; };
struct Holder { char pad[4]; Rva005A0B4CList list; };
class Rva002BA8F1Logic { public: char pad[0x4c]; Rva005A0B4CList list; };
extern Rva002BA8F1Logic *g_009FEF10;
class EmptyBase { public: EmptyBase() {} ~EmptyBase(); };
struct WrapPtr { WrapPtr(void *p) : m(p) {} ~WrapPtr(); void *m; };
class Rva0023A128 : public EmptyBase {
public:
  Rva0023A128(void *a0, void *a1, int a2);
  ~Rva0023A128();
  const void *m_00;
  const void *m_04;
  WrapPtr m_08;
  void *m_0C;
  int m_10;
  Rva0042D8D4 m_14;
  int m_18;
  int m_1C;
};
Rva0023A128::Rva0023A128(void *a0, void *a1, int a2)
  : EmptyBase(), m_04(g_00BED658), m_08(a0), m_0C(a1), m_00(g_00BED6C0), m_10(a2), m_14(), m_18(0), m_1C(0)
{
  m_04 = g_00BED6B8;
  ((Holder*)m_0C)->list.append((Rva002BA8F1Listener*)(void*)this);
  g_009FEF10->list.append((Rva002BA8F1Listener*)(void*)((char*)this+4));
}
