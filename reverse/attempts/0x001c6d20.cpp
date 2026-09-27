// _VP6_EncodeValue
// partial score=0.9291338582677166 date=2026-09-27
// cl: /O2 /Ob0 /Gy /MD
union Vp6HuffmanEdge {
    unsigned value;
    struct { unsigned low:8; unsigned high:24; } bytes;
    struct { unsigned leaf:1; unsigned index:7; unsigned rest:24; } fields;
};
struct Vp6HuffmanNode {
    Vp6HuffmanEdge left;
    Vp6HuffmanEdge right;
    unsigned char probability;
};
struct Vp6BoolEncoder;
struct Rva009AC4B0State;
struct Vp6HuffmanCoder {
    unsigned char prefix[0x18];
    unsigned measureCost;
};
extern "C" void VP6_EncodeBool(Vp6BoolEncoder *,int,int);
void Rva009AC4B0AddValue(Rva009AC4B0State *,int,int);
int Rva009B4600DecodeBool(void *,int);

extern "C" void VP6_EncodeValue(Vp6HuffmanCoder *coder,Vp6HuffmanNode *tree,int code,int length)
{
    unsigned index=0;
    for(--length;length>=0;--length) {
        int bit=(code>>length)&1;
        if(coder->measureCost)
            Rva009AC4B0AddValue((Rva009AC4B0State *)coder,bit,tree[index].probability);
        else
            VP6_EncodeBool((Vp6BoolEncoder *)coder,bit,tree[index].probability);
        if(bit) index=tree[index].right.fields.index;
        else index=tree[index].left.fields.index;
    }
}
