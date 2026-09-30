// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ??1Rva0020D583@@UAE@XZ 0x0020D583 99B evidence: dtor with vptr 0x007E3F98 plus 5 StringBase D releaseBuffer rowed; caller Unwind deleting dtor; prev ConstZeroGetters
template <typename T> class StringBase {
public: ~StringBase() { releaseBuffer(); }
private: void releaseBuffer();
         T *m_data; };
class Rva0020D583 {
public: virtual ~Rva0020D583();
private: StringBase<char> m_04;
         StringBase<char> m_08;
         StringBase<char> m_0c;
         StringBase<char> m_10;
         StringBase<char> m_14; };
Rva0020D583::~Rva0020D583() {}
