// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva002611F2@@QAE@PAVObject@@@Z, retail 0x002611F2, 84 bytes.
// Player-gated filter ctor: base clears +4, vtable 0x007F8FF0, +8 obj, +0xC flag set when controlling player +0x5C is 1.
// Evidence: sibling 0x00261058 same FuncInfo 0xB72D5F same base pattern; two getControllingPlayer calls 0x0028AFA9; neighbours 0x00261176/0x0026157E.
class Player
{
public:
	char m_pad[0x5C];
	int m_field5C;
};
class Object
{
public:
	Player *getControllingPlayer() const;
};
class Rva002611F2Base
{
public:
	Rva002611F2Base() : m_base4(0) {}
	~Rva002611F2Base();
private:
	int m_base4;
};
class Rva002611F2 : public Rva002611F2Base
{
public:
	Rva002611F2(Object *obj);
	virtual void dummy();
private:
	Object *m_obj;
	bool m_flag;
};
Rva002611F2::Rva002611F2(Object *obj) : Rva002611F2Base()
{
	m_obj = obj;
	m_flag = false;
	if (obj->getControllingPlayer() != 0) {
		if (m_obj->getControllingPlayer()->m_field5C == 1)
			m_flag = true;
	}
}
// ?dummy@Rva002611F2@@UAEXXZ present-unmatched
void Rva002611F2::dummy() {}
