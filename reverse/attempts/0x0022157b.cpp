// ?Rva0022157BGet@@YAXPAVINI@@@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?Rva0022157BGet@@YAXPAVINI@@@Z @0x0022157B 90B
// Calls 0x002214C5 to build FieldParse vector then INI::initFromINI with global g_00DFE4BC plus _free via vector dtor. Evidence: retail bytes plus rowed callees plus caller chain from 0x002214C5.
#include <vector>
#include "ascii_string.h"

struct BfmeE16 { const char *a; void *b; void *c; int d; };
struct FieldParse { const char *token; void *parse; const void *userdata; int offset; };
class INI {
public:
    void initFromINI(void *what, const FieldParse *parseTable);
};

extern void *g_00DFE4BC;
void Rva002214C5Get(_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > *out);

// ?Rva0022157BGet@@YAXPAVINI@@@Z present-unmatched
void Rva0022157BGet(INI *ini)
{
    _STL::vector<BfmeE16, _STL::allocator<BfmeE16> > tmp;
    Rva002214C5Get(&tmp);
    if (tmp.begin() != tmp.end())
        ini->initFromINI(g_00DFE4BC, (const FieldParse *)&*tmp.begin());
}
