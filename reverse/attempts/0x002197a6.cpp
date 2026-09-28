// ?rva002197A6@Rva002197A6@@QAEPAVRva002197A6Entry@@H@Z
// partial score=0.95 date=2026-09-28
// ?rva002197A6@Rva002197A6@@QAEPAVRva002197A6Entry@@H@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /MD
class Rva002197A6Entry
{
public:
    int m_unk0;
    int m_id;
};
class GameSlot
{
public:
    char m_pad[0x60];
    unsigned char m_has;
    char m_pad61[3];
    Rva002197A6Entry m_obj;
};
class GameInfo
{
public:
    GameSlot *getSlot(int i);
};
extern GameInfo *g_Rva00E02EEC;
extern Rva002197A6Entry **g_Rva009FE358;
extern Rva002197A6Entry **g_Rva009FE35C;
class Rva002197A6
{
public:
    Rva002197A6Entry *rva002197A6(int id);
};
// ?rva002197A6@Rva002197A6@@QAEPAVRva002197A6Entry@@H@Z present-unmatched
Rva002197A6Entry *Rva002197A6::rva002197A6(int id)
{
    unsigned int i = 0;
    Rva002197A6Entry *result = 0;
    if (g_Rva00E02EEC != 0) {
        for (; result == 0 && i < 8; ++i) {
            GameSlot *slot = g_Rva00E02EEC->getSlot(i);
            if (slot == 0)
                continue;
            Rva002197A6Entry *obj = slot->m_has ? &slot->m_obj : (Rva002197A6Entry *)0;
            if (obj == 0)
                continue;
            if (obj->m_id == id)
                result = obj;
        }
        return result;
    } else {
        int count = (int)g_Rva009FE35C - (int)g_Rva009FE358;
        count >>= 2;
        for (; result == 0 && i < (unsigned int)count; ++i) {
            Rva002197A6Entry *obj = g_Rva009FE358[i];
            result = (id == obj->m_id) ? obj : result;
        }
        return result;
    }
}
