// cl: /O1 /MD
// ?rva0010F110@Rva0010F110@@QAEXXZ @0x0010F110 12B.
// Infinite wait on the +0x18 handle via kernel32 WaitForSingleObject.
// Evidence: IAT WaitForSingleObject at 0x00BBA228, callers at 0x0010F11F
// and 0x000A8B73, push -1 (INFINITE) shape per /O1 recipe. Honest address
// name.
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void *handle, unsigned long timeout);

class Rva0010F110
{
public:
    void rva0010F110();
private:
    char m_pad0[0x18]; // +0..+0x17
    void *m_handle18; // +0x18
};

void Rva0010F110::rva0010F110()
{
    WaitForSingleObject(m_handle18, 0xFFFFFFFF);
}
