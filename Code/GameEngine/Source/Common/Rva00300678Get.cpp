// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva00300678Get@@YAPAVAsciiString@@XZ, retail 0x00300678, 76 bytes.
// Function-local static AsciiString "lws" with guard plus
// _atexit dtor registration; returns its address. Evidence: EH_prolog with
// funclet; guard byte at VA 0x009FF160 with object at VA 0x009FF15C; ctor row
// ??0?$StringBase@D@@AAE@PBD@Z; _atexit row; two callers need its address;
// ret with caller cleanup.
template <typename T> class StringBase
{
public:
	StringBase(const char *s);
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *s) : StringBase<char>(s) {}
	~AsciiString() {}
};

AsciiString *__cdecl Rva00300678Get(void)
{
	static AsciiString s("lws");
	return &s;
}
