// cl: /O1 /MD
// ?rva0025C061@Rva0025C061@@QAEXPAX@Z, retail 0x0025C061, 28 bytes.
// Reads ScienceType at arg+0x74 and pushes it into the vector<ScienceType> at
// this+4 (callee ?push_back@?$vector@W4ScienceType@@V?$allocator@W4ScienceType@@@_STL@@@_STL@@QAEXABW4ScienceType@@@Z
// rowed in Code/GameEngine/Source/Common/Thing/ThingTemplate.cpp).
// Evidence: callers at 0x005960D2/0x0059634C/0x00596483/0x0059666C pass the same
// holder pointer this free-function wrapper received; prev/next rows live in
// Code/GameEngine/Source/Common (FreeMemberDeleters.cpp /O1 /MD).
enum ScienceType
{
	SCIENCE_FIRST = 0
};

namespace _STL
{

template <class _Tp> class allocator
{
};

template <class _Tp, class _Alloc> class vector
{
public:
	void push_back(const _Tp &v);
	_Tp *m_start;
	_Tp *m_finish;
	_Tp *m_end;
};

}

class Rva0025C061
{
public:
	void rva0025C061(void *holder);
private:
	int m_unk0;
	_STL::vector<ScienceType, _STL::allocator<ScienceType> > m_sciences;
};

void Rva0025C061::rva0025C061(void *holder)
{
	m_sciences.push_back((ScienceType)*(int *)((char *)holder + 0x74));
}
