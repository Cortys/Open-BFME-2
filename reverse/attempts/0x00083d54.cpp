// ?rva00083D54@Rva00083D54@@QAEXXZ
// partial score=0.88 date=2026-09-29
// ?rva00083D54@Rva00083D54@@QAEXXZ
// partial score=0.88 date=2026-09-29
// cl: /O1 /G7 /Ireference/shims/bfmeterraintracks /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
typedef int Int;
typedef unsigned int Uint;
typedef unsigned short UShort;
void *__cdecl operator new(Uint s);
void __cdecl operator delete(void *p);
class RefCountClass
{
public:
	virtual void Delete_This() {}
	void Release_Ref()
	{
		if (--m_refs == 0)
			Delete_This();
	}
	int m_refs;
};
#define REF_PTR_RELEASE(x) { if (x) { (x)->Release_Ref(); x = 0; } }
class BFMEDX8DeviceLock
{
public:
	BFMEDX8DeviceLock();
	~BFMEDX8DeviceLock();
};
class IndexBufferClass
{
public:
	class WriteLockClass
	{
	public:
		WriteLockClass(IndexBufferClass *b, int flags);
		~WriteLockClass();
		UShort *Get_Index_Array() { return m_indices; }
	private:
		IndexBufferClass *m_buf;
		UShort *m_indices;
		BFMEDX8DeviceLock m_lock;
	};
};
class DX8IndexBufferClass : public RefCountClass
{
public:
	enum UsageType { USAGE_DEFAULT = 0 };
	DX8IndexBufferClass(Uint count, UsageType u);
private:
	char _t[0x10];
};
class BfmeDynamicNativeVB : public RefCountClass
{
public:
	BfmeDynamicNativeVB(Uint a, UShort b, Uint c, Uint d);
private:
	char _t[0x18];
};
struct TestGlobal
{
	char _pad[0x10C];
	Int m_10C;
};
#define TheTestGlobal (*(TestGlobal **)0x00DFE758)
class Rva00083D54
{
public:
	void rva00083D54();
private:
	RefCountClass *m_0;
	RefCountClass *m_4;
	char _pad08[0x14];
	Int m_1C;
};
// ?rva00083D54@Rva00083D54@@QAEXXZ present-unmatched
void Rva00083D54::rva00083D54()
{
	Int save10C = TheTestGlobal->m_10C;
	REF_PTR_RELEASE(m_4);
	REF_PTR_RELEASE(m_0);
	DX8IndexBufferClass *ib = new DX8IndexBufferClass((m_1C - 1) * 6, DX8IndexBufferClass::USAGE_DEFAULT);
	m_4 = ib;
	{
		IndexBufferClass::WriteLockClass lock((IndexBufferClass *)ib, 0);
		UShort *dst = lock.Get_Index_Array();
		int n = m_1C - 1;
		for (int i = 0; i < n; i++)
		{
			int v = i * 2;
			dst[0] = (UShort)v;
			dst[3] = (UShort)v;
			dst[1] = (UShort)(v + 1);
			dst[5] = (UShort)(v + 2);
			dst[2] = (UShort)(v + 3);
			dst[4] = (UShort)(v + 3);
			dst += 6;
		}
	}
	BfmeDynamicNativeVB *vb = new BfmeDynamicNativeVB(0x142, (UShort)((UShort)m_1C * (UShort)save10C * 2), 1, 0);
	m_0 = vb;
}
