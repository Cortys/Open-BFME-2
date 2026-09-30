// cl: /O1 /MD
//
// ?rva000EB08C@Rva000EB08C@@QAEXH_N@Z @0x000EB08C 90B. Index plus flag store.
// Evidence: __thiscall ret 8 with int plus bool, TheWritableGlobalData row
// plus 0x40 gate, count at +0x44540 with 0xE8 stride array at +0x600 holding
// id at +0 plus value at +0xA4, second array at +0x44578 stride 0x5C holding
// pointer plus target int at +0x5C, dirty flag at +0x45C64. Caller 0x000EB2AC.
// Honest address name.
class GlobalData
{
public:
	char m_pad00[0x40];
	unsigned char m_40;
};

extern GlobalData *TheWritableGlobalData;

class Rva000EB08C
{
public:
	void rva000EB08C(int index, bool flag);
	bool rva000EB2AC(int id, bool flag);
private:
	struct Elem1
	{
		int id1;
		char m_pad04[0x18 - 4];
		int id2;
		char m_pad1C[0xA4 - 0x18 - 4];
		int value;
		char m_padA8[0xE8 - 0xA4 - 4];
	};
	struct Elem2Target
	{
		char m_pad00[0x5C];
		int value;
	};
	struct Elem2
	{
		Elem2Target *ptr;
		char m_pad04[0x5C - 4];
	};
	char m_pad00[0x600];
	Elem1 m_elems[1];
	char m_pad01[0x44540 - 0x600 - 0xE8];
	int m_count;
	char m_pad02[0x44578 - 0x44540 - 4];
	Elem2 m_array2[1];
	char m_pad03[0x45C64 - 0x44578 - 0x5C];
	unsigned char m_dirty;
};

void Rva000EB08C::rva000EB08C(int index, bool flag)
{
	if (TheWritableGlobalData->m_40 == 0)
		return;
	if (index >= m_count)
		return;
	int id = m_elems[index].id1;
	if (id < 0)
		return;
	if (flag) {
		int val = m_array2[id].ptr->value;
		m_elems[index].value = val;
	} else {
		m_elems[index].value = 0xFF;
	}
	m_dirty = 1;
}

bool Rva000EB08C::rva000EB2AC(int id, bool flag)
{
	if (id == 0)
		return false;
	int n = m_count;
	for (int i = 0; i < n; ++i) {
		if (m_elems[i].id2 == id) {
			rva000EB08C(i, flag);
			return true;
		}
	}
	return false;
}
