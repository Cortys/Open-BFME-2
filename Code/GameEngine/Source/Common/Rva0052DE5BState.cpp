// cl: /O1 /G7 /DNDEBUG /MD /EHsc
//
// Rva0052DE5B::rva0052DE5B (retail 0x0052DE5B, 64 bytes): finish-reset that
// releases the node buffer back to the pool at 0x00A049D0 when the low nibble
// of the state flags is not 4, the node exists, five dwords at +0x14 are all
// zero, the backlink at +0x38 is null and the node flags at +0x2c have none of
// 0x18 set, then clears the node. Ported from Open-BFME-1
// Code/GameEngine/Source/Common/Rva003F7380State.cpp finishReset, with link
// and flag fields shifted +8 (value at +0x28, flags at +0x2c, link at +0x38)
// and the low-nibble mask widened 7 -> 0xf plus five zero-checked dwords at
// +0x14. Callees are declared-only so the gate resolves them; retail homes
// this in esi.

class MixFileInfoBuffer
{
public:
	void releaseInto(void *pool);
};

extern int TheMixFileInfoPool;

struct Rva0052DE5BNode
{
	unsigned char m_pad0[0x14];
	unsigned int m_check[5];
	int m_value;
	unsigned int m_nodeFlags;
	unsigned char m_pad1[8];
	void *m_link;
};

class Rva0052DE5B
{
public:
	void rva0052DE5B();
	void rva0052DED3();
	Rva0052DE5B *rva0052DFF2();

private:
	Rva0052DE5BNode *m_node;
	unsigned int m_4;
	unsigned short m_8;
	unsigned short m_A;
	unsigned int m_flags;
};

void Rva0052DE5B::rva0052DE5B()
{
	if ((m_flags & 0xf) == 4)
		return;
	Rva0052DE5BNode *node = m_node;
	if (node == 0)
		return;
	for (int i = 0; i < 5; ++i)
	{
		if (node->m_check[i] != 0)
			return;
	}
	if (node->m_link != 0)
		return;
	if ((node->m_nodeFlags & 0x18) != 0)
		return;
	((MixFileInfoBuffer *)node)->releaseInto(&TheMixFileInfoPool);
	m_node = 0;
}

void Rva0052DE5B::rva0052DED3()
{
	m_4 = 0;
	m_8 = 0xffff;
	m_flags = (m_flags & 0xff000010) | 0x10;
	rva0052DE5B();
}

Rva0052DE5B *Rva0052DE5B::rva0052DFF2()
{
	m_node = 0;
	rva0052DED3();
	return this;
}
