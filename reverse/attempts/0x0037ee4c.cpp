// ?rva0037EE4C@Rva0037EE4C@@QAEHPBURva0037EE4COuter@@HH@Z
// partial score=0.9 date=2026-09-29
?rva0037EE4C@Rva0037EE4C@@QAEHPBURva0037EE4COuter@@HH@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
//
// ?rva0037EE4C@Rva0037EE4C@@QAEHPAUOuter@@HH@Z @0x0037EE4C (109B).
// Record table find: linear scan of 0xD8-stride records between +4/+8
// comparing name at +0xD4 via rowed StringBase compare 0x000069D6
// against key name at +0x64. Returns index of the wanted match where
// filter -1 means Nth by count else field +0xA4 equality; -1 if none.
// Ten callers waiting. Same compare idiom as Rva003B573E precedent.
template <typename T>
class StringBase
{
public:
	int compare(const StringBase &other) const;
private:
	void *m_data;
};

struct Rva0037EE4COuter
{
	const StringBase<char> *getName() const { return (const StringBase<char> *)((const char *)this + 0x64); }
	char m_pad[0x64];
	StringBase<char> m_name;
};

struct Rva0037EE4CRec
{
	char m_pad[0xA4];
	int m_field;
	char m_mid[0xD4 - 0xA8];
	StringBase<char> m_name;
};

class Rva0037EE4C
{
public:
	int rva0037EE4C(const Rva0037EE4COuter *key, int filter, int wanted);
private:
	void *m_0;
	Rva0037EE4CRec *m_begin;
	Rva0037EE4CRec *m_end;
};

// ?rva0037EE4C@Rva0037EE4C@@QAEHPAUOuter@@HH@Z present-unmatched
int Rva0037EE4C::rva0037EE4C(const Rva0037EE4COuter *key, int filter, int wanted)
{
	const StringBase<char> *name = key->getName();
	int n = 0;
	int i = 0;
	for (Rva0037EE4CRec *r = m_begin; r != m_end; r = (Rva0037EE4CRec *)((char *)r + 0xD8), ++i, ++n) {
		if (r->m_name.compare(*name) == 0) {
			if ((filter == -1) ? (n == wanted) : (filter == r->m_field)) {
				return i;
			}
		}
	}
	return -1;
}
