// cl: /O1 /MD
//
// ?rva0033AC7F@Rva0033AC7F@@QAE_NAAV?$StringBase@G@@@Z @0x0033AC7F 35B
// Guarded wide-string getter: returns false when the member at +0x48 is
// empty, else copies it into the out-param via the pinned
// ?set@?$StringBase@G@@QAEXABV1@@Z and returns true. Evidence: rowed
// ?isEmpty@?$StringBase@G@@QBE_NXZ call plus pinned set call, single caller
// at 0x0040681B. Owning class unproven, hence honest Rva names.

template <typename T>
class StringBase
{
public:
	bool isEmpty() const;
	void set(const StringBase &src);
};

class Rva0033AC7F
{
public:
	bool rva0033AC7F(StringBase<unsigned short> &dst);

private:
	unsigned char m_pad[0x48];
	StringBase<unsigned short> m_str;
};

bool Rva0033AC7F::rva0033AC7F(StringBase<unsigned short> &dst)
{
	if (!m_str.isEmpty()) {
		dst.set(m_str);
		return true;
	}
	return false;
}
