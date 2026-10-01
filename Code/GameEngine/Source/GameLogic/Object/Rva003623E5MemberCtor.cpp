// cl: /O1 /MD /EHsc /DNDEBUG
//
// ??0Rva003623E5Member@@QAE@XZ at 0x003623E5 (82 bytes).
// The ctor resets its 4-byte handle to -1, builds a 0x94-byte default record
// with the rowed 0x360F55 ctor, registers/deduplicates it through 0x361790,
// stores the returned pool index, then destroys the local through 0x360FDB.
// The 0x361790 helper's identity is unknown; its pointer argument and integer
// return are established by this call site and the callee's table scan.

class Rva00360F55
{
public:
	Rva00360F55();
	~Rva00360F55();

private:
	unsigned char m_record[0x94];
};

int __cdecl Rva00361790(Rva00360F55 *record);

class Rva003623E5Member
{
public:
	Rva003623E5Member();

private:
	unsigned int m_record;
};

Rva003623E5Member::Rva003623E5Member()
	: m_record(-1)
{
	Rva00360F55 defaultRecord;
	m_record = Rva00361790(&defaultRecord);
}
