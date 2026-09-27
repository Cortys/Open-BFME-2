// ??0WindModuleInfo@FXParticleSystem@@QAE@XZ
// partial score=0.93 date=2026-09-26
// ??0WindModuleInfo@FXParticleSystem@@QAE@XZ
// partial score=0.93 date=2026-09-26
// cl: /O1 /GX- /arch:SSE2 /DNDEBUG /MD
namespace FXParticleSystem {
class Snapshot { public: virtual ~Snapshot() {} };
class WindModuleInfo : public Snapshot
{
public:
    WindModuleInfo();
    virtual ~WindModuleInfo() {}
    virtual void v1() = 0;
    int m04; float m08; float m0C; float m10; float m14; float m18; float m1C; float m20;
    float m24; float m28; float m2C; float m30; float m34; float m38; bool m3C; float m40; float m44;
};
static float g_wind24 = 0.0f;
static float g_wind30 = 5.4977874755859375f;
// ??0WindModuleInfo@FXParticleSystem@@QAE@XZ present-unmatched
WindModuleInfo::WindModuleInfo()
    : m04(1), m08(2.0f), m0C(75.0f), m10(200.0f), m14(0.0f),
      m18(0.15f), m1C(0.15f), m20(0.45f),
      m28(0.0f), m2C(0.7853981852531433f), m24(g_wind24),
      m34(5.4977874755859375f), m38(6.2831854820251465f), m30(g_wind30),
      m3C(true), m40(0.0f), m44(0.0f)
{
}
}
