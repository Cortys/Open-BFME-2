// cl: /O1 /MD
//
// 29 scalar deleting destructors sharing the Rva006FB9B0DeletingDtor.cpp
// shape (35 bytes each): call the class complete destructor, then a sized
// release through one of two pinned chain-block pools. The class is named
// after its own deleting destructor RVA; the complete dtor is only declared
// and resolves through its symbols.csv pin (same recipe as the
// Rva004B8CDEDeletingDtor.cpp opaque-middle stub), so the local empty body is
// emission scaffolding, not a recovery claim. The stub is marked
// present-unmatched and the full dtor bodies stay unrowed.
//
// Variation per member: complete-dtor call target, pool object
// (0x00E176E8/Rva006DB270 or 0x00E176F4/Rva006D2A60) and class size.

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

class Rva006D2A60
{
public:
	void freeBlock(void *block, int blockSize);
};

extern Rva006DB270 *g_pChainBlockAllocator;   // 0x00E176E8
// 0x00E176F4, zero-filled .bss (4 bytes); defined here, the first of its
// referencing units in link order.
Rva006D2A60 *g_pChainBlockAllocatorF4 = 0;


class Rva006CBF40 : public Rva006DE350
{
public:
	virtual ~Rva006CBF40();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x5C]; // sizeof 0x60
};

// ?Rva006CBF40::~Rva006CBF40 present-unmatched
Rva006CBF40::~Rva006CBF40()
{
}

void deleteRva006CBF40(Rva006CBF40 *p)
{
	delete p;
}

class Rva006CC2F0 : public Rva006DE350
{
public:
	virtual ~Rva006CC2F0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
};

// ?Rva006CC2F0::~Rva006CC2F0 present-unmatched
Rva006CC2F0::~Rva006CC2F0()
{
}

void deleteRva006CC2F0(Rva006CC2F0 *p)
{
	delete p;
}

class Rva006CD620 : public Rva006DE350
{
public:
	virtual ~Rva006CD620();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x4]; // sizeof 0x8
};

// ?Rva006CD620::~Rva006CD620 present-unmatched
Rva006CD620::~Rva006CD620()
{
}

void deleteRva006CD620(Rva006CD620 *p)
{
	delete p;
}

class Rva006CEA60 : public Rva006DE350
{
public:
	virtual ~Rva006CEA60();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
	char m_pad[0x18]; // sizeof 0x1C
};

// ?Rva006CEA60::~Rva006CEA60 present-unmatched
Rva006CEA60::~Rva006CEA60()
{
}

void deleteRva006CEA60(Rva006CEA60 *p)
{
	delete p;
}

class Rva006D64D0 : public Rva006DE350
{
public:
	virtual ~Rva006D64D0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006D64D0::~Rva006D64D0 present-unmatched
Rva006D64D0::~Rva006D64D0()
{
}

void deleteRva006D64D0(Rva006D64D0 *p)
{
	delete p;
}

class Rva006D6570 : public Rva006DE350
{
public:
	virtual ~Rva006D6570();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x20]; // sizeof 0x24
};

// ?Rva006D6570::~Rva006D6570 present-unmatched
Rva006D6570::~Rva006D6570()
{
}

void deleteRva006D6570(Rva006D6570 *p)
{
	delete p;
}

class Rva006D71B0 : public Rva006DE350
{
public:
	virtual ~Rva006D71B0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
	char m_pad[0x4]; // sizeof 0x8
};

// ?Rva006D71B0::~Rva006D71B0 present-unmatched
Rva006D71B0::~Rva006D71B0()
{
}

void deleteRva006D71B0(Rva006D71B0 *p)
{
	delete p;
}

class Rva006D71E0 : public Rva006DE350
{
public:
	virtual ~Rva006D71E0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x18]; // sizeof 0x1C
};

// ?Rva006D71E0::~Rva006D71E0 present-unmatched
Rva006D71E0::~Rva006D71E0()
{
}

void deleteRva006D71E0(Rva006D71E0 *p)
{
	delete p;
}

