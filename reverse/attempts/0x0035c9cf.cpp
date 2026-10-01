// ?rva0035C9CF@Rva0035CAD6@@QAEXXZ
// partial score=0.96 date=2026-10-01
// ?rva0035C9CF@Rva0035CAD6@@QAEXXZ
// partial score=0.96 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /GX- /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0035CAD6@@QAE@XZ @0x0035CAD6 49B. Ctor of an unknown BFME2NativeNetwork
// derived class (vtable 0x0081635C) with a 4-byte-element vector at +0xC that
// is cleared in the body. Base via inline BFME2NativeNetwork ctor calling the
// rowed baseConstruct 0x001B4E63 (Rva001FDB55Ctor precedent); member builds
// through the ICF-folded empty _Vector_base at 0x00211E58 and clears through
// the folded erase at 0x0031BD55 (BannerCarrierUpdateModuleDataCtor precedent
// for pointer-vector clear). Element is a 4-byte placeholder (long); real
// element type unproven beyond 4-byte trivial clear semantics. Sole caller
// at 0x0022F5FD.
#include <vector>

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

namespace _STL {
// Declared only so the default construction stays an outlined call that the
// gate resolves to the folded base at 0x00211E58; with the visible STLport
// definition the build inlines the base and the call vanishes.
template<> _Vector_base<long, allocator<long> >::_Vector_base(const allocator<long> &);
// Same for the clear path: keep erase outlined for the folded body at
// 0x0031BD55.
template<> long *vector<long, allocator<long> >::erase(long *, long *);
// Single-element erase stays outlined for the folded body at 0x001FF51F.
template<> long *vector<long, allocator<long> >::erase(long *);
}

class __declspec(novtable) BFME2NativeNetwork
{
public:
	__forceinline BFME2NativeNetwork() { baseConstruct(); }
	virtual ~BFME2NativeNetwork() { _ReadWriteBarrier(); }
	BFME2NativeNetwork *baseConstruct();
private:
	virtual void unused() = 0;
	char m_flag;
	int m_value;
};

class Overridable
{
public:
	Overridable *deleteOverrides();
};

class Rva0035CAD6 : public BFME2NativeNetwork
{
public:
	Rva0035CAD6();
	void rva0035C9CF();
private:
	_STL::vector<long, _STL::allocator<long> > m_vec;
};

Rva0035CAD6::Rva0035CAD6()
{
	m_vec.clear();
}

// ?rva0035C9CF@Rva0035CAD6@@QAEXXZ present-unmatched
void Rva0035CAD6::rva0035C9CF()
{
	for (long *it = m_vec.begin(); it != m_vec.end();) {
		long v = *it;
		Overridable *o = reinterpret_cast<Overridable *>(v);
		if (v == 0 || o->deleteOverrides() == 0) {
			long *pos = it;
			it = m_vec.erase(pos);
		}
		else
			++it;
	}
}
