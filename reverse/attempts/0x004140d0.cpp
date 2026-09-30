// ?Rva004140D0Construct@@YAXPAXABVRva00414093@@@Z
// partial score=0.93 date=2026-09-30
// ?Rva004140D0Construct@@YAXPAVINI@@HPAU?$_Rb_tree@W4NameKeyType@@U?$pair@$$CBW4NameKeyType@@VModuleTemplate@ModuleFactory@@@_STL@@U?$_Select1st@U?$pair@$$CBW4NameKeyType@@VModuleTemplate@ModuleFactory@@@_STL@@@3@U?$less@W4NameKeyType@@@3@V?$allocator@U?$pair@$$CBW4NameKeyType@@VModuleTemplate@ModuleFactory@@@_STL@@@3@@_STL@@@Z
// partial score=0.93 date=2026-09-30
// ?Rva004140D0Construct@@YAXPAXABVRva00414093@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
//
// ?Rva004140D0Construct@@YAXPAXABVRva00414093@@@Z, retail 0x004140D0, 45 bytes.
// Dedicated TU.
//
// Honest placement-construct wrapper for the just-landed Rva00414093 copy
// ctor 0x00414093: null-checks dst then copy-constructs. Evidence: chain
// lane calls only 0x00414093; test ecx je skips the call; push src then
// call with ecx dst; EH_prolog with handler 0x00785FE7 plus fs restore.
#include <new>
#include <vector>
#include <map>
enum NameKeyType { NAMEKEY_0 = 0 };
class ModuleFactory { public: class ModuleTemplate { public: void *m_createProc; void *m_createDataProc; int m_whichInterfaces; }; };
typedef _STL::pair<const NameKeyType, ModuleFactory::ModuleTemplate> ModuleFactoryMapValue140D0;
typedef _STL::_Rb_tree<NameKeyType, ModuleFactoryMapValue140D0, _STL::_Select1st<ModuleFactoryMapValue140D0>, _STL::less<NameKeyType>, _STL::allocator<ModuleFactoryMapValue140D0> > ModuleFactoryMapTree140D0;
class Rva00414093
{
public:
	Rva00414093(const Rva00414093 &src);
};
void __cdecl Rva004140D0Construct(void *dst, const Rva00414093 &src);
// ?Rva004140D0Construct@@YAXPAXABVRva00414093@@@Z present-unmatched
void __cdecl Rva004140D0Construct(void *dst, const Rva00414093 &src)
{
	if (dst)
		new (dst) Rva00414093(src);
}
