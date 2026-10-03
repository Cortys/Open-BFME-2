// ?rva005EA6A7@Rva005EA6A7@@QAEPAV1@PAUKeyHolder@@PAURange@@@Z
// partial score=0.98 date=2026-10-03
// cl: /O1 /MD /arch:SSE
// ?rva005EA6A7@Rva005EA6A7@@QAEPAV1@PAUKeyHolder@@PAURange@@@Z @0x005EA6A7 100B.
// Init from key holder plus element range: stores holder, finds index of holder key
// in 0x34-byte elements (key at +0x30), -1 when absent, zeroes the rest.
// Evidence: idiv 0x34 count, loop cmp [edx] vs [edi+0x14], callers 0x005EB619.
// ?rva005EA6A7@Rva005EA6A7@@QAEPAV1@PAUKeyHolder@@PAURange@@@Z present-unmatched
struct Elem
{
	char m_pad[0x30];
	int m_key;
};
struct Range
{
	Elem *m_begin;
	Elem *m_end;
};
struct KeyHolder
{
	char m_pad[0x14];
	int m_key;
};
class Rva005EA6A7
{
public:
	Rva005EA6A7 *rva005EA6A7(KeyHolder *holder, Range *range);
private:
	KeyHolder *m_holder;
	volatile int m_index;
	volatile float m_f8;
	volatile float m_fC;
	volatile float m_f10;
	volatile int m_14;
	volatile int m_18;
	volatile int m_1C;
	volatile int m_20;
};
Rva005EA6A7 *Rva005EA6A7::rva005EA6A7(KeyHolder *holder, Range *range)
{
	m_holder = holder;
	Elem *begin = range->m_begin;
	Elem *end = range->m_end;
	int count = end - begin;
	int i = 0;
	int result;
	if (count <= 0) {
		result = -1;
	} else {
		int key = holder->m_key;
		int *pk = &begin->m_key;
		do {
			if (*pk == key)
				goto found;
			++i;
			pk = (int *)((char *)pk + 0x34);
		} while (i < count);
		result = -1;
		goto store;
	found:
		result = i;
	store:;
	}
	m_index = result;
	m_14 = 0;
	m_18 = 0;
	m_1C = 0;
	m_f8 = 0.0f;
	m_fC = 0.0f;
	m_f10 = 0.0f;
	m_20 = 0;
	return this;
}
