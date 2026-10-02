// ??0Rva0052CD81@@QAE@ABV0@@Z
// partial score=0.9 date=2026-10-02
// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
// stlport
// ??0Rva0052CD81@@QAE@ABV0@@Z 0x0052CD81 96B evidence: Vector_base SaveMapPreview pin 0x004FF36C; get_allocator 0x0021983A row AsciiString; uninit-copy 0x0052C987 row Rva0052C987Get stride 20 via idiv; caller 0x0052D617; v4 real STL for EH prolog like SaveMapPreviewCopy but throwing copy; no TU-local STL redefinitions.
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
void *__cdecl Rva0052C987Get(void *first, void *last, void *result);
class Rva0052CD81 : public _STL::_Vector_base<SaveMapPreview, _STL::allocator<SaveMapPreview> >
{
public:
	Rva0052CD81(const Rva0052CD81 &x);
};
// ??0Rva0052CD81@@QAE@ABV0@@Z present-unmatched
Rva0052CD81::Rva0052CD81(const Rva0052CD81 &x)
	: _STL::_Vector_base<SaveMapPreview, _STL::allocator<SaveMapPreview> >(x._M_finish - x._M_start, *(const _STL::allocator<SaveMapPreview> *)&((const _STL::vector<AsciiString, _STL::allocator<AsciiString> > &)x).get_allocator())
{
	_M_finish = (SaveMapPreview *)Rva0052C987Get(x._M_start, x._M_finish, _M_start);
}
