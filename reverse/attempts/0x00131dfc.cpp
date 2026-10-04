// ?rva00131DFC@Rva00131DFC@@QAEXPAX000HH@Z
// partial score=0.93 date=2026-10-04
// cl: /O1 /MD /EHsc
// ?rva00131DFC@Rva00131DFC@@QAEXPAX000HH@Z @ 0x00131DFC (86B) linkbody: new 0x3c via rowed ??2 plus bfmeBaseInitZQ pin plus Set_Texture row. Evidence: forwards 6 stack args to pin 0x00131B57 then adopts via row 0x000EF87B; caller 0x00132F30 passes 6 pushes plus this global 0x009F297C; same new-adopt shape as BfmeMapPictureTexture ctor.
typedef unsigned int size_t;
void *__cdecl operator new(size_t bytes);

typedef int Int;

class TextureClass
{
public:
	Int m_unk00;
	unsigned short m_numRefs;
	unsigned short m_flags;
	char m_padTail[0x3C - 8];
};

class BfmeOwnerZQ
{
public:
	void bfmeBaseInitZQ(void *first, void *second, void *third, void *fourth, int fifth, int sixth);
// ??0BfmeOwnerZQ@@QAE@PAX000HH@Z present-unmatched
	BfmeOwnerZQ(void *a, void *b, void *c, void *d, int e, int f)
	{
		bfmeBaseInitZQ(a, b, c, d, e, f);
	}
private:
	char m_pad[0x3C];
};

class BfmeMapPictureTexture
{
public:
	void Set_Texture(TextureClass *texture);
};

class Rva00131DFC
{
public:
	void rva00131DFC(void *a, void *b, void *c, void *d, int e, int f);
};

// ?rva00131DFC@Rva00131DFC@@QAEXPAX000HH@Z present-unmatched
void Rva00131DFC::rva00131DFC(void *a, void *b, void *c, void *d, int e, int f)
{
	((BfmeMapPictureTexture *)this)->Set_Texture((TextureClass *)new BfmeOwnerZQ(a, b, c, d, e, f));
}
