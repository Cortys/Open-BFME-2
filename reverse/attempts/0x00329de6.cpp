// ??0BuildListInfo@@QAE@ABV0@@Z
// partial score=0.97 date=2026-09-29
// ??0BuildListInfo@@QAE@ABV0@@Z
// partial score=0.97 date=2026-09-29
// cl: /O1 /G7
// probe6 no base copy - 253B/87insns exact size/count; only push-lea order differs for first two StringBase copies (retail lea,lea,push vs ours lea,push,lea); vtable reloc only other diff; public BfmeBase dtor gives early EH state 0 plus Pod40 struct gives rep movsd

template <typename T>
class StringBase
{
	StringBase(const StringBase &that);
	friend class BuildListInfo;
public:
	~StringBase();
	T *m_data;
};

class BfmeBase
{
public:
	BfmeBase() {}
	~BfmeBase();
};

struct Pod40
{
	int v[10];
};

class BuildListInfo : public BfmeBase
{
public:
	BuildListInfo(const BuildListInfo &that);
	virtual void *deleteInstance(int pool);
	BuildListInfo *getNext() const { return m_nextBuildList; }
	void setNextBuildList(BuildListInfo *next) { m_nextBuildList = next; }
private:
	StringBase<char> m_str1;
	StringBase<char> m_str2;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	unsigned char m_24;
	int m_28;
	BuildListInfo *m_nextBuildList;
	StringBase<char> m_str30;
	int m_34;
	unsigned char m_38;
	unsigned char m_39;
	unsigned char m_3a;
	unsigned char m_3b;
	int m_3c;
	int m_40;
	unsigned char m_44;
	unsigned char m_45;
	unsigned char m_46;
	unsigned char m_47;
	int m_48;
	int m_4c;
	Pod40 m_50pod;
	int m_78;
	int m_7c;
};

// ??0BuildListInfo@@QAE@ABV0@@Z present-unmatched
BuildListInfo::BuildListInfo(const BuildListInfo &that)
	: BfmeBase()
	, m_str1(that.m_str1)
	, m_str2(that.m_str2)
	, m_0c(that.m_0c)
	, m_10(that.m_10)
	, m_14(that.m_14)
	, m_18(that.m_18)
	, m_1c(that.m_1c)
	, m_20(that.m_20)
	, m_24(that.m_24)
	, m_28(that.m_28)
	, m_nextBuildList(that.m_nextBuildList)
	, m_str30(that.m_str30)
	, m_34(that.m_34)
	, m_38(that.m_38)
	, m_39(that.m_39)
	, m_3a(that.m_3a)
	, m_3b(that.m_3b)
	, m_3c(that.m_3c)
	, m_40(that.m_40)
	, m_44(that.m_44)
	, m_45(that.m_45)
	, m_46(that.m_46)
	, m_47(that.m_47)
	, m_48(that.m_48)
	, m_4c(that.m_4c)
	, m_50pod(that.m_50pod)
	, m_78(that.m_78)
	, m_7c(that.m_7c)
{
}
