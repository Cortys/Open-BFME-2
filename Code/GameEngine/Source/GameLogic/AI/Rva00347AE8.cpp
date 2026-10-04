// cl: /O1 /DNDEBUG /MD
// ?rva00347AE8@Rva00342843@@UAEXXZ @0x00347AE8 85B via vtable slot6 of Rva00342843 with CritterDesync log and tailjmp to bfmeTail932E
typedef bool Bool;
struct Coord3D
{
    float x;
    float y;
    float z;
};
class StateMachine;
class AIUpdateInterface
{
public:
    char m_pad[0x140];
    int m_140;
    char m_pad2[0x3B1 - 0x144];
    unsigned char m_3B1;
};
class Object
{
public:
    char m_pad[0x258];
    AIUpdateInterface *m_ai;
};
class StateMachine
{
public:
    char m_pad[0x14];
    Object *m_owner;
};
class State
{
public:
    virtual ~State();
    virtual void slot01();
    virtual void slot02();
    virtual void xfer();
    virtual int onEnter();
    virtual void onExit();
    virtual int update();
protected:
    unsigned char m_pad04[0x18 - 0x04];
    StateMachine *m_machine;
};
class AIInternalMoveToState : public State
{
public:
    AIInternalMoveToState(StateMachine *machine, unsigned int hash);
    virtual ~AIInternalMoveToState();
    virtual void xfer();
    virtual int onEnter();
    virtual void onExit();
    virtual int update();
protected:
    unsigned char m_pad1C[0x20 - 0x1C];
    Coord3D m_goalPosition;
    unsigned char m_pad2C[0x48 - (0x20 + sizeof(Coord3D))];
    bool m_adjustsDestination;
};
class Rva00342843 : public AIInternalMoveToState
{
public:
    Rva00342843(StateMachine *machine);
    virtual void rva00347AE8();
private:
    int m_4C;
    bool m_50;
};
class BfmeThing932E
{
public:
    void bfmeTail932E();
};
extern "C" void *theLogicRandomLogFile;
extern unsigned char g_00E03745;
extern "C" int __cdecl fprintf(void *stream, const char *format, ...);

void Rva00342843::rva00347AE8()
{
    if (m_50) {
        Object *owner = m_machine->m_owner;
        AIUpdateInterface *ai = owner->m_ai;
        if (ai->m_140 != 0) {
            if (ai->m_3B1 == 0) {
                if (g_00E03745 != 0) {
                    if (theLogicRandomLogFile != 0) {
                        fprintf(theLogicRandomLogFile, "CritterDesync: setAdjustDestination(TRUE) 8");
                    }
                }
                m_adjustsDestination = true;
                m_50 = false;
            }
        }
    }
    ((BfmeThing932E *)this)->bfmeTail932E();
}
