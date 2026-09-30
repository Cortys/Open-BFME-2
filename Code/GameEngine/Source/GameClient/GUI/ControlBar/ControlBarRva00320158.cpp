// cl: /O1 /Ireference/shims/ini_bfme2 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/open-bfme-1/Code/GameEngine/Source/Common/System /Ireference/open-bfme-1/Code/GameEngine/Include /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
// stlport
//
// ?Rva00320158Parse@@YAXPAVINI@@PAVRva003200BC@@@Z, retail 0x00320158, 81 bytes.
// ControlBar factory (chain: calls 0x0031F7AB now ready). Evidence: news 0x1C
// via rowed ??2@YAPAXI@Z then rowed ??0Rva0031F7AB@@QAE@XZ; rowed
// ?initFromINI@INI@@QAEXPAXPBUFieldParse@@@Z with table 0x0080D720; rowed
// ?rva003200BC@Rva003200BC@@QAEXH@Z with new object; prev/next
// ControlBarList003200A2/ControlBarScheme share class and flags. Honest
// free-function name (no proven class): Rva00320158 + Parse.

struct FieldParse;

class INI
{
public:
	void initFromINI(void *what, const FieldParse *parseTable);
};

class Rva0031F7AB
{
public:
	Rva0031F7AB();
private:
	char m_pad[0x1C]; // +0x00..+0x1C: sizeof 0x1C from retail push 0x1C
};

class Rva003200BC
{
public:
	void rva003200BC(int value);
};

extern const FieldParse g_0080D720[];

void Rva00320158Parse(INI *ini, Rva003200BC *holder)
{
	Rva0031F7AB *obj = new Rva0031F7AB;
	ini->initFromINI(obj, g_0080D720);
	holder->rva003200BC((int)obj);
}
