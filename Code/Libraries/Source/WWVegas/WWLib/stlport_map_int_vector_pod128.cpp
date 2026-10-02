// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT /Ireference/shims/bfmealloc
// stlport
//
// The insert path of map<int, vector<BfmePod128> >. Target evidence: the pair
// copy it places calls the rowed vector<BfmePod128> copy constructor
// (0x0032ADC8, stlport_pod_vector_bodies.cpp) for the value at +4, after a
// one-word key copy, and the node constructor allocates 0x20 bytes (a 0x10-byte
// tree header plus the 0x10-byte pair). The tree bodies are the int-keyed ones
// stlport_map_int_int_os.cpp lands for map<int, int>, with its flags.

#include <map>
#include <vector>

struct BfmePod128 { int a[32]; };

typedef _STL::map<int, _STL::vector<BfmePod128> > IntPod128VectorMap;

template class _STL::map<int, _STL::vector<BfmePod128> >;
