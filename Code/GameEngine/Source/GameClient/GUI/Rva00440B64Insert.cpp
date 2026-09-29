// cl: /O1
//
// ?Rva00440B64Insert@@YAXPAPAXPAXVRva0043FE9A@@@Z @0x00440B64 47B.
// Unguarded linear insert with stateful comparator rowed at 0x0043FE9A.
// Shifts while comp(val next) then stores val. Evidence: callers 0x00441968
// 0x00441986; prev shares /O1; mirrors Rva005B6324Insert 47B.
class MapMetaData;

class Rva0043FE9A
{
public:
	bool rva0043FE9A(MapMetaData *a, MapMetaData *b);
private:
	int m_sort0;
	int m_sort1;
};

void Rva00440B64Insert(void **last, void *val, Rva0043FE9A comp)
{
	void **next = last - 1;
	while (comp.rva0043FE9A((MapMetaData *)val, (MapMetaData *)*next)) {
		*last = *next;
		last = next;
		--next;
	}
	*last = val;
}
