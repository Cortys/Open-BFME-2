// cl: /O1 /MD /EHsc
//
// ?rva005B4BDB@Rva005B4BDB@@QAEXXZ retail 0x005B4BDB 97B
// Evidence: chain lane; callee GadgetTextEntryGetText 0x00320AAB plus trim 0x00037F70 plus rva00407A6A 0x00407A6A plus virtual slot 0x14 plus releaseBuffer 0x00036E70; callers 0x005B4CB7 0x005B4D23; EH prolog with handler code 0x0079F347.
template <typename T>
class StringBase
{
	friend class UnicodeString;
private:
	StringBase();
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
public:
	void trim();
};
class UnicodeString
{
public:
	static const UnicodeString TheEmptyString;
	UnicodeString() {}
	UnicodeString(const UnicodeString &that);
	~UnicodeString() { m_data.releaseBuffer(); }
	void trim() { m_data.trim(); }
private:
	StringBase<unsigned short> m_data;
};
class GameWindow
{
public:
	unsigned int winGetStyle();
};
UnicodeString GadgetTextEntryGetText(GameWindow *textEntry);
class Rva00407A6A
{
public:
	virtual void pad0();
	virtual void pad1();
	virtual void pad2();
	virtual void pad3();
	virtual void pad4();
	virtual void vslot5();
	bool rva00407A6A(const UnicodeString &arg);
};
class Rva005B4BDBOuter
{
public:
	char m_pad[0x27c];
	Rva00407A6A m_inner;
};
class Rva005B4BDB
{
public:
	void rva005B4BDB();
private:
	char m_pad0[4];
	Rva005B4BDBOuter *m_outer04;
	GameWindow *m_window08;
};
void Rva005B4BDB::rva005B4BDB()
{
	UnicodeString tmp = GadgetTextEntryGetText(m_window08);
	tmp.trim();
	m_outer04->m_inner.rva00407A6A(tmp);
	m_outer04->m_inner.vslot5();
}
