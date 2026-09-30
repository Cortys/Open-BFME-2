// ?rva001F2155@Rva001F2155@@QAEXPAHABHABU__true_type@_STL@@I_N@Z
// partial score=0.93 date=2026-09-30
// ?rva001F2155@Rva001F2155@@QAEXPAHABHABU__true_type@_STL@@I_N@Z
// partial score=0.93 date=2026-09-30
// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/ocls /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib /Ireference/shims/bfme_namekey /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/shims -ICode/Libraries/Source/Compression/LZHCompress/CompLibHeader /Ireference/shims/bfme2htree /Ireference/shims/bfme2renderobj /Ireference/shims/bfmecamera /Ireference/shims/bfmelight /Ireference/shims/bfmeparticlehandle /Ireference/shims/bfmeparticleload /Ireference/shims/bfmeparticlequat /Ireference/shims/bfmeparticlesave /Ireference/shims/bfmeparticleline /Ireference/shims/bfme2ray /Ireference/shims/bfme2scene -D_STLP_USE_STATIC_LIB -DNDEBUG -DWIN32 -D_WINDOWS /Ireference/shims/bfmefrustum
// stlport
// ?rva001F2155@Rva001F2155@@QAEXPAHABHABU__true_type@_STL@@I_N@Z @0x001F2155 147B:
// vector<int>-shaped _M_insert_overflow true_type duplicate (stock vector<int>
// overflow already rowed at 0x006887F0 with alloc-only/memmove codegen).
// Retail here uses full-bfmealloc __copy_trivial plus inlined fill loop plus
// wrapper clear 0x0007FAB3 plus direct start/finish/end stores. Evidence:
// unlock lane; caller push_back 0x001F211B (58B) with 5-arg overflow call;
// stack vector<int> at 0x001F21E8 via AllocProxyInt 0x0014F3C4; neighbour
// Rva001F20D6Ctor shares flags. Best probe 150B/63insns vs 147B/63insns:
// new_len in ebx vs edi, new_start spilled to [ebp-4] vs ebx, fill dest in
// edi vs eax. Shape lever row 26 (definition order) tried without effect.
#include <deque>
class Rva001F2155
{
public:
    void rva001F2155(int *pos, const int &val, const _STL::__true_type &t, unsigned int n, bool at_end);
private:
    int *m_start;
    int *m_finish;
    int *m_end;
    void clear();
};
void Rva001F2155::rva001F2155(int *pos, const int &val, const _STL::__true_type &t, unsigned int n, bool at_end)
{
    const unsigned int old_size = m_finish - m_start;
    unsigned int tmp = old_size;
    const unsigned int *pmax = &n;
    if (old_size >= n)
        pmax = &tmp;
    const unsigned int new_len = old_size + *pmax;
    int *new_start;
    if (new_len != 0)
        new_start = (int *)_STL::allocator<char>::allocate(new_len * sizeof(int), 0);
    else
        new_start = 0;
    int *new_finish = (int *)_STL::__copy_trivial(m_start, pos, new_start);
    unsigned int c = n;
    if (c != 0)
        do {
            *new_finish++ = val;
        } while (--c != 0);
    if (!at_end)
        new_finish = (int *)_STL::__copy_trivial(pos, m_finish, new_finish);
    clear();
    m_finish = new_finish;
    m_start = new_start;
    m_end = new_start + new_len;
}
// ?rva001F2155@Rva001F2155@@QAEXPAHABHABU__true_type@_STL@@I_N@Z present-unmatched
