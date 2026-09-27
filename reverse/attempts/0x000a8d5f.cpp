// ??0PlayingAudio@@QAE@XZ
// partial score=0.93 date=2026-09-27
// ??0PlayingAudio@@QAE@XZ
// partial score=0.93 date=2026-09-27
// cl: /O1 /Oy- /Oi- /Ob1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /arch:SSE
//
// ??0PlayingAudio@@QAE@XZ
// RVA 0x000A8D5F size 171. Pinned ctor name; allocator 0x5320F news 0x50 and
// calls here then sets status playing at +0x18 while this ctor sets stopped
// at +0x18. Donor reference/open-bfme-1/.../PlayingAudioConstructor.cpp gives
// type/status/event/file/volume/index/flags shape; BFME2 shifts by +8 for an
// 8-byte stream member at +0x0C built by the shared 10B zeroing body at
// 0x7E81F and keeps UnicodeString at +0x20 plus SSE floats and O1 or-minus-1
// and 12 bool flags for 0x50 total.

class OpaqueRefCounted
{
public:
    OpaqueRefCounted() : m_refCount(0) {}
    virtual ~OpaqueRefCounted();
private:
    long m_refCount;
};

class MilesStreamRef
{
public:
    MilesStreamRef();
    ~MilesStreamRef();
private:
    int m_a;
    int m_b;
};

class UnicodeString
{
public:
    UnicodeString();
    ~UnicodeString();
private:
    void *m_data;
};

class PlayingAudio : public OpaqueRefCounted
{
public:
    PlayingAudio();
    virtual ~PlayingAudio();
private:
    void *m_milesHandle;
    MilesStreamRef m_stream;
    int m_type;
    volatile int m_status;
    void *m_event;
    UnicodeString m_file;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    int m_index;
    float m_f3c;
    float m_f40;
    bool m_b44;
    bool m_b45;
    bool m_b46;
    bool m_b47;
    bool m_b48;
    bool m_b49;
    bool m_b4a;
    bool m_b4b;
    bool m_b4c;
    bool m_b4d;
    bool m_b4e;
    bool m_b4f;
};

PlayingAudio::PlayingAudio() :
    OpaqueRefCounted(),
    m_stream(),
    m_type(5),
    m_status(1),
    m_event(0),
    m_file(),
    m_f24(0.0f),
    m_f28(0.0f),
    m_f2c(0.0f),
    m_f30(0.0f),
    m_f34(1.0f),
    m_index(-1),
    m_f3c(1.0f),
    m_f40(0.0f),
    m_b44(false),
    m_b45(false),
    m_b46(false),
    m_b47(false),
    m_b48(false),
    m_b49(false),
    m_b4a(false),
    m_b4b(false),
    m_b4c(false),
    m_b4d(false),
    m_b4e(false),
    m_b4f(false)
{
}
