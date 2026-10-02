// cl: /O1 /MD
// Sibling of rowed scalar deleting dtor ??_GRva006FB9B0@@UAEPAXI@Z at
// 0x006FB980 (35B). Retail 0x006CC320 (38B) is the scalar deleting dtor for
// a different class: it runs the complete SEH dtor at 0x006E6430, then, when
// the low flag bit is set, frees 0xB4 bytes through the pinned pool
// deallocator 0x006DB270 with the pool object at 0x00E176E8, and returns
// this (ret 4). The 0xB4 size is the class's own sizeof.
class Rva006DE350
{
public:
	virtual ~Rva006DE350();
};

class Rva006DB270
{
public:
	void freeBlock(void *block, int blockSize);
};

extern Rva006DB270 *g_pChainBlockAllocator; // 0x00E176E8

class Rva006E6430 : public Rva006DE350
{
public:
	virtual ~Rva006E6430();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
	char m_pad[0xB0]; // +0x04..0xB3: sizeof 0xB4 for the sized delete
};

// The empty body exists only to force ??_G emission; the complete dtor's
// real bytes live at 0x006E6430 and are pinned as a callee candidate.
// ??1Rva006E6430@@UAE@XZ present-unmatched
Rva006E6430::~Rva006E6430()
{
}

void deleteRva006E6430(Rva006E6430 *p)
{
	delete p;
}
