// ?rva0039BF0B@Rva0039BF0B@@QAEHABV?$BitFlags@$0HE@@@0@Z
// partial score=0.91 date=2026-10-03
// cl: /O2 /DNDEBUG /MD /EHsc
template <int N> class BitFlags
{ public: bool testSetAndClear(const BitFlags &a, const BitFlags &b) const; private: unsigned m_words[7]; };
struct ObjectCountMap { void *m_header; int m_pad04; int m_pad08; };
int __stdcall Rva0039BEC3Count(const BitFlags<116> &a, const BitFlags<116> &b, const ObjectCountMap *map);
class Rva0039BF0B { public: int rva0039BF0B(const BitFlags<116> &a, const BitFlags<116> &b);
private: char m_pad[0x1F0]; ObjectCountMap m_map; };
int Rva0039BF0B::rva0039BF0B(const BitFlags<116> &a, const BitFlags<116> &b)
{ const ObjectCountMap *p = &m_map; return Rva0039BEC3Count(a, b, p); }
