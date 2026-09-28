// ?Rva001530E9Parse@@YAXPBDPAX@Z
// partial score=0.93 date=2026-09-28
// ?Rva001530E9Parse@@YAXPBDPAX@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
extern "C" __declspec(dllimport) char *__cdecl strchr(const char *, int);
extern "C" __declspec(dllimport) char *__cdecl strrchr(const char *, int);
extern "C" __declspec(dllimport) char *__cdecl strncpy(char *, const char *, unsigned int);
extern "C" __declspec(dllimport) int __cdecl sscanf(const char *, const char *, ...);
extern "C" unsigned int __cdecl strlen(const char *);
extern "C" int __cdecl strcmp(const char *, const char *);

struct OutB
{
	char m_name[0x40];
	unsigned char m_flag40;
	unsigned char m_flag41;
	char m_pad42[2];
	int m_num44;
	const char *m_ext48;
};

// ?Rva001530E9Parse@@YAXPBDPAX@Z present-unmatched
void __cdecl Rva001530E9Parse(const char *src, void *outRaw)
{
	OutB *out = (OutB *)outRaw;
	out->m_name[0] = 0;
	out->m_flag40 = 0;
	out->m_flag41 = 0;
	out->m_num44 = 0;
	out->m_ext48 = 0;
	if (src == 0)
		return;
	const char *end = strchr(src, '.');
	if (end != 0)
	{
		out->m_ext48 = end + 1;
	}
	else
	{
		end = src + strlen(src);
		out->m_ext48 = 0;
	}
	if (end - src > 3)
	{
		const char *tmp = end - 3;
		if (strcmp(tmp, "[*]") == 0)
		{
			end = tmp;
			out->m_flag40 = 1;
		}
		else if (*(end - 1) == ']')
		{
			const char *br = strrchr(src, '[');
			if (br != 0)
			{
				out->m_flag41 = 1;
				sscanf(br + 1, "%d", &out->m_num44);
				end = br;
			}
		}
	}
	int cap = 0x40;
	int len = (int)(end - src);
	int *p = &cap;
	if (len <= cap)
		p = &len;
	int copyLen = *p;
	strncpy(out->m_name, src, copyLen);
	out->m_name[copyLen] = 0;
}
