// cl: /O1
//
// ?Rva00438144Update@@YAXPBVObject@@PAE@Z @0x00438144 34B
// Cached Object predicate helper. Evidence: free-function via two stack
// args plus ret (no ret-N, __cdecl); arg1 in ecx to rowed Object
// rva0028C1CC 0x0028C1CC (Object owner proven); arg2 byte flag read plus
// 0-or-1 store; no callers; name stays address-derived.
class Object
{
public:
	bool rva0028C1CC() const;
};

void Rva00438144Update(const Object *obj, unsigned char *flag)
{
	int value;
	if (*flag != 0)
		goto set_one;
	if (!obj->rva0028C1CC())
	{
		value = 0;
		goto store;
	}
set_one:
	value = 1;
store:
	*flag = (unsigned char)value;
}
