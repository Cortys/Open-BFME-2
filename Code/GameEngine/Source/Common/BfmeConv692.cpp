class BfmeThingDGF;

class Gen007F0130
{
public:
	static void *operator new(unsigned int size);
};

class Rva007EAServiceList;

class BfmeThingTWA
{
public:
	BfmeThingTWA(Rva007EAServiceList *service);
};

inline void *operator new(unsigned int, void *p)
{
	return p;
}

BfmeThingDGF *bfmeGoDGF(void *a)
{
	void *p = Gen007F0130::operator new(0x30);
	if (p != 0)
		return (BfmeThingDGF *)new (p) BfmeThingTWA((Rva007EAServiceList *)a);
	return 0;
}
