// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /EHsc
// ?rva0035118A@Rva0035118A@@QAEXH@Z, RVA 0x0035118A, 63 bytes.
// Leaf: this+0x20 ObjectID via TheGameLogic->findObjectByID, Object+0x250
// virtual +0x44 with (this+0x18)->+0x14 and 2, then (this+0x18) virtual
// +0x38 with 0. Single stack arg unused (ret 4). Evidence: rowed
// GameLogic::findObjectByID 0x00049DC5, TheGameLogic 0x00DFE78C.
enum ObjectID
{
	INVALID_ID = 0
};
class Object;
class Rva0035118A_A;
class Rva0035118A_B;
class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};
extern GameLogic *TheGameLogic;
class Rva0035118A_A
{
public:
	virtual void a00();
	virtual void a01();
	virtual void a02();
	virtual void a03();
	virtual void a04();
	virtual void a05();
	virtual void a06();
	virtual void a07();
	virtual void a08();
	virtual void a09();
	virtual void a10();
	virtual void a11();
	virtual void a12();
	virtual void a13();
	virtual void a14();
	virtual void a15();
	virtual void a16();
	virtual void slot44(int v, int w);
};
class Rva0035118A_B
{
public:
	virtual void b00();
	virtual void b01();
	virtual void b02();
	virtual void b03();
	virtual void b04();
	virtual void b05();
	virtual void b06();
	virtual void b07();
	virtual void b08();
	virtual void b09();
	virtual void b10();
	virtual void b11();
	virtual void b12();
	virtual void b13();
	virtual void slot38(int v);
	char m_pad[0x10];
	int m_x14;
};
class Object
{
public:
	char m_pad[0x250];
	Rva0035118A_A *m_a250;
};
class Rva0035118A
{
public:
	char m_pad[0x18];
	Rva0035118A_B *m_p18;
	int m_unk1C;
	ObjectID m_id20;
	void rva0035118A(int unused);
};
void Rva0035118A::rva0035118A(int unused)
{
	(void)unused;
	ObjectID id = m_id20;
	if (id != 0) {
		Object *obj = TheGameLogic->findObjectByID(id);
		if (obj) {
			Rva0035118A_A *a = obj->m_a250;
			if (a) {
				a->slot44(m_p18->m_x14, 2);
			}
		}
	}
	m_p18->slot38(0);
}
