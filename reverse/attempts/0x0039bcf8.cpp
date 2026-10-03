// ?rva0039BCF8@Rva0039BCF8@@QAEPAPAXPAX@Z
// partial score=0.92 date=2026-10-03
// ?rva0039BCF8@Rva0039BCF8@@QAEPAPAXPAX@Z
// partial score=0.92 date=2026-10-01
// ?rva0039BCF8@Rva0039BCF8@@QAEPAPAXPAX@Z
// partial score=0.92 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0039BCF8@Rva0039BCF8@@QAEPAPAXPAX@Z @0x0039BCF8 48B vector erase-first helper over +0x304 via rowed voidptr erase.
// Linear search for val then rowed erase; returns erase iterator or end.
// Evidence: callee rowed vector<void*>::erase 0x001FF51F; caller 0x0055A925 passes outer this as val with inner this at +0x10; stride 4 with 0x304/0x308 begin/end; EAX holds end/erase-return on all exits so non-void.

namespace _STL
{
template <typename T> class allocator
{
};
template <typename T, typename A = allocator<T> > class vector
{
public:
	T *m_begin;
	T *m_end;
	T *m_cap;
	void **erase(void **pos);
};
}

class Rva0039BCF8
{
public:
	void **rva0039BCF8(void *val);

	char m_pad[0x304];
	_STL::vector<void *> m_vec;
};

// ?rva0039BCF8@Rva0039BCF8@@QAEPAPAXPAX@Z present-unmatched
void **Rva0039BCF8::rva0039BCF8(void *val)
{
	void **first = m_vec.m_begin;
	void **last = m_vec.m_end;
	if (first == last)
		return last;
	for (void **it = first; it != last; ++it)
	{
		if (*it == val)
			return m_vec.erase(it);
	}
	return last;
}
