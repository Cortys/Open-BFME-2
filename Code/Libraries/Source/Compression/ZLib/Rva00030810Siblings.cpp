// cl: /MD
// Sibling of the rowed zlib _inflateInit_ at 0x00690860 (26B). Retail
// 0x00030810 is a 27-byte 4-argument thunk that shuffles its arguments
// through registers and calls the runtime-resolved function pointer at
// 0x00DE0400. The middle argument is the immediate 3. The absolute call
// site is a masked DIR32 relocation, so the pointer's spelling is local.
extern "C" int (__cdecl *g_bfmeResolved0030810)(void *a, const char *b, int c, int d);

int __cdecl rva00030810(void *z, const char *version, int stream_size)
{
	return g_bfmeResolved0030810(z, version, 3, stream_size);
}
