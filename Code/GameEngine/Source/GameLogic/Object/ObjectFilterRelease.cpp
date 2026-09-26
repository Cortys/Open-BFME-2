// cl: /O1 /DNDEBUG /MD
// ?Rva00360CB0Release@@YAXPAH@Z @0x00360CB0 61B
// Pool release for the 0x94-byte validity-table record shared with
// ?isValid@ObjectFilter@@QBE_NXZ at 0x00360CED. Index at [arg+0] is -1 when
// empty; otherwise bounds-checked against (end-begin)/0x94 via signed idiv
// from the .data globals at 0x00A01E68/0x00A01E6C, then the dword at
// table+index*0x94+0x8C is decremented and the index reset to -1 via or.
// Evidence: 5 callers in the 0x360xxx science cluster including the
// ??1Rva00360D26Member forwarder at 0x00360D26 (40+ callers incl rowed
// TransportContainModuleData dtor); unblocks 0x00362192 for GarrisonContain
// and TunnelContain ModuleData ctors; same globals/size/flags as sibling.
struct ValidityRecord148
{
    char m_pad00[0x8C];
    int m_refCount;
    char m_pad90[0x94 - 0x90];
};

extern unsigned char *g_validityBegin;
extern unsigned char *g_validityEnd;

void Rva00360CB0Release(int *indexHolder)
{
    int index = *indexHolder;
    if (index == -1)
        return;
    int count = (g_validityEnd - g_validityBegin) / (int)sizeof(ValidityRecord148);
    if ((unsigned int)index > (unsigned int)count)
        return;
    ValidityRecord148 *table = (ValidityRecord148 *)g_validityBegin;
    table[index].m_refCount--;
    *indexHolder = -1;
}
