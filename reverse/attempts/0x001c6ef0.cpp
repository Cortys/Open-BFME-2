// _VP6_ConfigureMvEntropyDecoder
// partial score=0.8301282051282052 date=2026-09-27
// cl: /O2 /MD
// VP6 motion-model updates: target 0x001C6EF0..0x001C703A (331 bytes).
// Donor name/layout plus independently equal 34-byte update table and public
// VP62::parseVectorModelsChanges semantics. Frame type is unused in both bodies.
struct MvPB {
    unsigned char unknown0[0x150];
    unsigned char br[32];
    unsigned char unknown1[0x704-0x170];
    unsigned char MvSignProbs[2], IsMvShortProb[2];
    unsigned char MvShortProbs[2][7];
    unsigned char unknown2[6];
    unsigned char MvSizeProbs[2][8];
};
extern unsigned char VP6_MvUpdateProbs[2][17];
int Rva009B4600DecodeBool(void *,int);
int bfmeGoUSC(void *,int);
extern "C" void VP6_ConfigureMvEntropyDecoder(MvPB *pbi,unsigned char frameType)
{
    for(int comp=0;comp<2;++comp) {
        if(Rva009B4600DecodeBool(pbi->br,VP6_MvUpdateProbs[comp][0])) {
            pbi->IsMvShortProb[comp]=(unsigned char)(bfmeGoUSC(pbi->br,7)<<1);
            if(!pbi->IsMvShortProb[comp]) pbi->IsMvShortProb[comp]=1;
        }
        if(Rva009B4600DecodeBool(pbi->br,VP6_MvUpdateProbs[comp][1])) {
            pbi->MvSignProbs[comp]=(unsigned char)(bfmeGoUSC(pbi->br,7)<<1);
            if(!pbi->MvSignProbs[comp]) pbi->MvSignProbs[comp]=1;
        }
    }
    for(int comp=0;comp<2;++comp) {
        for(unsigned node=0;node<7;++node) {
            if(Rva009B4600DecodeBool(pbi->br,VP6_MvUpdateProbs[comp][2+node])) {
                pbi->MvShortProbs[comp][node]=(unsigned char)(bfmeGoUSC(pbi->br,7)<<1);
                if(!pbi->MvShortProbs[comp][node]) pbi->MvShortProbs[comp][node]=1;
            }
        }
    }
    for(int comp=0;comp<2;++comp) {
        for(unsigned node=0;node<8;++node) {
            if(Rva009B4600DecodeBool(pbi->br,VP6_MvUpdateProbs[comp][9+node])) {
                pbi->MvSizeProbs[comp][node]=(unsigned char)(bfmeGoUSC(pbi->br,7)<<1);
                if(!pbi->MvSizeProbs[comp][node]) pbi->MvSizeProbs[comp][node]=1;
            }
        }
    }
}
