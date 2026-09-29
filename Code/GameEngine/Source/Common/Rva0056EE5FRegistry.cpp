// cl: /O1 /EHsc
// ?rva0056EE5F@Rva0056EE5F@@QAEEXZ retail 0x0056EE5F 121B
// Evidence: GetStringFromRegistry 0x00234E0B with Registered and empty via 0x00037BA0; compareNoCase true via 0x00037980; releaseBuffer 0x00036410; callers 0x00571C81 0x00571C93; precedent RegistryAsciiPath
typedef unsigned char Bool8;
class AsciiString;
template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const T *text);
	StringBase(const StringBase &src);
public:
	StringBase() : m_data(0) {}
	~StringBase();
	int compareNoCase(const char *text) const;
	struct Header { int ref_count; unsigned short length; unsigned short capacity; T data[1]; };
protected:
	Header *m_data;
};
class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &src) : StringBase<char>(src) {}
};
bool __cdecl GetStringFromRegistry(AsciiString path, AsciiString key, AsciiString &val);
struct Rva0056EE5F
{
	Bool8 rva0056EE5F();
};
Bool8 Rva0056EE5F::rva0056EE5F()
{
	AsciiString val;
	GetStringFromRegistry("", "Registered", val);
	return (Bool8)(val.compareNoCase("true") == 0);
}
