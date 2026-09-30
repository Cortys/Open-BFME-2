// ?rva000551C2@Rva000551C2@@QAEXH@Z
// partial score=0.92 date=2026-09-30
// ?rva000551C2@Rva000551C2@@QAEXH@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /MD /EHsc
// ?rva000551C2@Rva000551C2@@QAEXH@Z @0x000551C2 106B. Guarded single-entry erase
// of first BfmePod8 with a[0]==key then set dirty flag. Evidence: chain via
// 0x0004120E ctor and 0x0004122F dtor rows plus 0x00054B3F vector erase row;
// offsets +0x9d4 mutex +0xb54 vector +0x6aa flag from retail immediates.
struct BfmePod8
{
	int a[2];
};

namespace _STL
{
	template <class T> class allocator
	{
	};
	template <class T, class A = allocator<T> > class vector
	{
	public:
		T *begin() { return _M_start; }
		T *end() { return _M_finish; }
		T *erase(T *p);
		T *_M_start;
		T *_M_finish;
		T *_M_end;
	};
}

class MilesMutexGuard
{
public:
	MilesMutexGuard(void *m, int x);
	~MilesMutexGuard();
private:
	void *m_mutex;
	bool m_flag;
};

class Rva000551C2
{
public:
	void rva000551C2(int key);
private:
	char m_pad0[0x6aa];
	bool m_dirty; // +0x6aa
	char m_pad1[0x329];
	int m_mutexObj; // +0x9d4 passed by address
	char m_pad2[0x17c];
	_STL::vector<BfmePod8> m_vec; // +0xb54
};

// ?rva000551C2@Rva000551C2@@QAEXH@Z present-unmatched
void Rva000551C2::rva000551C2(int key)
{
	MilesMutexGuard guard(&m_mutexObj, 0);
	for (BfmePod8 *it = m_vec.begin(); it != m_vec.end(); ++it)
	{
		if (it->a[0] == key)
		{
			m_vec.erase(it);
			m_dirty = true;
			break;
		}
	}
}