class Rva006DA560 : public Rva006DE350
{
public:
	virtual ~Rva006DA560();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x28]; // sizeof 0x2C
};

// ?Rva006DA560::~Rva006DA560 present-unmatched
Rva006DA560::~Rva006DA560()
{
}

void deleteRva006DA560(Rva006DA560 *p)
{
	delete p;
}

class Rva006DE280 : public Rva006DE350
{
public:
	virtual ~Rva006DE280();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006DE280::~Rva006DE280 present-unmatched
Rva006DE280::~Rva006DE280()
{
}

void deleteRva006DE280(Rva006DE280 *p)
{
	delete p;
}

class Rva006DE760 : public Rva006DE350
{
public:
	virtual ~Rva006DE760();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006DE760::~Rva006DE760 present-unmatched
Rva006DE760::~Rva006DE760()
{
}

void deleteRva006DE760(Rva006DE760 *p)
{
	delete p;
}

class Rva006E9B20 : public Rva006DE350
{
public:
	virtual ~Rva006E9B20();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x20]; // sizeof 0x24
};

// ?Rva006E9B20::~Rva006E9B20 present-unmatched
Rva006E9B20::~Rva006E9B20()
{
}

void deleteRva006E9B20(Rva006E9B20 *p)
{
	delete p;
}

class Rva006E9B50 : public Rva006DE350
{
public:
	virtual ~Rva006E9B50();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x24]; // sizeof 0x28
};

// ?Rva006E9B50::~Rva006E9B50 present-unmatched
Rva006E9B50::~Rva006E9B50()
{
}

void deleteRva006E9B50(Rva006E9B50 *p)
{
	delete p;
}

class Rva006EC170 : public Rva006DE350
{
public:
	virtual ~Rva006EC170();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006EC170::~Rva006EC170 present-unmatched
Rva006EC170::~Rva006EC170()
{
}

void deleteRva006EC170(Rva006EC170 *p)
{
	delete p;
}

class Rva006ECF90 : public Rva006DE350
{
public:
	virtual ~Rva006ECF90();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x3C]; // sizeof 0x40
};

// ?Rva006ECF90::~Rva006ECF90 present-unmatched
Rva006ECF90::~Rva006ECF90()
{
}

void deleteRva006ECF90(Rva006ECF90 *p)
{
	delete p;
}

class Rva006F15D0 : public Rva006DE350
{
public:
	virtual ~Rva006F15D0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x24]; // sizeof 0x28
};

// ?Rva006F15D0::~Rva006F15D0 present-unmatched
Rva006F15D0::~Rva006F15D0()
{
}

void deleteRva006F15D0(Rva006F15D0 *p)
{
	delete p;
}

class Rva006F1DC0 : public Rva006DE350
{
public:
	virtual ~Rva006F1DC0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x24]; // sizeof 0x28
};

// ?Rva006F1DC0::~Rva006F1DC0 present-unmatched
Rva006F1DC0::~Rva006F1DC0()
{
}

void deleteRva006F1DC0(Rva006F1DC0 *p)
{
	delete p;
}

class Rva006F2C70 : public Rva006DE350
{
public:
	virtual ~Rva006F2C70();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x20]; // sizeof 0x24
};

// ?Rva006F2C70::~Rva006F2C70 present-unmatched
Rva006F2C70::~Rva006F2C70()
{
}

void deleteRva006F2C70(Rva006F2C70 *p)
{
	delete p;
}

class Rva006F3960 : public Rva006DE350
{
public:
	virtual ~Rva006F3960();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x28]; // sizeof 0x2C
};

// ?Rva006F3960::~Rva006F3960 present-unmatched
Rva006F3960::~Rva006F3960()
{
}

void deleteRva006F3960(Rva006F3960 *p)
{
	delete p;
}

class Rva006F7DC0 : public Rva006DE350
{
public:
	virtual ~Rva006F7DC0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
	char m_pad[0x2C]; // sizeof 0x30
};

