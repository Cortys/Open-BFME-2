// ?Rva005E6CA1Get@@YAPAURva005E6CA1Out@@PAU1@PAURva005E6CA1Obj@@@Z
// partial score=0.96 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHs-c-
// ?Rva005E6CA1Get@@YAPAVRva005E6CA1Out@@PAV1@PAVRva005E6CA1Obj@@@Z, retail 0x005E6CA1, 108 bytes. Linear search of indexed field via rowed gets 0x0040CB2C/0x0040CC0E and StringBase compare 0x000069D6. Called from 0x005E6DFA. Neighbours share /O1.
#include "ascii_string.h"
class Rva0040CB2CIndexedField
{
public:
	int get(int index) const;
	char m_pad[0x40];
	char *m_begin;
	char *m_end;
};
class Rva0040CC0EIndexedField
{
public:
	int get(int index) const;
	char m_pad[0x40];
	char *m_begin;
	char *m_end;
};
struct Rva005E6CA1Node
{
	int m_00;
	StringBase<char> m_str04;
};
struct Rva005E6CA1Out
{
	int m_first;
	int m_second;
};
struct Rva005E6CA1Obj
{
	char m_pad00[0x18];
	StringBase<char> m_key18;
	char m_pad1C[0x5C];
	Rva0040CB2CIndexedField *m_78;
};
Rva005E6CA1Out *__cdecl Rva005E6CA1Get(Rva005E6CA1Out *out, Rva005E6CA1Obj *obj)
{
	Rva0040CB2CIndexedField *f = obj->m_78;
	int idx = 0;
	int cnt = (int)(f->m_end - f->m_begin) >> 3;
	if (cnt <= 0)
		goto empty;
	{
		StringBase<char> *key = &obj->m_key18;
		do {
			int secondVal = f->get(idx);
			Rva005E6CA1Node *node = (Rva005E6CA1Node *)secondVal;
			if (node->m_str04.compare(*key) == 0) {
				int firstVal = ((Rva0040CC0EIndexedField *)f)->get(idx);
				out->m_first = firstVal;
				out->m_second = secondVal;
				return out;
			}
			++idx;
		} while (idx < cnt);
	}
empty:
	out->m_first = 0;
	out->m_second = 0;
	return out;
}
