// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ??1BfmeStrVM0@@UAE@XZ, retail 0x0025D686, 111 bytes.
// Destructor of BfmeStrVM0: stores vtable 0x7F5DA0 then runs the field-reset
// helper rva0025D19E and the list-clear rva0025C0FF on the same this, then
// destroys AsciiString at +0xF0/+0xD0 and Unicode string at +0xB0 in reverse
// order, then the GameEngineDeletingBase base dtor.
// Evidence: same-this calls at 0x0025D6A4/0x0025D6AB; vtable shared with ctor
// 0x0025D489 which inits the same D0/E0/E4/C8/CC/F0 fields; base call
// 0x001B4E74; deleting-dtor caller 0x0025DA57.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
	void set(const StringBase &o);
private:
	void releaseBuffer();
	T *m_data;
};

class Rva0025C0FF
{
public:
	void rva0025C0FF();
};

class W3DDisplay
{
public:
	void rva0025D2F6();
};

class ListNode0025D9E3
{
public:
	virtual void s000();
	virtual void s001();
	virtual void s002();
	virtual void s003();
	virtual void s004();
	virtual void v005();
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
	virtual void s026();
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
	virtual void s037();
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
	virtual void s089();
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
	virtual void s104();
	virtual void s105();
	virtual void s106();
	virtual void s107();
	virtual void s108();
	virtual void s109();
	virtual void s110();
	virtual void s111();
	virtual void s112();
	virtual void s113();
	virtual void s114();
	virtual void s115();
	virtual void s116();
	virtual void s117();
	virtual void s118();
	virtual void s119();
	virtual void s120();
	virtual void s121();
	virtual void s122();
	virtual void s123();
	virtual void s124();
	virtual void s125();
	virtual void s126();
	virtual void s127();
	virtual void s128();
	virtual void s129();
	virtual void s130();
	virtual void s131();
	virtual void s132();
	virtual void s133();
	virtual void s134();
	virtual void s135();
	virtual void s136();
	virtual void s137();
	virtual void s138();
	virtual void s139();
	virtual void s140();
	virtual void s141();
	virtual void s142();
	virtual void s143();
	virtual void s144();
	virtual void s145();
	virtual void s146();
	virtual void s147();
	virtual void s148();
	virtual void s149();
	virtual void s150();
	virtual void s151();
	virtual ListNode0025D9E3 *getNext();
};

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
private:
	char m_pad[8];
};

class BfmeStrVM0 : public GameEngineDeletingBase
{
public:
	virtual ~BfmeStrVM0();
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
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
	virtual void v29();
	virtual void v30();
	virtual void v31();
	virtual void v32();
	virtual void v33();
	virtual void v34();
	virtual void v35();
	virtual void v36();
	virtual void v37();
	virtual void v38();
	virtual void v39();
	virtual void v40();
	virtual void v41();
	virtual void v42();
	virtual void v43();
	virtual void v44();
	virtual void v45();
	virtual void v46();
	virtual void v47();
	virtual void v48();
	virtual void v49();
	virtual void v50();
	virtual void v51();
	virtual void v52();
	virtual void v53();
	virtual void v54();
	virtual void v55();
	virtual void v56();
	virtual void v57();
	virtual void v58();
	virtual void v59();
	virtual void v60();
	virtual void v61();
	virtual void v62();
	virtual void v63();
	virtual void v64();
	virtual void v65();
	virtual void v66();
	virtual void v67();
	virtual void v68();
	void rva0025D19E();
	void rva0025D358(StringBase<unsigned short> s, float fC0, float fC4, int iB4, int iB8, int iBC);
	void rva0025D9E3();
private:
	char m_pad0C[0x10];
	ListNode0025D9E3 *m_head1C;
	char m_pad20[0x90];
	StringBase<unsigned short> m_sB0;
	int m_iB4;
	int m_iB8;
	int m_iBC;
	float m_fC0;
	float m_fC4;
	float m_fC8;
	float m_fCC;
	StringBase<char> m_sD0;
	float m_fD4;
	bool m_bD8;
	char m_padD9[0x17];
	StringBase<char> m_sF0;
	char m_padF4[0x1C];
	char m_pad110[0x04];
	bool m_b114;
	char m_pad115[0x0B];
	float m_f120;
	char m_tail[0x22];
};

BfmeStrVM0::~BfmeStrVM0()
{
	rva0025D19E();
	((Rva0025C0FF *)this)->rva0025C0FF();
}

// ?rva0025D358@BfmeStrVM0@@QAEXV?$StringBase@G@@MMHHH@Z, retail 0x0025D358, 112 bytes.
// Sets the +0xB0 display block: Unicode string via set plus ints at +0xB4/+0xB8/+0xBC
// and floats at +0xC0/+0xC4; by-value string temp released at the end.
// Evidence: same +0xB0/+0xD0/+0xF0 layout as the dtor in this TU and ctor 0x0025D489;
// callees rowed/pinned set 0x00037150 plus releaseBuffer 0x00036E70; caller 0x00356AC1.
void BfmeStrVM0::rva0025D358(StringBase<unsigned short> s, float fC0, float fC4, int iB4, int iB8, int iBC)
{
	StringBase<unsigned short> &dst = m_sB0;
	dst.set(s);
	m_iB4 = iB4;
	m_iB8 = iB8;
	m_iBC = iBC;
	m_fC0 = fC0;
	m_fC4 = fC4;
}

// ?rva0025D9E3@BfmeStrVM0@@QAEXXZ, retail 0x0025D9E3, 116 bytes.
// Slot-9 virtual of BfmeStrVM0: when +0x114 is clear, zeroes +0xD4/+0xD8, runs
// the slot-68 virtual plus the W3DDisplay clear helper; then always clears
// +0x114/+0x120, walks the +0x1C list via slot-5 plus getNext, and zeroes
// +0xC8/+0xCC.
// Evidence: vtable slot 9 of 0x7F5DA0; same +0xB0/+0xC8/+0xD0/+0x114/+0x120
// layout as this TU and ctor 0x0025D489; callees slot-68 plus rowed
// rva0025D2F6 plus node slots 5/152; caller 0x00043427.
void BfmeStrVM0::rva0025D9E3()
{
	if (m_b114 == 0)
	{
		m_fD4 = 0.0f;
		m_bD8 = 0;
		v68();
		((W3DDisplay *)this)->rva0025D2F6();
	}
	ListNode0025D9E3 *cur = m_head1C;
	m_b114 = 0;
	m_f120 = 0.0f;
	if (cur != 0)
	{
		ListNode0025D9E3 *next;
		do
		{
			cur->v005();
			next = cur->getNext();
			cur = next;
		} while (next != 0);
	}
	m_fC8 = 0.0f;
	m_fCC = 0.0f;
}
