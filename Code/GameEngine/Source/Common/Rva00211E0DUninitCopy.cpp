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
