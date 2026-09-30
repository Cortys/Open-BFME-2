// ?rva00416143@Rva00416143@@QAEXABVAsciiString@@@Z
// partial score=0.91 date=2026-09-30
// ?rva00416143@Rva00416143@@QAEXABVAsciiString@@@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /Og /MD /EHsc
// ?rva00416143@Rva00416143@@QAEXABVAsciiString@@@Z @0x00416143 (174B): buddy/host address record parse.
// sscanf "%d %d %d" into +4/+8/+0x14 then split " PW:"/" #HOST:" substrings into +0x10/+0x0C.
// Evidence: sscanf IAT strstr IAT x2 strlen thunk x3 via 0x00629170 StringBase set 0x00036780/0x000055F5
// releaseBuffer 0x00036410 empty string 0x00BBAC1C via g_Rva0107301CEmptyString caller 0x0041775D
// neighbours 0x00416088/0x004161F1. Best probe V6 two ternaries gives 172B vs 174B 69 vs 70 insns.
extern "C" __declspec(dllimport) int __cdecl sscanf(const char *buf, const char *fmt, ...);
extern "C" __declspec(dllimport) char *__cdecl strstr(const char *s, const char *sub);
extern "C" unsigned int __cdecl strlen(const char *s);

extern const char g_Rva0107301CEmptyString[];

template <typename T> class StringBase {
	friend class AsciiString;
	friend struct Rva00416143;
	struct Header {
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
	void releaseBuffer();
public:
	void set(const T *s);
	void set(const T *s, int len);
};

class AsciiString {
public:
	StringBase<char> m_data;
};

struct Rva00416143 {
	int m_00;
	int m_04;
	int m_08;
	StringBase<char> m_0C;
	StringBase<char> m_10;
	int m_14;
	void rva00416143(const AsciiString &a);
};

// ?rva00416143@Rva00416143@@QAEXABVAsciiString@@@Z present-unmatched
void Rva00416143::rva00416143(const AsciiString &a)
{
	void *h = a.m_data.m_data;
	const char *s = h != 0 ? (const char *)h + 8 : g_Rva0107301CEmptyString;
	const char *t = h != 0 ? (const char *)h + 8 : g_Rva0107301CEmptyString;
	sscanf(s, "%d %d %d", &m_04, &m_08, &m_14);
	const char *pw = strstr(t, " PW:");
	const char *host = strstr(pw, " #HOST:");
	if (pw == 0 || host == 0) {
		m_10.releaseBuffer();
		m_0C.releaseBuffer();
	} else {
		int len = (int)(host - pw) - (int)strlen(" PW:");
		m_10.set(pw + strlen(" PW:"), len);
		m_0C.set(host + strlen(" #HOST:"));
	}
}
