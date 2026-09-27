// ??1Rva004703E0@@QAE@XZ
// partial score=0.93 date=2026-09-27
// ??1Rva004703E0@@QAE@XZ
// partial score=0.93 date=2026-09-27
// cl: /O1 /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <vector>
struct BfmePod16 { int a[4]; };
template <typename T> class StringBase {
public: ~StringBase() { releaseBuffer(); }
private: void releaseBuffer();
         void *m_data;
};
class AsciiString {
public: ~AsciiString() {}
private: StringBase<char> m_data;
};
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
