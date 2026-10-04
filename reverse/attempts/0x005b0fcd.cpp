// ?rva005B0FCD@Rva005B0FCD@@QAEXH@Z
// partial score=0.83 date=2026-10-04
// cl: /O1 /G7 /GX- /MD
// Native5B0FCD/76: dynamic block at (index+31)*12, records stride20;
// zero index first invokes sibling5B097F, then forwards field+10 with
// increasing ordinal to5B07C1 and invokes virtual slot14. Identities unknown.
struct Rva005B0FCDRecord { int field0,field4,field8,fieldC,field10; };
struct Rva005B0FCDBlock { Rva005B0FCDRecord *start,*finish,*capacity; };
class Rva005B0FCD {
public:
 virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;
 virtual void v3()=0;virtual void v4()=0;virtual void v5()=0;
 void rva005B097F(int);
 void rva005B07C1(int,unsigned,int);
 void rva005B0FCD(int);
 unsigned char unknown[0x170];Rva005B0FCDBlock blocks[1];
};
void Rva005B0FCD::rva005B0FCD(int index) {
 int selected=index;
 index=0;
 Rva005B0FCDBlock *block=&blocks[selected];
 if(selected==0) rva005B097F(selected);
 for(Rva005B0FCDRecord *record=block->start;record!=block->finish;++record) {
  rva005B07C1(selected,index,record->field10);
  ++index;
 }
 v5();
}