// ?Rva006F7DC0::~Rva006F7DC0 present-unmatched
Rva006F7DC0::~Rva006F7DC0()
{
}

void deleteRva006F7DC0(Rva006F7DC0 *p)
{
	delete p;
}

class Rva006F8D70 : public Rva006DE350
{
public:
	virtual ~Rva006F8D70();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocator->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006F8D70::~Rva006F8D70 present-unmatched
Rva006F8D70::~Rva006F8D70()
{
}

void deleteRva006F8D70(Rva006F8D70 *p)
{
	delete p;
}

class Rva006FBC60 : public Rva006DE350
{
public:
	virtual ~Rva006FBC60();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006FBC60::~Rva006FBC60 present-unmatched
Rva006FBC60::~Rva006FBC60()
{
}

void deleteRva006FBC60(Rva006FBC60 *p)
{
	delete p;
}

class Rva006FC0F0 : public Rva006DE350
{
public:
	virtual ~Rva006FC0F0();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x60]; // sizeof 0x64
};

// ?Rva006FC0F0::~Rva006FC0F0 present-unmatched
Rva006FC0F0::~Rva006FC0F0()
{
}

void deleteRva006FC0F0(Rva006FC0F0 *p)
{
	delete p;
}

class Rva006FC190 : public Rva006DE350
{
public:
	virtual ~Rva006FC190();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x1C]; // sizeof 0x20
};

// ?Rva006FC190::~Rva006FC190 present-unmatched
Rva006FC190::~Rva006FC190()
{
}

void deleteRva006FC190(Rva006FC190 *p)
{
	delete p;
}

class Rva006FE430 : public Rva006DE350
{
public:
	virtual ~Rva006FE430();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x20]; // sizeof 0x24
};

// ?Rva006FE430::~Rva006FE430 present-unmatched
Rva006FE430::~Rva006FE430()
{
}

void deleteRva006FE430(Rva006FE430 *p)
{
	delete p;
}

class Rva0070A530 : public Rva006DE350
{
public:
	virtual ~Rva0070A530();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x40]; // sizeof 0x44
};

// ?Rva0070A530::~Rva0070A530 present-unmatched
Rva0070A530::~Rva0070A530()
{
}

void deleteRva0070A530(Rva0070A530 *p)
{
	delete p;
}

class Rva0070A560 : public Rva006DE350
{
public:
	virtual ~Rva0070A560();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x2C]; // sizeof 0x30
};

// ?Rva0070A560::~Rva0070A560 present-unmatched
Rva0070A560::~Rva0070A560()
{
}

void deleteRva0070A560(Rva0070A560 *p)
{
	delete p;
}

class Rva0070A590 : public Rva006DE350
{
public:
	virtual ~Rva0070A590();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x30]; // sizeof 0x34
};

// ?Rva0070A590::~Rva0070A590 present-unmatched
Rva0070A590::~Rva0070A590()
{
}

void deleteRva0070A590(Rva0070A590 *p)
{
	delete p;
}

class Rva00711350 : public Rva006DE350
{
public:
	virtual ~Rva00711350();
	static void operator delete(void *p, unsigned int size)
	{
		g_pChainBlockAllocatorF4->freeBlock(p, size);
	}
	char m_pad[0x20]; // sizeof 0x24
};

// ?Rva00711350::~Rva00711350 present-unmatched
Rva00711350::~Rva00711350()
{
}

void deleteRva00711350(Rva00711350 *p)
{
	delete p;
}

// Other units name this global (at the same address) with the spelling(s)
// below; bind them to this definition.
#pragma comment(linker, "/alternatename:?g_poolAtE176F4@@3PAVAptValueGC_PoolManager@@A=?g_pChainBlockAllocatorF4@@3PAVRva006D2A60@@A")
#pragma comment(linker, "/alternatename:?g_bfmeChainBlockAllocatorAtE176F4@@3PAVRva006D2A60@@A=?g_pChainBlockAllocatorF4@@3PAVRva006D2A60@@A")
