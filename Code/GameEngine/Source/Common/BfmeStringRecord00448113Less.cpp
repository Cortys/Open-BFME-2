// cl: /O1 /DNDEBUG /MD

// ??M@YA_NABUBfmeStringRecord00448113@@0@Z @ 0x00448D3C (23B). Free operator< for
// BfmeStringRecord00448113 (two UnicodeStrings from StringRecordInlineCopyBFME2.cpp).
// Leaf over matched StringBase<ushort>::compare at 0x6A7A. Called by tree bodies
// 0x48D65 0x48DCB 0x48E64. Same shape as AsciiStringLess at 0x5598C.

typedef bool Bool;

template <typename T> class StringBase
{
public:
    int compare(const StringBase<T> &that) const;

private:
    void *m_data;
};

class UnicodeString : public StringBase<unsigned short>
{
};

struct BfmeStringRecord00448113
{
    UnicodeString text0;
    UnicodeString text1;
};

Bool operator<(const BfmeStringRecord00448113 &left, const BfmeStringRecord00448113 &right)
{
    return (left.text0.compare(right.text0) < 0) || false;
}
