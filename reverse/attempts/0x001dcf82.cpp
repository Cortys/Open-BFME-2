// ?rva001DCF82@Rva001DCF82@@QAEXXZ
// partial score=0.91 date=2026-09-29
// ?rva001DCF82@Rva001DCF82@@QAEXXZ
// partial score=0.91 date=2026-09-29
// ?rva001DCF82@Rva001DCF82@@QAEXXZ
// partial score=0.91 date=2026-09-29
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /G7 /arch:SSE
// ?rva001DCF82@Rva001DCF82@@QAEXXZ @0x001DCF82 71B evidence: caller 0x001DF91B; LogicFPS 0x00DBA4E4; floats at 0x00BBE358 0x00BDC380 guessed as 1.0f 2.0f unproven

class Rva001DCF82
{
public:
    void rva001DCF82();
private:
    float m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    float m_14;
};

void Rva001DCF82::rva001DCF82()
{
    m_00 = 1.0f;
    m_04 = *(const int *)0x00DBA4E4 * 3;
    m_08 = *(const int *)0x00DBA4E4 * 7;
    m_0c = *(const int *)0x00DBA4E4 * 30;
    m_10 = 2000;
    m_14 = 2.0f;
}
