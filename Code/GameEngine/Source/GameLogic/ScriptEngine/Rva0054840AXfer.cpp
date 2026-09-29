// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /ICode/Libraries/Source/WWVegas/WWLib
// stlport
// ?rva0054840A@Rva0054840A@@QAEXPAVXfer@@@Z @0x0054840A 90B thiscall xfer with version 1 1 plus ObjectID plus three uints plus list<int>.
// Evidence: chain callee rowed xferListInt 0x00206861; callees rowed XferObjectID 0x003060B2 plus Xfer slots 0x28 version and 0x78 uint; caller 0x003550EB news 0x14 and calls directly; ret 4 single Xfer arg.
#define _STLP_NO_EXCEPTIONS 1
#include <list>

typedef unsigned char UnsignedByte;
typedef unsigned int UnsignedInt;
typedef bool Bool;

struct XferVersion
{
	UnsignedByte m_version;
	UnsignedByte m_currentVersion;
};

class Xfer
{
public:
	virtual ~Xfer();
	virtual Bool isLoading();
	virtual Bool isSaving();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual Xfer &xferVersion(XferVersion *version);
	virtual Xfer &xferTypeName(const char *const &name);
	virtual void slot12();
	virtual void slot13();
	virtual void slot14();
	virtual void slot15();
	virtual void slot16();
	virtual void slot17();
	virtual void slot18();
	virtual void slot19();
	virtual void slot20();
	virtual void slot21();
	virtual void slot22();
	virtual void slot23();
	virtual void slot24();
	virtual void slot25();
	virtual void slot26();
	virtual void slot27();
	virtual void slot28();
	virtual void slot29();
	virtual Xfer &xferUnsignedShort(UnsignedInt *value);
};

enum ObjectID
{
	INVALID_ID = 0
};

typedef _STL::list<int> ListInt;

void XferObjectID(Xfer *xfer, ObjectID *objectID);
Xfer *xferListInt(Xfer *xfer, ListInt *list);

class Rva0054840A
{
public:
	void rva0054840A(Xfer *xfer);
private:
	ObjectID m_00;
	ListInt m_list04;
	UnsignedInt m_08;
	UnsignedInt m_0c;
	UnsignedInt m_10;
};

void Rva0054840A::rva0054840A(Xfer *xfer)
{
	XferVersion version;
	version.m_version = 1;
	version.m_currentVersion = 1;
	xfer->xferVersion(&version);
	XferObjectID(xfer, &m_00);
	xfer->xferUnsignedShort(&m_08);
	xfer->xferUnsignedShort(&m_0c);
	xfer->xferUnsignedShort(&m_10);
	xferListInt(xfer, &m_list04);
}
