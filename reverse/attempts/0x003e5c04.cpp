// ?Rva003E5C04Check@@YG_NPAVParameter@@PAUCondA003E5C04@@PAUCondB003E5C04@@@Z
// partial score=0.97 date=2026-10-01
// ?Rva003E5C04Check@@YG_NPAVParameter@@PAUCondA003E5C04@@PAUCondB003E5C04@@@Z
// retail 0x003E5C04, 173 bytes.
// Evidence: leaf via pin-only ScriptEngine::rva00357B82 plus rowed getEachPlayerFromMask; g_Va009FE16C plus ThePlayerList; Player+0x3bc Rva0039BF67 sum over two BitFlags<116> by value; threshold >=.
// cl: /O1

class Parameter
{
};

class ScriptEngine
{
public:
	int rva00357B82(Parameter *p);
};

extern ScriptEngine *g_Va009FE16C;

class Player
{
};

class PlayerList
{
public:
	Player *getEachPlayerFromMask(int &mask);
};

extern PlayerList *ThePlayerList;

void *__cdecl ji_006291ae(void *dest, int val, unsigned int count);
#pragma comment(linker, "/alternatename:?ji_006291ae@@YAPAXPAXHI@Z=?ji_006291ae@@YAXXZ")

class BfmeFixedStorage0004543D
{
	char m_bytes[28];
public:
	BfmeFixedStorage0004543D() {}
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &);
};

template <int N>
class BitFlags
{
public:
	BitFlags() {}
	void set(unsigned int bit)
	{
		unsigned *words = (unsigned *)this;
		words[bit >> 5] |= 1u << (bit & 31);
	}
private:
	BfmeFixedStorage0004543D m_storage;
};

class Rva0039BF67
{
public:
	int rva0039BF67(BitFlags<116> mustBeSet, BitFlags<116> mustBeClear);
};

struct CondA003E5C04
{
	char m_pad[8];
	int m_threshold;
};

struct CondB003E5C04
{
	char m_pad[8];
	unsigned int m_bit;
};

// ?Rva003E5C04Check@@YG_NPAVParameter@@PAUCondA003E5C04@@PAUCondB003E5C04@@@Z present-unmatched
bool __stdcall Rva003E5C04Check(Parameter *param, CondA003E5C04 *a, CondB003E5C04 *b)
{
	int mask = g_Va009FE16C->rva00357B82(param);
	Player *player = ThePlayerList->getEachPlayerFromMask(mask);
	if (!player)
		return false;

	Rva0039BF67 *r = (Rva0039BF67 *)((char *)player + 0x3bc);
	if (!r)
		return false;

	BitFlags<116> mustBeSet;
	ji_006291ae(&mustBeSet, 0, 28);
	mustBeSet.set(b->m_bit);

	BitFlags<116> mustBeClear;
	ji_006291ae(&mustBeClear, 0, 28);
	ji_006291ae(&mustBeClear, 0, 28);

	int sum = r->rva0039BF67(mustBeSet, mustBeClear);
	return sum >= a->m_threshold;
}
