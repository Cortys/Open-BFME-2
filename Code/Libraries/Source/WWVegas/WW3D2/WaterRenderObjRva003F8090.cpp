// cl: /O1 /MD
// ?rva003F8090@Rva003F8090@@QAEXXZ, retail 0x003F8090 (31B).
// Evidence: chain lane calls rowed 0x003F7F30; offsets +0xc begin +0x10 end +0x18 flag.
class Rva003F7F30
{
public:
	void rva003F7F30();
};

class Rva003F8090
{
public:
	void rva003F8090();
private:
	char m_00[0xc];
	Rva003F7F30 **m_0c;
	Rva003F7F30 **m_10;
	char m_14[4];
	int m_18;
};

void Rva003F8090::rva003F8090()
{
	m_18 = -1;
	Rva003F7F30 **p = m_0c;
	Rva003F7F30 **e = m_10;
	while (p != e)
	{
		(*p)->rva003F7F30();
		++p;
	}
}

// ?rva003F8076@Rva003F8076@@QAEXXZ @0x003F8076 13B.
// Null-checked tail forward to rowed 0x003F7E83 via +0x14 member.
// Evidence: unlock lane; retail mov ecx,[ecx+0x14]; test ecx,ecx; je ret;
// jmp 0x003F7E83; caller jmp at 0x003F837F in unclaimed 0x003F8374.
class Rva003F7E83
{
public:
	void rva003F7E83();
	void rva003F7E90();
};

class Rva003F8076
{
public:
	void rva003F8076();
private:
	char m_00[0x14];
	Rva003F7E83 *m_14;
};

void Rva003F8076::rva003F8076()
{
	Rva003F7E83 *p = m_14;
	if (p == 0)
		return;
	p->rva003F7E83();
}

// ?rva003F8083@Rva003F8083@@QAEXXZ @0x003F8083 13B.
// Null-checked tail forward to rowed 0x003F7E90 via +0x14 member.
// Evidence: unlock lane sibling of 0x003F8076; retail mov ecx,[ecx+0x14];
// test ecx,ecx; je ret; jmp 0x003F7E90; caller jmp at 0x003F8390.
class Rva003F8083
{
public:
	void rva003F8083();
private:
	char m_00[0x14];
	Rva003F7E83 *m_14;
};

void Rva003F8083::rva003F8083()
{
	Rva003F7E83 *p = m_14;
	if (p == 0)
		return;
	p->rva003F7E90();
}
