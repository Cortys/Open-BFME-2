// cl: /O1 /MD
// ?rva00041078@Rva00041078@@QAE_NKHPAH@Z @0x00041078 160B
// WaitForMultipleObjects wrapper: waits on m_handles with timeout, marks
// m_done bytes and optionally reports the signaled index via out. Evidence:
// 4 callers at 0x0004132D 0x000413EB 0x0073F0E3 0x0073F292, IAT
// WaitForMultipleObjects at 0x00BBA2D8, neighbours share /O1 /MD. Honest
// address-derived name: identity unproven from 160 bytes.
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForMultipleObjects(unsigned long nCount, const void *lpHandles, int bWaitAll, unsigned long dwMilliseconds);

class Rva00041078
{
public:
    bool rva00041078(unsigned long timeout, int single, int *out);
private:
    void *m_handles; // +0
    int m_pad04; // +4
    unsigned char *m_done; // +8
    int m_count; // +0xc
};

bool Rva00041078::rva00041078(unsigned long timeout, int single, int *out)
{
    if (out != 0)
        *out = 0;
    unsigned long result = WaitForMultipleObjects((unsigned long)m_count, m_handles, single == 0, timeout);
    if (result < (unsigned long)m_count) {
        if (single == 0) {
            for (int i = 0; i < m_count; ++i)
                m_done[i] = 1;
        } else {
            m_done[result] = 1;
            if (out != 0)
                *out = (int)result;
        }
        return true;
    } else {
        if (result < 0x80 || result >= (unsigned long)(m_count + 0x80))
            return false;
        if (single == 0) {
            for (int i = 0; i < m_count; ++i)
                m_done[i] = 1;
        } else {
            m_done[result - 0x80] = 1;
            if (out != 0)
                *out = (int)(result - 0x80);
        }
        return true;
    }
}
