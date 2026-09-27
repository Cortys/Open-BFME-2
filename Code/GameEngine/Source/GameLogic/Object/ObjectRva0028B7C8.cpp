// cl: /O1 /arch:SSE
// ?rva0028B7C8@Object@@QBEHXZ, retail 0x0028B7C8, 26 bytes.
// Object int gate over the float at +0x258-holder: returns 1 when
// rva0028AC7D exceeds the shared 0.1f at 0x007C2424, else 0.
// Evidence: calls the rowed ?rva0028AC7D@Object@@QBEMXZ; fld/fxch/fcompi shape
// needs /arch:SSE per ObjectRva0028AC4EAccessors; 0.1f at 0x7C2424 proven by
// PathfindShimWorldToCell; callers at 0x00458DA5 0x00458DD6 0x004AE3FB test al
// with Object this. Name stays address-derived; true method name unproven.
extern float g_Va00BC2424;

class Object
{
public:
	float rva0028AC7D() const;
	int rva0028B7C8() const;
};

int Object::rva0028B7C8() const
{
	if (rva0028AC7D() > g_Va00BC2424)
		return 1;
	return 0;
}
