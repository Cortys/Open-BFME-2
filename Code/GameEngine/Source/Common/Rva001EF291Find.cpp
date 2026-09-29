// cl: /O1 /MD
//
// Retail 0x001EF291 58B:
// ?Rva001EF291Find@@YAHABVAsciiString@@@Z
// Empty check via rowed isEmpty 0x00001E2F returns -1. Loop 0x38 over
// retail pointer table at 0x00DB9058 via rowed compareNoCase 0x00037980
// returns index or -1. Callers at 0x002A344F 0x004023A6 0x0042AB2B.
//

template <typename T>
class StringBase
{
public:
	bool isEmpty() const;
	int compareNoCase(const T *str) const;
private:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString(const char *text);
	AsciiString(const AsciiString &other);
	~AsciiString();
};

extern const char *g_00DB9058[];

int __stdcall Rva001EF291Find(const AsciiString &s)
{
	if (s.isEmpty())
		return -1;
	for (int i = 0; i < 0x38; ++i) {
		if (s.compareNoCase(g_00DB9058[i]) == 0)
			return i;
	}
	return -1;
}
