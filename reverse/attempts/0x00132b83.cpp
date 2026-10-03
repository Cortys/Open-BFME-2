// ?Get_Texture_Memory_Usage@?$RefCountPtr@VTextureClass@@@@QBEIXZ
// partial score=0.97 date=2026-10-03
// ?Get_Texture_Memory_Usage@?$RefCountPtr@VTextureClass@@@@QBEIXZ
// partial score=0.97 date=2026-10-03
// cl: /O1 /MD /G7
// Corrected symbol shape: the banked prior stash declared a concrete `Holder`,
// which does not emit the pinned template symbol at all. This body defines the
// real ?$RefCountPtr@VTextureClass@@ member and emits it at 80/79 bytes.
// Remaining: retail keeps `tex` in esi, loads surface into edi, then copies
// esi=edi before the call; ours uses edi for tex and reloads [edi+0x14] for the
// mip check (3B vs retail's 2B copy) plus the tex-register swap. Single-local
// forms coalesce to 75B; two independent loads give the reload at 80B.
enum WW3DFormat { WW3D_FORMAT_UNKNOWN = 0 };
unsigned __fastcall Get_Bits_Per_Pixel(WW3DFormat format);
struct TextureSurfaceInfo {
	int m_pad00[3];
	int m_type0C;
	int m_pad10[6];
	int m_dim28;
	int m_dim2C;
	int m_dim30;
	int m_pad34[4];
	int m_mip44;
	int m_pad48;
	int m_format4C;
};
class TextureBaseClass { public: void Add_Ref(); void Release_Ref(); };
class TextureClass : public TextureBaseClass {
public:
	virtual ~TextureClass();
	virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
	virtual void v09(); virtual bool Is_Initialized();
	char m_pad04[16];
	TextureSurfaceInfo *m_surface;
};
template<class T>
class RefCountPtr {
public:
	T *Referent;
	unsigned Get_Texture_Memory_Usage() const;
};
template<class T>
unsigned RefCountPtr<T>::Get_Texture_Memory_Usage() const
{
	T *tex = Referent;
	if (tex == 0)
		return 0;
	if (!tex->Is_Initialized())
		return 0;
	TextureSurfaceInfo *a = tex->m_surface;
	unsigned mem = Get_Bits_Per_Pixel((WW3DFormat)a->m_format4C)
		* a->m_dim30 * a->m_dim2C * a->m_dim28 >> 3;
	TextureSurfaceInfo *b = tex->m_surface;
	if (b->m_type0C == 2)
		mem *= 6;
	if (b->m_mip44 != 1)
		mem = mem * 4 / 3;
	return mem;
}
template class RefCountPtr<TextureClass>;
