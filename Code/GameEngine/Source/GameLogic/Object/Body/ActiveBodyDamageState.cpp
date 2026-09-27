// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva004BDA29@Rva004BDA29@@QBEHXZ @0x004BDA29 62B. Damage-state calc from
// health ratio without division: returns 3 when health == 0.0f (RUBBLE),
// 2 when health <= reallyThresh*maxHealth, 1 when health <= damagedThresh*
// maxHealth, else 0 (PRISTINE). Evidence: caller 0x004BE8BD/1189B (vtable
// slot 21 of Highlander/Immortal/Structure/Respawn/DelayedDeath/Oathbreaker
// bodies) calls this address with same this then compares result to
// [ebx+0x30] (m_curDamageState) and stores it; reads are [ecx+0x18] health,
// [ecx+0x20] maxHealth, [ecx+0x24] damagedThresh, [ecx+0x28] reallyThresh
// plus global 0.0f at 0x007BAEAC; ZH ActiveBody.cpp calcDamageState donor
// uses same 0/1/2/3 BodyDamageType order with division.
class Rva004BDA29 {
    virtual void vtableSlot0();
    char m_pad04[0x14];
    float m_health;
    char m_pad1C[4];
    float m_maxHealth;
    float m_damagedThresh;
    float m_reallyDamagedThresh;
public:
    int rva004BDA29() const;
};
int Rva004BDA29::rva004BDA29() const
{
    if (m_health == 0.0f)
        return 3;
    else if (m_reallyDamagedThresh * m_maxHealth >= m_health)
        return 2;
    else if (m_damagedThresh * m_maxHealth >= m_health)
        return 1;
    else
        return 0;
}
