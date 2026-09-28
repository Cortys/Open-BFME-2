// cl: /O1 /MD
//
// ?rva002DB44F@Rva002DB44F@@QAEXHABUOpaqueRefElement4@@@Z, retail 0x002DB44F, 20 bytes.
// __thiscall array setter storing via rowed OpaqueRefElement4::operator=
// 0x00239099 into this+0x64+i*4. Leaf (one rowed callee). Caller 0x002DB7B8.
// Prev 0x002DAC27 dword setter / next BfmeMapPictureTexture ctor. Honest
// address name; owner class unproven.
struct OpaqueRefElement4
{
	struct OpaqueRefCounted *referent;
	~OpaqueRefElement4();
	struct OpaqueRefElement4 &operator=(const struct OpaqueRefElement4 &other);
};

struct Rva002DB44F
{
	char m_pad[0x64];
	struct OpaqueRefElement4 m_arr[1];
	void rva002DB44F(int i, const struct OpaqueRefElement4 &v);
};

void Rva002DB44F::rva002DB44F(int i, const struct OpaqueRefElement4 &v)
{
	m_arr[i] = v;
}
