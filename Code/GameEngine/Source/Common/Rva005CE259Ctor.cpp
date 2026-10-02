// cl: /O1 /MD
// ??0Rva005CE259@@QAE@PBUPayload@0@@Z, retail 0x005CE259, 30 bytes.
// vtable 0x00875124 at +0; +4 zeroed; 2-dword mov copy from src arg to +8; ret 4.
// Caller 0x005CE2BA news 0x10 and stores with refcount inc; twin pattern of
// 0x005CE327 3-dword ctor with 2-mov shape; unblocks 0x005CE2A1.
class Rva005CE259
{
public:
	struct Payload { int v[2]; };
	Rva005CE259(const Payload *src);
	virtual ~Rva005CE259();
private:
	int m_ref; // +4
	Payload m_data; // +8
};

Rva005CE259::Rva005CE259(const Payload *src)
	: m_ref(0)
	, m_data(*src)
{
}
