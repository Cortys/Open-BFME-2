// cl: /O1 /Ireference/shims/bfmevector /G7 /arch:SSE /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
//
// ?rva004ECECD@Rva004ECECD@@QAEPAVTeam@@H@Z retail 0x004ECECD 56B
// Evidence: unlock lane; array stride 0x14 matches ModelNodeClass (RenderObj Model + BoneIndex + Vector3 Offset) in HLodModelNodeAssign.cpp; callees rowed/pinned TheTeamFactory 0x00A028BC plus findInstance 0x0039F761; callers 0x005ACDA9 (push 0) 0x005AD0E6 (push eax null Object then Team iterate) plus 11 more; prev 0x004ECEA8 ModelNodeClass::operator= ends at this start.
class Team;
class TeamFactory;
extern TeamFactory *TheTeamFactory;

class Rva0039F761Owner
{
public:
    Team *findInstance(void *p);
};

struct Rva004ECECDNode
{
    void *m_model;
    char m_pad[0x10];
};

class Rva004ECECD
{
public:
    Team *rva004ECECD(int id);

private:
    char m_pad00[0x14];
    Rva004ECECDNode *m_begin;
    Rva004ECECDNode *m_end;
};

Team *Rva004ECECD::rva004ECECD(int id)
{
    Rva004ECECDNode *begin = m_begin;
    Rva004ECECDNode *end = m_end;
    for (Rva004ECECDNode *it = begin; it != end; ++it)
    {
        Team *t = ((Rva0039F761Owner *)TheTeamFactory)->findInstance(it->m_model);
        if (t != 0)
        {
            void *mid = *(void **)((char *)t + 0x30);
            if (*(int *)((char *)mid + 0x2dc) == id)
                return t;
        }
    }
    return 0;
}
