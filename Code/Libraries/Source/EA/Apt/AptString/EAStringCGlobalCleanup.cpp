// cl: /O2 /DNDEBUG /MD
// Target-only reconstruction. The names of the static strings are unknown.
// Ghidra proves the complete 10B boundary at 0x007B9C30. Its registered
// atexit callback (pushed at 0x007B676A) releases the EAStringC at VA
// 0x00E177D4 through the independently matched destructor 0x006D3010.
// The one-pointer value layout is shared with EAStringCRefCount.cpp.
class EAStringC
{
    class StringDataC;
    StringDataC *m_pData;
public:
    ~EAStringC();
};

extern EAStringC g_eaStringAtE177D4;
extern EAStringC g_eaStringAtE18060;

void rva007B9C30()
{
    g_eaStringAtE177D4.~EAStringC();
}

// Complete 10B Ghidra boundary; independently registered at 0x007B678A.
// The adjacent initializer calls EAStringC's default ctor on VA E18060,
// then registers this same object's destructor callback.
void rva007B9C40()
{
    g_eaStringAtE18060.~EAStringC();
}
