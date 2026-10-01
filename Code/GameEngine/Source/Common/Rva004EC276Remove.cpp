// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva004EC276@Rva004EC276@@QAEXPAX@Z @ 0x004EC276, 94 bytes.
// Removes value from vector<void*> at +0x130 and list<int> at +0x13C.
// Evidence: callees are rowed vector<void*>::erase 0x001FF51F and
// list<int>::erase 0x00438539; caller 0x0055ADBA passes its this as value;
// vector loop with cmp [eax] ebx erase-or-add-4 and list loop with cmp
// [eax+8] ebx struct-return erase reusing param slot; Rva honest-address name
// since caller class is UNCLAIMED.
#include <vector>
#include <list>

class Rva004EC276
{
public:
	void rva004EC276(void *value);
	char m_pad[0x130];
	_STL::vector<void *, _STL::allocator<void *> > m_vec;
	_STL::list<int, _STL::allocator<int> > m_list;
};

void Rva004EC276::rva004EC276(void *value)
{
	_STL::vector<void *>::iterator it = m_vec.begin();
	while (it != m_vec.end()) {
		if (*it == value)
			it = m_vec.erase(it);
		else
			++it;
	}
	_STL::list<int>::iterator jt = m_list.begin();
	while (jt != m_list.end()) {
		if (*jt == (int)value)
			jt = m_list.erase(jt);
		else
			++jt;
	}
}
