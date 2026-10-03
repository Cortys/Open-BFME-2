// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ
// partial score=0.93 date=2026-10-03
// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ
// cl: /O1 /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ, retail 0x0009D9BD, 64 bytes.
// Index loop over vector<void*> at +0x1C0 via rowed thunk 0x000518E0
// then erase begin-end via rowed 0x0031BD55. Evidence: sar 2 count,
// push [eax+edi*4] plus thunk plus erase, 2 unblocked plus 3 callers.

#include <vector>

// Retail pushes the element then loads ecx from the unnamed global at
// 0x00DE5DFC before calling 0x000518E0, which reads its this from [esp+4]
// and never uses ecx. So the call site was written as a __thiscall member
// on a global instance, not a free stdcall thunk.
class Rva000518E0Owner
{
public:
	void rva000518E0Thunk(void *p);
};

extern Rva000518E0Owner *g_Rva000DE5DFC;

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
	_STL::vector<void *> &vec = m_vec;
	for (unsigned int i = 0; i < vec.size(); ++i)
		g_Rva000DE5DFC->rva000518E0Thunk(vec[i]);
	vec.erase(vec.begin(), vec.end());

}
