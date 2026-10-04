// cl: /O1 /MD
//
// ?rva00091189@Rva00091189@@QAEXXZ 0x00091189 109B.
// VP6 chunk poll: sets +0x48/+0x4c to -1, runs the embedded range at +0x1c
// through invokeForMode/Go/Advance (rows 0x00106A06/0x001068D1/0x0010690D),
// dispatching probe tags 0x36505641 ('AVP6') and 0x6468564D ('MVhd'),
// then the slot-2 virtual and winmm timeGetTime into +0x50.
// Donor evidence for the tag pair and shapes:
// Open-BFME-1 Rva007E55F0Vp6StreamInvoke.cpp ('MVhd' chunk noting 'AVP6',
// id == 0x36505641 / 0x6468564d) and Rva007E4AD0Vp6Update.cpp
// (first == 0x36505641 / 0x6468564D). Embedded layout (+4 dev/+8 kind,
// slot 0x14) shares Rva007E3410Object/BfmeB996Range; caller at 0x00091315.

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime();

class Rva007E3410Object
{
public:
	void invokeForMode();
};

class BfmeB996Range
{
public:
	bool rva001068D1( int first, unsigned int *second, char *third );
	void rva0010690D();
};

class Rva00091189
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	void rva00091189();

private:
	char m_pad04[ 0x18 ];
	char m_range[ 0x10 ];
	char m_pad2c[ 0x1c ];
	int m_48;
	int m_4c;
	unsigned long m_50;
};

void Rva00091189::rva00091189()
{
	m_48 = -1;
	m_4c = -1;
	char *range = m_range;
	( (Rva007E3410Object *)range )->invokeForMode();
	int probe;
	unsigned int arg;
	char flag;
	goto go;
tag:
	if ( probe == 0x36505641 ) {
		( (BfmeB996Range *)range )->rva0010690D();
		goto go;
	}
	if ( probe == 0x6468564D )
		goto mvhd;
go:
	if ( ( (BfmeB996Range *)range )->rva001068D1( (int)&probe, &arg, &flag ) )
		goto tag;
	goto done;
mvhd:
	( (BfmeB996Range *)range )->rva0010690D();
done:
	v2();
	m_50 = timeGetTime();
}
