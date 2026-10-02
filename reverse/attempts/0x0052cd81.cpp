// ??0Rva0052CD81@@QAE@ABV0@@Z
// partial score=0.95 date=2026-10-02
// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
// stlport
// ??0Rva0052CD81@@QAE@ABV0@@Z 0x0052CD81 96B evidence: Vector_base SaveMapPreview pin 0x004FF36C; get_allocator 0x0021983A row AsciiString; uninit-copy 0x0052C987 row Rva0052C987Get stride 20 via idiv tag reuse; caller 0x0052D617; v4 real STL custom empty-ctor tag temp for reuse no zero; 97 vs 96B extra push ecx tag at ebp-0xd vs ebp+0xb.
#include <vector>
class Xfer;
class Rva002262E7SnapshotBase {
public:
    virtual ~Rva002262E7SnapshotBase();
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
};
class SaveMapPreview : public Rva002262E7SnapshotBase {
public:
    unsigned int word04;
    struct Words { unsigned int a,b,c; } words08;
    SaveMapPreview(const SaveMapPreview &o);
    virtual ~SaveMapPreview();
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
};
class AsciiString;
struct Rva0052CD81Tag { Rva0052CD81Tag() {} };
void *__cdecl Rva0052C987Get(void *first, void *last, void *result, const Rva0052CD81Tag &tag);
class Rva0052CD81 : public _STL::_Vector_base<SaveMapPreview, _STL::allocator<SaveMapPreview> >
{
public:
    Rva0052CD81(const Rva0052CD81 &x);
};
// ??0Rva0052CD81@@QAE@ABV0@@Z present-unmatched
Rva0052CD81::Rva0052CD81(const Rva0052CD81 &x)
    : _STL::_Vector_base<SaveMapPreview, _STL::allocator<SaveMapPreview> >(x._M_finish - x._M_start, *(const _STL::allocator<SaveMapPreview> *)&((const _STL::vector<AsciiString, _STL::allocator<AsciiString> > &)x).get_allocator())
{
    m_finish = (SaveMapPreview *)Rva0052C987Get(x._M_start, x._M_finish, m_start, Rva0052CD81Tag());
}
