// cl: /O1 /DNDEBUG /MD
//
// ?rva0026D56C@Rva0026D56C@@QAEX... @0x0026D56C 143B: vtable slot 23 of AIUpdate
// family. Guards on Object::isMobile, optional Rva001E4147 copy, three virtuals
// on member +0x30, voice response for b==0/1, then AICommandInterface call.
// Evidence: 5 vtables slot 23, caller 0x0049AC5F ret 8, rowed callees.
class Object
{
public:
	bool isMobile() const;
};

struct Rva001E4147Twelve
{
	int a;
	int b;
	int c;
};

class Rva001E4147
{
public:
	void rva001E4147(Rva001E4147Twelve *src);
};

struct Coord3D
{
	float x;
	float y;
	float z;
};

class BFMEMoveVoiceAI
{
public:
	void playMoveVoiceResponse(const Coord3D *pos);
};

enum CommandSourceType
{
	CMD_DUMMY = 0
};

class AICommandInterface
{
public:
	void rva0026C486(Object *obj, CommandSourceType src);
};

class M30
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8(int v);
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14(void *p);
};

class Rva0026D56C
{
public:
	virtual void rva0026D56C(void *a, int b);
private:
	char m_pad00[4];
	Object *m_object; // +8
	char m_pad0C[0x30 - 0x0C];
	M30 *m_30; // +30
	char m_pad34[0x48 - 0x34];
	int m_48; // +48
	char m_pad4C[0x16c - 0x4C];
	int m_16c; // +16c
	char m_pad170[0x1f0 - 0x170];
	Rva001E4147 *m_1f0; // +1f0
	char m_pad1F4[0x3b8 - 0x1f4];
	unsigned char m_3b8; // +3b8
};

void Rva0026D56C::rva0026D56C(void *a, int b)
{
	if (!m_object->isMobile())
		return;
	if (m_1f0)
		m_1f0->rva001E4147((Rva001E4147Twelve *)m_object);
	m_30->v5();
	m_30->v14(a);
	m_16c = 0;
	m_3b8 = 0;
	m_48 = b;
	m_30->v8(56);
	if (b == 0 || b == 1)
		((BFMEMoveVoiceAI *)this)->playMoveVoiceResponse((const Coord3D *)((char *)a + 0x38));
	if ((*(unsigned char *)(*(int *)((char *)a + 4) + 0x11f) & 0x80) == 0)
		return;
	((AICommandInterface *)(*(char **)((char *)a + 0x258) + 0x20))->rva0026C486(m_object, (CommandSourceType)b);
}
