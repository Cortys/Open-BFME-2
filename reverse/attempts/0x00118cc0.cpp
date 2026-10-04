// ?rva00118CC0@Render2DRawArray@@QAEPAXH@Z
// partial score=0.92 date=2026-10-04
// ?rva00118CC0@Render2DRawArray@@QAEPAXH@Z
// partial score=0.9 date=2026-10-03
// cl: /O2 /G7 /arch:SSE /DNDEBUG /MD /EHsc
// ?rva00118CC0@Render2DRawArray@@QAEPAXH@Z 0x00118CC0 121 unlock Render2DRawArray grow of 44-byte elements via realloc caller 0x0011BD80
extern "C" __declspec(dllimport) void *__cdecl realloc(void *ptr, unsigned int size);

struct Raw44
{
	int v[11];
};

class Render2DRawArray
{
public:
	void *rva00118CC0(int count);
	Raw44 *Data;
	unsigned int Size;
	unsigned int Count;
	int GrowthStep;
};

// ?rva00118CC0@Render2DRawArray@@QAEPAXH@Z present-unmatched
void *Render2DRawArray::rva00118CC0(int count)
{
	if (count == 0 || (unsigned int)count >= 0x80000000u)
		return 0;
	Count += count;
	if (Count <= Size)
	{
		Raw44 *data = Data;
		unsigned int old = Count - (unsigned int)count;
		return &data[old];
	}
	unsigned int newSize = Count + (unsigned int)GrowthStep;
	Size = newSize;
	Raw44 *oldData = Data;
	void *newData = realloc(oldData, newSize * sizeof(Raw44));
	Data = (Raw44 *)newData;
	if (!newData)
		return 0;
	unsigned int old = Count - (unsigned int)count;
	return &((Raw44 *)newData)[old];
}
