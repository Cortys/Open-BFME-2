// ?Rva00590F76Get@@YAHPBVRva004D6119@@@Z
// partial score=0.9 date=2026-09-27
// ?Rva00590F76Get@@YAHPBVRva004D6119@@@Z
// partial score=0.9 date=2026-09-27
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /GX-
// ?Rva00590F76Get@@YAH PBVRva004D6119@@@Z @0x00590F76 (47B):
// Free __cdecl size helper: copies the +0x1c UnicodeString via rowed getter
// @0x004D6119 into the dead arg slot, reads length low byte at m_data+4,
// releases via rowed releaseBuffer @0x00036E70, returns len*2+0x19.
// Sibling @0x00590F47 uses +0x0D. Caller 0x005929DE. Honest-address name.

typedef unsigned short WideChar;

template <typename T>
class StringBase
{
	friend class UnicodeString;

public:
	void releaseBuffer();

private:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);

	struct Header
	{
		int m_ref;
		unsigned char m_lenLo;
		unsigned char m_lenHi;
		unsigned short m_cap;
		T m_data[1];
	};

	Header *m_data;
};

class UnicodeString
{
public:
	unsigned char getLen() const
	{
		const StringBase<WideChar>::Header *h = *(const StringBase<WideChar>::Header *const *)this;
		if (!h)
			return 0;
		return h->m_lenLo;
	}
	void release()
	{
		((StringBase<WideChar> *)this)->releaseBuffer();
	}

private:
	void *m_pad;
};

class Rva004D6119
{
public:
	UnicodeString rva004D6119() const;
};

// ?Rva00590F76Get@@YAHPBVRva004D6119@@@Z present-unmatched
int __cdecl Rva00590F76Get(const Rva004D6119 *obj)
{
	UnicodeString tmp = obj->rva004D6119();
	unsigned char b = tmp.getLen();
	tmp.release();
	return b * 2 + 0x19;
}
