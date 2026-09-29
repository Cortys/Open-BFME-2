// cl: /O1 /DNDEBUG /MD /EHsc
// ??1Rva0048C200Owner@@QAE@XZ, retail 0x002019E1, 54B.
// Dtor of two-String owner whose ctor is 0x00201998; calls releaseBuffer
// at +8 then +4 via inlined StringBase<char> member dtors with EH.
// Evidence: abuts ctor (0x00201998+73=0x002019E1), same flags, callees rowed.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

class Rva0048C200Owner
{
public:
	~Rva0048C200Owner();
private:
	void *m_head00;
	StringBase<char> m_first04;
	StringBase<char> m_second08;
};

Rva0048C200Owner::~Rva0048C200Owner()
{
}
