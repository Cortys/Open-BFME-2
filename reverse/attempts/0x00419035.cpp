// ??0Rva00419035@@QAE@ABU0@@Z
// partial score=0.93 date=2026-09-30
// ??0Rva00419035@@QAE@ABU0@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva00419035@@QAE@ABU0@@Z, retail 0x00419035 165B. Chain lane: calls the
// just-landed HH _M_copy at 0x00418E05, the rowed HPAX _Rb_tree_base ctor at
// 0x001F0534, and the folded get_allocator at 0x0021983A. Same 165B shape as
// 0x004186F2 sibling but calling the 0x00418E05 copy; honest-address copy
// ctor since the HH/HPAX template names are already claimed. Callers at
// 0x00419149 0x0041920B.
#define private public
#define protected public
#define _M_copy _M_copy_00418E05
#include <map>
#undef _M_copy
#undef protected
#undef private
typedef _STL::_Rb_tree<int, _STL::pair<const int, int>, _STL::_Select1st<_STL::pair<const int, int> >, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > HHTree00419035;
typedef _STL::_Rb_tree_base<_STL::pair<const int, void *>, _STL::allocator<_STL::pair<const int, void *> > > HPAXBase00419035;
struct Rva00419035 : public HPAXBase00419035 {
	int _M_node_count;
	_STL::less<int> _M_key_compare;
	Rva00419035(const Rva00419035 &__x);
};
// ??0Rva00419035@@QAE@ABU0@@Z present-unmatched
Rva00419035::Rva00419035(const Rva00419035 &__x)
	: HPAXBase00419035(__x.get_allocator()), _M_node_count(0), _M_key_compare(__x._M_key_compare)
{
	if (__x._M_header._M_data->_M_parent == 0) {
		_M_header._M_data->_M_color = false;
		_M_header._M_data->_M_parent = 0;
		_M_header._M_data->_M_left = _M_header._M_data;
		_M_header._M_data->_M_right = _M_header._M_data;
	} else {
		_M_header._M_data->_M_color = false;
		_M_header._M_data->_M_parent = ((HHTree00419035 *)this)->_M_copy_00418E05((HHTree00419035::_Link_type)__x._M_header._M_data->_M_parent, (HHTree00419035::_Link_type)_M_header._M_data);
		HHTree00419035::_Link_type r = (HHTree00419035::_Link_type)_M_header._M_data->_M_parent;
		while (r->_M_left != 0)
			r = (HHTree00419035::_Link_type)r->_M_left;
		_M_header._M_data->_M_left = r;
		r = (HHTree00419035::_Link_type)_M_header._M_data->_M_parent;
		while (r->_M_right != 0)
			r = (HHTree00419035::_Link_type)r->_M_right;
		_M_header._M_data->_M_right = r;
	}
	_M_node_count = __x._M_node_count;
}
