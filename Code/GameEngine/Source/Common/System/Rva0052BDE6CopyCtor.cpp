// cl: /O1 /MD /EHsc
// ??0Rva0052BDE6@@QAE@ABV0@@Z, retail 0x0052BDE6, 77 bytes.
// Copy ctor for an address-named value type holding strings at +4 and +8
// with vtable 0x00C61DB4. Evidence: StringBase<char> copies via pinned
// 0x000365F0 from param+4/+8 to this+4/+8 with EH state 0 then 1, sole
// caller 0x0052C369 placement construct, unlocks 0x0052C34D. Sibling of
// Rva0052BEF0 copy ctor (same empty-base EH plus manual vtable recipe).
template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase() { m_data = 0; }
	StringBase(const StringBase<T> &other);
	void *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString();
	AsciiString &operator=(const AsciiString &other);
};

extern const void *const g_00C61DB4[];

class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};

class Rva0052BDE6 : public EmptyBase
{
public:
	Rva0052BDE6(const Rva0052BDE6 &other);

private:
	const void *m_vtable; // +0
	AsciiString m_str04; // +4
	AsciiString m_str08; // +8
};

Rva0052BDE6::Rva0052BDE6(const Rva0052BDE6 &other)
	: m_vtable(g_00C61DB4)
	, m_str04(other.m_str04)
	, m_str08(other.m_str08)
{
}
