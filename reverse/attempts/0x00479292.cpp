// ?getObjectGarrisonPointIndex@GarrisonContain@@UAEHW4ObjectID@@@Z
// partial score=0.91 date=2026-09-26
// ?getObjectGarrisonPointIndex@GarrisonContain@@UAEHW4ObjectID@@@Z
// partial score=0.91 date=2026-09-26
// cl: /O1 /DNDEBUG /MD /EHsc
typedef int Int;
enum ObjectID { INVALID_ID = 0, FORCE = 0x7ffffff };
class Object;
struct ListNode { ListNode *next; ListNode *prev; Object *obj; };
struct ListHeader {
  ListNode *head;
  ListNode *tail;
  ListHeader() {}
  ListHeader(const ListHeader &o) { head = o.head; tail = o.tail; }
};
class HordeContainInterface {
public:
#define H(n) virtual void s##n() = 0;
H(00)H(01)H(02)H(03)H(04)H(05)H(06)H(07)H(08)H(09)H(10)H(11)H(12)H(13)H(14)H(15)H(16)H(17)H(18)H(19)H(20)H(21)H(22)H(23)H(24)H(25)H(26)H(27)H(28)H(29)H(30)H(31)H(32)H(33)H(34)H(35)H(36)H(37)H(38)H(39)H(40)H(41)H(42)H(43)H(44)H(45)H(46)H(47)H(48)H(49)H(50)H(51)H(52)H(53)H(54)H(55)H(56)H(57)H(58)H(59)H(60)H(61)H(62)H(63)H(64)H(65)
#undef H
  virtual ListHeader getContainList() const = 0;
};
class ObjectContainModuleInterface {
public:
#define C(n) virtual void c##n() = 0;
C(00)C(01)C(02)C(03)C(04)C(05)C(06)C(07)C(08)C(09)C(10)C(11)C(12)C(13)C(14)C(15)C(16)C(17)C(18)C(19)C(20)C(21)C(22)C(23)C(24)C(25)C(26)C(27)C(28)C(29)C(30)
#undef C
  virtual HordeContainInterface *getHordeContainInterface() = 0;
};
class Object {
public:
  ObjectID getID() const { return m_id; }
private:
  char pad0[0x74];
  ObjectID m_id;
  char pad1[0x250-0x78];
public:
  ObjectContainModuleInterface *m_contain;
};
class GameLogic { public: Object *findObjectByID(ObjectID id); };
#define TheGameLogic (*(GameLogic **)0x00DFE78C)
struct GarrisonPointData { ObjectID objectID; Int a,b,c; void *e; };
class GarrisonContain {
public:
#define G(n) virtual void g##n() = 0;
G(00)G(01)G(02)G(03)G(04)G(05)G(06)G(07)G(08)G(09)G(10)G(11)G(12)G(13)G(14)G(15)G(16)G(17)G(18)G(19)G(20)G(21)G(22)G(23)G(24)G(25)G(26)
#undef G
  virtual Int getObjectGarrisonPointIndex(ObjectID id);
private:
  char pad[0x100-4];
  GarrisonPointData arr[40];
};
// ?getObjectGarrisonPointIndex@GarrisonContain@@UAEHW4ObjectID@@@Z present-unmatched
Int GarrisonContain::getObjectGarrisonPointIndex(ObjectID objectID) {
  if (objectID == INVALID_ID) return -1;
  Object *object = TheGameLogic->findObjectByID(objectID);
  if (object == 0) return -1;
  Int i = 0;
  GarrisonPointData *point = arr;
  for (; i < 40; ++i, ++point) {
    ObjectContainModuleInterface *contain = object->m_contain;
    if (contain != 0) {
      HordeContainInterface *horde = contain->getHordeContainInterface();
      if (horde != 0) {
        ListHeader list = horde->getContainList();
        ListNode *end = list.tail->next;
        for (ListNode *it = end->next; it != end; it = it->next) {
          ObjectID cid = it->obj->getID();
          for (Int j = 0; j < 40; ++j) {
            if (arr[j].objectID == cid) return j;
          }
        }
      }
    } else if (point->objectID == objectID) {
      return i;
    }
  }
  return -1;
}
