// cl: /O1
// ?erase@?$vector@UBfmeStringRecord00204A30@@V?$allocator@UBfmeStringRecord00204A30@@@_STL@@@_STL@@QAEPAUBfmeStringRecord00204A30@@PAU3@@Z @ 0x00357CA2 (55B).
// Single-element vector erase over 20-byte BfmeStringRecord00204A30 (word AsciiString word AsciiString word).
// Evidence: shift tail via rowed __copy_ptrs 0x00204A13 then pop finish and destroy via rowed dtor 0x00204848;
// shape-identical to rowed ModuleInfo Nugget single erase 0x0033C3BC (55B ret 4); caller is 0x00357D7D.
class AsciiString
{
public:
	~AsciiString();

private:
	void *m_data;
};

struct BfmeStringRecord00204A30
{
	~BfmeStringRecord00204A30();

	unsigned int word0;
	AsciiString text0;
	unsigned int word1;
	AsciiString text1;
	unsigned int word2;
};

namespace _STL
{

struct __false_type
{
};

template <class Type>
class allocator
{
};

template <class Type, class Allocator>
class vector
{
public:
	typedef Type *iterator;

	iterator erase(iterator position);
	iterator end() { return m_finish; }

private:
	iterator m_start;
	iterator m_finish;
	iterator m_endOfStorage;
};

template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type &tag);

template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type *tag, int extra);

template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type &tag)
{
	__false_type local;
	return __copy_ptrs(first, last, result, &local, 0);
}

}

_STL::vector<BfmeStringRecord00204A30, _STL::allocator<BfmeStringRecord00204A30> >::iterator
_STL::vector<BfmeStringRecord00204A30, _STL::allocator<BfmeStringRecord00204A30> >::erase(
	iterator position)
{
	if (position + 1 != end())
	{
		__copy_ptrs(position + 1, m_finish, position, __false_type());
	}

	--m_finish;
	m_finish->~BfmeStringRecord00204A30();
	return position;
}
