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
private:
  char m_pad[0x14];
  Rva00575674 m_holder;
};
void Rva005EA183::rva005EA183()
{
  AABTreeLinkClass *link = new AABTreeLinkClass((AABTreeCullSystemClass *)this);
  m_holder.rva00575674((Object *)link);
  return m_holder.m_ptr->f1();
}
