// ?rva0027900B@Rva0027900B@@QBE_NXZ
// partial score=0.99 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
// ?rva0027900B@Rva0027900B@@QBE_NXZ @0x0027900B 105B
// PlayerTemplateStore lookup: match +0x6C string via rowed StringBase compare against each template +0x18 then return +0x1BC flag.
// Evidence: caller 0x0027916A; callees rowed getNthPlayerTemplate 0x001FD3C6 compare 0x000069D6 plus ThePlayerTemplateStore; prev 0x00278689 Drawable.
#include "ascii_string.h"

class PlayerTemplate
{
public:
	char m_pad[0x18];
	AsciiString m_name18;
	char m_pad2[0x1BC - 0x18 - 4];
	bool m_flag1BC;
};

class PlayerTemplateStore
{
public:
	const PlayerTemplate *getNthPlayerTemplate(int i) const;
private:
	char m_pad[0xC];
public:
	int m_minC;
	int m_max10;
};

extern PlayerTemplateStore *ThePlayerTemplateStore;

struct BaseWithString
{
	char m_pad[0x6C];
	AsciiString m_str6C;
};

class Rva0027900B
{
public:
	bool rva0027900B() const;
private:
	char m_pad0[4];
	BaseWithString *m_p4;
};
// ?rva0027900B@Rva0027900B@@QBE_NXZ present-unmatched
bool Rva0027900B::rva0027900B() const
{
	BaseWithString *base = *(BaseWithString **)((char *)this + 4);
	const StringBase<char> *needle = 0;
	if (base != 0)
	{
		needle = (const StringBase<char> *)&base->m_str6C;
		for (int i = 0; i < (ThePlayerTemplateStore->m_max10 - ThePlayerTemplateStore->m_minC) / 0x1DC; ++i)
		{
			const PlayerTemplate *pt = ThePlayerTemplateStore->getNthPlayerTemplate(i);
			if (pt == 0)
				continue;
			if (needle->compare(*(const StringBase<char> *)&pt->m_name18) == 0)
				return pt->m_flag1BC;
		}
	}
	return false;
}
