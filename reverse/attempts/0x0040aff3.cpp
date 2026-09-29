// ??1Rva0040AFF3@@QAE@XZ
// partial score=0.93 date=2026-09-29
// ??1Rva0040AFF3@@QAE@XZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD /EHs
// ??1Rva0040AFF3@@QAE@XZ retail 0x0040AFF3 117B
// Evidence: EH dtor releases StringBase<D> at +0x60 +0x5C +0x58 +0x54 via 0x00036410 then frees +0x10 +0x4 via 0x00030830; deleting dtor caller 0x0040B2E1; precedent Rva002E5791Dtor
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

extern "C" void __cdecl free(void *block);

struct Rva0040AFF3Base
{
	char m_pad0[4];
	char *m_ptr4;
	char m_pad8[8];
	char *m_ptr10;
	char m_pad14[0x54 - 0x14];
	__forceinline ~Rva0040AFF3Base()
	{
		if (m_ptr10)
			free(m_ptr10);
		if (m_ptr4)
			free(m_ptr4);
	}
};

struct Rva0040AFF3 : public Rva0040AFF3Base
{
	StringBase<char> m_str54;
	StringBase<char> m_str58;
	StringBase<char> m_str5C;
	StringBase<char> m_str60;
// ??1Rva0040AFF3@@QAE@XZ present-unmatched
	~Rva0040AFF3();
};

Rva0040AFF3::~Rva0040AFF3()
{
}
