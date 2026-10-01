// cl: /O1 /EHsc /arch:SSE2
// ??0Rva00560135@@QAE@XZ, retail 0x00560135 74B.
// Empty publisher ctor: STREAK_DRAW getInstance plus Rva005C7889Init then
// new StreakLineClass (0x19c) into g_00E06224. Evidence: guarded init caller
// 0x003A8354 (object VA 0x00E02914 guard VA 0x00E02918 atexit VA 0x007B7EC1),
// callee rows 0x003AA37B 0x005C7889 0x0002FDA0 0x00742470, S4StreakLinePublisher pattern.
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
    static const ConcreteModuleClass<TAG> &getInstance();
private:
    void *m_words[4];
};
extern const char *const STREAK_DRAW_MODULE_KEY;
extern const char *const STREAK_DRAW_MODULE_NAME;
class StreakDrawModule;
class StreakDrawModuleTemplate;
}
void __cdecl Rva005C7889Init(void);
void *__cdecl operator new(unsigned int);
class RefCountClass
{
public:
    virtual void Delete_This();
    virtual ~RefCountClass();
    int NumRefs;
};
class MultiListObjectClass
{
public:
    virtual ~MultiListObjectClass();
    void *ListNode;
};
class RenderObjClass : public RefCountClass, public MultiListObjectClass
{
private:
    char m_tail[0xB8];
};
class StreakLineClass : public RenderObjClass
{
public:
    StreakLineClass();
private:
    char m_tail[0xD4];
};
typedef char CheckStreakSize[(sizeof(StreakLineClass) == 0x19c) ? 1 : -1];
extern StreakLineClass *g_00E06224;
struct Rva00560135
{
    Rva00560135();
};
Rva00560135::Rva00560135()
{
    FXParticleSystem::ConcreteModuleClass<FXParticleSystem::ModuleTag<6, FXParticleSystem::STREAK_DRAW_MODULE_KEY, FXParticleSystem::STREAK_DRAW_MODULE_NAME, FXParticleSystem::StreakDrawModule, FXParticleSystem::StreakDrawModuleTemplate, FXParticleSystem::DefaultParticleModule<6> > >::getInstance();
    Rva005C7889Init();
    StreakLineClass *line = new StreakLineClass;
    g_00E06224 = line;
}
