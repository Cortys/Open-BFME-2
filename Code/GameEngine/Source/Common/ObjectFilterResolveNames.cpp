// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva003611EFResolveNames@ObjectFilter@@SAXPAV1@@Z retail 0x003611EF 585 bytes.
// ObjectFilter name resolution: every inclusion name (+0x00) starting with S:
// with length >= 3 (rest names a template kept in its own list at +0x18) or
// naming a template (+0x30) must resolve through g_009FF000 rva002D06CA else
// INIException ObjectFilter resolveNames specified. Name list cleared after.
// Same pass over exclusion names (+0x0C) into +0x24 and +0x3C. Evidence: four
// message literals name it. BFME1 donor ObjectFilterResolveNames.cpp retail
// 0x0039E2B0 has same six vectors at same offsets. Callers at 0x0036145E and
// 0x0036235C push one filter pointer cdecl. All callees rowed or pinned.
#include <vector>

extern const char g_Rva0107301CEmptyString[];

template <typename T>
struct StringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T>
class StringBase
{
	friend class AsciiString;
	StringBase(const T *s);
	void releaseBuffer();

public:
	int getLength() const
	{
		return m_data ? m_data->length : 0;
	}
	const T *str() const
	{
		return m_data ? &m_data->text[0] : (const T *)g_Rva0107301CEmptyString;
	}
	bool startsWith(const T *s) const;

protected:
	StringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString(const char *s) : StringBase<char>(s) {}
	AsciiString(const AsciiString &other);
	~AsciiString() { releaseBuffer(); }
};

class ModuleData
{
};

class INIException
{
public:
	char *mFailureMessage;
	int m_argCount;
	INIException(int argCount, const char *format, ...);
};

class Rva002D06CA
{
public:
	void *rva002D06CA(const AsciiString *key);
};

extern Rva002D06CA *g_009FF000;

extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);

struct ObjectFilterThrowInfoAnchor { int a; int b; int c; int d; };
static const ObjectFilterThrowInfoAnchor objectFilterThrowInfoAnchor = { 0, 0, 0, 0 };

class ObjectFilter
{
public:
	static void rva003611EFResolveNames(ObjectFilter *filter);

	_STL::vector<AsciiString> m_inclusionNames;
	_STL::vector<AsciiString> m_exclusionNames;
	_STL::vector<const ModuleData *> m_inclusionSTemplates;
	_STL::vector<const ModuleData *> m_exclusionSTemplates;
	_STL::vector<const ModuleData *> m_inclusionTemplates;
	_STL::vector<const ModuleData *> m_exclusionTemplates;
	char m_tail[0x94 - 0x48];
};

void ObjectFilter::rva003611EFResolveNames(ObjectFilter *filter)
{
	int i;
	int count = filter->m_inclusionNames.size();
	for (i = 0; i < count; ++i)
	{
		AsciiString &name = filter->m_inclusionNames[i];
		if (name.startsWith("S:") && (unsigned)name.getLength() >= 3)
		{
			const char *templateName = name.str();
			templateName += 2;
			const ModuleData *tmpl;
			{
				AsciiString tmp(templateName);
				tmpl = (const ModuleData *)g_009FF000->rva002D06CA(&tmp);
			}
			if (!tmpl)
			{
				INIException e(3, "ObjectFilter::resolveNames() specified +S:%s but template %s doesn't exist! Typo?", templateName, templateName);
				_CxxThrowException(&e, (const _s__ThrowInfo *)&objectFilterThrowInfoAnchor); __assume(0);
			}
			filter->m_inclusionSTemplates.push_back(tmpl);
		}
		else
		{
			const ModuleData *tmpl = (const ModuleData *)g_009FF000->rva002D06CA(&name);
			if (!tmpl)
			{
				INIException e(3, "ObjectFilter::resolveNames() specified +%s but this template doesn't exist! Typo?", name.str());
				_CxxThrowException(&e, (const _s__ThrowInfo *)&objectFilterThrowInfoAnchor); __assume(0);
			}
			filter->m_inclusionTemplates.push_back(tmpl);
		}
	}
	filter->m_inclusionNames.clear();

	count = filter->m_exclusionNames.size();
	for (i = 0; i < count; ++i)
	{
		AsciiString &name = filter->m_exclusionNames[i];
		if (name.startsWith("S:") && (unsigned)name.getLength() >= 3)
		{
			const char *templateName = name.str();
			templateName += 2;
			const ModuleData *tmpl;
			{
				AsciiString tmp(templateName);
				tmpl = (const ModuleData *)g_009FF000->rva002D06CA(&tmp);
			}
			if (!tmpl)
			{
				INIException e(3, "ObjectFilter::resolveNames() specified -S:%s but template %s doesn't exist! Typo?", templateName, templateName);
				_CxxThrowException(&e, (const _s__ThrowInfo *)&objectFilterThrowInfoAnchor); __assume(0);
			}
			filter->m_exclusionSTemplates.push_back(tmpl);
		}
		else
		{
			const ModuleData *tmpl = (const ModuleData *)g_009FF000->rva002D06CA(&name);
			if (!tmpl)
			{
				INIException e(3, "ObjectFilter::resolveNames() specified -%s but this template doesn't exist! Typo?", name.str());
				_CxxThrowException(&e, (const _s__ThrowInfo *)&objectFilterThrowInfoAnchor); __assume(0);
			}
			filter->m_exclusionTemplates.push_back(tmpl);
		}
	}
	filter->m_exclusionNames.clear();
}
