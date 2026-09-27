// cl: /O1 /MD
// ?Rva001FB912Init@@YAXPAX@Z @0x001FB912 43B
// Free __cdecl init storing FXParticleSystem GetKey(8) token at +0x80 and parse
// 0x001FA8DD at +0x84 with zeros at +0x88 and +0x8C. Evidence: push 8 GetKey
// rowed 0x003AFD16; stores mirror 0x001FBAB2 at +0x70 and 0x001FBC69 at +0x60;
// caller 0x001FBAB2 becomes ready; honest Rva free-function name.
namespace FXParticleSystem
{
    enum ModuleCategory
    {
        CAT_6 = 6,
        CAT_7 = 7,
        CAT_8 = 8
    };
    const char * __cdecl GetKey(ModuleCategory category);
};

void __cdecl Rva001FA8DDParse();

struct Obj80
{
    char pad[0x80];
    const char *token;
    void *parse;
    void *userdata;
    int offset;
};

void __cdecl Rva001FB912Init(void *obj_)
{
    Obj80 *obj = (Obj80 *)obj_;
    const char *key = FXParticleSystem::GetKey(FXParticleSystem::CAT_8);
    obj->userdata = 0;
    obj->offset = 0;
    obj->token = key;
    obj->parse = (void *)Rva001FA8DDParse;
}
