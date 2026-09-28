// cl: /O1 /MD
//
// ??1Rva005D242F@@UAE@XZ retail 0x005D242F 26 bytes.
// Stores vtable 0x008757D8 then if linked word at +0x18 equals member at +0xC
// clears it to -1 then tail-jmps to rowed base dtor ??1Rva005C3F02@@UAE@XZ
// at 0x005C3F02. Caller is deleting dtor at 0x005D2495. Base member at +8 is
// a pointer to a struct with int at +0x18; derived member at +0xC is int.
// Honest address name; owner class unproven.
struct Rva005D242FLinked
{
	int m00, m04, m08, m0C, m10, m14;
	int m18;
};

class Rva005C3F02
{
public:
	virtual ~Rva005C3F02();
protected:
	int m04;
	Rva005D242FLinked *m08;
};

class Rva005D242F : public Rva005C3F02
{
public:
	virtual ~Rva005D242F();
private:
	int m0C;
};

Rva005D242F::~Rva005D242F()
{
	if (m08->m18 == m0C)
		m08->m18 = -1;
}
