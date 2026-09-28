// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva0028867DCheck@@YA_NPBX@Z, retail 0x0028867D, 37 bytes.
// Multiplayer-gated zero-check on bytes at +0x101/+0x102 via TheBfmeGlob 0x00DFE78C gate (rowed bfmeCall939D 0x0023C6FD).
// Evidence: 5 callers home object into ESI for post-call reads (0x00288937 0x0028895A 0x00288DCD 0x00288E59 0x002897E6);
// adjacent byte getters at 0x002885EC (+0x102) and 0x002885F3 (+0x101) prove the offsets;
// same-gate donor Rva0031DF89 selects offsets via TheBfmeGlob; static ESI-arg convention per Rva008B8F80 precedent.

class BfmeGlob939D
{
public:
	char bfmeCall939D();
};

#define TheBfmeGlob (*(BfmeGlob939D **)0x00DFE78C)

struct Rva0028867DData
{
	char m_pad[0x101];
	unsigned char m_b101;
	unsigned char m_b102;
};

static bool Rva0028867DCheck(const void *p)
{
	const Rva0028867DData *d = (const Rva0028867DData *)p;
	if (TheBfmeGlob->bfmeCall939D())
		return d->m_b101 == 0;
	return d->m_b102 == 0;
}

// absent-from-retail: keeps the static alive with the ESI argument convention.
bool Rva0028867DCaller(const void *p)
{
	if (p)
		return Rva0028867DCheck(p);
	return false;
}
