
class BfmeOtherDFC
{
public:
	void *bfmeMakeDFC(void *info, int flag);
};

class BfmeThingDFC
{
public:
	BfmeThingDFC *bfmeGoDFC(BfmeOtherDFC *other);
	void *m_bfmeVal;
};

BfmeThingDFC *BfmeThingDFC::bfmeGoDFC(BfmeOtherDFC *other)
{
	m_bfmeVal = other->bfmeMakeDFC((char *)"NUM-LOBBIES", 0);
	return this;
}
