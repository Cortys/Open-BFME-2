// ?rva001D9867@Rva001D9867@@QAEHXZ
// partial score=0.99 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
//
// ?rva001D9867@Rva001D9867@@QAEHXZ, retail 0x001D9867, 86 bytes.
// Unlock lane: landing it readies 0x000520F4 and 0x0005910F.
// Cached selector: +0xB4 holds the cached value (-1 = dirty); a flag bit
// at +0x48 forces 1, otherwise +0xB0 maps {0->2, 1->1, 2->0, 3->3,
// default 0}. The owner class is unproven (callers unclaimed), hence the
// honest Rva address name. All callees are none (leaf).
class Rva001D9867
{
	char m_pad0[0x48];
	unsigned char m_48;
	char m_pad49[0x67];
	int m_b0;
	int m_b4;
public:
	int rva001D9867();
};

// ?rva001D9867@Rva001D9867@@QAEHXZ present-unmatched
int Rva001D9867::rva001D9867()
{
	if (m_b4 == -1) {
		if (m_48 & 0x10)
			m_b4 = 1;
		else switch (m_b0) {
		case 0: m_b4 = 2; break;
		case 1: m_b4 = 1; break;
		case 2: m_b4 = 0; break;
		case 3: m_b4 = 3; break;
		default: m_b4 = 0; break;
		}
	}
	return m_b4;
}
