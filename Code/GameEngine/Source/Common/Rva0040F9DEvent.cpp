// cl: /O1 /MD
// ?set@Rva0040F9D@@QAE_NXZ at 0x00040F9D (24B).
// Honest address-derived class: vptr at +0 and event handle at +4 match the
// base-dtor layout at 0x00040EDB (CloseHandle on +4). IAT SetEvent slot
// 0x00BBA2CC with neg/sbb/neg bool normalization. 8 callers incl 0x0010EC93.
extern "C" __declspec(dllimport) int __stdcall SetEvent(void *eventHandle);

class Rva0040F9D
{
public:
	virtual ~Rva0040F9D();
	bool set();
private:
	void *m_handle;
};

bool Rva0040F9D::set()
{
	if (m_handle != 0)
		return SetEvent(m_handle) != 0;
	return false;
}
