// ?rva0007EEBE@Rva0007EEBE@@QAEXH@Z
// partial score=0.96 date=2026-09-29
// ?rva0007EEBE@Rva0007EEBE@@QAEXH@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /GX
// ?rva0007EEBE@Rva0007EEBE@@QAEXH@Z, retail 0x0007EEBE, 119 bytes.
// Per-index particle texture load: string holder at +0x40 via rowed
// Rva0030BBA9 getter, skip when isEmpty, filename at buf+8 or default
// 0x7BAC1C, BFME2LoadParticleTexture into temp then RefCountPtr op= to
// slot +0x44[i]. Callers 0x82061/0x820CA loop 4 entries with set insert.
class Rva0030BBA9
{
public:
	void *rva0030BBA9(int i);
};

template <typename T>
class StringBase
{
public:
	bool isEmpty() const;
	const char *m_data;
};

typedef StringBase<char> AsciiString;

class TextureBaseClass
{
public:
	void Release_Ref();
};

class TextureClass : public TextureBaseClass
{
	int m_pad[2];
};

template <class T>
class RefCountPtr
{
public:
	const RefCountPtr &operator=(const RefCountPtr &other);
	~RefCountPtr() { if (m_ptr) m_ptr->Release_Ref(); }
	T *m_ptr;
};

class BFME2ParticleTextureHandle : public RefCountPtr<TextureClass>
{
};

BFME2ParticleTextureHandle __cdecl BFME2LoadParticleTexture(const char *filename, int a, int b);

class Rva0007EEBE
{
public:
	void rva0007EEBE(int index);
private:
	char m_pad[0x40];
	Rva0030BBA9 *m_holder;
	RefCountPtr<TextureClass> m_textures[4];
};

// ?rva0007EEBE@Rva0007EEBE@@QAEXH@Z present-unmatched
void Rva0007EEBE::rva0007EEBE(int index)
{
	AsciiString *s = (AsciiString *)m_holder->rva0030BBA9(index);
	if (!s->isEmpty()) {
		const char *name = s->m_data ? s->m_data + 8 : (const char *)0x7BAC1C;
		m_textures[index] = BFME2LoadParticleTexture(name, 0, 0);
	}
}
