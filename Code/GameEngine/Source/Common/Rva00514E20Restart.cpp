// cl: /O1 /MD
// ?Rva00514E20Restart@@YAXXZ @0x00514E20 75B.
// Restarts global thread object via wrapper. Evidence: chain lane packet.
#include <new>
void *__cdecl operator new(unsigned int size);
void __cdecl operator delete(void *p);
class Rva0073F778 {
    char _pad[4];
    void *m_handle;
public:
    bool rva0073F778(unsigned (__stdcall *start)(void *), void *arglist, int resume, unsigned stackSize, int priority, void *security);
    bool rva0073F83F(int resume, unsigned stackSize, int priority, void *security);
};
class ThreadRestartObj {
public:
    virtual ~ThreadRestartObj();
    virtual void *unused0();
    virtual void *stop(int code);
private:
    void *m_handle;
    friend void Rva00514E20Restart();
};
// ??1ThreadRestartObj@@UAE@XZ present-unmatched
inline ThreadRestartObj::~ThreadRestartObj() {}
// ?unused0@ThreadRestartObj@@UAEPAXXZ present-unmatched
inline void *ThreadRestartObj::unused0() { return 0; }
// ?stop@ThreadRestartObj@@UAEPAXH@Z present-unmatched
inline void *ThreadRestartObj::stop(int code) { return 0; }
extern ThreadRestartObj *g_bfmeThreadAtE048E0;
void *Rva00514E20RestartHelper();
void Rva00514E20Restart()
{
    ThreadRestartObj *old = g_bfmeThreadAtE048E0;
    if (old) {
        void *p = old->stop(0);
        operator delete(p);
    }
    ThreadRestartObj *nw = (ThreadRestartObj *)operator new(8);
    if (nw) {
        nw->m_handle = 0;
        new (nw) ThreadRestartObj;
    } else {
        nw = 0;
    }
    g_bfmeThreadAtE048E0 = nw;
    if (nw) {
        ((Rva0073F778 *)nw)->rva0073F83F(1, 0, 4, 0);
    }
}
