// cl: /O1 /MD /EHsc
// ?Rva005186E1Format@@YAXPAVOptionPreferences@@PAVAsciiString@@@Z @0x005186E1 117B
// Builds 9-int "%d" list into output AsciiString via OptionPreferences dispatch plus separator concat.
// Evidence: caller 0x0051889D pushes OptionPreferences* plus this+0x314 AsciiString* with __cdecl cleanup; rowed dispatch format concat releaseBuffer; separator 0x007BFB20 plus "%d" 0x007BE164.
template <typename T> class StringBase
{
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	void clear() { releaseBuffer(); }
	void concat(char const *s);
	void concat(StringBase const &other);
private:
	void releaseBuffer();
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	void format(char const *fmt, ...);
};

class OptionPreferences
{
public:
	int Rva002E42AFDispatch(int idx);
};

extern char const g_00BBE164[];
extern char const g_00BBFB20[];

void Rva005186E1Format(class OptionPreferences *prefs, class AsciiString *out)
{
	out->clear();
	AsciiString tmp;
	for (int i = 0; i < 9; ++i)
	{
		int v = prefs->Rva002E42AFDispatch(i);
		tmp.format(g_00BBE164, v);
		if (i != 0)
			out->concat(g_00BBFB20);
		out->concat(tmp);
	}
}
