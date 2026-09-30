// cl: /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
// ??1Rva00180B94_Prototype@@UAE@XZ @0x00180A46 90B
// Virtual dtor twin of Rva001805E0 (0x00180527 90B): stores vtable
// 0x007D5050, deletes +0x14 link via slot-0 virtual get(0) plus operator
// delete 0x0002FD60 row, tears down +0x18 StringClass via 0x00610A40,
// delegates to base 0x0061ED80. Layout mirrors Rva00180B94Ctor.cpp.
class Rva001805E0Link
{
public:
	virtual void *get(int x);
};

class StringClass
{
public:
	~StringClass();
};

class Rva0061ED80
{
public:
	virtual ~Rva0061ED80();
};

class Rva00180B94_Prototype : public Rva0061ED80
{
public:
	virtual ~Rva00180B94_Prototype();

private:
	char m_pad04[0x10];
	Rva001805E0Link *m_link;
	StringClass m_name;
};

Rva00180B94_Prototype::~Rva00180B94_Prototype()
{
	void *tmp = m_link ? m_link->get(0) : 0;
	delete tmp;
}
