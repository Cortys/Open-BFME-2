// ?rva006D0A30@Rva006D0A30@@QAEXPAPAUPayload@@ABURva008B4260StringRef@@@Z
// partial score=0.93 date=2026-09-29
// ?rva006D0A30@Rva006D0A30@@QAEXPAPAUPayload@@ABURva008B4260StringRef@@@Z
// partial score=0.93 date=2026-09-29
// ?rva006D0A30@Rva006D0A30@@QAEXPAPAUPayload@@ABURva008B4260StringRef@@@Z
// partial score=0.93 date=2026-09-29
//
// ?rva006D0A30@Rva006D0A30@@QAEXPAPAUPayload@@ABURva008B4260StringRef@@@Z @0x006D0A30 82B
// Find interned payload by StringRef: walks the +0/+4 list comparing the
// StringRef at payload+8 via rowed 0x006D36C0, stores the payload (or null)
// through the out-param and bumps its +0 refcount on success. Evidence:
// unlock lane, callers at 0x006D0ABA/0x006D0B6E/0x006D0D9A/0x006D0E20.
// Owning class unproven.

struct Rva008B4260StringRef
{
	const char *m_payload;
	int compare008B4260(const Rva008B4260StringRef &other) const;
};

struct Payload
{
	int m_refcount;
	char m_pad04[4];
	const char *m_buffer;
};

struct Node
{
	Payload *m_payload;
	Node *m_next;
};

class Rva006D0A30
{
public:
	void rva006D0A30(Payload **out, const Rva008B4260StringRef &key);

private:
	Node *m_head;
};

// ?rva006D0A30@Rva006D0A30@@QAEXPAPAUPayload@@ABURva008B4260StringRef@@@Z present-unmatched
void Rva006D0A30::rva006D0A30(Payload **out, const Rva008B4260StringRef &key)
{
	volatile int unused = 0;
	Node *cur = m_head;
	if (cur == 0)
		goto fail;
loop:
	{
		const Rva008B4260StringRef *curRef = (const Rva008B4260StringRef *)((const char *)cur->m_payload + 8);
		if (curRef->compare008B4260(key) == 0)
			goto found;
		cur = cur->m_next;
		if (cur != 0)
			goto loop;
	}
fail:
	*out = 0;
	return;
found:
	{
		Payload *hit = cur->m_payload;
		*out = hit;
		if (hit != 0)
			++hit->m_refcount;
	}
}
