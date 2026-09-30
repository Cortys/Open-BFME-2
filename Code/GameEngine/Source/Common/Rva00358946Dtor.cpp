// cl: /O1 /MD
//
// ??1Rva00358946@@QAE@XZ, retail 0x00358946, 17 bytes.
// Target evidence: frameless WideString helper releasing +0x04 via 0x00036E70
// then zeroing +0x08; called by 0x00358994 and by W3DDisplayString path
// 0x001061C1. Prev/next are BfmeConv454 and rb_tree_hint pair ctor. True
// element name unproven so honest Rva address name stands in.

struct Rva00358946;
template <typename T>
class StringBase
{
	void releaseBuffer();
	friend struct Rva00358946;

private:
	T *m_data;
};

struct Rva00358946
{
public:
	~Rva00358946();

private:
	int m_x0;
	StringBase<unsigned short> m_str4;
	int m_x8;
};

Rva00358946::~Rva00358946()
{
	m_str4.releaseBuffer();
	m_x8 = 0;
}
