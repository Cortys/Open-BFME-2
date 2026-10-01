// cl: /O1 /EHsc /arch:SSE2
// ??0Rva0055C8BC@@QAE@XZ, retail 0x0055C8BC 71B.
// Empty publisher ctor: DefaultModuleTag6 getInstance plus Rva005C7889Init then
// new PointGroupClass (0x5c) into g_00E06098. Evidence: guarded init caller
// 0x003A8314 plus same S4 publisher shape as 0x00560135,
// callee rows 0x003AA350 0x005C7889 0x0002FDA0 0x00178E50.
namespace FXParticleSystem
{
template <int N>
class DefaultModuleTag
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
}
void __cdecl Rva005C7889Init(void);
void *__cdecl operator new(unsigned int);
class PointGroupClass
{
public:
    PointGroupClass();
    virtual ~PointGroupClass();
private:
    char m_pad[0x58];
};
typedef char CheckPointGroupSize[(sizeof(PointGroupClass) == 0x5c) ? 1 : -1];
extern PointGroupClass *g_00E06098;
struct Rva0055C8BC
{
    Rva0055C8BC();
};
Rva0055C8BC::Rva0055C8BC()
{
    FXParticleSystem::ConcreteModuleClass<FXParticleSystem::DefaultModuleTag<6> >::getInstance();
    Rva005C7889Init();
    PointGroupClass *group = new PointGroupClass;
    g_00E06098 = group;
}
