// cl: /O1 /EHsc /arch:SSE /DNDEBUG /MD
// ?rva004B0EBC@EmotionTrackerUpdate@@QAE_NXZ, retail 0x004B0EBC, 41 bytes.
// Honest-address method of EmotionTrackerUpdate proven by vector offsets:
// +0x90/+0x94 are m_emotions begin/end (EmotionTrackerUpdateDtor.cpp has
// EmotionTrackerVecHolder at +0x90). Iterates 4-byte pointer array,
// double-derefs +4 then tests byte at +0x18C, returns bool.
class EmotionTrackerUpdate
{
public:
    bool rva004B0EBC();

private:
    char m_pad[0x90];
    void *m_begin;
    void *m_end;
};

struct Rva004B0EBCInner
{
    char m_pad[4];
    void *m_ptr;
};

struct Rva004B0EBCOuter
{
    char m_pad[0x18C];
    bool m_flag;
};

bool EmotionTrackerUpdate::rva004B0EBC()
{
    void **it = (void **)m_begin;
    void **end = (void **)m_end;
    goto cond;
loop:
    {
        Rva004B0EBCInner *inner = *(Rva004B0EBCInner **)it;
        Rva004B0EBCOuter *outer = *(Rva004B0EBCOuter **)((char *)inner + 4);
        if (*(bool *)((char *)outer + 0x18C)) {
            return true;
        }
        ++it;
    }
cond:
    if (it != end) {
        goto loop;
    }
    return false;
}
