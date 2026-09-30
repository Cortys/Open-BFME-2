// cl: /O1 /EHs /DNDEBUG /MD
// ??1Rva0026AF86@@UAE@XZ retail 0x0026AF86 75B: dtor freeing +0x10 then +4 via rowed free then restoring Snapshot vtable BBB554.
// Evidence: EH_prolog scopetable plus push ecx push esi mov esi ecx with state 1 free +0x10 then state 0 free +4 then mov [esi] g_00BBB554; caller 0x0026AF6A deleting dtor with operator delete.
extern "C" void __cdecl free(void *block);
extern const void *const g_00BBB554[];
class Xfer;
class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer);
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};
inline Snapshot::~Snapshot()
{
	*(const void **)this = g_00BBB554;
}
class AsciiString
{
public:
	~AsciiString()
	{
		if (m_data != 0)
			free(m_data);
	}
private:
	void *m_data;
};
class __declspec(novtable) Rva0026AF86 : public Snapshot
{
public:
	virtual ~Rva0026AF86();
private:
	AsciiString m_04;
	char m_pad08[8];
	AsciiString m_10;
};
Rva0026AF86::~Rva0026AF86()
{
}
