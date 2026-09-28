// cl: /O1 /DNDEBUG /MD
// ??1Rva002C589B@@QAE@XZ @0x002C589B 24B: non-virtual dtor that deletes the
// +0x24 heap object via the rowed Rva003ECDB7 dtor 0x003ECDB7 plus the rowed
// operator delete 0x0002FD60. Called by the unclaimed deleting dtor 0x0050526D
// plus two vector cleanups 0x0050549A and 0x00505710. Same +0x24 member is
// created by the unclaimed ctor 0x002C5C1F which formats AIThreatFinder%d.
// Owner identity unproven so the name stays address-derived.
class Rva003ECDB7Object
{
public:
	~Rva003ECDB7Object();
};

class Rva002C589B
{
public:
	~Rva002C589B();

private:
	char m_pad[0x24];
	Rva003ECDB7Object *m_ptr;
};

Rva002C589B::~Rva002C589B()
{
	delete m_ptr;
}
