// ?Rva003014D6Less@@YG_NPAVMapMetaData@@0@Z
// partial score=0.94 date=2026-09-29
// ?Rva003014D6Less@@YG_NPAVMapMetaData@@0@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva003014D6Less@@YG_NPAVMapMetaData@@0@Z, retail 0x003014D6, 94 bytes.
// MapMetaData name-less comparator: returns a->rva00300D0E() < b->rva00300D0E()
// via UnicodeString compareNoCase. Evidence: EH_prolog with funclet; two calls
// to row ?rva00300D0E@MapMetaData@@QAE?AVUnicodeString@@XZ; row
// ?compareNoCase@?$StringBase@G@@QBEHABV1@@Z with setl; two row
// ?releaseBuffer@?$StringBase@G@@AAEXXZ dtors; ret 8 (__stdcall two pointers);
// 12 callers needing a sort predicate; chain via 0x00300D0E.
typedef unsigned short WideChar;

template <typename T> class StringBase
{
public:
	int compareNoCase(const StringBase<T> &other) const throw();
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};

class UnicodeString : public StringBase<WideChar>
{
public:
	UnicodeString() {}
	~UnicodeString() {}
};

class MapMetaData
{
public:
	UnicodeString rva00300D0E();
};

// ?Rva003014D6Less@@YG_NPAVMapMetaData@@0@Z present-unmatched
bool __stdcall Rva003014D6Less(MapMetaData *a, MapMetaData *b)
{
	UnicodeString tmpB = b->rva00300D0E();
	UnicodeString tmpA = a->rva00300D0E();
	return ((const StringBase<WideChar> &)tmpA).compareNoCase((const StringBase<WideChar> &)tmpB) < 0;
}
