// cl: /O1 /DNDEBUG /MD
// ??0Rva00332FC1@@QAE@ABVBfmeObject872Header@@0@Z @0x00332FC1 38B
// retail 0x00332FC1 38 bytes chain ctor UnicodeString at +0 plus two BfmeObject872Header at +4 and +0x14
// via rowed UnicodeString default 0x00326BE6 and rowed BfmeObject872Header copy 0x002CF108 caller 0x00336FDF
// sibling of Rva00332F5B same shape different members and offsets

class UnicodeString
{
public:
	UnicodeString();
private:
	void *m_text;
};

class BfmeObject872Header
{
public:
	BfmeObject872Header(const BfmeObject872Header &that);
private:
	char m_data[16];
};

class Rva00332FC1
{
public:
	Rva00332FC1(const BfmeObject872Header &a, const BfmeObject872Header &b);
private:
	UnicodeString m_uni;
	BfmeObject872Header m_a;
	BfmeObject872Header m_b;
};

Rva00332FC1::Rva00332FC1(const BfmeObject872Header &a, const BfmeObject872Header &b) : m_uni(), m_a(a), m_b(b)
{
}
