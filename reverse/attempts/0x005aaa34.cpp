// ?rva005AAA34@Rva005AA860@@QAEXXZ
// partial score=0.98 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva005AAA34@Rva005AA860@@QAEXXZ @0x005AAA34 162B. Identity: Rva005AA860 init creating Rva00573B23 at +0x58 from MenFortress then Coord and float and Slot6.
// Evidence: new 0x40 + ctor 0x00573A9B; StringBase ctor/set/releaseBuffer rowed; rva00573A00 rowed; movss float g_00C08954; virtual slot 0x18; caller 0x005AAB08 same class.
#include "ascii_string.h"

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Rva00573A00
{
public:
	void rva00573A00(const Coord3D *p);
};

enum ObjectID
{
	INVALID_ID = 0
};

class Rva0055B0CC
{
public:
	virtual void slot0();
	virtual void slot1();
	virtual void slot2();
	virtual void slot3();
	virtual void slot4();
	virtual void slot5();
	virtual void Slot6(void *arg1, bool arg2);
	virtual void slot7();
	virtual void slot8();
	virtual void slot9();
	virtual void slot10();
	virtual void slot11();
	virtual void Rva0055AED6(void *xfer, void *arg2);
public:
	float m_04;
	ObjectID m_08;
	AsciiString m_0C;
	unsigned int m_10;
	int m_pad14;
	float m_18;
	int m_pad1C;
	bool m_20;
	bool m_21;
	ObjectID m_24;
	bool m_28;
};

struct Coord3DBase
{
	float x;
	float y;
	float z;
};

class Rva00573B23 : public Rva0055B0CC
{
public:
	Rva00573B23();
public:
	AsciiString m_2c;
	Coord3DBase m_30;
	float m_3c;
};

extern float g_00C08954;

class Rva005AA860
{
public:
	virtual ~Rva005AA860();
	void rva005AAA34();
private:
	char m_pad04[0x20 - 4];
	void *m_20;
	void *m_24;
	char m_pad28[0x58 - 0x28];
	Rva00573B23 *m_58;
};

// ?rva005AAA34@Rva005AA860@@QAEXXZ present-unmatched
void Rva005AA860::rva005AAA34()
{
	{
		Rva00573B23 *p = new Rva00573B23();
		m_58 = p;
	}
	{
		AsciiString tmp("MenFortress");
		m_58->m_0C.set(tmp);
	}
	((Rva00573A00 *)m_58)->rva00573A00((const Coord3D *)((char *)m_20 + 0xc));
	m_58->m_04 = g_00C08954;
	m_58->m_20 = false;
	m_58->Slot6(m_24, false);
}
