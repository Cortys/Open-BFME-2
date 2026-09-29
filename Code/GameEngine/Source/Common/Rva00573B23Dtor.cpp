// cl: /O1 /DNDEBUG /MD /EHsc
// ??1Rva00573B23@@UAE@XZ @0x00573B23 59B
// Dtor: vptr store, inline StringBase<char> member dtor at +0x2c (inlined to
// a direct releaseBuffer call, arming EH state 0), then the virtual public
// base dtor ??1Rva0055B0CC@@UAE@XZ (pin-only). Empty body: everything implicit.
// Evidence: mov [esi] vtable, and [ebp-4]0, lea ecx [esi+2c] call
// releaseBuffer@StringBase@D, or [ebp-4]-1, mov ecx esi call 0x0055B0CC.
template <typename T>
class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};
struct Rva0055B0CC
{
	virtual ~Rva0055B0CC();
};
struct Rva00573B23 : Rva0055B0CC
{
	char m_pad04[0x28];
	StringBase<char> m_2c;
	virtual ~Rva00573B23();
};
Rva00573B23::~Rva00573B23()
{
}
