// cl: /O1 /EHsc /MD
// ?rva00513D8F@Rva00513D8F@@QAEHPAG@Z @0x00513D8F 37B
// Unlock lane: landing it makes 0x00513E25 ready. Prev/next vector ctors
// in stlport_vector_s_o1.cpp (adjacent rows only). Calls rowed
// Rva000B3F84Pair::copyWchars 0x002342A7 then rowed
// BFME2WideStringRef::copyPayloadTo 0x0021AC32 via this+8; returns sum.
// Same shape as BFME2WideConcatPair::copyPayloads in WideConcatPair.cpp.
class Rva000B3F84Pair
{
public:
	int copyWchars(unsigned short *dst);
};

struct BFME2WideStringRef
{
	int copyPayloadTo(unsigned short *dst) const;
};

class Rva00513D8F
{
public:
	int rva00513D8F(unsigned short *dst);
private:
	const char *m_ptr; // +0 for pair view
	int m_len; // +4
	const void *m_second; // +8 ref view
};

int Rva00513D8F::rva00513D8F(unsigned short *dst)
{
	int first = ((Rva000B3F84Pair *)this)->copyWchars(dst);
	int second = ((const BFME2WideStringRef *)((const char *)this + 8))->copyPayloadTo(dst + first);
	return first + second;
}
