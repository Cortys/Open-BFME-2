// ??0Rva00501219@@QAE@XZ
// partial score=0.96 date=2026-10-03
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT /Ireference/shims/bfmealloc
// stlport
// ??0Rva00501219@@QAE@XZ @0x00501219 25B: default ctor of map<int vector<vector<BfmePod88>>> forwards empty comp and alloc to rowed _Rb_tree 0x004FF6AB. Evidence: caller 0x005016AF constructs member at +0x4C after five vector bases; neighbours are pair copy and map insert path in same TU.
class Rva004FF6AB
{
public:
	Rva004FF6AB(unsigned dummy0, unsigned dummy1);
};

struct Rva00501219Less
{
	Rva00501219Less() {}
};

struct Rva00501219Alloc
{
	Rva00501219Alloc() {}
};

class Rva00501219
{
public:
	Rva00501219();
private:
	Rva004FF6AB m_tree;
};

// ??0Rva00501219@@QAE@XZ present-unmatched
Rva00501219::Rva00501219() : m_tree((unsigned)&Rva00501219Less(), (unsigned)&Rva00501219Alloc()) {}
