// ?Rva005116C2Load@@YAXXZ
// partial score=0.95 date=2026-09-29
// ?Rva005116C2Load@@YAXXZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva005116C2Load@@YAXXZ @0x005116C2 110B.
// Loads Messenger.apt when game state allows; early-outs otherwise.
// Evidence: unlock lane packet; GameLogic row; StringBase private ctor via
// friend; manager slot 32 then slot 0.
// ?Rva005116C2Load@@YAXXZ present-unmatched
void Rva005116C2Load();
template <typename T>
class StringBase {
    StringBase(const char *s);
    friend void Rva005116C2Load();
    void *m_data;
};
class GameLogic {
    char m_pad[0x110];
public:
    int m_gameMode;
    bool isInMultiplayerGame();
};
class Rva005116C2Obj {
public:
    virtual void use(int x);
};
class Rva005116C2Mgr {
public:
    virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
    virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
    virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
    virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
    virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
    virtual Rva005116C2Obj *load();
};
struct Rva005116C2A {
    char _pad[0xa44];
    int m_flag;
};
extern int g_bfmeFlagAtE02320;
extern int g_bfmeFlagAtDFE958;
extern int g_bfmeFlagAtE046B8;
extern GameLogic *g_bfmeGameLogicAtDFE78C;
extern Rva005116C2A *g_bfmeAAtDFE758;
extern Rva005116C2Mgr *g_bfmeMgrAtDFEF1C;
void Rva005116C2Load()
{
    if (g_bfmeFlagAtE02320 != 0)
        goto check;
    if (g_bfmeFlagAtDFE958 == 0)
        return;
check:
    if (g_bfmeFlagAtE046B8 != 0)
        return;
    GameLogic *g = g_bfmeGameLogicAtDFE78C;
    if (g->isInMultiplayerGame()) {
        if (g->m_gameMode == 3)
            return;
        if (g_bfmeAAtDFE758->m_flag == 0)
            return;
    }
    StringBase<char> name = "Messenger.apt";
    Rva005116C2Obj *o = g_bfmeMgrAtDFEF1C->load();
    o->use(0);
}
