// cl: /O1 /DNDEBUG /MD
// ?Rva002A1316Store@@YGPAXPAPAXPAX0@Z retail 0x002A1316 37B
// Doubly-linked insert via rowed freelist store 0x0029FB80. Evidence: ret 0xC
// with 3 args returning first; push third for Store; link pos/next/node/out.
void *__stdcall Rva0029FB80Store(void **p);

void *__stdcall Rva002A1316Store(void **out, void *pos, void **val)
{
	void *node = Rva0029FB80Store(val);
	void *next = *(void **)((char *)pos + 4);
	*(void **)node = pos;
	*(void **)((char *)node + 4) = next;
	*(void **)next = node;
	*(void **)((char *)pos + 4) = node;
	*out = node;
	return out;
}
