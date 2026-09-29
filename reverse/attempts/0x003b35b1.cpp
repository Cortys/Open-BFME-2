// ??1Rva003B35B1@@UAE@XZ
// partial score=0.93 date=2026-09-29
// ??1Rva003B35B1@@UAE@XZ
// partial score=0.93 date=2026-09-29
// ??1Rva003B35B1@@UAE@XZ retail 0x003B35B1 177B
// Evidence: vtable 0x0081F424 then base Snapshot 0x007BB554; callers 0x003B41FB 0x003B3F61 unblocks deleting 0x003B41F8 plus 0x003B3F5E; members delete plus 5 releaseBuffer
template<typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

class Rva003B35B1Ptr
{
public:
	virtual void *v0(int x);
};

void __cdecl operator delete(void *p);

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc();
	virtual void loadPostProcess();
	virtual void xfer();
};

inline Snapshot::~Snapshot()
{
	*(const void **)this = reinterpret_cast<const void *>(0x007BB554);
}

class Rva003B35B1 : public Snapshot
{
public:
	virtual ~Rva003B35B1();
private:
	StringBase<char> m_04;
	StringBase<char> m_08;
	StringBase<char> m_0C;
	char m_pad10[0x0C];
	StringBase<char> m_1C;
	char m_pad20[0x10];
	Rva003B35B1Ptr *m_30;
	Rva003B35B1Ptr *m_34[2];
	char m_pad3C[0x08];
	StringBase<char> m_44;
};

// ??1Rva003B35B1@@UAE@XZ present-unmatched
Rva003B35B1::~Rva003B35B1()
{
	if (m_30) {
		void *p = m_30->v0(0);
		::operator delete(p);
	}
	for (int i = 0; i < 2; ++i) {
		if (m_34[i]) {
			void *p = m_34[i]->v0(0);
			::operator delete(p);
		}
	}
}
