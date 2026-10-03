// ?rva000DDAB7@W3DBridge@@QAEXPAVVirtualArg@@@Z
// partial score=0.99 date=2026-10-03
// ?rva000DDAB7@W3DBridge@@QAEXPAVVirtualArg@@@Z
// partial score=0.99 date=2026-10-03
// ?rva000DDAB7@W3DBridge@@QAEXPAVVirtualArg@@@Z
// partial score=0.99 date=2026-10-03
// ?rva000DDAB7@W3DBridge@@QAEXPAVVirtualArg@@@Z
// partial score=0.97 date=2026-10-03
// cl: /Os /Oy- /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
// ?rva000DDAB7@W3DBridge@@QAEXPAUVirtualArg@@@Z 0x000DDAB7 96B W3DBridge method after dtor; flag +0x104 gates Draw_Triangles with texture hold via AssetReference copy and two virtual calls; evidence: contiguous with ??1W3DBridge, Draw_Triangles row 0x00120620, AssetReference copy row 0x000424BB, callers at 0x000DF982/0x000DFA6B in 0x000DF776
class CountedAsset
{
public:
	void Release_Ref();
};

class AssetReference
{
public:
	AssetReference(const AssetReference &that);
	~AssetReference();
private:
	CountedAsset *m_object;
};

class VirtualArg
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4(int x);
};

class BridgeManager
{
public:
	virtual void v0();
	virtual void v1(AssetReference a);
};

extern BridgeManager *volatile g_00DEBC60;

class DX8Wrapper
{
public:
	static void __cdecl Draw_Triangles(unsigned start_index, unsigned polygon_count, unsigned min_vertex_index, unsigned vertex_count);
};

class W3DBridge
{
public:
	void rva000DDAB7(VirtualArg *arg);
private:
	unsigned char m_pad0[0x34];
	AssetReference m_tex;
	unsigned char m_pad1[0xF4 - 0x38];
	unsigned int m_f4;
	unsigned int m_f8;
	unsigned int m_fc;
	unsigned int m_100;
	unsigned char m_104;
};

// ?rva000DDAB7@W3DBridge@@QAEXPAVVirtualArg@@@Z present-unmatched
void W3DBridge::rva000DDAB7(VirtualArg *arg)
{
	if (m_104 == 0)
		return;
	if (arg != 0) {
		g_00DEBC60->v1(m_tex);
		arg->v4(2);
	}
	DX8Wrapper::Draw_Triangles(m_f4, m_100, m_fc, m_f8);
}
