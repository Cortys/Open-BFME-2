// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?Rva00339A8DCopy@@YAPAV?$vector@HV?$allocator@H@_STL@@@_STL@@PAV12@00PAXH@Z @0x00339A8D 50B forward copy via rowed 0x0021C21B stride 0xC with dummy trailing args.
// Retail: push ebp / mov ebp esp / mov eax [ebp+c] / sub eax [ebp+8] / push 0xc / cdq / pop ecx / idiv ecx / test eax eax / jle / push esi / mov esi eax / push [ebp+8] / mov ecx [ebp+0x10] / call 0x21C21B / add [ebp+8] 0xc / add [ebp+0x10] 0xc / dec esi / jne / pop esi / mov eax [ebp+0x10] / pop ebp / ret.
// Target facts: __cdecl (first last dest tag extra) -> dest; count=(last-first)/12 via idiv 0xC; loop *dest=*first via rowed vector assign ++first ++dest; tag/extra dead for 5-arg callers with add esp 0x14; caller 0x001FFC38 pushes 5.
// Callers: 0x001FFC38 wrapper pushes 5; callees: 0x0021C21B vector<int> assign (int pin; ScienceType and int are both 4B PODs with identical codegen per rowed dup_0021c21b).
// Precedent: Rva0014FA90Copy 50B same shape stride 0x4C with dummy-tag 5-arg form; Rva0039BAA0Copy 50B stride 0x14; PlayerScienceAssign uses int spelling of folded assign.
// Not established: owning class identity; honest Rva address-derived free-function name.

namespace _STL
{

template <class Type>
class allocator
{
};

template <class Type, class Allocator>
class vector
{
public:
	typedef Type *pointer;

	vector &operator=(const vector &x);

private:
	pointer m_start;
	pointer m_finish;
	pointer m_endOfStorage;
};

}

typedef _STL::vector<int, _STL::allocator<int> > SciVec;

SciVec *__cdecl Rva00339A8DCopy(SciVec *first, SciVec *last, SciVec *dest, void *tag, int extra)
{
	int n = last - first;
	if (n <= 0)
		return dest;
	for (int i = n; i != 0; --i) {
		*dest = *first;
		++first;
		++dest;
	}
	return dest;
}
