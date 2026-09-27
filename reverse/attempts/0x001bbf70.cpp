// _VP6_ConfigureEntropyDecoder
// partial score=0.9280575539568345 date=2026-09-27
// cl: /O2 /MD
// BFME2 reconstruction guided by VP6 donor PDB, matching probability tables,
// MFNode VP62::parseCoeffModelsChanges and BFME1 bank009AB530.
// Banked556-byte C++ vs full target556; residual byte-result register allocation.
// Signed AC type index restores loop control. Four matched helpers; no new pins.
// BFME1 bank had incorrect nesting and missing AC default updates; this body
// follows target and public decoder semantics instead.
// Cdecl PB_INSTANCE* plus unsigned-char frame type from donor type187A1.
// Target full extent1BBF70..1BC19B inclusive=556; Ghidra550 truncates epilogue.
struct PB_INSTANCE {
    unsigned char unaccessed0[0x150];
    unsigned char br[32];
    unsigned char unaccessed1[0x3a0-0x170];
    unsigned char DcProbs[2][11];
    unsigned char AcProbs[2][3][6][11];
    unsigned char DcNodeContexts[30];
    unsigned char ZeroRunProbs[2][14];
    unsigned char unaccessed2[0x63c-0x57c];
    unsigned char ScanBands[64];
};
struct Rva009B4800State;
struct Rva009AAFE0Context;
int Rva009B4800DecodeBool(Rva009B4800State *,int);
int bfmeGoUSC(void *,int);
void Rva009AAFE0BuildTable(Rva009AAFE0Context *,const unsigned char *);
void Rva009B64A0BuildTone(unsigned char *);
extern unsigned char VP6_DcUpdateProbs[2][11];
extern unsigned char ScanBandUpdateProbs[64];
extern unsigned char VP6_ZeroRunUpdateProbs[2][14];
extern unsigned char VP6_ZeroRunDefaultProbs[28];
extern unsigned char VP6_AcUpdateProbs[3][2][6][11];
extern "C" void *__cdecl memset(void *,int,unsigned int);
extern "C" void *__cdecl memcpy(void *,const void *,unsigned int);
#pragma intrinsic(memset,memcpy)
extern "C" void VP6_ConfigureEntropyDecoder(PB_INSTANCE *pbi,unsigned char frameType)
{
    unsigned char *ctx=(unsigned char *)pbi;
    unsigned char previous[11];
    memset(previous,128,sizeof(previous));
    Rva009B4800State *state=(Rva009B4800State *)(pbi->br);
    for(unsigned row=0;row<2;++row) {
        for(unsigned node=0;node<11;++node) {
            if(Rva009B4800DecodeBool(state,VP6_DcUpdateProbs[row][node])) {
                unsigned char value=(unsigned char)(bfmeGoUSC(state,7)<<1);
                value+=(value==0);
                previous[node]=value;
                pbi->DcProbs[row][node]=value;
            } else if(!frameType) pbi->DcProbs[row][node]=previous[node];
        }
    }
    if(!frameType) memcpy(pbi->ZeroRunProbs,VP6_ZeroRunDefaultProbs,28);
    if(Rva009B4800DecodeBool(state,128)) {
        for(unsigned node=1;node<64;++node) {
            if(Rva009B4800DecodeBool(state,ScanBandUpdateProbs[node]))
                pbi->ScanBands[node]=(unsigned char)bfmeGoUSC(state,4);
        }
        Rva009AAFE0BuildTable((Rva009AAFE0Context *)ctx,pbi->ScanBands);
    }
    for(unsigned row=0;row<2;++row) {
        for(unsigned node=0;node<14;++node) {
            if(Rva009B4800DecodeBool(state,VP6_ZeroRunUpdateProbs[row][node])) {
                unsigned char value=(unsigned char)(bfmeGoUSC(state,7)<<1);
                value+=(value==0);
                pbi->ZeroRunProbs[row][node]=value;
            }
        }
    }
    for(int type=0;type<3;++type) {
        for(unsigned block=0;block<2;++block) {
            for(unsigned group=0;group<6;++group) {
                for(unsigned node=0;node<11;++node) {
                    if(Rva009B4800DecodeBool(state,VP6_AcUpdateProbs[type][block][group][node])) {
                        unsigned char value=(unsigned char)(bfmeGoUSC(state,7)<<1);
                        value+=(value==0);
                        previous[node]=value;
                        pbi->AcProbs[block][type][group][node]=value;
                    } else if(!frameType) pbi->AcProbs[block][type][group][node]=previous[node];
                }
            }
        }
    }
    Rva009B64A0BuildTone(ctx);
}
