// cl: /Ireference/shims/bfme2_ascii /O1 /GX- /DNDEBUG /MD /arch:SSE2
// ??0Rva005635CD@@QAE@XZ @0x005635CD 17B: empty publisher default ctor calling RENDEROBJECT_DRAW getInstance 0x003AA57C then Rva005C7889Init 0x005C7889 returning this with esi save.
// Evidence: chain lane (calls 0x005C7889 just landed); push esi mov esi ecx call call mov eax esi pop esi ret; static-init caller 0x003A8454 constructs g_00E02934 via this ctor with guard+atexit; getInstance row 0x003AA57C.
namespace FXParticleSystem
{
template <int CATEGORY>
class DefaultParticleModule;
class RenderObjectDrawModule;
class RenderObjectDrawModuleTemplate;
extern const char *const RENDEROBJECT_DRAW_MODULE_KEY;
extern const char *const RENDEROBJECT_DRAW_MODULE_NAME;
template <int CATEGORY, const char *const &KEY, const char *const &NAME, class MODULE, class TEMPLATE, class DEFAULT>
class ModuleTag
{
};
template <class TAG>
class ConcreteModuleClass
{
public:
	static const ConcreteModuleClass<TAG> &getInstance();
private:
	void *m_words[4];
};
typedef ModuleTag<6, RENDEROBJECT_DRAW_MODULE_KEY, RENDEROBJECT_DRAW_MODULE_NAME, RenderObjectDrawModule, RenderObjectDrawModuleTemplate, DefaultParticleModule<6> > RenderObjectDrawTag6;
}

void __cdecl Rva005C7889Init(void);

class Rva005635CD
{
public:
	Rva005635CD();
};

Rva005635CD::Rva005635CD()
{
	FXParticleSystem::ConcreteModuleClass<FXParticleSystem::RenderObjectDrawTag6>::getInstance();
	Rva005C7889Init();
}
