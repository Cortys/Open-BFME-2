// cl: /O2 /MD
// May2006 Xbox release APT0.19.03 donor supplies AptMath method and static-field
// names; GUID46a11dfd-96b7-4859-900b-d1c12429eda5 age126. Target assertions name
// AptStd/AptMath.h and both count/capacity expressions. Target establishes
// unsigned16 count VA E18100 / capacity E180FC / base pointer E180F4 and stride96.
// ClipTransform_t is an opaque stride view; no internal donor layout is claimed.
// Full Ghidra boundaries6CBD10+78 and6DFDF0+82 agree with donor and final returns.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *,const char *,int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class AptMath {
public:
    struct ClipTransform_t { unsigned char unaccessed[96]; };
    static ClipTransform_t *ClipStackPush();
    static ClipTransform_t *ClipStackPop();
private:
    static ClipTransform_t *m_pStackBase;
    static unsigned short m_nStackCapacity;
    static unsigned short m_nStackCount;
};
// The unusual pop assertion is present in retail: preserve it literally.
AptMath::ClipTransform_t *AptMath::ClipStackPop()
{
    if (!(m_nStackCount < m_nStackCapacity)) {
        g_bfmeAptAssertAtE17734("m_nStackCount < m_nStackCapacity", "..\\..\\include\\apt\\AptStd/AptMath.h",91);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return &m_pStackBase[--m_nStackCount];
}
AptMath::ClipTransform_t *AptMath::ClipStackPush()
{
    if (!((m_nStackCount+1) < m_nStackCapacity)) {
        g_bfmeAptAssertAtE17734("(m_nStackCount+1) < m_nStackCapacity", "..\\..\\include\\apt\\AptStd/AptMath.h",86);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return &m_pStackBase[++m_nStackCount];
}
