// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva0030062CGet@@YAPAVAsciiString@@XZ, retail 0x0030062C, 76 bytes.
// Function-local static AsciiString "LivingWorldScripts" with guard plus
// _atexit dtor registration; returns its address. Evidence: EH_prolog with
// funclet; guard byte at VA 0x009FF158 with object at VA 0x009FF154; ctor row
// ??0?$StringBase@D@@AAE@PBD@Z; _atexit row; three callers need its address;
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

AsciiString *__cdecl Rva0030062CGet(void)
{
	static AsciiString s("LivingWorldScripts");
	return &s;
}
