// ?rva003B70CA@Rva003B573E@@QAEXXZ
// partial score=0.91 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <vector>
#include "ascii_string.h"

// ?rva003B66D8@Rva003B573E@@QAEXH@Z @0x003B66D8 (131B): remove record at index
// from the 0x14-stride ScriptList subrecord. Same object as the rowed search
// 0x003B573E (thiscall on same this): dec references at +0xE, mark released
// at +0xC, return while nodes at +0x10 remain; else locate sorted position via
// search, unlink prev/next with tail at +0x1C, push to free list at +0x18,
// release the name buffer, erase the sorted entry. Evidence: chain from
// 0x003B573E, record shape from Rva003B675BRecord, subrecord layout of two
// vectors plus two ints from ScriptListSubrecordCtor.

struct Rva003B675BRecord
{
	int m_previous; // +0x00
	int m_next; // +0x04
	AsciiString m_name; // +0x08
	unsigned char m_released; // +0x0C
	unsigned char m_pad; // +0x0D
	unsigned short m_references; // +0x0E
	void *m_nodes; // +0x10
};

void __cdecl operator delete(void *block);

class BfmeNodeZ
{
public:
	~BfmeNodeZ();
	BfmeNodeZ *m_next;
};

class Rva003B448C
{
public:
	~Rva003B448C();
	Rva003B448C *m_next;
};

class Rva003B573E
{
public:
	int rva003B573E(const StringBase<char> &key);
	int rva003B6633(const StringBase<char> &key);
	void rva003B66D8(int index);
	void rva003B7096(int index);
	void rva003B70CA();
	void rva003B71B4(int index);
private:
	_STL::vector<void *> m_sorted; // +0x00
	_STL::vector<Rva003B675BRecord> m_records; // +0x0C
	int m_freeHead; // +0x18
	int m_tail; // +0x1C
};

void Rva003B573E::rva003B66D8(int index)
{
	Rva003B675BRecord *rec = &m_records[index];
	--rec->m_references;
	rec->m_released = 1;
	if (rec->m_nodes != 0)
		return;
	int pos = rva003B573E(*(const StringBase<char> *)&rec->m_name);
	if (rec->m_previous != -1)
		m_records[rec->m_previous].m_next = rec->m_next;
	if (rec->m_next != -1)
		m_records[rec->m_next].m_previous = rec->m_previous;
	else
		m_tail = rec->m_previous;
	rec->m_previous = m_freeHead;
	m_freeHead = index;
	rec->m_name.~AsciiString();
	m_sorted.erase(m_sorted.begin() + pos);
}

int Rva003B573E::rva003B6633(const StringBase<char> &key)
{
	int pos = rva003B573E(key);
	if ((unsigned int)pos < m_sorted.size()) {
		int idx = (int)m_sorted[pos];
		if ((*(const StringBase<char> *)&m_records[idx].m_name).compare(key) == 0)
			return idx;
	}
	return -1;
}

void Rva003B573E::rva003B71B4(int index)
{
	Rva003B675BRecord *rec = &m_records[index];
	BfmeNodeZ *nd = (BfmeNodeZ *)rec->m_nodes;
	rec->m_nodes = nd->m_next;
	delete nd;
	rva003B66D8(index);
}

// ?rva003B7096@Rva003B573E@@QAEXH@Z @0x003B7096 (52B): pop head node with the
// rowed Rva003B448C dtor then remove the record via rowed rva003B66D8. Twin of
// rowed rva003B71B4 which uses the pinned BfmeNodeZ dtor. Evidence: chain from
// 0x003B66D8, same 0x14-stride unlink plus delete plus tail remove shape,
// callers at 0x003B70F8 and 0x003B77F8.
void Rva003B573E::rva003B7096(int index)
{
	Rva003B675BRecord *rec = &m_records[index];
	Rva003B448C *nd = (Rva003B448C *)rec->m_nodes;
	rec->m_nodes = nd->m_next;
	delete nd;
	rva003B66D8(index);
}

// ?rva003B70CA@Rva003B573E@@QAEXXZ @0x003B70CA (116B): walk from m_tail via
// m_previous, releasing records with rowed rva003B7096 else draining nodes
// after the head with the rowed Rva003B448C dtor and setting references to 1.
// Evidence: chain from just-landed 0x003B7096, same 0x14 stride and +0x1C tail.
// ?rva003B70CA@Rva003B573E@@QAEXXZ present-unmatched
void Rva003B573E::rva003B70CA()
{
	int i = m_tail;
	while (i != -1) {
		Rva003B675BRecord &rec = m_records[i];
		int prev = rec.m_previous;
		if (rec.m_released) {
			rva003B7096(i);
		} else {
			Rva003B448C *head = (Rva003B448C *)rec.m_nodes;
			while (head->m_next != 0) {
				Rva003B448C *nd = head->m_next;
				Rva003B448C *next = nd->m_next;
				delete nd;
				head->m_next = next;
			}
			rec.m_references = 1;
		}
		i = prev;
	}
}
