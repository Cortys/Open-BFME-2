// ?rva0035B570@Rva0035B570@@QAEXXZ
// partial score=0.95 date=2026-09-29
// ?rva0035B570@Rva0035B570@@QAEXXZ
// partial score=0.95 date=2026-09-29
// ?rva0035B570@Rva0035B570@@QAEXXZ @0x0035B570 82B
// Locomotor OVERRIDE at +0x20: null check, word +0x5D8 vs global, AsciiString +0x64
// via Rva002D06CA store, tail dup_001e35df on [eax+4].
// Evidence: OVERRIDE operator-> 0x0035C95F x4, rva002D06CA 0x002D06CA, dup 0x001E35DF,
// ret void no args, unblocks 9, 40+ callers.
class AsciiString
{
	char *m_text;
};

class LocomotorTemplate
{
public:
	unsigned char m_pad0[4];
	void *m_unk04;
	unsigned char m_pad08[0x64 - 8];
	AsciiString m_unk64;
	unsigned char m_pad68[0x5D8 - (0x64 + 4)];
	unsigned short m_unk5D8;
};

template <typename T>
class OVERRIDE
{
public:
	const T *operator->() const;
};

class Rva002D06CA
{
public:
	void *rva002D06CA(const AsciiString *key);
};

void dup_001e35df();

extern unsigned short g_locoWord;
extern Rva002D06CA *g_locoStore;

class Rva0035B570
{
public:
	void rva0035B570();
private:
	unsigned char m_pad[0x20];
	OVERRIDE<LocomotorTemplate> m_override;
};

// ?rva0035B570@Rva0035B570@@QAEXXZ present-unmatched
void Rva0035B570::rva0035B570()
{
	if (m_override.operator->() == 0)
	{
		return;
	}
	else
	{
		const LocomotorTemplate *loco = m_override.operator->();
		unsigned short v = *(unsigned short *)((char *)loco + 0x5D8);
		if (v >= g_locoWord)
		{
			const LocomotorTemplate *loco3 = m_override.operator->();
			Rva002D06CA *store = g_locoStore;
			const AsciiString *key = (const AsciiString *)((char *)loco3 + 0x64);
			void *ret = store->rva002D06CA(key);
			void *p = *(void **)((char *)ret + 4);
			if (p == 0)
				return;
			dup_001e35df();
			return;
		}
		else
		{
			const LocomotorTemplate *loco2 = m_override.operator->();
			void *p = *(void **)((char *)loco2 + 4);
			if (p == 0)
				return;
			dup_001e35df();
			return;
		}
	}
}
