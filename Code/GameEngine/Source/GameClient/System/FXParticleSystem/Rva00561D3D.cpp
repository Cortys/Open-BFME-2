// cl: /DNDEBUG /MD /EHsc /O1 /Ob2 /arch:SSE
// ??0Rva00561D3D@@QAE@XZ @ 0x00561D3D 87B unlock via rowed getInstance Init new StreakLine.
// Honest-address default ctor for static at 0x00A0291C (caller 0x003A8394 guards at 0x00A02920).
// Evidence: EH prologue, rowed getInstance LIGHTNING_DRAW 0x003AA5A7, rowed Init 0x005C7889,
// rowed new 0x0002FDA0 with 0x19c, rowed StreakLine ctor 0x00742470,
// rowed Set_Texture_Mapping_Mode 0x007419A0 with 2, global g_00E0626C, returns this.
namespace FXParticleSystem
{
template <int CATEGORY>
class DefaultParticleModule;
template <int CATEGORY, const char *const &KEY, const char *const &NAME, class MODULE,
    class TEMPLATE, class DEFAULT>
class ModuleTag
{
};
template <class TAG>
class ConcreteModuleClass
{
public:
    __declspec(noinline) static const ConcreteModuleClass<TAG> &getInstance();
};
extern const char *const LIGHTNING_DRAW_MODULE_KEY;
extern const char *const LIGHTNING_DRAW_MODULE_NAME;
class LightningDrawModule;
class LightningDrawModuleTemplate;
typedef ModuleTag<6, LIGHTNING_DRAW_MODULE_KEY, LIGHTNING_DRAW_MODULE_NAME, LightningDrawModule,
    LightningDrawModuleTemplate, DefaultParticleModule<6> > LightningDrawTag5;
}
void __cdecl Rva005C7889Init();
class SegLineRendererClass
{
public:
    enum TextureMapMode
    {
        MODE0 = 0,
        MODE1 = 1,
        MODE2 = 2
    };
};
class StreakLineClass
{
public:
    StreakLineClass();
    void Set_Texture_Mapping_Mode(SegLineRendererClass::TextureMapMode mode);
private:
    char m_pad[0x19c];
};
class Rva00561D3D
{
public:
    Rva00561D3D();
};
extern StreakLineClass *g_00E0626C;
Rva00561D3D::Rva00561D3D()
{
    FXParticleSystem::ConcreteModuleClass<FXParticleSystem::LightningDrawTag5>::getInstance();
    Rva005C7889Init();
    StreakLineClass *p = new StreakLineClass;
    g_00E0626C = p;
    p->Set_Texture_Mapping_Mode((SegLineRendererClass::TextureMapMode)2);
}
