// cl: /O1 /MD
// ?rva006DE150@Rva006DE150@@QAEXXZ @0x006DE150 12B.
// Sets bit 3 of the flag word at +4 then tail-calls the rowed table clear
// ?handle@Gen0089C880@@QAEXXZ on the member at +8 (add ecx,8 plus jmp).
// Callers are three jmp thunks. No donor; retail-shaped.
class Gen0089C880
{
public:
	void handle();
};

class Rva006DE150
{
public:
	char m_pad[4];
	unsigned int m_flags;
	Gen0089C880 m_table;
	void rva006DE150();
};

void Rva006DE150::rva006DE150()
{
	m_flags |= 8;
	m_table.handle();
}
