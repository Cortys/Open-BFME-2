// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva00109C27@@QAE@PBD@Z @0x00109C27 60B
// Ctor over empty base for EH state 0 before StringClass member at +8;
// vtable 0x00BCFA0C at +0 and null at +4; caller at 0x00109CDC.
class StringClass
{
public:
	StringClass(const char *name, bool flag);
private:
	char *m_Buffer;
};
class Base4
{
public:
	Base4() : m_4(0) {}
	~Base4();
	void *m_4;
};
class Rva00109C27 : public Base4
{
public:
	Rva00109C27(const char *src);
// ??1Rva00109C27@@UAE@XZ present-unmatched
	virtual ~Rva00109C27() {}
private:
	StringClass m_str;
};
Rva00109C27::Rva00109C27(const char *src)
	: Base4()
	, m_str(src, false)
{
}
