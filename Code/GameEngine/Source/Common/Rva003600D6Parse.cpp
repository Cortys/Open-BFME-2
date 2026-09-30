// cl: /O1 /MD /EHsc
// ?Rva003600D6Parse@@YAXPAVINI@@PAVRva003600D6Holder@@@Z @ 0x003600D6 87B: factory news 0x40,
// calls ctor ??0Rva0035FF76 at 0x0036006F, parses table 0x00816738 via rowed
// INI::initFromINI 0x0002DE78, copies m_endFrame to m_frameLength, stores via
// holder+0x10 setter pinned at 0x005F69CE. Chain from 0x0036006F; same 87B shape
// as 0x0035F6E2. Opaque address-derived names; layout from Rva0035FF76Ctor.cpp.
struct FieldParse;
extern const FieldParse g_00C16738[];

class INI
{
public:
	void initFromINI(void *what, const FieldParse *table);
};

class Rva001DBAA4
{
public:
	virtual ~Rva001DBAA4();
	Rva001DBAA4();
	int m_frameLength;
	bool m_isFinished;
	bool m_isForward;
	bool m_isReversed;
	void *m_win;
};

class Rva0035FF76 : public Rva001DBAA4
{
public:
	virtual ~Rva0035FF76();
	virtual void init(void *win);
	virtual void update(int frame);
	virtual void reverse();
	virtual void draw();
	virtual void skip();
	virtual bool isFinished();
	virtual int getFrameLength();
	Rva0035FF76();
	int m_startFrame;
	int m_endFrame;
	int m_posX;
	int m_posY;
	int m_sizeX;
	int m_sizeY;
	float m_percent;
	int m_drawState;
	float m_fadeRed;
	float m_fadeGreen;
	float m_fadeBlue;
	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;
};

typedef char Rva0035FF76SizeMatchesRetail[(sizeof(Rva0035FF76) == 0x40) ? 1 : -1];

class Rva003600D6Holder
{
public:
	void set(Rva0035FF76 *obj);
};

void __cdecl Rva003600D6Parse(INI *ini, Rva003600D6Holder *holder)
{
	Rva0035FF76 *obj = new Rva0035FF76;
	ini->initFromINI(obj, g_00C16738);
	obj->m_frameLength = obj->m_endFrame;
	holder->set(obj);
}
