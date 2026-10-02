// cl: /O1 /DNDEBUG /MD /EHs /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /Ireference/shims/bfmealloc /Ireference/shims/bfmelist
// ?rva004F597F@Rva004F599E@@QAEXXZ, retail 0x004F597F, 31 bytes.
// Zeroes two int[21] blocks at +4 and +0x58; called from ctor 0x004F599E after vtable store.
class Rva004F599E
{
public:
	void rva004F597F();
private:
	void *m_vtbl;
	int m_a[21];
	int m_b[21];
};
void Rva004F599E::rva004F597F()
{
	for (int i = 0; i < 20; ++i) {
		m_a[i] = 0;
		m_b[i] = 0;
	}
	m_a[20] = 0;
	m_b[20] = 0;
}
