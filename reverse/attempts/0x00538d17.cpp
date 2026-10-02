// ?rva00538D17@Rva00538D17@@QAE_NPAURva00538D17Out@@@Z
// partial score=0.92 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
//
// ?rva00538D17@Rva00538D17@@QAE_NPAURva00538D17Out@@@Z, retail 0x00538D17, 36 bytes.
// Vector-tail copy: begin at +0 and end at +4 of 16-byte records, last record
// fields +4/+8 to 8-byte out, false when empty. Evidence: callers 0x003190BB
// 0x003197B7 0x0031986B all check (end-begin)>>4 emptiness the same way then
// delegate with out param, fallback copies +0x44/+0x48; getWheelInfo row.

struct Rva00538D17Out
{
	int m00;
	int m04;
};

struct Rva00538D17Entry
{
	int m00;
	int m04;
	int m08;
	int m0C;
};

class Rva00538D17
{
public:
	bool rva00538D17(Rva00538D17Out *out);
private:
	Rva00538D17Entry *m_begin;
	Rva00538D17Entry *m_end;
};

// ?rva00538D17@Rva00538D17@@QAE_NPAURva00538D17Out@@@Z present-unmatched
bool Rva00538D17::rva00538D17(Rva00538D17Out *out)
{
	Rva00538D17Entry *end = m_end;
	if (end - m_begin != 0) {
		out->m00 = (end - 1)->m04;
		out->m04 = (end - 1)->m08;
		return true;
	}
	return false;
}
