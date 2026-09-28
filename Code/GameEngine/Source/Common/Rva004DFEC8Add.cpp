// ?rva004DFEC8@Rva004DFEC8@@QAEXPBVModuleData@@@Z @ 0x004DFEC8 (16B): vector
// push_back wrapper (lea eax,[esp+4] / push eax / add ecx,0x2C / call
// push_back<vector<ModuleData*>> at 0x004DFCB0 / ret 4). Callers at 0x0059760B
// 0x00598F38; prev 0x004DFCB0 is the rowed push_back and next 0x004DFED8 is
// the rowed dtor. Identity unrecovered: opaque address-derived holder.
// No // cl: line (defaults match the frameless 16-byte shape like 0x0039C7A5 19B).
class ModuleData;
namespace _STL
{
template <class T> class allocator
{
};
template <class T, typename A = allocator<T> > class vector
{
public:
	void push_back(const T &value);
};
}
class Rva004DFEC8
{
public:
	void rva004DFEC8(const ModuleData *data);
private:
	char m_pad[0x2C];
	_STL::vector<const ModuleData *> m_vec;
};
void Rva004DFEC8::rva004DFEC8(const ModuleData *data)
{
	m_vec.push_back(data);
}
