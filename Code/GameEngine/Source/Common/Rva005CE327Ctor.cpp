// cl: /O1 /MD
// ??0Rva005CE327@@QAE@PBUPayload@0@@Z, retail 0x005CE327, 29 bytes.
// vtable 0x00875130 at +0; +4 zeroed; 3-dword movsd from src arg to +8; ret 4.
// Caller 0x005CE3F9 news 0x14 and stores with refcount inc; twin pattern of
// Rva005CDF6C / Rva005CDB8F 5-dword ctors; unblocks 0x005CE3F9.
class Rva005CE327
{
public:
	struct Payload { int v[3]; };
	Rva005CE327(const Payload *src);
	virtual ~Rva005CE327();
private:
	int m_ref; // +4
	Payload m_data; // +8
};

Rva005CE327::Rva005CE327(const Payload *src)
	: m_ref(0)
	, m_data(*src)
{
}
