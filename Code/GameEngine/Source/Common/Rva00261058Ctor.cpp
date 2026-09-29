// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva00261058@@QAE@PAVObject@@_N@Z, retail 0x00261058, 69 bytes.
// Player-filter ctor: base clears +4, vtable 0x007F8FE4, +8 controlling player or 0, +0xC flag.
// Evidence: caller 0x002FDCBE lea temp plus push 0 push esi; vtable store; rowed getControllingPlayer 0x0028AFA9; neighbours 0x00261046/0x0026115D.
class Player;
class Object
{
public:
	Player *getControllingPlayer() const;
};
class Rva00261058Base
{
public:
	Rva00261058Base() : m_base4(0) {}
	~Rva00261058Base();
private:
	int m_base4;
};
class Rva00261058 : public Rva00261058Base
{
public:
	Rva00261058(Object *obj, bool flag);
	virtual void dummy();
private:
	Player *m_player;
	bool m_flag;
};
Rva00261058::Rva00261058(Object *obj, bool flag) : Rva00261058Base()
{
	if (obj == 0)
		m_player = 0;
	else
		m_player = obj->getControllingPlayer();
	m_flag = flag;
}
// ?dummy@Rva00261058@@UAEXXZ present-unmatched
void Rva00261058::dummy() {}
