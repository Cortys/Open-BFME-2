// cl: /O1
// ??0Rva00270025@@QAE@XZ @0x00270025 28B
// Ctor for 0x74-byte class with vtable 0x007FAD34; zeroes 14 void-ptrs at +0x04 and 14 ints at +0x3C.
// Evidence: new 0x74 at 0x00270BB4 calls it; dtor at 0x00270041 destroys first array; honest Rva name.
class Rva00270025
{
public:
	Rva00270025();
	virtual ~Rva00270025();
private:
	void *m_04[14];
	int m_3c[14];
};

Rva00270025::Rva00270025()
{
	for (int i = 0; i < 14; i++) {
		m_04[i] = 0;
		m_3c[i] = 0;
	}
}
