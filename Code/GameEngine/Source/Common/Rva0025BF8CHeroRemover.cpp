// cl: /O1 /Oy- /DNDEBUG /MD /EHsc
// stlport
// ?rva0025BF8C@Rva0025BF8C@@QAE_NPAX@Z, retail 0x0025BF8C, 59 bytes.
// Vector find-and-erase returning bool: loads CreateAHeroData* at arg+0x74 into
// a stack temp (mov eax,[ebp+8]; mov eax,[eax+0x74]; mov [ebp+8],eax), finds it
// in the vector<CreateAHeroData*> at this+4 via rowed find at 0x0020E873, erases
// via rowed erase at 0x0025BF5D when present, returns 1 else 0 (mov al,1 / xor al).
// Callers (4 at 0x005960F1 etc.) pass a holder with hero at +0x74; unblocks 4.
// Prev is VectorObjectIDFillInsert, next is Rva0025BFE3 ctor; EBP frame needs /Oy-.
#include <vector>
class CreateAHeroData;
class Rva0025BF8C
{
public:
	bool rva0025BF8C(void *arg);
private:
	char m_pad[4];
	_STL::vector<CreateAHeroData *> m_vec04;
};
bool Rva0025BF8C::rva0025BF8C(void *arg)
{
	CreateAHeroData *hero = *(CreateAHeroData **)((char *)arg + 0x74);
	_STL::vector<CreateAHeroData *>::iterator it =
		_STL::find(m_vec04.begin(), m_vec04.end(), hero);
	if (it != m_vec04.end()) {
		m_vec04.erase(it);
		return true;
	}
	return false;
}
