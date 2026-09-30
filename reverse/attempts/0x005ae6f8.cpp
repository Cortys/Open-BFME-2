// ?Rva005AE6F8Find@@YAPAXPAX0HPAE@Z
// partial score=0.92 date=2026-09-30
// ?Rva005AE6F8Find@@YAPAXPAX0HPAE@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /MD
//
// ?Rva005AE6F8Find@@YAPAXPAX0HPAE@Z retail 0x005AE6F8 107 bytes. Free search
// over stride-8 pointer table comparing pointed int to value with 4x
// unrolled main loop plus Duff remainder returning found or end. Evidence
// is caller 0x005AE78A pushing 4 plus unroll sar 5 plus sar 3 plus no
// imports plus neighbour flags.

struct Elem
{
	void *ptr;
	int pad;
};

struct Target
{
	int id;
};

void *Rva005AE6F8Find(void *start, void *end, int value, unsigned char *unused)
{
	unsigned char *p = (unsigned char *)start;
	unsigned char *e = (unsigned char *)end;
	int stride = 8;
	int n = (int)(e - p) >> 5;
	goto rem_check;
loop:
	{
		void *q0 = *(void **)p;
		if (*(int *)q0 == value)
			return p;
		p += stride;
		void *q1 = *(void **)p;
		if (*(int *)q1 == value)
			return p;
		p += stride;
		void *q2 = *(void **)p;
		if (*(int *)q2 == value)
			return p;
		p += stride;
		void *q3 = *(void **)p;
		if (*(int *)q3 == value)
			return p;
		p += stride;
		--n;
	}
rem_check:
	if (n > 0)
		goto loop;
	int rem = (int)(e - p) >> 3;
	--rem;
	if (rem == 0)
		goto one;
	--rem;
	if (rem == 0)
		goto two;
	--rem;
	if (rem != 0)
		return e;
	{
		void *q = *(void **)p;
		if (*(int *)q == value)
			return p;
		p += stride;
	}
two:
	{
		void *q = *(void **)p;
		if (*(int *)q == value)
			return p;
		p += stride;
	}
one:
	{
		void *q = *(void **)p;
		if (*(int *)q == value)
			return p;
		p += stride;
	}
	return e;
}
