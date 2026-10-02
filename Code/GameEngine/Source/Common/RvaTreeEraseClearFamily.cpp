// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX /arch:SSE
//
// STLport red-black tree node erase and clear bodies, one pair per tree
// instantiation, with the shapes of the rowed Rva00226883::rva00226883 (45-byte
// recursive erase: erase the right subtree, free the node, walk left) and
// Rva00226883::rva0022999F (41-byte clear: if non-empty, erase from the root and
// reset the header's links and the count). Found by searching .text for those
// shapes with call displacements masked: each erase calls only itself and free
// (0x00030830), each clear only its tree's erase. Which tree each belongs to is
// not recovered, so the owners are named after their erase's address (an erase
// already rowed keeps its owner and parameter type).

extern "C" void __cdecl free(void *block);

struct RvaTreeFamilyNode
{
	char m_pad[8]; // +0x00..0x07
	RvaTreeFamilyNode *m_next; // +0x08
	RvaTreeFamilyNode *m_child; // +0x0C
};

struct RvaTreeFamilyHead
{
	char m_pad00[4]; // +0x00
	RvaTreeFamilyNode *m_first; // +0x04
	RvaTreeFamilyHead *m_next; // +0x08
	RvaTreeFamilyHead *m_child; // +0x0C
};

// owner Rva0006F318: erase 0x0006F318, clear 0x0006FA70
class Rva0006F318
{
public:
	void rva0006F318(void *node);
	void rva0006FA70();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0006F318::rva0006F318(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0006F318(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0006F318::rva0006FA70()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0006F318(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0007E971: erase 0x0007E971, clear 0x0007FAC1
class Rva0007E971
{
public:
	void rva0007E971(void *node);
	void rva0007FAC1();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0007E971::rva0007E971(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0007E971(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0007E971::rva0007FAC1()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0007E971(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva000D20A9: erase 0x000D20A9, clear 0x000D2294
class Rva000D20A9
{
public:
	void rva000D20A9(void *node);
	void rva000D2294();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva000D20A9::rva000D20A9(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva000D20A9(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva000D20A9::rva000D2294()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva000D20A9(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva001DD70F: erase 0x001DD70F, clear 0x001DD846
class Rva001DD70F
{
public:
	void rva001DD70F(void *node);
	void rva001DD846();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva001DD70F::rva001DD70F(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva001DD70F(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva001DD70F::rva001DD846()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva001DD70F(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0021119B: erase 0x0021119B, clear 0x00211DD2
class Rva0021119B
{
public:
	void rva0021119B(void *node);
	void rva00211DD2();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0021119B::rva0021119B(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0021119B(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0021119B::rva00211DD2()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0021119B(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva002294A3: erase 0x002294A3, clear 0x0022C409
class Rva002294A3
{
public:
	void rva002294A3(void *node);
	void rva0022C409();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva002294A3::rva002294A3(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva002294A3(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva002294A3::rva0022C409()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva002294A3(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva002294D0: erase 0x002294D0, clear 0x0022C432
class Rva002294D0
{
public:
	void rva002294D0(void *node);
	void rva0022C432();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva002294D0::rva002294D0(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva002294D0(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva002294D0::rva0022C432()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva002294D0(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0027F4CB: erase 0x0027F4CB, clear 0x00280AB6
class Rva0027F4CB
{
public:
	void rva0027F4CB(void *node);
	void rva00280AB6();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0027F4CB::rva0027F4CB(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0027F4CB(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0027F4CB::rva00280AB6()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0027F4CB(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0028881C: erase 0x0028881C, clear 0x002889BB
class Rva0028881C
{
public:
	void rva0028881C(void *node);
	void rva002889BB();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0028881C::rva0028881C(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0028881C(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0028881C::rva002889BB()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0028881C(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva002A8B8C: erase 0x002A8B8C, clear 0x002A8BEE
class Rva002A8B8C
{
public:
	void rva002A8B8C(void *node);
	void rva002A8BEE();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva002A8B8C::rva002A8B8C(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva002A8B8C(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva002A8B8C::rva002A8BEE()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva002A8B8C(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00372F00: erase 0x00372F00, clear 0x00372F56
class Rva00372F00
{
public:
	void rva00372F00(void *node);
	void rva00372F56();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00372F00::rva00372F00(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva00372F00(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva00372F00::rva00372F56()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva00372F00(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00388EAE: erase 0x00388EAE, clear 0x00389129
class Rva00388EAE
{
public:
	void rva00388EAE(void *node);
	void rva00389129();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00388EAE::rva00388EAE(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva00388EAE(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva00388EAE::rva00389129()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva00388EAE(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0041331E: erase 0x0041331E, clear 0x0041334B
class Rva0041331E
{
public:
	void rva0041331E(void *node);
	void rva0041334B();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0041331E::rva0041331E(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0041331E(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0041331E::rva0041334B()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0041331E(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0043B2E2: erase 0x0043B2E2, clear 0x0043B334
class Rva0043B2E2
{
public:
	void rva0043B2E2(void *node);
	void rva0043B334();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0043B2E2::rva0043B2E2(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0043B2E2(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0043B2E2::rva0043B334()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0043B2E2(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0043EA9C: erase 0x0043EA9C, clear 0x0043F124
class Rva0043EA9C
{
public:
	void rva0043EA9C(void *node);
	void rva0043F124();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0043EA9C::rva0043EA9C(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0043EA9C(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0043EA9C::rva0043F124()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0043EA9C(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004D0545: erase 0x004D0545, clear 0x004D0F82
class Rva004D0545
{
public:
	void rva004D0545(void *node);
	void rva004D0F82();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004D0545::rva004D0545(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004D0545(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004D0545::rva004D0F82()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004D0545(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004D0572: erase 0x004D0572, clear 0x004D0FAB
class Rva004D0572
{
public:
	void rva004D0572(void *node);
	void rva004D0FAB();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004D0572::rva004D0572(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004D0572(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004D0572::rva004D0FAB()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004D0572(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004E7B13: erase 0x004E7B13, clear 0x004E7BAF
class Rva004E7B13
{
public:
	void rva004E7B13(void *node);
	void rva004E7BAF();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004E7B13::rva004E7B13(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004E7B13(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004E7B13::rva004E7BAF()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004E7B13(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004E9419: erase 0x004E9419, clear 0x004E94A1
class Rva004E9419
{
public:
	void rva004E9419(void *node);
	void rva004E94A1();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004E9419::rva004E9419(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004E9419(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004E9419::rva004E94A1()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004E9419(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004EA149: erase 0x004EA149, clear 0x004EA264
class Rva004EA149
{
public:
	void rva004EA149(void *node);
	void rva004EA264();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004EA149::rva004EA149(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004EA149(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004EA149::rva004EA264()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004EA149(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004FCA9C: erase 0x004FCA9C, clear 0x004FCBCD
class Rva004FCA9C
{
public:
	void rva004FCA9C(void *node);
	void rva004FCBCD();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004FCA9C::rva004FCA9C(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004FCA9C(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004FCA9C::rva004FCBCD()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004FCA9C(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004FCAC9: erase 0x004FCAC9, clear 0x004FCBF6
class Rva004FCAC9
{
public:
	void rva004FCAC9(void *node);
	void rva004FCBF6();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004FCAC9::rva004FCAC9(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004FCAC9(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004FCAC9::rva004FCBF6()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004FCAC9(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004FCAF6: erase 0x004FCAF6, clear 0x004FCC1F
class Rva004FCAF6
{
public:
	void rva004FCAF6(void *node);
	void rva004FCC1F();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004FCAF6::rva004FCAF6(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004FCAF6(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004FCAF6::rva004FCC1F()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004FCAF6(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004FF3DB: erase 0x004FF3DB, clear 0x004FF49F
class Rva004FF3DB
{
public:
	void rva004FF3DB(void *node);
	void rva004FF49F();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004FF3DB::rva004FF3DB(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004FF3DB(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004FF3DB::rva004FF49F()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004FF3DB(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva004FF408: erase 0x004FF408, clear 0x004FF4C8
class Rva004FF408
{
public:
	void rva004FF408(void *node);
	void rva004FF4C8();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva004FF408::rva004FF408(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva004FF408(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva004FF408::rva004FF4C8()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva004FF408(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0053BAE1: erase 0x0053BAE1, clear 0x0053BCC4
class Rva0053BAE1
{
public:
	void rva0053BAE1(void *node);
	void rva0053BCC4();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0053BAE1::rva0053BAE1(void *node)
{
	if (!node)
		return;
	RvaTreeFamilyNode *cur = (RvaTreeFamilyNode *)node;
	do {
		rva0053BAE1(cur->m_child);
		RvaTreeFamilyNode *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva0053BAE1::rva0053BCC4()
{
	if (m_04Flag == 0)
		return;
	RvaTreeFamilyHead *h = (RvaTreeFamilyHead *)m_00Head;
	rva0053BAE1(h->m_first);
	((RvaTreeFamilyHead *)m_00Head)->m_next = (RvaTreeFamilyHead *)m_00Head;
	((RvaTreeFamilyHead *)m_00Head)->m_first = 0;
	((RvaTreeFamilyHead *)m_00Head)->m_child = (RvaTreeFamilyHead *)m_00Head;
	m_04Flag = 0;
}
