// cl: /O1 /G7 /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// ?rva00293330@Rva00293330@@QAEPAXI@Z, retail 0x00293330, 63 bytes.
// Map lookup at this+0x268 via rowed _M_find 0x00357180: found returns
// second at node+0x14 else if key==0 and size at +0x26c>0 returns begin
// second else null. Evidence: callers at 0x002A247C 0x00392FD3 0x00393252
// 0x00393858 0x00393942; jbe plus leftmost shape; unblocks 0x00392DC0.
#include <map>

class Rva00293330
{
public:
	void *rva00293330(unsigned int key);

private:
	char m_pad[0x268];
	_STL::map<unsigned int, void *> m_map;
};

void *Rva00293330::rva00293330(unsigned int key)
{
	_STL::map<unsigned int, void *>::iterator it = m_map.find(key);
	if (it != m_map.end())
		return it->second;
	if (key != 0)
		return 0;
	if (m_map.size() <= 0)
		return 0;
	it = m_map.begin();
	if (it != m_map.end())
		return it->second;
	return 0;
}
