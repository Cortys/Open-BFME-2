// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ
// partial score=0.94 date=2026-10-04
// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?rva0009D9BD@Rva0009D9BD@@QAEXXZ, retail 0x0009D9BD, 64 bytes.
// Index loop over vector<void*> at +0x1C0 via rowed thunk 0x000518E0
// then erase begin-end via rowed 0x0031BD55. Evidence: sar 2 count,
// push [eax+edi*4] plus thunk plus erase, 2 unblocked plus 3 callers.
//
// space-bunny-alpha: the whole structure is byte-exact except which register
// holds the loop count (see re_attempts.log). Retail computes
//   mov eax,[esi+4] ; sub eax,[esi] ; sar eax,2     (count in eax, 2-byte sub)
// before the loop test AND on loop-back; ours emits
//   mov eax,[esi] ; mov ecx,[esi+4] ; sub ecx,eax ; sar ecx,2  (count in ecx,
// 3-byte) because STLport size() = (finish - start)/sizeof(T) materializes start
// first. A source that keeps a cached size_type local (unsigned int n) DOES emit
// retail's exact 2-byte `sub X,[r]` count sequence (verified R1/R2/R3), but then
// hoists it into a callee-saved register computed once and adds push-ebx noise,
// instead of recomputing into eax each pass as retail does. So the two-byte count
// and the per-iteration recompute into eax are mutually exclusive under cl 7.1 /O1:
// size() in the loop condition forces the re-read but materializes through ecx;
// a cached local gives the exact sub but hoists. Register-allocation limit only.

#include <vector>

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
