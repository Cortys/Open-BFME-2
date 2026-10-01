void *bfmeAllocBlock(unsigned int bytes);

class Bucket
{
public:
	enum BucketMagicEnum { BFME_ZERO_JT = 0 };

	static void *operator new(unsigned int n, BucketMagicEnum m);
};

inline void *Bucket::operator new(unsigned int size, BucketMagicEnum)
{
	return bfmeAllocBlock(size);
}

#pragma inline_depth(0)
// ?bfmeEmitBfmeConv2079BucketNew@@YAXXZ present-unmatched
void bfmeEmitBfmeConv2079BucketNew()
{
	Bucket::operator new(0, Bucket::BFME_ZERO_JT);
}
#pragma inline_depth()
