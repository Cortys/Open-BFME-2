
class BfmeThingBNH;

void bfmeDoBNH(BfmeThingBNH *who, void *tag, int one, int two);

class BfmeThingBNH
{
public:
	BfmeThingBNH *bfmeGoBNH(void *what);
};

BfmeThingBNH *BfmeThingBNH::bfmeGoBNH(void *what)
{
	bfmeDoBNH(this, (char *)"exscorch01.tga", 0, 0);
	return this;
}
