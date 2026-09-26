// ?read_data_file@@YAHXZ
// partial score=0.95 date=2026-09-26
// ?read_data_file@@YAHXZ
// partial score=0.95 date=2026-09-26
// Stash for retail 0x006B5940 (true size 755B; ghidra says 752). Standalone probe
// that compiles with // cl: /O2 /GS /MD /GR- /EHsc- -Ireference/shims/nbench and
// yields 755B/264insns with 0 structural regions vs retail. To land: replace the
// fopen/fscanf read_data_file body in Code/Libraries/Source/Benchmark/nbench1.c
// (vendored file still has BFME1 file version; retail is sscanf-from-memory) and
// map the externs to that TU's real globals (g_s1/g_s2 = the two concatenated
// input blobs at 0x009DBFB8/0x009DBFBC; g_numpats at 0x00A20FA0; in/out tables at
// 0x00A20200/0x00A21AF0). Remaining diffs: malloc size lea output edx not eax
// (retail lea eax,[ebx+ebp+1]/push eax); out_pats anchor +8 not +16 (retail edi =
// out+16, ours out+8; 7 fstp disps off by 8); 3 branch. Tried 6 variants: v1
// helper-call skips (bad); v2 inline skips + check-after-skip; v3 ptr-sub strlen
// while(*a++);/reloads/no-8-check (donor has no 8-check); v4 load-s2-before-l1-sub
// (fixed strlen regs); v5 malloc order swap (no effect); v6 out +2 anchor (worse,
// raised pressure, reverted).
// cl: /O2 /GS /MD /GR- /EHsc- -Ireference/shims/nbench
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *g_s1;
extern char *g_s2;
extern int g_numpats;
extern double g_inpats[10][35];
extern double g_outpats[10][8];

// ?read_data_file@@YAHXZ present-unmatched
int read_data_file(void)
{
	char *a = g_s1;
	char *b = a + 1;
	while (*a++)
		;
	char *c = g_s2;
	int l1 = (int)(a - b);
	char *d = c + 1;
	while (*c++)
		;
	int l2 = (int)(c - d);
	char *buf = (char *)malloc(l1 + l2 + 1);
	memcpy(buf, g_s1, l1);
	memcpy(buf + l1, g_s2, l2);
	buf[l1 + l2] = 0;
	int xinsize, yinsize, youtsize;
	int v1, v2, v3, v4, v5, v6, v7, v8;
	int vals;
	char *s = buf;
	char *t;
	vals = sscanf(s, "%d  %d  %d", &xinsize, &yinsize, &youtsize);
	t = s;
	while (*t != '\n' && *t != 0)
		t++;
	if (*t == '\n')
		t++;
	s = t;
	if (vals != 3)
		return -1;
	vals = sscanf(s, "%d", &g_numpats);
	t = s;
	while (*t != '\n' && *t != 0)
		t++;
	if (*t == '\n')
		t++;
	s = t;
	if (vals != 1)
		return -1;
	if (g_numpats > 10)
		g_numpats = 10;
	for (int patt = 0; patt < g_numpats; patt++) {
		for (int row = 0; row < yinsize; row++) {
			vals = sscanf(s, "%d  %d  %d  %d  %d", &v1, &v2, &v3, &v4, &v5);
			t = s;
			while (*t != '\n' && *t != 0)
				t++;
			if (*t == '\n')
				t++;
			s = t;
			if (vals != 5)
				return -1;
			int el = row * xinsize;
			g_inpats[patt][el] = (double)v1; el++;
			g_inpats[patt][el] = (double)v2; el++;
			g_inpats[patt][el] = (double)v3; el++;
			g_inpats[patt][el] = (double)v4; el++;
			g_inpats[patt][el] = (double)v5; el++;
		}
		for (int i = 0; i < 35; i++) {
			if (g_inpats[patt][i] >= 0.9)
				g_inpats[patt][i] = 0.9;
			if (g_inpats[patt][i] <= 0.1)
				g_inpats[patt][i] = 0.1;
		}
		sscanf(s, "%d  %d  %d  %d  %d  %d  %d  %d", &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8);
		t = s;
		while (*t != '\n' && *t != 0)
			t++;
		if (*t == '\n')
			t++;
		s = t;
		g_outpats[patt][0] = (double)v1;
		g_outpats[patt][1] = (double)v2;
		g_outpats[patt][2] = (double)v3;
		g_outpats[patt][3] = (double)v4;
		g_outpats[patt][4] = (double)v5;
		g_outpats[patt][5] = (double)v6;
		g_outpats[patt][6] = (double)v7;
		g_outpats[patt][7] = (double)v8;
	}
	free(buf);
	return 0;
}
