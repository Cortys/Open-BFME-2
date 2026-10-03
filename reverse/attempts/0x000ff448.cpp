// ?rva000FF448@Rva000FF448@@QAEXXZ
// partial score=0.97 date=2026-10-03
// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /Ireference/open-bfme-1/game/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/game/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/inputs/reference/shims/sweep
// ?rva000FF448@Rva000FF448@@QAEXXZ, retail 0x000FF448, 142 bytes.
// Evidence: leaf lane; first list tail +0x10 via FeNode +0x3c flag +0xb0 next
// with conditional rva000FE001 move, second list head +0x14 via BfmeThingSH
// reset plus operator delete, then three intrusive releases at +4/+8/+0 with
// dec [ecx+4] plus virtual slot 0; caller 0xFF4D6; neighbours FE9E3/FF50D.
struct FeNode
{
	unsigned char m_pad0[0x3c];
	unsigned char m_flag3c;
	unsigned char m_pad1[0xb0 - 0x3d];
	FeNode *m_next;
	FeNode *m_prev;
};

class Rva000FE001
{
public:
	void rva000FE001(FeNode *other);
private:
	unsigned char m_pad[0x10];
	FeNode *m_tail10;
	FeNode *m_head14;
};

class BfmeThingSH
{
public:
	void bfmeResetSH();
	void *m_vft00;
	void *m_sub04;
	unsigned char m_pad08[0x3c - 0x08];
	unsigned char m_flag3c;
	unsigned char m_pad3d[0xb0 - 0x3d];
	BfmeThingSH *m_nextB0;
	BfmeThingSH *m_prevB4;
};

class RefObj
{
public:
	virtual void Release();
	int m_ref;
};

void __cdecl operator delete(void *p);

class Rva000FF448
{
public:
	void rva000FF448();
private:
	RefObj *m_00;
	RefObj *m_04;
	RefObj *m_08;
	unsigned char m_pad0c[0x10 - 0x0c];
	FeNode *m_tail10;
	BfmeThingSH *m_head14;
};

// ?rva000FF448@Rva000FF448@@QAEXXZ present-unmatched
void Rva000FF448::rva000FF448()
{
	FeNode *node = m_tail10;
	while (node != 0)
	{
		FeNode *next = node->m_next;
		if (node->m_flag3c == 0)
			((Rva000FE001 *)this)->rva000FE001(node);
		node = next;
	}
	m_tail10 = 0;
	while (m_head14 != 0)
	{
		BfmeThingSH *cur = m_head14;
		BfmeThingSH *next = m_head14->m_nextB0;
		cur->bfmeResetSH();
		::operator delete(cur);
		m_head14 = next;
	}
	RefObj *p4 = m_04;
	if (p4 != 0)
	{
		if (--p4->m_ref == 0)
			p4->Release();
		m_04 = 0;
	}
	RefObj *p8 = m_08;
	if (p8 != 0)
	{
		if (--p8->m_ref == 0)
			p8->Release();
		m_08 = 0;
	}
	RefObj *p0 = m_00;
	if (p0 != 0)
	{
		if (--p0->m_ref == 0)
			p0->Release();
		m_00 = 0;
	}
}
