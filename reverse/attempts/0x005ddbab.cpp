// ?rva005DDBAB@Rva005DDBAB@@QAEXPAVGameWindow@@PAPAH@Z
// partial score=0.93 date=2026-09-30
// ?rva005DDBAB@Rva005DDBAB@@QAEXPAVGameWindow@@PAPAH@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /arch:SSE
// ??0Rva005DD772@@QAE@XZ @0x005DD772 81B.
// Default ctor of an 8-byte UnicodeString+float display record: base UnicodeString
// from narrow "-" at 0x83DD78 via AsciiString temp then float 0.0f at +4 via xmm.
// Callees all rowed: StringBase<char> 0x37BA0 plus UnicodeString(AsciiString)
// 0x6CB6D0 plus releaseBuffer 0x36410. Callers 0x5DD8E0/0x5DD9F9/0x5DDED5 all pass
// the same this as base init then format percent/time via set/format/concat.
// Non-virtual no vptr; returns this. Honest Rva ctor name; owner proven only as
// the shared base of those callers.
typedef unsigned short Wide;
class AsciiString;
class UnicodeString;
template<class T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    struct Header { int refs; unsigned short length,capacity; T data[1]; };
    Header *data;
    StringBase(const T*);
    StringBase(const StringBase&);
    void releaseBuffer();
public:
    StringBase():data(0){}
    ~StringBase(){ releaseBuffer(); }
};
class AsciiString:public StringBase<char> {
public:
    AsciiString(const char *s):StringBase<char>(s){}
};
class UnicodeString:public StringBase<Wide> {
public:
    UnicodeString(const AsciiString&);
    UnicodeString(){}
    UnicodeString(const UnicodeString& o):StringBase<Wide>(o){}
    UnicodeString(const Wide *s):StringBase<Wide>(s){}
    ~UnicodeString(){}
    void __cdecl format(const UnicodeString* fmt, ...);
    void __cdecl format(const Wide* fmt, ...);
};
class Rva005DD772 : public UnicodeString {
public:
    float m04;
    Rva005DD772();
    Rva005DD772(const UnicodeString &str, float v);
};
Rva005DD772::Rva005DD772() : UnicodeString(AsciiString("-")), m04(0.0f) {}
// ??0Rva005DD772@@QAE@ABVUnicodeString@@M@Z @0x005DD86D 29B unlock lane:
// (UnicodeString,float) copy ctor: StringBase Wide copy 0x00037050 for the
// base at +0 then float to +4 via xmm; frameless ret 8 returning this.
// Same 8B layout and callees as the default ctor above; callers in the big
// parsers 0x005BEA70/0x005C1BDE.
Rva005DD772::Rva005DD772(const UnicodeString &str, float v) : UnicodeString(str), m04(v) {}
class GameTextInterface {
public:
    virtual ~GameTextInterface(){}
    virtual void slot00()=0; virtual void slot01()=0; virtual void slot02()=0; virtual void slot03()=0;
    virtual void slot04()=0; virtual void slot05()=0; virtual void slot06()=0; virtual void slot07()=0;
    virtual void slot08()=0; virtual void slot09()=0; virtual void slot10()=0; virtual void slot11()=0;
    virtual void slot12()=0; virtual void slot13()=0; virtual void slot14()=0; virtual void slot15()=0;
    virtual const UnicodeString& slot44(const char* label, bool* exists=0)=0;
};
extern GameTextInterface* TheGameText;
// ??0Rva005DD9F9@@QAE@M@Z @0x005DD9F9 94B chain of base 0x5DD772.
// Float ctor overwrites base m04 then rounds v+0.5f via 0x7C26F0 to int for
// TheGameText slot44 GUI:WinPercent fetch returning const UnicodeString&
// then UnicodeString format 0x6CB660. Same 8B layout no vptr returns this.
class Rva005DD9F9 : public Rva005DD772 {
public:
    Rva005DD9F9(float v);
};
Rva005DD9F9::Rva005DD9F9(float v) : Rva005DD772() {
    m04 = v;
    int i = (int)(v + 0.5f);
    ((UnicodeString*)this)->format(&TheGameText->slot44("GUI:WinPercent"), i);
}

