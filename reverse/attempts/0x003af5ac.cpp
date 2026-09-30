// ??0Rva003AF5AC@@QAE@ABV0@@Z
// partial score=0.93 date=2026-09-30
// ??0Rva003AF5AC@@QAE@ABV0@@Z
// partial score=0.93 date=2026-09-30
// cl: /DNDEBUG /MD /GX- /O1 /Ob2 /G7
// ??0Rva003AF5AC@@QAE@ABV0@@Z @0x003AF5AC 98B: particle module-template copy ctor with LineEmissionVolumeInfo member at +0x1c via rowed base 0x003AF50D plus null-preserving sub pointer and dual vtable pairs. Evidence: caller 0x003AF57F plus rowed callees 0x003AF50D 0x003A653B plus vtables DIR32. Neighbours 0x003AF50D 0x003AF929.
class Rva003AF50D
{
public:
	Rva003AF50D(const Rva003AF50D &other);
};

namespace FXParticleSystem
{
class LineEmissionVolumeInfo
{
public:
	LineEmissionVolumeInfo(const LineEmissionVolumeInfo &other);
};
}

extern "C" char Rva003AF5AC_v18first;
extern "C" char Rva003AF5AC_v0a;
extern "C" char Rva003AF5AC_v14a;
extern "C" char Rva003AF5AC_v18a;
extern "C" char Rva003AF5AC_vsub;
extern "C" char Rva003AF5AC_v0b;
extern "C" char Rva003AF5AC_v14b;
extern "C" char Rva003AF5AC_v18b;

class Rva003AF5AC
{
public:
	__declspec(noinline) Rva003AF5AC(const Rva003AF5AC &other);

private:
	void *m_v0; // +0x00
	char m_pad04[16]; // +0x04
	void *m_v14; // +0x14
	void *m_v18; // +0x18
};

// ??0Rva003AF5AC@@QAE@ABV0@@Z present-unmatched
Rva003AF5AC::Rva003AF5AC(const Rva003AF5AC &that)
{
	const void *src = &that;
	((Rva003AF50D *)this)->Rva003AF50D::Rva003AF50D(*(const Rva003AF50D *)src);
	const void *sub_src = src ? (const char *)src + 0x1c : 0;
	*(void * volatile *)((char *)this + 0x18) = (void *)&Rva003AF5AC_v18first;
	FXParticleSystem::LineEmissionVolumeInfo *sub =
		(FXParticleSystem::LineEmissionVolumeInfo *)((char *)this + 0x1c);
	*(void **)this = &Rva003AF5AC_v0a;
	*(void **)((char *)this + 0x14) = &Rva003AF5AC_v14a;
	*(void **)((char *)this + 0x18) = &Rva003AF5AC_v18a;
	sub->LineEmissionVolumeInfo::LineEmissionVolumeInfo(
		*(const FXParticleSystem::LineEmissionVolumeInfo *)sub_src);
	*(void **)sub = &Rva003AF5AC_vsub;
	*(void **)this = &Rva003AF5AC_v0b;
	*(void **)((char *)this + 0x14) = &Rva003AF5AC_v14b;
	*(void **)((char *)this + 0x18) = &Rva003AF5AC_v18b;
}
