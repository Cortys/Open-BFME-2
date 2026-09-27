// ?Rva002AAD52Find@@YAXPAPAXPAX1PAG@Z
// partial score=0.93 date=2026-09-27
// ?Rva002AAD52Find@@YAXPAPAXPAX1PAG@Z
// partial score=0.93 date=2026-09-27
// cl: /O1
void Rva002AAD52Find(void **out, void *start, void *end, unsigned short *key)
{
	void *cur = start;
	if (cur != end) {
		unsigned short k = *key;
		do {
			if (*(unsigned short *)((char *)cur + 8) == k)
				break;
			cur = *(void **)cur;
		} while (cur != end);
	}
	*out = cur;
}
