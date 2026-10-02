// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /GX
// ??1Rva0052CFB1@@UAE@XZ @0x0052CFB1 157B: dtor with AsciiStrings vectors and twin deletes via get plus Snapshot base BBB554.
// Evidence: vtable 0x00868780 at +0, releaseBuffer +0x04 +0x30 +0x34, vectors +0x0C +0x24 rowed, deletes +0x1C +0x20 via virtual get, base 0xBBB554, caller 0x0052D305, neighbours ConstIntGetters4 RvaVectorDtorFamily.
#include "ascii_string.h"
extern const void *const g_00BBB554[];
void __cdecl operator delete(void *);
struct RvaItem0052CFB1 { virtual void *get(int x); };
struct Rva0052CA2D { void *m_start; void *m_finish; void *m_end; ~Rva0052CA2D(); };
struct Rva0052CA6C { void *m_start; void *m_finish; void *m_end; ~Rva0052CA6C(); };
class Snapshot0052CFB1 {
public:
	virtual ~Snapshot0052CFB1();
};
// ??1Snapshot0052CFB1@@UAE@XZ present-unmatched
inline Snapshot0052CFB1::~Snapshot0052CFB1() { *(const void **)this = (const void *)g_00BBB554; }
class Rva0052CFB1 : public Snapshot0052CFB1 {
public:
	virtual ~Rva0052CFB1();
private:
	AsciiString m_04;
	int m_08;
	Rva0052CA2D m_0c;
	int m_18;
	RvaItem0052CFB1 *m_1c;
	RvaItem0052CFB1 *m_20;
	Rva0052CA6C m_24;
	AsciiString m_30;
	AsciiString m_34;
};
Rva0052CFB1::~Rva0052CFB1()
{
	delete (m_1c ? m_1c->get(0) : 0);
	delete (m_20 ? m_20->get(0) : 0);
}
