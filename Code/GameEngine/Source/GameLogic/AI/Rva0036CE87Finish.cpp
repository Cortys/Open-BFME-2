// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva0036CE87@AIGroup@@QAEXXZ @0x0036CE87 73B
// AIGroup ground-path reset: destroy the Path at +0x14 through its out-of-line
// destructor, free it, then clear the path state. The four clears run from the
// destructor of a scoped PathDeleteArgument temporary, which is what places the
// `and [esi+0x14],0` and the three float zero stores AFTER the operator-delete
// call and lets the `pop ecx` argument cleanup schedule between them; the
// banked void-return attempt stalled on exactly that `pop ecx` slot.
// Donor shape: reference/open-bfme-1 .../AIGroup/Rva00150700PathReset.cpp
// (same RAII spelling, BFME1 offsets +0x18..+0x30; this body uses BFME2's
// +0x14 ground path and +0x18/+0x1c/+0x20 float state).

void __cdecl operator delete(void *) throw();

class Path
{
public:
	~Path(void) throw();
};

class BFMEDeletablePath : public Path
{
public:
	void destroy(void) { Path::~Path(); }
};

class PathDeleteArgument;

class AIGroup
{
public:
	void rva0036CE87();
	friend class PathDeleteArgument;

private:
	unsigned char m_head[0x14];
	Path *m_groundPath;
	float m_pathState18;
	float m_pathState1C;
	float m_pathState20;
	float m_pathState24;
	float m_pathState28;
	float m_pathState2C;
};

class PathDeleteArgument
{
public:
	PathDeleteArgument(Path *path, AIGroup *owner) :
		m_path(path), m_owner(owner) { }
	operator void *(void) const { return m_path; }
	~PathDeleteArgument(void) throw()
	{
		m_owner->m_groundPath = 0;
		m_owner->m_pathState18 = 0.0f;
		m_owner->m_pathState1C = 0.0f;
		m_owner->m_pathState20 = 0.0f;
	}

private:
	Path *m_path;
	AIGroup *m_owner;
};

void AIGroup::rva0036CE87()
{
	if (m_groundPath)
	{
		Path *p = m_groundPath;
		reinterpret_cast<BFMEDeletablePath *>(p)->destroy();
		operator delete(PathDeleteArgument(p, this));
		m_pathState24 = 10.0f;
		m_pathState28 = 0.0f;
		m_pathState2C = 0.0f;
	}
}
