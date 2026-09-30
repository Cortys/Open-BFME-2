// cl: /Ireference/shims/bfmelist /O1 /DNDEBUG /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva0035CE52@Rva0035CE52@@QAEAAV0@ABV0@@Z @0x0035CE52 84B
// Honest address-derived placeholder: operator= in new opaque class
// Rva0035CE52 derived from StreakDrawModuleTemplate. Evidence: rowed base
// assign 0x001FD28E plus pinned AsciiString assign 0x000366F0 plus rowed
// list assign 0x0035CDDF plus callers 0x0035CEEB 0x0035CF9E.
class AsciiString
{
public:
	AsciiString &operator=(const AsciiString &that);
private:
	char m_pad[4];
};

struct BfmeStringRecord000B757D
{
	unsigned int word0, word1;
	AsciiString text;
	unsigned int word2;
	unsigned char tail;
	BfmeStringRecord000B757D();
	BfmeStringRecord000B757D(const BfmeStringRecord000B757D &o);
};
#include <list>

class FXParticleSystem
{
public:
	class StreakDrawModuleTemplate
	{
	public:
		StreakDrawModuleTemplate &operator=(const StreakDrawModuleTemplate &that);
	private:
		char m_pad[0x10];
	};
};

struct SevenInts00035CE52
{
	int v[7];
};

class Rva0035CE52 : public FXParticleSystem::StreakDrawModuleTemplate
{
public:
	Rva0035CE52 &operator=(const Rva0035CE52 &that);
private:
	AsciiString m_0010; // +0x10
	int m_0014; // +0x14
	int m_0018; // +0x18
	SevenInts00035CE52 m_001C; // +0x1c..+0x37 rep movsd 7
	int m_0038; // +0x38
	_STL::list<BfmeStringRecord000B757D, _STL::allocator<BfmeStringRecord000B757D> > m_003C; // +0x3c
	unsigned char m_0040; // +0x40
};

Rva0035CE52 &Rva0035CE52::operator=(const Rva0035CE52 &that)
{
	FXParticleSystem::StreakDrawModuleTemplate::operator=(that);
	m_0010 = that.m_0010;
	m_0014 = that.m_0014;
	m_0018 = that.m_0018;
	m_001C = that.m_001C;
	m_0038 = that.m_0038;
	m_003C = that.m_003C;
	m_0040 = that.m_0040;
	return *this;
}
