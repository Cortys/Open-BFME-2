// ??0Rva0073F708@@QAE@PAXH@Z
// partial score=0.96 date=2026-09-29
// ??0Rva0073F708@@QAE@PAXH@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /MD /EHsc
// ??0Rva0073F708@@QAE@PAXH@Z @0x0073F708 112B.
// Constructs holder with arg, thread object, and event, then starts thread.
// Evidence: chain lane packet; new 8 with vtable; event ctor rowed; thread
// spawner rowed with unclaimed start routine.
// ??0Rva0073F708@@QAE@PAXH@Z present-unmatched
void *__cdecl operator new(unsigned int size);
typedef void (__cdecl *Rva004F553FCb)(void *data, void *user);
class Rva004F553F
{
public:
    void rva004F553F(Rva004F553FCb cb, void *user, bool flag);
};
class Rva0073F778
{
    char _pad[4];
    void *m_handle;
public:
    bool rva0073F778(unsigned (__stdcall *start)(void *), void *arglist, int resume, unsigned stackSize, int priority, void *security);
};
unsigned __stdcall Rva0073F6FCCb(void *arg);
class ThreadObj {
    virtual ~ThreadObj();
    void *m_handle;
public:
    ThreadObj();
};
// ??1ThreadObj@@UAE@XZ present-unmatched
inline ThreadObj::~ThreadObj() {}
// ??0ThreadObj@@QAE@XZ present-unmatched
inline ThreadObj::ThreadObj() : m_handle(0) {}
class Rva0040F9D {
public:
    Rva0040F9D(int a1, int a2, char const *a3, void *a4);
    virtual ~Rva0040F9D();
    char _pad[4];
};
class Rva0073F708 {
    void *m_a1;
    Rva0073F778 *m_thread;
    Rva0040F9D m_event;
public:
    Rva0073F708(void *a1, int pri);
};
Rva0073F708::Rva0073F708(void *a1, int pri)
    : m_a1(a1), m_thread((Rva0073F778 *)new ThreadObj), m_event(1, 0, 0, 0)
{
    ((Rva0073F778 *)m_thread)->rva0073F778((unsigned (__stdcall *)(void *))Rva0073F6FCCb, this, 1, 0, pri, 0);
}
