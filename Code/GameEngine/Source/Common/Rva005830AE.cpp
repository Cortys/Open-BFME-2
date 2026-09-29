// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva005830AE@Rva005830AE@@QAEXH@Z @0x005830AE 115B
// Free-standing progress tooltip updater: null-checked slot 0x40 on 0x9FEA28,
// empty-string Mouse tooltip via 0x37050/0x1EEA6D, then slots 0x5C 0x28 0x28 0x28 0x30.
// Evidence: callers 0x0044C629 0x0044C828 pass ecx+1 stack arg ret4; empty at 0xA0C898.

template<class T> class StringBase {
	void *m_data;
	void releaseBuffer();
public:
	StringBase(const StringBase &);
	void set(const StringBase &);
protected:
	__forceinline ~StringBase() { releaseBuffer(); }
};

class UnicodeString : private StringBase<unsigned short> {
public:
	__forceinline UnicodeString(const UnicodeString &o) : StringBase<unsigned short>(o) {}
	void set(const UnicodeString &o) { StringBase<unsigned short>::set(o); }
	__forceinline ~UnicodeString() {}
	static UnicodeString TheEmptyString;
};

struct RGBColor { float red, green, blue; };

class Mouse {
public:
	void rva001EEA6D(UnicodeString tooltip, int delay, const RGBColor *color, float width);
};

class Dummy24 {
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16(int x);
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
};

extern Dummy24 *g_Va009FEA28;
extern Mouse *g_Va009FDCA0;
extern Dummy24 *g_Va009FE710;
extern Dummy24 *g_Va009FEF1C;
extern Dummy24 *g_Va009FE4CC;
extern Dummy24 *g_Va009FE9D8;

class Rva005830AE {
public:
	void rva005830AE(int x);
};

void Rva005830AE::rva005830AE(int x)
{
	(void)x;
	if (g_Va009FEA28 != 0)
		g_Va009FEA28->v16(0);
	g_Va009FDCA0->rva001EEA6D(UnicodeString::TheEmptyString, -1, 0, 1.0f);
	g_Va009FE710->v23();
	g_Va009FEF1C->v10();
	g_Va009FE4CC->v10();
	g_Va009FE9D8->v10();
	g_Va009FE9D8->v12();
}
