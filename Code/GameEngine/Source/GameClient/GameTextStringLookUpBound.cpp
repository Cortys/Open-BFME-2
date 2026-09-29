// cl: /O1 /DNDEBUG /DWIN32 /MD /D_STLP_USE_STATIC_LIB
// ?Rva002E5C15LowerBound@@YAPAUStringLookUp@@PAU1@0ABQBDURva002E5C15Comp@@H@Z 0x002E5C15 76B
// Evidence: chain from 0x002E56B3 Less; binary lower_bound over 8B StringLookUp array; callers 0x002E609E.

struct AsciiString
{
	void *m_data;
};

struct StringLookUp
{
	AsciiString *label;
	void *info;
};

struct Rva002E5C15Comp
{
	bool operator()(const StringLookUp *left, const char *right) const;
};

StringLookUp *__cdecl Rva002E5C15LowerBound(StringLookUp *first, StringLookUp *last, const char *const &val, Rva002E5C15Comp comp, int d2)
{
	int count = int(last - first);
	while (count > 0) {
		int half = count >> 1;
		StringLookUp *mid = first + half;
		if (comp(mid, val)) {
			first = mid + 1;
			count = count - half - 1;
		} else {
			count = half;
		}
	}
	return first;
}
