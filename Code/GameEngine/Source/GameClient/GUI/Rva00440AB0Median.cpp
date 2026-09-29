// cl: /O1
//
// ?Rva00440AB0Median@@YAPAPAXPAPAX00VRva0043FE9A@@@Z @0x00440AB0 107B.
// Median-of-three with Rva0043FE9A comp (5 calls). Evidence: caller
// 0x004434A6; prev shares /O1; mirrors Rva0021B9A0Median branch shape.
class MapMetaData;

class Rva0043FE9A
{
public:
	bool rva0043FE9A(MapMetaData *a, MapMetaData *b);
private:
	int m_sort0;
	int m_sort1;
};

void **Rva00440AB0Median(void **a, void **b, void **c, Rva0043FE9A comp)
{
	if (comp.rva0043FE9A((MapMetaData *)*a, (MapMetaData *)*b)) {
		if (comp.rva0043FE9A((MapMetaData *)*b, (MapMetaData *)*c))
			return b;
		else if (comp.rva0043FE9A((MapMetaData *)*a, (MapMetaData *)*c))
			return c;
		else
			return a;
	} else {
		if (comp.rva0043FE9A((MapMetaData *)*a, (MapMetaData *)*c))
			return a;
		else if (comp.rva0043FE9A((MapMetaData *)*b, (MapMetaData *)*c))
			return c;
		else
			return b;
	}
}
