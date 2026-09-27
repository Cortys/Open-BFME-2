// cl: /GX-
// ?rva000309B0@Rva000309B0@@QAEXXZ @ 0x000309B0 21B
// TLS heap-id setter: if the TLS index at 0x00DB35A4 is not -1, stores this
// object's +0x00 pointer into that TLS slot via TlsSetValue. Evidence: IAT
// TlsSetValue at 0x00BBA198, TLS index 0x00DB35A4 holding the calling
// thread's heap id, callers at 0x0062265B 0x0062214F load ecx then call.
// Honest address-derived name: owner unproven. No STL.
extern unsigned long g_Va00DB35A4;
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long index, void *value);

class Rva000309B0
{
public:
	void rva000309B0();
private:
	void *m_value;
};

void Rva000309B0::rva000309B0()
{
	unsigned long index = g_Va00DB35A4;
	if (index != (unsigned long)-1)
		TlsSetValue(index, m_value);
}
