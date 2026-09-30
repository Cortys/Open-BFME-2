// cl: /Ireference/shims/bfme2_ascii /O1 /MD
//
// Opaque single-member destructors that tail-call the folded AsciiString
// member destructor at 0x0036410, the same shape as Bucket::~Bucket (vtable
// store, this-adjust, tail jump). Each class below is a distinct retail
// vtable whose owner identity is unproven; the member offset is retail
// measured per body. One ledger row per destructor, landed one commit at
// a time; the AsciiStringMember declaration is shared and never defined
// (it resolves to the 0x36410 fold via symbols.csv).

class AsciiStringMember
{
public:
	~AsciiStringMember();
};

class Rva00217537
{
public:
	virtual ~Rva00217537();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

Rva00217537::~Rva00217537()
{
}

class Rva0030714F
{
public:
	virtual ~Rva0030714F();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

Rva0030714F::~Rva0030714F()
{
}

class Rva004E156B
{
public:
	virtual ~Rva004E156B();

private:
	AsciiStringMember m_member04;
};

Rva004E156B::~Rva004E156B()
{
}

class Rva004E194E
{
public:
	virtual ~Rva004E194E();

private:
	char m_pad04[8];
	AsciiStringMember m_member0C;
};

Rva004E194E::~Rva004E194E()
{
}

class Rva004FA830
{
public:
	virtual ~Rva004FA830();

private:
	AsciiStringMember m_member04;
};

Rva004FA830::~Rva004FA830()
{
}

class Rva00538C5F
{
public:
	virtual ~Rva00538C5F();

private:
	AsciiStringMember m_member04;
};

Rva00538C5F::~Rva00538C5F()
{
}

#include "ascii_string.h"

class Rva005C31FB
{
public:
	virtual ~Rva005C31FB();
	Rva005C31FB(int level, const AsciiString &name);

private:
	int m_level;
	AsciiString m_name;
	bool m_flag0C;
};

// ??0Rva005C31FB@@QAE@HABVAsciiString@@@Z @0x005C31D5 38B: vtable 0x008743F8, level at +4, name copy at +8 via 0x365F0, flag 0 at +0xC.
// Callers at 0x005284F4 0x00528B11 0x005F2856 pass level from GetLevel 0x4128BB plus StringBase temp; new 0x10.
// Sibling dtor at 0x005C31FB plus deleting dtor at 0x005C327F in this TU (/O1 /MD).
Rva005C31FB::Rva005C31FB(int level, const AsciiString &name) : m_level(level), m_name(name), m_flag0C(false)
{
}

Rva005C31FB::~Rva005C31FB()
{
}
