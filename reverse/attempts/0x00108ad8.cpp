// ?rva00108AD8@Rva00108AD8@@QAEXXZ
// partial score=0.95 date=2026-09-29
// ?rva00108AD8@Rva00108AD8@@QAEXXZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /arch:SSE /EHsc /Ireference/shims/bfmecamera /DNDEBUG /MD /Ireference/open-bfme-1/Code/GameEngine/Source/Common
class HashTableClass;
class HashableClass
{
public:
	virtual ~HashableClass() {}
	virtual const char *Get_Key() = 0;
private:
	HashableClass *NextHash;
	friend class HashTableClass;
	friend class HashTableIteratorClass;
};
class HashTableIteratorClass
{
public:
	HashTableIteratorClass(HashTableClass &table) : Table(table) {}
	virtual ~HashTableIteratorClass() {}
	void First();
	void Next();
	bool Is_Done() { return CurrentEntry == 0; }
	HashableClass *Get_Current() { return CurrentEntry; }
private:
	const HashTableClass &Table;
	int Index;
	HashableClass *CurrentEntry;
	HashableClass *NextEntry;
	void Advance_Next();
};
class Base8
{
public:
	virtual ~Base8() {}
	int m_pad;
};
struct Rva00108AD8Entry : public Base8, public HashableClass
{
	const char *Get_Key() { return 0; }
	char m_pad2[0x24];
	float m_x;
	float m_y;
	float m_z;
};
class Rva00108AD8
{
public:
	HashTableClass *m_table;
	void rva00108AD8();
};
// ?rva00108AD8@Rva00108AD8@@QAEXXZ present-unmatched
void Rva00108AD8::rva00108AD8()
{
	HashTableIteratorClass iter(*m_table);
	for (iter.First(); !iter.Is_Done(); iter.Next()) {
		Rva00108AD8Entry *e = static_cast<Rva00108AD8Entry *>(iter.Get_Current());
		float *p = &e->m_x;
		p[0] = 0.0f;
		p[1] = 0.0f;
		p[2] = 0.0f;
	}
}
