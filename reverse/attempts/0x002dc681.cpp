// ?rva002DC681@Rva002DC267@@QBE_NXZ
// partial score=0.99 date=2026-10-01
// cl: /O1 /EHsc
// ?rva002DC681@Rva002DC267@@QBE_NXZ, retail 0x002DC681, 201 bytes.
// Save-dir disk-space check via rva002DC267 + GetDiskFreeSpaceExW; private
// StringBase/UnicodeString kept (not shared header) because retail str()
// uses UnicodeString TheNullChr at 0x00BBB5C4 (?TheNullChr@?1??str@UnicodeString).
typedef int Int;
typedef unsigned short WideChar;
#define NULL 0
template <typename T>
class StringBase
{
	friend class UnicodeString;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	bool isEmpty() const throw();
	void set(const StringBase<T> &other);
protected:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};
class UnicodeString : public StringBase<WideChar>
{
public:
	UnicodeString() {}
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	__forceinline UnicodeString(const WideChar *s) : StringBase<WideChar>(s) {}
	__forceinline ~UnicodeString() { releaseBuffer(); }
	const WideChar *str() const
	{
		static const WideChar TheNullChr = 0;
		return m_data ? &m_data->data[0] : &TheNullChr;
	}
};
class Rva002DC267
{
public:
	UnicodeString rva002DC267() const;
	bool rva002DC681() const;
};
extern const WideChar g_00C03F94[];
extern "C" __declspec(dllimport) Int __stdcall GetDiskFreeSpaceExW(
	const WideChar *dir, void *freeAvail, void *totalBytes, void *totalFree);
// ?rva002DC681@Rva002DC267@@QBE_NXZ present-unmatched
bool Rva002DC267::rva002DC681() const
{
	UnicodeString path(g_00C03F94);
	bool has = !rva002DC267().isEmpty();
	if (has) {
		path.set(rva002DC267());
	}
	unsigned long long freeBytes = 0;
	bool ok;
	if (GetDiskFreeSpaceExW(path.str(), &freeBytes, 0, 0) != 0) {
		if (freeBytes >= 0xF00000)
			ok = true;
		else
			ok = false;
	} else {
		ok = true;
	}
	return ok;
}
