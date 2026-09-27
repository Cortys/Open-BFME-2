// cl: /O2 /MD
// Retail prefix-tree walk; PDB supplies the original VP6 identity.
// Target/donor provenance: reverse/vp6_structural_evidence.json, huffman_scalar.
// Authored from target disassembly; source-handoff body text is not imported.
// Only the initialized low byte is used before a complete edge is loaded.
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
int Rva009B4600DecodeBool(void *,int);

extern "C" int VP6_DecodeValue(void *coder,Vp6HuffmanNode *tree)
{
    Vp6HuffmanEdge edge;
    edge.bytes.low=0;
    do {
        Vp6HuffmanNode *node=&tree[edge.fields.index];
        if(Rva009B4600DecodeBool(coder,node->probability)) edge=node->right;
        else edge=node->left;
    } while(!edge.fields.leaf);
    return edge.fields.index;
}
