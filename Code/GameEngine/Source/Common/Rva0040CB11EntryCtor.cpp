// cl: /O1
// ??0Rva0040CB11Entry@@QAE@HABVRva004F6093Holder@@@Z @0x0040CB11 27B
// Entry ctor for sorted vector: int key at +0, Holder value at +4 via copy ctor.
// Evidence: 1 caller at 0x0040ED06; callee copy ctor 0x004F6093 now rowed; shared 8-byte entry layout with twin getters and binary search.
class Rva004F6093Holder
{
public:
	Rva004F6093Holder(const Rva004F6093Holder &other);
};

class Rva0040CB11Entry
{
public:
	Rva0040CB11Entry(int key, const Rva004F6093Holder &val);
	Rva0040CB11Entry(const Rva0040CB11Entry &other);
private:
	int m_first;
	Rva004F6093Holder m_second;
};

Rva0040CB11Entry::Rva0040CB11Entry(int key, const Rva004F6093Holder &val) : m_first(key), m_second(val)
{
}

Rva0040CB11Entry::Rva0040CB11Entry(const Rva0040CB11Entry &other) : m_first(other.m_first), m_second(other.m_second)
{
}

typedef unsigned int size_t;

inline void *operator new(size_t, void *place)
{
	return place;
}

namespace _STL
{

template <class T1, class T2>
void _Construct(T1 *p, const T2 &value)
{
	if (p)
		new (p) T1(value);
}

}

template void _STL::_Construct(Rva0040CB11Entry *, const Rva0040CB11Entry &);
