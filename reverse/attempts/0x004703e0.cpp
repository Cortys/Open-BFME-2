// ??1Rva004703E0@@QAE@XZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// stlport
// ??1Rva004703E0@@QAE@XZ @0x004703E0 78B non-virtual dtor: vector<BfmePod16> erase then free then AsciiString releaseBuffer
// Evidence: callees rowed vector erase @0x002BF70F _free @0x00030830 releaseBuffer @0x00036410; callers @0x004704AC @0x00475942
#include "ascii_string.h"
#include <vector>
struct BfmePod16 { int a[4]; };
namespace _STL {
template <>
vector<BfmePod16, allocator<BfmePod16> >::iterator
vector<BfmePod16, allocator<BfmePod16> >::erase(
  vector<BfmePod16, allocator<BfmePod16> >::iterator first,
  vector<BfmePod16, allocator<BfmePod16> >::iterator last);
}
class Rva004703E0 {
public: ~Rva004703E0();
private:
  int m_unk0;
  AsciiString m_str;
  _STL::vector<BfmePod16, _STL::allocator<BfmePod16> > m_vec;
};
Rva004703E0::~Rva004703E0() {
  _STL::vector<BfmePod16, _STL::allocator<BfmePod16> > &v = m_vec;
  v.erase(v.begin(), v.end());
}
