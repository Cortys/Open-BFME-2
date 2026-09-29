// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?Rva003B46C7Destroy@@YAXPAUPrereqUnitRec@ProductionPrerequisite@@0@Z @0x003B46C7 25B destroy range over 0x14-byte PrereqUnitRec via rowed dtor 0x00577998 callers 0x003B6846 0x003B7057
class AsciiString
{
public:
	~AsciiString();
private:
	char *m_data;
	char m_pad[8];
};
class ProductionPrerequisite
{
public:
	struct PrereqUnitRec
	{
		unsigned int m_first;
		unsigned int m_second;
		AsciiString m_name;
		~PrereqUnitRec();
	};
};
void Rva003B46C7Destroy(ProductionPrerequisite::PrereqUnitRec *first, ProductionPrerequisite::PrereqUnitRec *last)
{
	for (; first != last; ++first)
		first->~PrereqUnitRec();
}
