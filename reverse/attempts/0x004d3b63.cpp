// ?rva004D3B63@DisconnectManager@@QAEIXZ
// partial score=0.96 date=2026-10-03
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /O1
// ?rva004D3B63@DisconnectManager@@QAEIXZ 0x004D3B63 27 max of 8 uints at +0x230
// Evidence: between 0x004D3AB2 and 0x004D3CA8; caller 0x004D3D76 passes same this; cmova unsigned max loop.

class DisconnectManager
{
public:
	unsigned int rva004D3B63(void);
private:
	char m_pad[0x230];
	unsigned int m_vals[8];
};

// ?rva004D3B63@DisconnectManager@@QAEIXZ present-unmatched
unsigned int DisconnectManager::rva004D3B63(void)
{
	unsigned int m = 0;
	unsigned int *p = m_vals;
	int n = 8;
	do
	{
		if (*p > m)
			m = *p;
		++p;
	}
	while (--n != 0);
	return m;
}
