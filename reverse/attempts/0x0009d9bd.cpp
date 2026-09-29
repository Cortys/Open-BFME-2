// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ
// partial score=0.9 date=2026-09-29
// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ
// partial score=0.90 date=2026-09-29
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ, retail 0x0009D9BD, 64 bytes.
// Index loop over vector<void*> at +0x1C0 via rowed thunk 0x000518E0
// then erase begin-end via rowed 0x0031BD55. Evidence: sar 2 count,
// push [eax+edi*4] plus thunk plus erase, 2 unblocked plus 3 callers.

#include <vector>

void __stdcall Rva000518E0Thunk(void *p);

class Rva0009D9BD
{
public:
	void rva0009D9BD();

private:
	unsigned char m_pad00[0x1C0];
	_STL::vector<void *> m_vec;
};

// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ present-unmatched
void Rva0009D9BD::rva0009D9BD()
{
	for (unsigned int i = 0; i < m_vec.size(); ++i)
		Rva000518E0Thunk(m_vec[i]);
	m_vec.erase(m_vec.begin(), m_vec.end());
}
