class BfmeThingDGD
{
public:
	BfmeThingDGD(void *a);
};

class Gen007F0130
{
public:
	static void *operator new(unsigned int size);
};

inline void *operator new(unsigned int, void *p)
{
	return p;
}

BfmeThingDGD *bfmeGoDGD(void *a)
{
	void *p = Gen007F0130::operator new(0x6e0);
	if (p != 0)
		return new (p) BfmeThingDGD(a);
	return 0;
}
