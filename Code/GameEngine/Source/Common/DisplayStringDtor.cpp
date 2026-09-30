// cl: /O1 /MD /EHsc
// ??1DisplayString@@UAE@XZ @0x00358994 57B
// DisplayString virtual dtor; caller W3DDisplayString path 0x001061AC as base,
// donor GameClient/DisplayString.cpp dtor calls reset(); layout UnicodeString
// m_text +0x04 GameFont* m_font +0x08 next/prev; callees via row 0x00358946
// (reset/helper shape) and rowed releaseBuffer 0x00036E70.
template <typename T>
class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	int compare(const StringBase &other) const;
	void set(const StringBase &other);
private:
	T *m_data;
};
class GameFont;
class UnicodeString : public StringBase<unsigned short>
{
};
class DisplayString
{
public:
	virtual ~DisplayString();
	virtual void setText(UnicodeString text);
	virtual void pad02();
	virtual void pad03();
	virtual void notifyTextChanged();
	virtual void reset();
private:
	StringBase<unsigned short> m_text;
	GameFont *m_font;
	void *m_next;
	void *m_prev;
};

DisplayString::~DisplayString()
{
	DisplayString::reset();
}

void DisplayString::setText(UnicodeString text)
{
	if (text.compare(m_text) != 0)
	{
		m_text.set(text);
		notifyTextChanged();
	}
}
