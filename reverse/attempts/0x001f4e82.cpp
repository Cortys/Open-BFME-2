// ??0ParticleSystemInfo@FXParticleSystem@@QAE@XZ
// partial score=0.96 date=2026-10-01
// ??0ParticleSystemInfo@FXParticleSystem@@QAE@XZ
// partial score=0.96 date=2026-10-01
// cl: /O1 /MD /arch:SSE /Ireference/shims/bfme2_ascii
// ??0ParticleSystemInfo@FXParticleSystem@@QAE@XZ @0x001F4E82 216B
// Evidence: vtable 0x007BB5C8 store at [this]; ghidra ParticleSystemInfo size 216;
// callers 0x001FC1F1 0x001FC71B; member offsets match ParticleSystemInfoCopyCtor layout;
// float 1.0f via g_Va00BBB8D8 for Region2D max; 16x7367 donor fx_particle_system.h.
#include "ascii_string.h"

extern float g_Va00BBB8D8;

struct IntFloatFloat
{
    unsigned int a;
    float b;
    float c;
};

struct Coord3D
{
    float x;
    float y;
    float z;
};

struct Region2D
{
    float x_min;
    float y_min;
    float x_max;
    float y_max;
};

class Xfer;

class Snapshot
{
public:
    virtual ~Snapshot() {}
    virtual const char *GetSnapshotName() = 0;
    virtual void LoadPostProcess() = 0;
    virtual void DoXfer(Xfer &xfer) = 0;
};

namespace FXParticleSystem
{

class ParticleSystemInfo : public Snapshot
{
public:
    ParticleSystemInfo();
    virtual ~ParticleSystemInfo();
    virtual const char *GetSnapshotName();
    virtual void LoadPostProcess();
    virtual void DoXfer(Xfer &xfer);

private:
    unsigned char m_isOneShot;
    unsigned int m_shaderType;
    unsigned int m_particleType;
    AsciiString m_particleTypeName;
    IntFloatFloat m_angleZ;
    unsigned int m_systemLifetime;
    unsigned int m_volumeParticleDepth;
    IntFloatFloat m_angularRateZ;
    IntFloatFloat m_angularDamping;
    unsigned int m_windMotion;
    IntFloatFloat m_velDamping;
    IntFloatFloat m_lifetime;
    IntFloatFloat m_startSize;
    AsciiString m_slaveSystemName;
    Coord3D m_slavePosOffset;
    AsciiString m_attachedSystemName;
    unsigned int m_emissionVelocityType;
    unsigned char m_isEmissionVolumeHollow;
    unsigned char m_isGroundAligned;
    unsigned char m_isEmitAboveGroundOnly;
    unsigned char m_isParticleUpTowardsEmitter;
    unsigned char m_windMotionMovingToEndAngle;
    Region2D m_uv;
    unsigned int m_unknown98;
};

// ??0ParticleSystemInfo@FXParticleSystem@@QAE@XZ present-unmatched
ParticleSystemInfo::ParticleSystemInfo()
{
    m_angleZ.b = 0.0f;
    m_angleZ.c = 0.0f;
    m_angleZ.a = 0;
    m_angularRateZ.b = 0.0f;
    m_angularRateZ.c = 0.0f;
    m_angularRateZ.a = 0;
    m_angularDamping.b = 0.0f;
    m_angularDamping.c = 0.0f;
    m_angularDamping.a = 0;
    m_velDamping.b = 0.0f;
    m_velDamping.c = 0.0f;
    m_velDamping.a = 0;
    m_lifetime.b = 0.0f;
    m_lifetime.c = 0.0f;
    m_lifetime.a = 0;
    m_startSize.b = 0.0f;
    m_startSize.c = 0.0f;
    m_startSize.a = 0;
    m_emissionVelocityType = 1;
    m_particleType = 1;
    m_shaderType = 1;
    m_isEmissionVolumeHollow = 0;
    m_isGroundAligned = 0;
    m_isEmitAboveGroundOnly = 0;
    m_isParticleUpTowardsEmitter = 0;
    m_windMotionMovingToEndAngle = 0;
    m_isOneShot = 0;
    m_slavePosOffset.x = 0.0f;
    m_slavePosOffset.y = 0.0f;
    m_slavePosOffset.z = 0.0f;
    m_uv.x_min = 0.0f;
    m_uv.y_min = 0.0f;
    float one = g_Va00BBB8D8;
    m_systemLifetime = 0;
    m_volumeParticleDepth = 0;
    m_windMotion = 0;
    m_uv.x_max = one;
    m_uv.y_max = one;
    m_unknown98 = 0;
}

}
