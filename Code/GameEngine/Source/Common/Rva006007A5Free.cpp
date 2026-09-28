// cl: /O1 /MD
//
// ?rva006007A5@Rva006007A5@@QAEXPAX@Z @0x006007A5 45B. Recursive list/tree
// free helper: if node null return else loop over siblings at +8 recursing
// on child at +0x0C with the same this then freeing via rowed _free
// 0x00030830. Same recipe as AnimationSoundTree::rva004CA167 without the
// payload dtor. Evidence: self-call at 0x006007B7; callers at 0x00600839
// (clear checking count +4) and self; ret 4.

extern "C" void free(void *);

class Rva006007A5
{
public:
	void rva006007A5(void *node);
};

void Rva006007A5::rva006007A5(void *nodeIn)
{
	if (!nodeIn)
		return;
	char *cur = (char *)nodeIn;
	do
	{
		char *child = *(char **)(cur + 0x0C);
		rva006007A5(child);
		char *next = *(char **)(cur + 8);
		free(cur);
		cur = next;
	} while (cur);
}
