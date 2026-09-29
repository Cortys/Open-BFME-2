// cl: /O1 /EHsc /MD
// ?Rva0021C8D7AdjustHeap@@YAXPAURva0021915B@@HHU1@URva0021B753@@@Z @0x0021C8D7 153B adjust-heap with rowed comparator assign pushheap.
// Evidence: unlock lane all callees rowed; stride 8 plus bool-first comparator plus pushheap caller prove Rva0021915B family; same adjust shape as STL __adjust_heap with EH for non-trivial value.
template <typename T> class StringBase {
	friend class AsciiString;
	StringBase(const StringBase &);
	__forceinline ~StringBase() { releaseBuffer(); }
	void releaseBuffer();
private:
	void *m_data;
};
class AsciiString : public StringBase<char> {
public:
	AsciiString(const AsciiString &other);
	AsciiString &operator=(const AsciiString &other);
	~AsciiString() { releaseBuffer(); }
};
class Rva0021915B {
public:
	Rva0021915B &operator=(const Rva0021915B &other);
	friend struct Rva0021B753;
private:
	AsciiString m_str;
	bool m_byte;
};
struct Rva0021B753 {
	bool operator()(const Rva0021915B &a, const Rva0021915B &b) const;
};
void __cdecl Rva0021BB61PushHeap(Rva0021915B *first, int holeIndex, int topIndex, Rva0021915B val, Rva0021B753 comp);
void __cdecl Rva0021C8D7AdjustHeap(Rva0021915B *first, int holeIndex, int len, Rva0021915B value, Rva0021B753 comp)
{
	int topIndex = holeIndex;
	int secondChild = 2 * holeIndex + 2;
	while (secondChild < len) {
		if (comp(*(first + secondChild), *(first + (secondChild - 1))))
			--secondChild;
		*(first + holeIndex) = *(first + secondChild);
		holeIndex = secondChild;
		secondChild = 2 * (secondChild + 1);
	}
	if (secondChild == len) {
		*(first + holeIndex) = *(first + (secondChild - 1));
		holeIndex = secondChild - 1;
	}
	Rva0021BB61PushHeap(first, holeIndex, topIndex, value, comp);
}
