// cl: /O1 /EHsc /MD
//
// ??0TreeKey00242F5E@@QAE@IVAsciiString@@@Z retail 0x000A780A 63B
// TreeKey00242F5E 2-arg ctor (unsigned id at +0 plus AsciiString at +4).
// Evidence: callers 0x000A7E9E and 0x000A8127 build this 8B struct on the
// stack via StringBase copy at 0x000365F0 then pass it to set insert for
// set<TreeKey00242F5E> at 0x000A7DCE; layout matches rowed TreeKey copy ctor
// 0x000CF475 and _Construct 0x000A7876.

class AsciiString;

template <typename T>
class StringBase
{
public:
	void concat(const T *text);

private:
	friend class AsciiString;

	StringBase(const T *text);
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
};

class AsciiString
{
public:
	AsciiString()
	{
		m_text = 0;
	}

	AsciiString(const AsciiString &that)
	{
		((StringBase<char> *)this)->StringBase<char>::StringBase(
			(const StringBase<char> &)that);
	}

	~AsciiString()
	{
		((StringBase<char> *)this)->releaseBuffer();
	}

private:
	char *m_text;
};

struct TreeKey00242F5E
{
	unsigned int m_id;
	AsciiString m_name;

	TreeKey00242F5E(unsigned int id, AsciiString name);
};

TreeKey00242F5E::TreeKey00242F5E(unsigned int id, AsciiString name)
	: m_id(id)
	, m_name(name)
{
}
