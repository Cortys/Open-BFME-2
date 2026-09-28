// cl: /O1 /MD
// ?Rva00469124Xfer@@YAAAVXfer@@PAV1@PAURva00469124Pair@@@Z 0x00469124 30B evidence: ObjectID+int pair via rowed XferObjectID 0x3060B2 then slot 0x78 callers 0x47028A 0x4702D8
typedef unsigned int UnsignedInt;
typedef bool Bool;
struct XferVersion
{
	unsigned char m_version;
	unsigned char m_currentVersion;
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
	virtual Xfer &xferInt(int *value);
};
enum ObjectID
{
	INVALID_ID = 0
};
void XferObjectID(Xfer *xfer, ObjectID *objectID);
struct Rva00469124Pair
{
	ObjectID m_id;
	int m_value;
};
Xfer &Rva00469124Xfer(Xfer *xfer, Rva00469124Pair *pair)
{
	// Rowed XferObjectID is declared void but its body tail-calls XferEnum
	// which returns Xfer& in eax; retail reuses that eax as the xfer for the
	// slot-0x78 call, so call it through an Xfer&-returning type.
	Xfer &r = ((Xfer &(__cdecl *)(Xfer *, ObjectID *))XferObjectID)(xfer, (ObjectID *)pair);
	return r.xferInt(&pair->m_value);
}
