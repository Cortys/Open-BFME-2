// ??1Rva006FBC90Owner@@UAE@XZ @0x006FBC90, 82 bytes. Target Ghidra evidence:
// the deleting wrapper at 0x006FBC60 calls this body and conditionally frees
// the object; the wrapper is referenced by vtable 0x00CED880. This destructor
// stores that vtable, destroys the opaque member at +8 through 0x0070A840,
// then calls the matched base destructor at 0x006DE350. The member/base
// class identities remain RVA-derived; the Zero Hour LadderPreferences name
// is not used because its separately matched BFME2 layout differs.

struct Rva006DE350
{
	virtual ~Rva006DE350();
};

struct Rva0070A840
{
	~Rva0070A840();
};

struct Rva006FBC90Owner : public Rva006DE350
{
	char m_pad[4]; // +0x04..0x07
	Rva0070A840 m_member; // +0x08
	virtual ~Rva006FBC90Owner();
};

Rva006FBC90Owner::~Rva006FBC90Owner()
{
}
