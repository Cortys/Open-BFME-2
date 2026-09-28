// cl: /O1 /MD /EHsc /DNDEBUG
// stlport
//
// ??0Rva00507823@@QAE@XZ retail 0x0050775B 172B
// Base ctor storing vtable 0x00864010 same as dtor 0x00507823. Zeroes two
// 0x80 mask blocks at +0x04 and +0x84 via rowed clear80 0x001EAE6F plus
// and-zero at +0x104 then builds two 12B vectors at +0x108 and +0x114 via
// pinned Vector_base 0x00211E58 plus filter at +0x120 via pinned ctor
// 0x003623E5 plus two FixedStorage temps from 0x009FEFA4 via rowed copy
// 0x0004543D consumed by pinned initFromStorages 0x00362087 plus bool at
// +0x124. Evidence: deleting dtor 0x00507807 calls dtor 0x00507823 plus
// derived 0x00507C2D calls here as base plus slot 8 resolve 0x00507877
// proves AsciiString vectors at +0x108/+0x114 and masks at +0x04/+0x84.
// Same EH 0/1/2 shape as EmotionTracker precedent.
#include <vector>

class Rva001EAE6FHelper
{
public:
	Rva001EAE6FHelper() { clear80(); }
	Rva001EAE6FHelper *clear80();
private:
	char m_pad[0x80];
};

class BfmeFixedStorage0004543D
{
public:
	__declspec(nothrow) BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other);
private:
	unsigned char m_bytes[28];
};

class Rva003623E5Member
{
public:
	Rva003623E5Member();
	~Rva003623E5Member();
	void initFromStorages(BfmeFixedStorage0004543D first, BfmeFixedStorage0004543D second);
private:
	int m_x;
};

template <typename Char>
class StringBase
{
protected:
	void *m_data;
	void releaseBuffer();
protected:
	~StringBase() { releaseBuffer(); }
};

class AsciiString : private StringBase<char>
{
public:
	~AsciiString() {}
};

class Rva00507823
{
public:
	virtual ~Rva00507823();
	Rva00507823();
private:
	Rva001EAE6FHelper m_bits04;
	Rva001EAE6FHelper m_bits84;
	int m_104;
	_STL::vector<AsciiString> m_vec108;
	_STL::vector<AsciiString> m_vec114;
	Rva003623E5Member m_filter120;
	bool m_124;
};

Rva00507823::Rva00507823()
	: m_104(0)
	, m_124(false)
{
	m_filter120.initFromStorages(
		BfmeFixedStorage0004543D(*reinterpret_cast<const BfmeFixedStorage0004543D *>(0x00DFEFA4)),
		BfmeFixedStorage0004543D(*reinterpret_cast<const BfmeFixedStorage0004543D *>(0x00DFEFA4)));
}
