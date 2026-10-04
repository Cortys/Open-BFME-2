// ?rva0014DA92@Rva0014F699@@QAEXPBXV?$RefCountPtr@VTextureClass@@@@@Z
// partial score=0.94 date=2026-10-04
// cl: /O1
// ?rva0014DA92@Rva0014F699@@QAEXPBXV?$RefCountPtr@VTextureClass@@@@@Z @0x0014DA92 154B: setter copying 16 dwords to +8..+44 and RefCountPtr to +0x48 with param release. Evidence: same 0x4C element as Rva0014F699Assign with rowed RefCountPtr assign 0x000424D0 and Release_Ref 0x0061ED10; caller at 0x0014F7C2; ret 8 with two args.
class TextureClass
{
public:
	void Add_Ref();
	void Release_Ref();
};

template<class T>
class RefCountPtr
{
public:
	RefCountPtr(const RefCountPtr &other);
	~RefCountPtr() { if (Referent) Referent->Release_Ref(); }
	RefCountPtr const &operator=(RefCountPtr const &other);
private:
	T *Referent;
};

class Rva0014F699
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	int m_28;
	int m_2c;
	int m_30;
	int m_34;
	int m_38;
	int m_3c;
	int m_40;
	int m_44;
	RefCountPtr<TextureClass> m_48;
public:
	void rva0014DA92(const void *src, RefCountPtr<TextureClass> tex);
};

// ?rva0014DA92@Rva0014F699@@QAEXPBXV?$RefCountPtr@VTextureClass@@@@@Z present-unmatched
void Rva0014F699::rva0014DA92(const void *src, RefCountPtr<TextureClass> tex)
{
	const int *s = (const int *)src;
	m_08 = s[0];
	m_0c = s[1];
	m_10 = s[2];
	m_14 = s[3];
	m_18 = s[4];
	m_1c = s[5];
	m_20 = s[6];
	m_24 = s[7];
	m_28 = s[8];
	m_2c = s[9];
	m_30 = s[10];
	m_34 = s[11];
	m_38 = s[12];
	m_3c = s[13];
	m_40 = s[14];
	m_44 = s[15];
	RefCountPtr<TextureClass> &dst = m_48;
	dst = tex;
}
