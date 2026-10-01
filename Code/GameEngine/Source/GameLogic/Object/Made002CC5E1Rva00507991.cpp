// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /DNDEBUG /arch:SSE
//
// ?rva00507991@Made002CC5E1@@QAEX... retail 0x00507991 94B slot 5 of 0x00864048
// (Made002CC5E1) and 0x00864C38 (Made002CCA37 inherits). Float at +0x130 vs
// BfmeZeroRange (?BfmeZeroRange@@3MB): if !=0 call slot1 bool check then slot14
// with (a b 0); if >0 call slot6 with (a b+0x38). Base size 0x128 from ctor
// 0x00507C2D (m_128 at +0x128 m_12C +0x12C m_130 +0x130). ret 8 = 2 args.
extern const float BfmeZeroRange;

class Made002CC5E1
{
public:
	virtual ~Made002CC5E1();
	virtual bool v1(void *a, void *b);
	virtual void pad02();
	virtual void pad03();
	virtual void pad04();
	virtual void rva00507991(void *a, void *b);
	virtual void v6(void *a, void *b);
	virtual void pad07();
	virtual void pad08();
	virtual void pad09();
	virtual void pad10();
	virtual void pad11();
	virtual void pad12();
	virtual void pad13();
	virtual void v14(void *a, void *b, int c);
private:
	char m_pad04[0x128 - 4];
	float m_128;
	float m_12C;
	float m_130;
};

void Made002CC5E1::rva00507991(void *a, void *b)
{
	if (m_130 == BfmeZeroRange) {
		if (v1(a, b)) {
			v14(a, b, 0);
		}
	}
	if (m_130 > BfmeZeroRange) {
		v6(a, (char *)b + 0x38);
	}
}
