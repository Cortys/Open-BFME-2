// ?rva0045992F@SiegeDockingBehavior@@QAEXPAUDockPos@1@H@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?stopDocking@SiegeDockingBehavior@@AAEXXZ @0x00459C27 49B.
// Clears the +0x24 entry vector: deletes each entry via rowed ??3 0x0002FD60
// behind an explicit null test then empties via rowed voidptr erase 0x0031BD55.
// Callers are the rowed deleting dtor 0x0045A17D via dtor 0x00459DAA at
// 0x00459DDA and the xfer 0x0045A02F at 0x0045A0F9 which clears before reload.
// Donor is BFME1 SiegeDockingBehavior_stopDocking (same delete-plus-erase
// shape; BFME2 binds erase to the rowed voidptr opt). Mixed this-via-ebx
// access is load-bearing for the tail (Glo012F1028 precedent).
namespace _STL
{
template <class T>
class allocator
{
};

template <class T, class A>
class vector
{
public:
	T *m_start;
	T *m_finish;
	T *m_end_of_storage;
	T *begin() { return m_start; }
	T *end() { return m_finish; }
	int size() const { return m_finish - m_start; }
	T &operator[](int i) const { return m_start[i]; }
	T *erase(T *first, T *last);
};
}

class SiegeDockingBehavior
{
public:
	struct DockPos
	{
		float m_f;
		int m_b;
		int m_c;
	};
	void rva0045992F(DockPos *out, int index);

private:
	void stopDocking() throw();

private:
	unsigned char m_pad00[8];
	class Object *m_08;
	unsigned char m_pad0C[0x24 - 0x0C];
	_STL::vector<void *, _STL::allocator<void *> > m_entries; // +0x24
};

struct DockEntry
{
	unsigned char m_pad[0x14];
	SiegeDockingBehavior::DockPos m_pos14;
};

class Object
{
public:
	unsigned char m_pad00[0x38];
	SiegeDockingBehavior::DockPos m_pos38;
};

void SiegeDockingBehavior::stopDocking() throw()
{
	_STL::vector<void *, _STL::allocator<void *> > *entries = &m_entries;
	for (void **it = m_entries.begin(); it != m_entries.end(); ++it)
	{
		if (*it)
			::operator delete(*it);
	}
	entries->erase(entries->m_start, entries->m_finish);
}

// ?rva0045992F@SiegeDockingBehavior@@QAEXPAUDockPos@1@H@Z, retail 0x0045992F 61B.
// Bounds-checked entry position: entries[index]+0x14 else m_08+0x38, stored
// field-wise to out. Unlocks 0x004C5877 and 0x00469967.
// ?rva0045992F@SiegeDockingBehavior@@QAEXPAUDockPos@1@H@Z present-unmatched
void SiegeDockingBehavior::rva0045992F(DockPos *out, int index)
{
	int count = m_entries.size();
	const DockPos *src;
	if (index < 0 || (unsigned int)index >= (unsigned int)count)
		src = &m_08->m_pos38;
	else
		src = &((DockEntry *)m_entries.m_start[index])->m_pos14;
	out->m_f = src->m_f;
	out->m_b = src->m_b;
	out->m_c = src->m_c;
}
