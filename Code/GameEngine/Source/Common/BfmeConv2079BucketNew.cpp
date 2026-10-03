// Target 0x001B6400 forwards bytes to bfmeAllocBlock at 0x001B63C0.
// Its allocator and native14B body differ from NameKeyGenerator::Bucket's
// donor operator new. Address-derived identity; original class is unknown.
void *bfmeAllocBlock(unsigned int bytes);

class Rva001B6400Allocation
{
public:
	enum AllocationTag { BFME_ZERO_JT = 0 };

	static void *operator new(unsigned int n, AllocationTag m);
};

inline void *Rva001B6400Allocation::operator new(unsigned int size, AllocationTag)
{
	return bfmeAllocBlock(size);
}

#pragma inline_depth(0)
// ?bfmeEmitBfmeConv2079BucketNew@@YAXXZ present-unmatched
void bfmeEmitBfmeConv2079BucketNew()
{
	Rva001B6400Allocation::operator new(0, Rva001B6400Allocation::BFME_ZERO_JT);
}
#pragma inline_depth()
