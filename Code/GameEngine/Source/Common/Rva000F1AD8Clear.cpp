// cl: /O1 /MD /EHsc
// ?rva000F1AD8@Rva000F1AD8@@QAEXXZ @0x000F1AD8 95B
// Evidence: unlock lane calls rowed First Next Reset plus virtual release; table at +0; iterator on stack.
class HashableClass {
public:
 virtual void release();
 int m_ref;
 HashableClass *m_next;
};
class HashTableClass {
public:
 void Reset();
};
struct IterBase {
 const HashTableClass *m_table;
 IterBase(HashTableClass *t) : m_table(t) {}
};
class HashTableIteratorClass : public IterBase {
 int m_index;
 HashableClass *m_cur;
 HashableClass *m_next;
public:
 HashTableIteratorClass(HashTableClass *t) : IterBase(t) {}
 virtual ~HashTableIteratorClass() {}
 void First();
 void Next();
 bool Is_Done() { return m_cur == 0; }
 HashableClass *Get_Current() { return m_cur; }
};
struct Rva000F1AD8 {
 HashTableClass *m_00;
 void rva000F1AD8();
};
void Rva000F1AD8::rva000F1AD8()
{
 HashTableClass *t = m_00;
 HashTableIteratorClass it(t);
 it.First();
 while (!it.Is_Done()) {
 HashableClass *e = it.Get_Current();
 HashableClass *b = e ? (HashableClass*)((char*)e - 8) : 0;
 if (--b->m_ref == 0)
 b->release();
 it.Next();
 }
 m_00->Reset();
}
