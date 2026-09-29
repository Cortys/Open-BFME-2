// cl: /O1 /DNDEBUG /MD
// ?Rva00211E0DGet@@YAPAVRva002111C8@@PAV1@00@Z, RVA 0x00211E0D, 38B. Chain lane:
// uninitialized copy over 0x10-stride Rva002111C8 via rowed 0x00211DFB
// placement copy; push-esi/edi loop with late cmp, returns final dest.
// Dedicated TU so the Construct definition cannot inline. Callers at
// 0x00213E79/0x00213EC4. Owner unknown so honest address-derived names.
class RvaSmartPtr12
{
	char m_data[12];
};
class Rva002111C8
{
	RvaSmartPtr12 m_00;
	int m_0c;
};
void __cdecl Rva00211DFBConstruct(Rva002111C8 *d, const Rva002111C8 *s);

Rva002111C8 *__cdecl Rva00211E0DGet(Rva002111C8 *first, Rva002111C8 *last, Rva002111C8 *result)
{
	Rva002111C8 *cur = result;
	for (; first != last; ++first, ++cur)
		Rva00211DFBConstruct(cur, first);
	return cur;
}

// ?Rva00211E33Fill@@YAPAVRva002111C8@@PAV1@IPBV1@@Z, RVA 0x00211E33, 37B.
// Chain lane: uninitialized fill_n over 0x10-stride Rva002111C8 via rowed
// 0x00211DFB; count in edi with jbe guard, value stays fixed, returns final
// dest. Same dedicated TU so Construct stays a call. Caller at 0x00213EA6.
// Owner unknown so honest address-derived names.

Rva002111C8 *__cdecl Rva00211E33Fill(Rva002111C8 *dest, unsigned int count, const Rva002111C8 *value)
{
	Rva002111C8 *cur = dest;
	for (; count > 0; --count, ++cur)
		Rva00211DFBConstruct(cur, value);
	return cur;
}
