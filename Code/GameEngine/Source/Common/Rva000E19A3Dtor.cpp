// cl: /O1 /MD /EHsc
// ??1Rva000E19A3@@UAE@XZ, RVA 0x000E19A3, 122B. Virtual dtor: explicit m_04
// init plus global clear plus Erase("Terrain"), then implicit member teardown
// in reverse (RefCountPtr textures at +0x24/+0x20 via rowed Release_Ref, then
// five S members at +0x18..+0x08 resetting to base vtable, then own vptr to
// base). Evidence: deleting dtor at 0x000E1A1D calls it; rowed callees
// 0x001532E1 (erase) and 0x0061ED10 (Release_Ref); string "Terrain".

extern const void *const g_00BCE50C[];
extern int g_00DEBC60;

void __cdecl Rva001532E1Erase(const char *name);

class TextureBaseClass
{
public:
	void Release_Ref();
};

class Base
{
public:
	virtual ~Base() {}
};

struct S : public Base
{
	~S() {}
};

template<class T>
class RefCountPtr
{
public:
	~RefCountPtr()
	{
		if (ptr)
			ptr->Release_Ref();
	}
	T *ptr;
};

class Rva000E19A3 : public Base
{
public:
	virtual ~Rva000E19A3();
private:
	void *m_04;
	S m_08;
	S m_0C;
	S m_10;
	S m_14;
	S m_18;
	int m_1C;
	RefCountPtr<TextureBaseClass> m_20;
	RefCountPtr<TextureBaseClass> m_24;
};

Rva000E19A3::~Rva000E19A3()
{
	m_04 = (void *)g_00BCE50C;
	g_00DEBC60 = 0;
	Rva001532E1Erase("Terrain");
}
