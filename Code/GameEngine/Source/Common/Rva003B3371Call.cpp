// cl: /O1 /EHsc /MD
// ?Rva003B3371Call@@YAXH@Z @0x003B3371 81B. Free cdecl void(int): if global
// ScriptEngine at 0x009FE16C is set, builds AsciiString temp from table
// 0x009C1050[index] via pinned AsciiString(PBD) at 0x00037BA0, calls rowed
// ScriptEngine::rva00357DD2, destroys temp via releaseBuffer. Evidence:
// rowed StringBase ctor plus rowed rva00357DD2 plus releaseBuffer; 6 callers.
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	__forceinline ~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text);
	AsciiString(const AsciiString &other);
	~AsciiString();
};

class ScriptEngine
{
public:
	void rva00357DD2(const AsciiString &s);
};
extern ScriptEngine *G009FE16C;
extern const char *G009C1050[];

void __cdecl Rva003B3371Call(int index)
{
	if (G009FE16C == 0)
		return;
	AsciiString tmp(G009C1050[index]);
	G009FE16C->rva00357DD2(tmp);
}
