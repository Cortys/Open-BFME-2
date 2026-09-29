// ??0Rva000A8893@@QAE@PAXH@Z
// partial score=0.96 date=2026-09-29
// ??0Rva000A8893@@QAE@PAXH@Z
// partial score=0.96 date=2026-09-29
// ??0Rva000A8893@@QAE@PAXH@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /MD /EHsc
// ??0Rva000A8893@@QAE@PAXH@Z @0x000A8893 112B.
// Twin of 0x0073F708: holder with arg, thread object, and event, then starts
// thread. Evidence: chain lane packet; identical disassembly to 0x0073F708;
// HEAD START from stashed 0x0073F708 partial.
// ??0Rva000A8893@@QAE@PAXH@Z present-unmatched
void *__cdecl operator new(unsigned int size);
class Rva0073F778
{
    char _pad[4];
    void *m_handle;
public:
    bool rva0073F778(unsigned (__stdcall *start)(void *), void *arglist, int resume, unsigned stackSize, int priority, void *security);
};
unsigned __stdcall Rva0073F6FCCb(void *arg);
class ThreadObjA8893 {
    virtual ~ThreadObjA8893();
    void *m_handle;
public:
    ThreadObjA8893();
};
// ??1ThreadObjA8893@@UAE@XZ present-unmatched
inline ThreadObjA8893::~ThreadObjA8893() {}
// ??0ThreadObjA8893@@QAE@XZ present-unmatched
inline ThreadObjA8893::ThreadObjA8893() : m_handle(0) {}
class Rva0040F9D {
public:
    Rva0040F9D(int a1, int a2, char const *a3, void *a4);
    virtual ~Rva0040F9D();
    char _pad[4];
};
class Rva000A8893 {
    void *m_a1;
    Rva0073F778 *m_thread;
    Rva0040F9D m_event;
public:
    Rva000A8893(void *a1, int pri);
};
Rva000A8893::Rva000A8893(void *a1, int pri)
    : m_a1(a1), m_thread((Rva0073F778 *)new ThreadObjA8893), m_event(1, 0, 0, 0)
{
    ((Rva0073F778 *)m_thread)->rva0073F778((unsigned (__stdcall *)(void *))Rva0073F6FCCb, this, 1, 0, pri, 0);
}
