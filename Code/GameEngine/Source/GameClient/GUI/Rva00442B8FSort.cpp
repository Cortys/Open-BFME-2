// cl: /O1 /G7
// ?Rva00442B8FSort@@YAXPAPAX0VRva0043FE9A@@@Z @0x00442B8F 61B.
// Honest-address sort heap drain over void* elements. Pops first-last with
// the rowed pop at 0x00442892 then decrements last until one element left.
// Evidence: callee rowed 0x00442892; caller 0x00443030.
class MapMetaData;

class Rva0043FE9A
{
public:
	bool rva0043FE9A(MapMetaData *a, MapMetaData *b);
private:
	int m_sort0;
	int m_sort1;
};

void Rva00442892Pop(void **first, void **last, Rva0043FE9A comp);
void Rva00442B8FSort(void **first, void **last, Rva0043FE9A comp)
{
	while ((((int)last - (int)first) & ~3) > 4) {
		Rva00442892Pop(first, last, comp);
		--last;
	}
}
