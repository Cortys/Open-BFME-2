// cl: /O1 /MD
// ?rva001EE5EE@Mouse@@QAEXEPAE@Z @ 0x001EE5EE (66B): Mouse tooltip setter with Hide.
// Retail stores byte arg into byte pointer arg then checks tooltip string at +0x12F8
// via StringBase isEmpty (row 0x35740). If not empty and rva001EDE26 (row Mouse +0x4F9D
// cursor check) is false it fires HideToolTip via Rva003807B7Hide (landed 60B) clears
// +0x12F8 via releaseBuffer (row 0x36E70) and clears dword +0x1304. Callers 0x00041B90.
// Prev Mouse::setVisibility proves Mouse class; honest-address rva name per packet.
template <typename T>
class StringBase
{
	friend class UnicodeString;
public:
	bool isEmpty() const;
private:
	void releaseBuffer();
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class UnicodeString
{
public:
	bool isEmpty() const
	{
		return ((const StringBase<unsigned short> *)this)->isEmpty();
	}
	void releaseBuffer()
	{
		((StringBase<unsigned short> *)this)->releaseBuffer();
	}
private:
	StringBase<unsigned short> m_data;
};

void Rva003807B7Hide();

class Mouse
{
	char m_pad0[0x12F8];
	UnicodeString m_12F8;
	char m_pad1[0x1304 - 0x12FC];
	int m_1304;
public:
	bool rva001EDE26() const;
	void rva001EE5EE(unsigned char a, unsigned char *b);
};

void Mouse::rva001EE5EE(unsigned char a, unsigned char *b)
{
	*b = a;
	if (!m_12F8.isEmpty())
	{
		if (!rva001EDE26())
		{
			Rva003807B7Hide();
			m_12F8.releaseBuffer();
			m_1304 = 0;
		}
	}
}