// ??0Rva005DD822@@QAE@I@Z @ 0x005DD822 75B
// Unsigned-int ctor of 8-byte UnicodeString+float display record (Rva005DD772 layout).
// Base default inlines to and [esi],0; m04 via fild plus 2^32 adjust at 0x7C26EC;
// base formatted via rowed UnicodeString::format 0x6CB5D0 with static wide fmt at 0x7C9260.
// Callers 40+ in big parsers 0x5B8116/0x5DE100/0x5BEA70/0x5C1BDE pass int; neighbours share /O1 /EHsc.
extern const Wide g_007C9260[];
class Rva005DD822 : public UnicodeString {
public:
    float m04;
    Rva005DD822(unsigned int v);
};
Rva005DD822::Rva005DD822(unsigned int v) {
    m04 = (float)v;
    ((UnicodeString*)this)->format(g_007C9260, v);
}

// ?rva005DD88A@Rva005DD88A@@QAEHPAVGameWindow@@HHM@Z, retail 0x005DD88A, 86 bytes.
// Same 8B UnicodeString+float record (m04 at +4). Color is (m04==f) green
// 0xFF64FF64 else white -1 via ucomiss+lahf+test+jp. Then rowed
// GadgetListBoxAddEntryText with *this base plus (color a b true) returning
// idx in esi, then rowed Rva0032434ASet(win idx b 2). Caller 0x005DDC2D.
// Unblocks 0x005DDBAB.

class GameWindow;

int GadgetListBoxAddEntryText(GameWindow *win, UnicodeString txt, int c, int a, int b, bool flag);
void Rva0032434ASet(GameWindow *win, int x, int y, int z);

class Rva005DD88A : public UnicodeString
{
public:
	float m04;
	int rva005DD88A(GameWindow *win, int a, int b, float f);
};

int Rva005DD88A::rva005DD88A(GameWindow *win, int a, int b, float f)
{
	int color = (m04 == f) ? 0xFF64FF64 : -1;
	int idx = GadgetListBoxAddEntryText(win, *(UnicodeString *)this, color, a, b, true);
	Rva0032434ASet(win, idx, b, 2);
	return idx;
}

// ?rva005DDBAB@Rva005DDBAB@@QAEXPAVGameWindow@@PAPAH@Z, retail 0x005DDBAB, 192 bytes.
// Holder with UnicodeString base + Rva005DD88A array [ +4 begin +8 end ] +
// float +0x10 + bool +0x14. Once-flag g_00E0668C/g_00E06688, early-out on
// +0x14==0, first Gadget entry from *this, loop over int vector (begin/end at
// [vec+0]/[vec+4]) calling array element rva005DD88A, final Gadget entry from
// wide g_00BC26DC. Callers 0x005DDDF9 0x005DE06E. Unblocks 0x005DE059.

extern int g_00E06688;
extern int g_00E0668C;
extern const Wide g_00BC26DC[];

class Rva005DDBAB : public UnicodeString
{
public:
	Rva005DD88A *m04_begin; // +0x04
	Rva005DD88A *m08_end; // +0x08
	char m0C[4]; // +0x0C
	float m10; // +0x10
	unsigned char m14; // +0x14
	void rva005DDBAB(GameWindow *win, int **vec);
};

// ?rva005DDBAB@Rva005DDBAB@@QAEXPAVGameWindow@@PAPAH@Z present-unmatched
void Rva005DDBAB::rva005DDBAB(GameWindow *win, int **vec)
{
	if ((g_00E0668C & 1) == 0)
	{
		g_00E0668C |= 1;
		g_00E06688 |= -1;
	}
	if (m14 == 0)
		return;
	unsigned int loopIdx = 1;
	unsigned int idx1 = (unsigned int)GadgetListBoxAddEntryText(win, *(UnicodeString *)this, g_00E06688, -1, 0, true);
	int **vecLocal = vec;
	unsigned int *curPtr = (unsigned int *)vecLocal[0];
	while (curPtr != (unsigned int *)vecLocal[1])
	{
		unsigned int cur = *curPtr;
		unsigned int count = (unsigned int)(m08_end - m04_begin);
		if (cur < count)
		{
			Rva005DD88A *elem = *(Rva005DD88A **)((char *)this + 4) + cur;
			elem->rva005DD88A(win, (int)idx1, (int)loopIdx, m10);
		}
		++loopIdx;
		++curPtr;
	}
	GadgetListBoxAddEntryText(win, UnicodeString(g_00BC26DC), g_00E06688, -1, 0, true);
}
