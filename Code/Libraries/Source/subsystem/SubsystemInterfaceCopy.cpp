// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??0SubsystemInterface@@QAE@ABV0@@Z @0x00329F5E 37B plus ??4SubsystemInterface@@QAEAAV0@ABV0@@Z @0x00329880 31B
// SubsystemInterface copy ctor and copy assign.
// Evidence: vtable 0x00BD77A0 set by copy ctor (base ctor pin at 0x001B4E63 installs same vtable and zeroes +4/+8).
// m_name at +0x08 via rowed setName at 0x0006F3CC (assigns +0x08 through 0x366F0). Byte at +4 copied as single byte.
// Callees: 0x000365F0 StringBase copy (pin) through AsciiString inline forwarder (cf. DataChunkOutputWriteNameKey.cpp).
// 0x000366F0 AsciiString assign (pin cf. SubsystemInterfaceSetName.cpp).
// Callers: copy ctor from 0x0032EF55 and assign from 0x0032E989 (unclaimed copy loops).
// Donor: BFME1 SubsystemInterface.cpp copy semantics (retail layout proven by base ctor plus setName).

template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase(const StringBase<T> &other);
	void *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	AsciiString &operator=(const AsciiString &other);
	~AsciiString();
};

class SubsystemInterface
{
public:
	virtual ~SubsystemInterface();
	SubsystemInterface(const SubsystemInterface &that);
	SubsystemInterface &operator=(const SubsystemInterface &that);
private:
	bool m_flag; // +4
	AsciiString m_name; // +8
};

// ??0SubsystemInterface@@QAE@ABV0@@Z present-unmatched
SubsystemInterface::SubsystemInterface(const SubsystemInterface &that) :
	m_flag(that.m_flag),
	m_name(that.m_name)
{
}

SubsystemInterface &SubsystemInterface::operator=(const SubsystemInterface &that)
{
	m_flag = that.m_flag;
	m_name = that.m_name;
	return *this;
}
