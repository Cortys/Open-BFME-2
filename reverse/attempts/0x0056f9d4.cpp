// ??1Rva0056F43E@@QAE@XZ
// partial score=0.93 date=2026-09-29
// ??1Rva0056F43E@@QAE@XZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ??1Rva0056F43E@@QAE@XZ @0x0056F9D4 56B
// Dtor of the Rva0056F43E table: body calls this->rva0056F503; the header
// at m_00 is freed by the implicit destruction of the inline holder member
// m_00 (non-trivial dtor arms EH state 0 and spills this for the funclet).
// Same class: the clear call threads the same this, m_00 at +0 holds header.
// NEAR MISS 52/56: only retail `or [ebp-4],-1` disarm after mov esi,[esi]
// is missing; all offsets/registers identical. Tried: plain /EHsc /EHs,
// try/catch /EHs /EHsc (extra ebx/edi saves + handler tail), scoped guard
// with inline-empty dtor (region collapses), member holder /EHsc (this one).
template <typename T>
class StringBase
{
public:
	void clear();
private:
	void *m_data;
};
extern "C" void __cdecl free(void *p);
struct Rva0056F43EHolder
{
	void *m_ptr;
	~Rva0056F43EHolder() { if (m_ptr) free(m_ptr); }
};
struct Rva0056F43E
{
	Rva0056F43EHolder m_00;
	int m_04;
	void *m_08;
	void *m_0c;
	StringBase<unsigned short> m_10;
	void rva0056F43E(void *node);
	void rva0056F503();
	~Rva0056F43E();
};
Rva0056F43E::~Rva0056F43E()
{
	rva0056F503();
}
