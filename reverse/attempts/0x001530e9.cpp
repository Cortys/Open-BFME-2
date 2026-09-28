// ?Rva001530E9Parse@@YAXPBDPAX@Z
// partial score=0.96 date=2026-09-28
// ?Rva001530E9Parse@@YAXPBDPAX@Z
// partial score=0.96 date=2026-09-28
// cl: /O1 /MD /Oi-
// ?Rva001530E9Parse@@YAXPBDPAX@Z @0x001530E9 224B: free __cdecl parser splitting name[.ext] with [*]/[N] handling; callers compare m_name via _strcmpi (0x80E30 Bases, 0xE1F42 Shroud/Taint, 0x14FE33 Color, 0x1F4A90 Draw); strings "[*]" 0x7D3B5C "%d" 0x7BE164.
// Evidence: strchr '.' + strlen + strcmp "[*]" + strrchr '[' + sscanf "%d" + strncpy 64 + null-terminate; struct 0x4C {char[64] +0x40 bool star +0x41 bool bracket +0x44 int index +0x48 ext}.
extern "C" unsigned int __cdecl strlen(const char *s);
extern "C" int __cdecl strcmp(const char *a, const char *b);
extern "C" __declspec(dllimport) char *__cdecl strchr(const char *s, int c);
extern "C" __declspec(dllimport) char *__cdecl strrchr(const char *s, int c);
extern "C" __declspec(dllimport) int __cdecl sscanf(const char *buf, const char *fmt, ...);
extern "C" __declspec(dllimport) char *__cdecl strncpy(char *dst, const char *src, unsigned int n);

struct Parts {
    char m_name[64];
    bool m_hasStar;
    bool m_hasBracket;
    char m_pad[2];
    int m_index;
    const char *m_ext;
};

// ?Rva001530E9Parse@@YAXPBDPAX@Z present-unmatched
void __cdecl Rva001530E9Parse(const char *src, void *dstRaw)
{
    Parts *dst = (Parts *)dstRaw;
    dst->m_name[0] = 0;
    dst->m_hasStar = false;
    dst->m_hasBracket = false;
    dst->m_index = 0;
    dst->m_ext = 0;
    if (!src)
        return;
    const char *dot = strchr(src, '.');
    const char *end = dot;
    if (dot) {
        dst->m_ext = dot + 1;
    } else {
        end = src + strlen(src);
        dst->m_ext = 0;
    }
    if ((int)(end - src) > 3) {
        const char *cand = end - 3;
        if (strcmp(cand, "[*]") == 0) {
            end = cand;
            dst->m_hasStar = true;
        } else if (*(end - 1) == ']') {
            const char *br = strrchr(src, '[');
            if (br) {
                dst->m_hasBracket = true;
                sscanf(br + 1, "%d", &dst->m_index);
                end = br;
            }
        }
    }
    int maxLen = 64;
    int curLen = (int)(end - src);
    int &useLen = (curLen > maxLen ? maxLen : curLen);
    int copyLen = useLen;
    strncpy(dst->m_name, src, copyLen);
    dst->m_name[copyLen] = 0;
}
