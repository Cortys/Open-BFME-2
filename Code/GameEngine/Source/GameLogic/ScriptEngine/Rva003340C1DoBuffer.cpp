// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc
//
// ?rva003340C1@Rva003340C1@@QAEXPADHABVAsciiString@@@Z @0x003340C1 57B: Lua
// dobuffer helper calling lua_dobuffer then lua_settop 0. Evidence: GetStr via
// m_data+8 or g_Rva0107301CEmptyString, lua_dobuffer 0x0074DD00,
// lua_settop 0x00746F40, this+0xC lua_State, caller 0x003345BE passes
// buffer size and AsciiString chunkname.
#include "ascii_string.h"

extern const char g_Rva0107301CEmptyString[];

__forceinline const char *GetStr003340C1(const AsciiString &s)
{
	char *t = *(char * *)(void *)&s;
	return t ? t + 8 : g_Rva0107301CEmptyString;
}

struct lua_State;

extern "C" int __cdecl lua_dobuffer(struct lua_State *L, const char *buff, unsigned int size, const char *name);
extern "C" void __cdecl lua_settop(struct lua_State *L, int idx);

class Rva003340C1
{
public:
	void rva003340C1(char *buff, int size, const AsciiString &chunk);

private:
	unsigned char m_pad[0xC];
	struct lua_State *m_lua;
};

void Rva003340C1::rva003340C1(char *buff, int size, const AsciiString &chunk)
{
	const char *name = GetStr003340C1(chunk);
	lua_dobuffer(m_lua, buff, size, name);
	lua_settop(m_lua, 0);
}
