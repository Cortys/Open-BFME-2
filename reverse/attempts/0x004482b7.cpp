// ?rva004482B7@Rva004482B7@@QAEPAXPAV?$StringBase@G@@H@Z
// partial score=0.9 date=2026-09-29
// ?rva004482B7@Rva004482B7@@QAEPAXPAV?$StringBase@G@@H@Z
// partial score=0.9 date=2026-09-29
// cl: /O1 /MD
//
// ?rva004482B7@Rva004482B7@@QAEPAXPAV?$StringBase@G@@H@Z @0x004482B7 40B.
// Indexed record-name copy: copy-construct a StringBase<wchar> at out from
// m_items[index].m_name (records 0x1D0 wide at +0x10C) via rowed copy ctor
// 0x00037050, return out. Evidence: unlock lane; stride matches 0x1D0 record
// family; callers at 0x004482AB 0x0044AF50 0x0044B076 0x0044B0CE; neighbours.
template <typename T> class StringBase
{
	friend class Rva004482B7;

	StringBase(const StringBase &that);
	T *m_data;
};

struct Rva004482B7Elem
{
	StringBase<unsigned short> m_name;
	char m_rest[0x1CC];
};

class Rva004482B7
{
	char m_pad[0x10C];
	Rva004482B7Elem m_items[8];

public:
	void *rva004482B7(StringBase<unsigned short> *out, int index);
};

// ?rva004482B7@Rva004482B7@@QAEPAXPAV?$StringBase@G@@H@Z present-unmatched
void *Rva004482B7::rva004482B7(StringBase<unsigned short> *out, int index)
{
	// Retail zeroes its frame slot with `and [ebp-4],0`; a plain local is lost
	// to dead-store elimination, so this pins the slot and its EBP frame.
	volatile bool unused = false;
	out->StringBase<unsigned short>::StringBase<unsigned short>(m_items[index].m_name);
	return out;
}
