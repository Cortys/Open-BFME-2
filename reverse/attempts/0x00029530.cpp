// ?bfmeDoInsertQX@BfmeThingQX@@QAEXPADIE@Z
// partial score=0.65 date=2026-10-02
// cl: /Od
// STLport narrow-string insertion bodies, reached by BfmeThingQX wrappers.

namespace _STL
{
	typedef unsigned int size_type;

	void *__cdecl __copy_trivial(const void *first, const void *last,
		void *result);
	void __cdecl fill(char *first, char *last, const char &value);
	void __cdecl free(void *block);

	template <class T>
	class allocator
	{
	public:
		static T *__cdecl allocate(size_type count, const void *hint);
	};

	template <class T>
	class char_traits {};

	template <>
	class char_traits<char>
	{
	public:
		static char *__cdecl assign(char *destination, size_type count,
			char value);
	};

	template <class T>
	__forceinline T *uninitialized_copy(T *first, T *last, T *result)
	{
		return (T *)__copy_trivial(first, last, result);
	}

	template <class T>
	inline const T &(max)(const T &a, const T &b)
	{
		return a < b ? b : a;
	}

}

#define BFME_UNINITIALIZED_FILL_N(first, count, value) \
	(_STL::fill((first), (first) + (count), (value)), (first) + (count))
#define BFME_UNINITIALIZED_COPY(first, last, result) \
	((char *)_STL::__copy_trivial((first), (last), (result)))

// The range-destroy helper is an empty retail body at 0x69E440. Reuse its
// existing two-slot cdecl pin; the target's callee identity is unresolved.
void __cdecl ReportError(char *message, int code);

extern "C" __declspec(dllimport) void *__cdecl memmove(void *destination,
	const void *source, unsigned int count);

struct BfmeThingQX
{
	BfmeThingQX *bfmeInsertQX(unsigned int where, unsigned int many, unsigned char what);

	void bfmeRangeErrorQX(void);

	void bfmeLengthErrorQX(void);

	void bfmeDoInsertQX(char *at, unsigned int many, unsigned char what);

	char *m_bfmeAt;				// 0x0
	char *m_bfmeEnd;			// 0x4
	char *m_bfmeStorageEnd;		// 0x8
};

void BfmeThingQX::bfmeDoInsertQX(char *at, unsigned int many,
	unsigned char what)
{
	if (many != 0) {
		if ((unsigned int)(m_bfmeStorageEnd - m_bfmeEnd) >= many + 1) {
			const unsigned int elems_after = m_bfmeEnd - at;
			char *old_finish = m_bfmeEnd;
			if (elems_after >= many) {
				BFME_UNINITIALIZED_COPY((m_bfmeEnd - many) + 1,
					m_bfmeEnd + 1, m_bfmeEnd + 1);
				m_bfmeEnd += many;
				memmove(at + many, at, (elems_after - many) + 1);
				_STL::char_traits<char>::assign(at, many, what);
			}
			else {
				BFME_UNINITIALIZED_FILL_N(m_bfmeEnd + 1,
					many - elems_after - 1, *(char *)&what);
				m_bfmeEnd += many - elems_after;
				BFME_UNINITIALIZED_COPY(at, old_finish + 1, m_bfmeEnd);
				m_bfmeEnd += elems_after;
				_STL::char_traits<char>::assign(at, elems_after + 1, what);
			}
		}
		else {
			const unsigned int old_size = m_bfmeEnd - m_bfmeAt;
			const unsigned int len = old_size +
				(unsigned int)(_STL::max)(old_size, many) + 1;
			char *new_start = _STL::allocator<char>::allocate(len, 0);
			char *new_finish = new_start;
			new_finish = BFME_UNINITIALIZED_COPY(m_bfmeAt, at, new_start);
			new_finish = BFME_UNINITIALIZED_FILL_N(new_finish, many,
				*(char *)&what);
			new_finish = BFME_UNINITIALIZED_COPY(at, m_bfmeEnd,
				new_finish);
			*new_finish = 0;
			ReportError(m_bfmeAt, (int)(m_bfmeEnd + 1));
			if (m_bfmeAt != 0)
				_STL::free(m_bfmeAt);
			m_bfmeAt = new_start;
			m_bfmeEnd = new_finish;
			m_bfmeStorageEnd = new_start + len;
		}
	}
}

BfmeThingQX *BfmeThingQX::bfmeInsertQX(unsigned int where, unsigned int many, unsigned char what)
{
	if (where > (unsigned int)(m_bfmeEnd - m_bfmeAt))
		bfmeRangeErrorQX();

	if ((unsigned int)(m_bfmeEnd - m_bfmeAt) > 0xfffffffe - many)
		bfmeLengthErrorQX();

	char *at = m_bfmeAt;

	bfmeDoInsertQX(at + where, many, what);

	return this;
}
