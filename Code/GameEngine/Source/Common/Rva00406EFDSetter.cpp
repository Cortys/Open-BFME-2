// cl: /O1 /MD
// ?rva00406EFD@Rva00406EFD@@QAE_NH@Z @0x00406EFD 21B: conditional setter comparing stack arg with +0x10 and setting bit 2 at +0x38. Caller 0x00407012 passes 0. Owner unknown so honest-address name.
class Rva00406EFD
{
	int m_00[4];
	int m_10;
	int m_14[9];
	int m_38;
public:
	bool rva00406EFD(int v);
};
bool Rva00406EFD::rva00406EFD(int v)
{
	if (v != m_10) {
		m_38 |= 2;
		m_10 = v;
	}
	return true;
}
