// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ?Rva00422D1CGet@@YGHH@Z retail 0x00422D1C 34B.
// Global map<int,int> lookup: find key via rowed _M_find 0x00388F63,
// return mapped value at node+0x14 or -1 when iterator equals end.
// Evidence: retail lea eax [esp+4] push eax mov ecx <global> call _M_find,
// cmp eax [global] je or -1 else mov eax [eax+0x14] ret 4; caller 0x0037FAC6.
#include <map>

#define GlobalMap00422D1C (*(_STL::map<int, int> *)0x00E0319C)

int __stdcall Rva00422D1CGet(int key)
{
	_STL::map<int, int>::iterator it = GlobalMap00422D1C.find(key);
	if (it != GlobalMap00422D1C.end())
		return (*it).second;
	return -1;
}
