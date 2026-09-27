// cl: /O1 /MD
// ?rva004D6C9C@Rva004D6C9C@@QAEXW4ScienceType@@@Z @0x004D6C9C (16B):
// Frameless vector<ScienceType>::push_back wrapper, member at +0x04.
// Retail lea eax,[esp+4]; push eax; add ecx,4; call push_back @0x002E01C6;
// ret 4. Single caller 0x002ACCA3 loops a ScienceType vector and pushes each
// element into the +0x730 object. Honest-address name: owner unproven.

enum ScienceType
{
	SCIENCE_INVALID = 0
};

namespace _STL
{
template <class T> class allocator
{
};

template <class T, class A = allocator<T> > class vector
{
public:
	void push_back(const T &value);

	T *m_start;
	T *m_finish;
	T *m_end;
};
}

class Rva004D6C9C
{
public:
	void rva004D6C9C(ScienceType science);

private:
	char m_pad04[4];
	_STL::vector<ScienceType> m_vec;
};

void Rva004D6C9C::rva004D6C9C(ScienceType science)
{
	m_vec.push_back(science);
}
