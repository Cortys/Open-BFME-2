// ?rva0021122A@Rva0021122A@@QAEPAVRvaSmartPtr12@@PAV2@@Z
// partial score=0.9 date=2026-09-29
// ?rva0021122A@Rva0021122A@@QAEPAVRvaSmartPtr12@@PAV2@@Z
// partial score=0.9 date=2026-09-28
// cl: /O1 /DNDEBUG /MD

// ?rva0021122A@Rva0021122A@@QAEPAVRvaSmartPtr12@@PAV2@@Z, RVA 0x0021122A,
// 27B. Unlock lane: copy-constructs *out from the RvaSmartPtr12 member at
// +0x1C through rowed ??0RvaSmartPtr12 at 0x0004CC19, returns out, ret 4.
// The leading push+and slot has no other use; an unused zeroed local keeps
// the same bytes. Owner unknown so honest address-derived names.
class RvaSmartPtr12
{
public:
	RvaSmartPtr12(const RvaSmartPtr12 &o);
private:
	char m_data[12];
};

class Rva0021122A
{
public:
	RvaSmartPtr12 *rva0021122A(RvaSmartPtr12 *out);
private:
	char m_pre[0x1C];
	RvaSmartPtr12 m_1c;
};

inline void *__cdecl operator new(unsigned int, RvaSmartPtr12 *p) throw() { return (void *)p; }

// ?rva0021122A@Rva0021122A@@QAEPAVRvaSmartPtr12@@PAV2@@Z present-unmatched
RvaSmartPtr12 *Rva0021122A::rva0021122A(RvaSmartPtr12 *out)
{
	int unused = 0;
	(void)unused;
	new (out) RvaSmartPtr12(m_1c);
	return out;
}
