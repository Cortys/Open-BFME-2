// ?Rva003BB700@@YGX_N@Z
// partial score=0.95 date=2026-09-29
// ?Rva003BB700@@YGX_N@Z
// partial score=0.95 date=2026-09-29
// cl: /O1
//
// ?Rva003BAAD6@@YAXXZ @0x003BAAD6 14B: free forwarder to virtual slot 0x1A0 via global 0xDFEA3C.
// Evidence: mov ecx,[0xDFEA3C] mov eax,[ecx] jmp [eax+0x1A0]; callers 0x3CAD41 0x3CC8DF in ScriptActions dispatch with mov ecx,edi no pushes.

template <class T> class StringBase;
struct Rva0033070EEntry;
class Rva0033070E
{
public:
	Rva0033070EEntry *rva0033070E(const StringBase<char> &key);
};

#define Rva00E01DB0 (*(Rva0033070E **)0x00E01DB0)

class Rva003BAAD6Holder
{
public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026(struct Rva0033070EEntry *e);
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037(bool v);
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
    virtual void s052();
    virtual void s053();
    virtual void s054();
    virtual void s055();
    virtual void s056();
    virtual void s057();
    virtual void s058();
    virtual void s059();
    virtual void s060();
    virtual void s061();
    virtual void s062();
    virtual void s063();
    virtual void s064();
    virtual void s065();
    virtual void s066();
    virtual void s067();
    virtual void s068();
    virtual void s069();
    virtual void s070();
    virtual void s071();
    virtual void s072();
    virtual void s073();
    virtual void s074();
    virtual void s075();
    virtual void s076();
    virtual void s077();
    virtual void s078();
    virtual void s079();
    virtual void s080();
    virtual void s081();
    virtual void s082();
    virtual void s083();
    virtual void s084();
    virtual void s085();
    virtual void s086();
    virtual void s087();
    virtual void s088();
    virtual void s089(int v);
    virtual void s090();
    virtual void s091();
    virtual void s092();
    virtual void s093();
    virtual void s094();
    virtual void s095();
    virtual void s096();
    virtual void s097();
    virtual void s098();
    virtual void s099();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void target();
};

#define Rva00DFEA3C (*(Rva003BAAD6Holder **)0x00DFEA3C)
#define Rva00DFEDF0 (*(Rva003BAAD6Holder **)0x00DFEDF0)
#define Rva00DFE6E8 (*(Rva003BAAD6Holder **)0x00DFE6E8)

void Rva003BAAD6()
{
    Rva00DFEA3C->target();
}

// ?Rva003BB141Notify@@YGXABV?$StringBase@D@@@Z @0x003BB141 34B chain via 0x0033070E caller 0x003CAE0D globals 0xE01DB0 0xDFEA3C slot 0x68
void __stdcall Rva003BB141Notify(const StringBase<char> &key)
{
	Rva0033070EEntry *e = Rva00E01DB0->rva0033070E(key);
	if (e)
		Rva00DFEA3C->s026(e);
}

// ?Rva003BB61E@@YAXXZ @0x003BB61E 14B free forwarder to virtual slot 0x15C via global 0xDFEDF0 caller 0x003CBBCE
void Rva003BB61E()
{
	Rva00DFEDF0->s087();
}

class RadarWindowOverrideSource
{
public:
	void rva002D3615(bool value);
};

#define Rva00DFF028 (*(RadarWindowOverrideSource **)0x00DFF028)

// ?Rva003BB7E2@@YAXXZ @0x003BB7E2 14B free caller of 0x002D3615 with false via global 0xDFF028 caller 0x003CBD39
void Rva003BB7E2()
{
	Rva00DFF028->rva002D3615(false);
}

// ?Rva003BB7F0@@YAXXZ @0x003BB7F0 14B free caller of 0x002D3615 with true via global 0xDFF028 caller 0x003CBD45
void Rva003BB7F0()
{
	Rva00DFF028->rva002D3615(true);
}

// ?Rva003BBF8F@@YAXXZ @0x003BBF8F 17B free caller of vslot 0x94 with false via global 0xDFEDF0 caller 0x003CC44C
void Rva003BBF8F()
{
	Rva00DFEDF0->s037(false);
}

// ?Rva003BBFA0@@YAXXZ @0x003BBFA0 17B free caller of vslot 0x94 with true via global 0xDFEDF0 caller 0x003CC458
void Rva003BBFA0()
{
	Rva00DFEDF0->s037(true);
}

// ?Rva003BB641@@YAXXZ @0x003BB641 19B null-guarded forwarder to vslot 0x16C via global 0xDFE6E8 caller 0x003CE42B
void Rva003BB641()
{
	Rva003BAAD6Holder *p = Rva00DFE6E8;
	if (p)
		p->s091();
}

// ?Rva003BB62C@@YGXH@Z @0x003BB62C 21B null-guarded forwarder to vslot 0x164 via global 0xDFE6E8 caller 0x003CE41F forwards stdcall int
void __stdcall Rva003BB62C(int v)
{
	Rva003BAAD6Holder *p = Rva00DFE6E8;
	if (p)
		p->s089(v);
}

// ?Rva003BB654@@YAXXZ @0x003BB654 19B null-guarded forwarder to vslot 0x17C via global 0xDFE6E8 caller 0x003CE477
void Rva003BB654()
{
	Rva003BAAD6Holder *p = Rva00DFE6E8;
	if (p)
		p->s095();
}

struct Rva003BB700Holder
{
	char m_pad[0x98];
	bool m_98;
};

#define Rva00DFE78C (*(Rva003BB700Holder **)0x00DFE78C)

// ?Rva003BB700@@YGX_N@Z @0x003BB700 19B byte setter at +0x98 via global 0xDFE78C caller 0x003CBC88
// ?Rva003BB700@@YGX_N@Z present-unmatched
void __stdcall Rva003BB700(bool v)
{
	Rva00DFE78C->m_98 = v;
}
