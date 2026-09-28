// cl: /O1 /MD /Oi-
// ?Rva0044780FCopy@@YAPADPADPAXI0@Z, retail 0x0044780F, 54 bytes.
// Checked memcpy (dst-first): copies size bytes from src to dst and returns
// dst+size or dst unchanged when dst+size would pass limit (null limit always
// copies). Evidence: unlock lane; callees rowed/pinned (memcpy via _memcpy pin
// at 0x006291A8); callers at 0x00447861 0x00447887 0x004478A0 0x00447E28;
// landing unblocks 0x00447845 0x0044786B 0x00447891.
extern "C" void *__cdecl memcpy(void *dest, const void *src, unsigned int count);
char *__cdecl Rva0044780FCopy(char *dst, void *src, unsigned int size, char *limit)
{
	if (limit != 0) {
		if (dst > limit)
			return dst;
		if (dst + size > limit)
			return dst;
	}
	memcpy(dst, src, size);
	return dst + size;
}
