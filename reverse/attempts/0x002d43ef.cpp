// ?Rva002D43EFFire@@YAXPAVRva00222A8BTarget@@PAXPBDPAHPAUAsciiHolder@@@Z
// partial score=0.93 date=2026-09-30
// ?Rva002D43EFFire@@YAXPAVRva00222A8BTarget@@PAXPBDPAHPAUAsciiHolder@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?Rva002D43EFFire@@YAXPAVRva00222A8BTarget@@PAXPBDPAHPAUAsciiHolder@@@Z retail 0x002D43EF 117B.
// UI callback firer with int-to-string plus AsciiString args and empty fallback.
// Evidence: caller 0x002D4A95 pushes target owner name int-ptr ascii-ptr;
// rowed Rva00222834Get 0x00222834 plus pinned invoke 0x00222A8B plus empty
// g_Rva0107301CEmptyString plus releaseBuffer 0x00036410; EH for temp.

template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	T *m_data;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

AsciiString Rva00222834Get(int val);

class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern const char g_Rva0107301CEmptyString[];

struct AsciiHolder
{
	const char *m_ptr;
};

void Rva002D43EFFire(Rva00222A8BTarget *target, void *owner, const char *name, int *intPtr, AsciiHolder *holder)
{
	AsciiString tmp = Rva00222834Get(*intPtr);
	const char *s1 = holder->m_ptr;
	if (s1 == 0)
		s1 = g_Rva0107301CEmptyString;
	else
		s1 = s1 + 8;
	const char *s2 = *(const char **)&tmp;
	if (s2 == 0)
		s2 = g_Rva0107301CEmptyString;
	else
		s2 = s2 + 8;
	target->invoke(owner, name, 2, s2, (void *)s1, 0, 0, 0);
}
