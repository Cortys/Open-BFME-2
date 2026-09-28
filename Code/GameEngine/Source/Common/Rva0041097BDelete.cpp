// cl: /O1 /MD
//
// ?rva0041097B@Rva0041097B@@QAEXPAX@Z, retail 0x0041097B, 28 bytes. Chain lane:
// hashtable node delete for Rva004104C9 value (val at +4). Destroys val via
// rowed ??1Rva004104C9@@QAE@XZ then frees node via rowed _free. Callers
// 0x00410A3D and 0x00410AC7 are hashtable clear loops (push node; mov ecx tbl).
class Rva004104C9
{
public:
	~Rva004104C9();
};

extern "C" void __cdecl free(void *p);

struct Rva0041097BNode
{
	void *_M_next;
	Rva004104C9 _M_val;
};

class Rva0041097B
{
public:
	void rva0041097B(void *p);
};

void Rva0041097B::rva0041097B(void *p)
{
	((Rva0041097BNode *)p)->_M_val.~Rva004104C9();
	if (p)
		free(p);
}
