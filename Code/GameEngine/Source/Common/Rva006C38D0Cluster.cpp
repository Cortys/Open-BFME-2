// ?rva006C38D0@Rva006C1F60@@QAE_NXZ @ 0x006C38D0 (99B) and
// ?rva006C3940@Rva006C1F60@@QAEPAXI@Z @ 0x006C3940 (146B).
//
// Both bodies sit immediately above the rowed 0x006C3840 lock-guarded setter
// (Rva006C3840Cluster.cpp) and share its Rva006C1F60 layout, so the class, the
// 0x006C33D0 callee and the +0x4E4 lock are already established. Two callees are
// named nowhere in the ledger and are called here as address-derived members:
//
//   0x00033D50 -- proven a member of THIS object from target bytes: it AddRefs
//     this+0x4E4 on entry, walks the +0x49C map and the +0x448 sentinel list,
//     then stores 0 to +0x4E4 and Release/Deletes the lock. memory_pool.cpp
//     proves +0x448 as a list sentinel and +0x4E4 as a Lock*, and
//     Rva006C1F60.cpp proves +0x4E4 on this class. Reached via thunk 0x34D00.
//   0x00033ED0 -- a thiscall member taking (unsigned int, int) and returning
//     void*: it rounds `first+11` up to a multiple of 0x10, tests flag bit 8
//     and hands off to 0x00032DF0, otherwise walks free lists at this+0x00..
//     +0x30. Both arguments are read off the stack, so the return is in eax.
//
// Structural inference, NOT proven identity: 0x6C38D0 propagates the byte
// 0x33D50 returns and invokes it on the same object, so it reads as a
// teardown/flush predicate that always clears the +0x510 byte. 0x6C3940
// allocates: it calls 0x33ED0 with (len+2, 0x80000000) in a retry loop and, on
// success, clears the PPMalloc fencepost word at block+fencepost-0xA and sets
// header bit 4 -- byte-for-byte the shape of the unrowed 0x006C1CC0 wrapper at
// 0x006C1CDC -- while the four call sites at 0x6C3A55/0x6C3BC9/0x6C3C8C/
// 0x6C3D29 write a 2-byte length then a 2-byte tag into the returned buffer.
//
// +0x678 is read as a self-pointer: both bodies compare it against `this`, and
// on the mismatch path 0x6C3940 loads it into ecx for the 0x35080 call, i.e.
// the allocation is forwarded to THAT object, not to this one. Field labels
// below are descriptive; only the offsets are target facts. The loop
// back-edge at 0x6C3966 is taken from the fencepost write itself, so the
// retry re-enters 0x33ED0 with the already-adjusted length.

struct Rva00030DD0Lock;
int Rva00030DD0AddRef(Rva00030DD0Lock *lock);
int Rva00030DF0Release(Rva00030DD0Lock *lock);

// Private view of the rowed array-of-chains class (0x006C17B0); only its state
// fields are touched here, because 0x6C38D0 inlines the four stores instead of
// calling the 0x006C17B0 body. The field WIDTHS below are target facts, read
// off the stores themselves: +0x684, +0x68C and +0x694 take a DWORD while
// +0x688 takes a BYTE, so the field at +4 is a byte and not the int the rowed
// Rva006C17B0.cpp view happens to carry.
class Rva006C17B0
{
public:
	void rva006C17B0(bool flag1, bool flag2);

	void *m_array;			// +0x00
	unsigned char m_pad4;		// +0x04
	unsigned char m_pad5[3];
	unsigned int m_count;		// +0x08
	int m_padC;			// +0x0C, untouched by 0x006C38D0
	int m_10;			// +0x10
};

// Rva006C1F60 is itself a GeneralAllocator: memory_pool.cpp proves +0x448 as
// that class's list sentinel and +0x4E4 as its Lock*, and 0x00033D50 reads both
// through `this`. Only the malloc-shaped member is needed here, so this view
// carries no fields and the base stays empty; 0x00035080 is already pinned
// under the GeneralAllocator name and the call below must mangle to it.
namespace EA
{
namespace Allocator
{
class GeneralAllocator
{
public:
	void *rva00035080(unsigned int size, int flags);
};
}
}

class Rva006C1F60 : public EA::Allocator::GeneralAllocator
{
public:
	bool rva006C38D0();
	void *rva006C3940(unsigned int len);

	// Address-derived members, pinned at 0x00033D50 and 0x00033ED0.
	bool rva00033D50();
	void *rva00033ED0(unsigned int size, int flags);

	void rva006C33D0(int a, int b);

private:
	unsigned char m_pad0[0x478];
	int m_478;
	unsigned char m_pad1[0x4E4 - 0x478 - 4];
	Rva00030DD0Lock *m_lock;
	unsigned char m_pad2[0x510 - 0x4E4 - 4];
	unsigned char m_510;
	unsigned char m_pad3[0x548 - 0x510 - 1];
	char *m_548;
	char *m_54C;
	char *m_550;
	char *m_554;
	unsigned char m_pad4[0x678 - 0x554 - 4];
	Rva006C1F60 *m_678;
	unsigned char m_pad5[0x684 - 0x678 - 4];
	Rva006C17B0 m_684;
};

bool Rva006C1F60::rva006C38D0()
{
	rva006C33D0(0, 0);
	bool result = rva00033D50();
	m_510 = 0;
	if (m_678 == this)
	{
		m_684.m_array = 0;
		m_684.m_pad4 = 0;
		m_684.m_count = 0;
		m_684.m_10 = 0;
	}
	else
	{
		m_684.rva006C17B0(true, true);
	}
	return result;
}

// ?rva006C3940@Rva006C1F60@@QAEPAXI@Z present-unmatched
void *Rva006C1F60::rva006C3940(unsigned int len)
{
	if (m_678 != this)
		return m_678->rva00035080(len, 0);

	int saved = m_478;
	m_478 = 0;
	void *block = 0;
	do
	{
		block = rva00033ED0(len + 2, 0x80000000);
		if (block != 0)
			break;
		if (m_554 == m_548)
			break;
		rva006C33D0(0, 0);
	} while (true);
	if (block != 0)
	{
		char *const chunk = reinterpret_cast<char *>(block);
		unsigned int header = *reinterpret_cast<unsigned int *>(chunk - 4);
		unsigned int fencepost;
		if (header & 2)
			fencepost = header & 0x7FFFFFF8u;
		else
			fencepost = (header & 0x7FFFFFF8u) + 4;
		*reinterpret_cast<unsigned short *>(chunk + fencepost - 0xA) = 0;
		header |= 4;
		*reinterpret_cast<unsigned int *>(chunk - 4) = header;
	}
	m_478 = saved;
	return block;
}