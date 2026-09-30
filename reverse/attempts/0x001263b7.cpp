// ??0Rva00126350@@QAE@ABV0@@Z
// partial score=0.95 date=2026-09-30
// ??0Rva00126350@@QAE@ABV0@@Z
// partial score=0.95 date=2026-09-30
// cl: /Os /arch:SSE /Ireference/shims/bfmecamera /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHs /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main
// ??0Rva00126350@@QAE@ABV0@@Z @0x001263B7 104B
// Copy ctor via defaults then rowed assign call.
// Evidence: callee 0x00126350 row assign; caller 0x00168587 copy ctor at +0xE4; globals 0x009B624C preset 0x007BB8D8 1.0f; prev LineSegment same includes with EHs for state store.
class TextureClass;
template <class T> class RefCountPtr
{
public:
	RefCountPtr() : m_ptr(0) {}
	~RefCountPtr();
	const RefCountPtr<T> &operator=(const RefCountPtr<T> &other);
private:
	T *m_ptr;
};
extern int g_009B624C;
class Rva00126350
{
public:
	Rva00126350(const Rva00126350 &other);
	Rva00126350 &operator=(const Rva00126350 &other);
private:
	RefCountPtr<TextureClass> m_tex;
	int m_4;
	float m_8;
	float m_c;
	float m_10;
	float m_14;
	float m_18;
	float m_1c;
	unsigned char m_20;
};
// ??0Rva00126350@@QAE@ABV0@@Z present-unmatched
Rva00126350::Rva00126350(const Rva00126350 &other)
	: m_tex()
	, m_4(g_009B624C)
	, m_8(0.0f)
	, m_c(1.0f)
	, m_10(1.0f)
	, m_14(1.0f)
	, m_18(1.0f)
	, m_1c(1.0f)
	, m_20(0)
{
	*this = other;
}
