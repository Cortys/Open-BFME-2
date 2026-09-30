// cl: /Ireference/shims/bfmelist /O1 /DNDEBUG /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?setShellMenuScheme@ShellMenuSchemeManager@@QAEXVAsciiString@@@Z @0x002005DE 124B.
// ShellMenuSchemeManager::setShellMenuScheme. Evidence: BFME1 donor
// GameEngine/Source/GameClient/GUI/Shell/ShellMenuScheme.cpp setShellMenuScheme
// (empty guard + toLower + list search + compare + store current); rowed
// StringBase<D> releaseBuffer 0x00036410 and toLower 0x00036A70 and compare
// 0x000069D6; caller 0x0035C49C passes Shell+0x64 manager with by-value string.
#include <list>

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	bool isEmpty() const { return m_data == 0 || m_data->length == 0; }
	void toLower();
	int compare(const StringBase<T> &other) const;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	void toLower() { StringBase<char>::toLower(); }
	bool isEmpty() const { return StringBase<char>::isEmpty(); }
};

class ShellMenuScheme
{
public:
	AsciiString m_name;
};

class ShellMenuSchemeManager
{
public:
	void setShellMenuScheme(AsciiString name);
private:
	_STL::list<ShellMenuScheme *> m_schemeList;
	ShellMenuScheme *m_currentScheme;
};

void ShellMenuSchemeManager::setShellMenuScheme(AsciiString name)
{
	if (name.isEmpty()) {
		m_currentScheme = 0;
		return;
	}

	_STL::list<ShellMenuScheme *>::iterator it = m_schemeList.begin();
	name.toLower();
	while (it != m_schemeList.end()) {
		ShellMenuScheme *scheme = *it;
		if (scheme->m_name.compare(name) == 0) {
			m_currentScheme = scheme;
			break;
		}
		++it;
	}
}
