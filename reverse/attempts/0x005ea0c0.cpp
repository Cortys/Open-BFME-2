// ?rva005EA0C0@Rva005EA183@@QAEXXZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHs-c-
// ?rva005EA183@Rva005EA183@@QAEXXZ @0x005EA183 46B thiscall new-Link Set tail-slot1 caller 0x005EA5BD
// new AABTreeLinkClass(this as system) Set via rowed Rva00575674 tail virtual slot1 on holder ptr
class AABTreeCullSystemClass;
class AABTreeLinkClass
{
public:
  AABTreeLinkClass(AABTreeCullSystemClass *sys);
  char m_pad[0x10];
};
class Object
{
public:
  virtual void f0();
  virtual void f1();
  virtual void f2();
};
class Rva00575674
{
public:
  void rva00575674(Object *p);
  Object *m_ptr;
};
class Rva005EA183
{
public:
  void rva005EA183();
  void rva005EA5BD();
  void rva005EA0C0();
private:
  char m_pad[0x14];
  Rva00575674 m_holder;
};
extern const void *const g_00C78174[];
struct Rva005EA0C0Link
{
  const void *m_vptr;
  void *m_sys;
  Rva005EA0C0Link(void *s, const void *vt)
  {
    m_sys = s;
    m_vptr = vt;
  }
};
void Rva005EA183::rva005EA183()
{
  AABTreeLinkClass *link = new AABTreeLinkClass((AABTreeCullSystemClass *)this);
  m_holder.rva00575674((Object *)link);
  return m_holder.m_ptr->f1();
}
// ?rva005EA5BD@Rva005EA183@@QAEXXZ @0x005EA5BD 17B chain calls 0x005EA183 tail slot2 callers 0x005EAD00 0x005EAE75
void Rva005EA183::rva005EA5BD()
{
  rva005EA183();
  return m_holder.m_ptr->f2();
}
// ?rva005EA0C0@Rva005EA183@@QAEXXZ @0x005EA0C0 47B new-8 link Set tail-slot1 vtable g_00C78174 callers jmp 0x005EA260 0x005EA44A
// ?rva005EA0C0@Rva005EA183@@QAEXXZ present-unmatched
void Rva005EA183::rva005EA0C0()
{
  Rva005EA0C0Link *link = new Rva005EA0C0Link(this, (const void *)g_00C78174);
  m_holder.rva00575674((Object *)link);
  return m_holder.m_ptr->f1();
}
