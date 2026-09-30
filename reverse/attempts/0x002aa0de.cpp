// ?rva002AA0DE@Rva002AA0DE@@QAE_NPAVThing@@@Z
// partial score=0.93 date=2026-09-30
// ?rva002AA0DE@Rva002AA0DE@@QAE_NPAVThing@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD
// ?rva002AA0DE@Rva002AA0DE@@QAE_NPAVThing@@@Z @0x002AA0DE (69B)
// Checks m_b8 and arg then dual isAnyKindOf with second inverted.
// Ret 4. Evidence unlock lane plus rowed isAnyKindOf plus caller.
template <int N> class BitFlags {};
class Thing { public: bool isAnyKindOf(const BitFlags<69> &mask) const; };
struct Inner002AA0DE {
	char m_pad[0x14];
	char m_14raw[0x1c];
	char m_30raw[0x20];
};
class Rva002AA0DE
{
public:
	bool rva002AA0DE(Thing *arg);
private:
	char m_pad[0xb8];
	Inner002AA0DE *m_b8;
};
// ?rva002AA0DE@Rva002AA0DE@@QAE_NPAVThing@@@Z present-unmatched
bool Rva002AA0DE::rva002AA0DE(Thing *arg)
{
	unsigned char second;
	if (!m_b8 || !arg)
		return false;
	if (!arg->isAnyKindOf(*(const BitFlags<69> *)&m_b8->m_14raw))
		return false;
	second = arg->isAnyKindOf(*(const BitFlags<69> *)&m_b8->m_30raw);
	if (second)
		return false;
	return true;
}
