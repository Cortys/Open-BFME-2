// ??0Rva002E0906@@QAE@XZ
// partial score=0.9 date=2026-09-30
// ??0Rva002E0906@@QAE@XZ
// partial score=0.90 date=2026-09-30
// cl: /O1 /EHsc /MD
// ??0Rva002E0906@@QAE@XZ present-unmatched
template <typename T> class StringBase
{
	friend class Rva002E0906;
	StringBase(const char *str);
	void *m_data;
};
class Rva002E0906EmptyBase
{
public:
	Rva002E0906EmptyBase() {}
	~Rva002E0906EmptyBase();
};
class Rva002E0906 : public Rva002E0906EmptyBase
{
public:
	Rva002E0906();
private:
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	StringBase<char> m_24;
	int m_28;
	int m_2c;
	int m_30;
	int m_34;
	int m_38;
	int m_3c;
};
Rva002E0906::Rva002E0906() : m_24("DefaultGoodArmyIcon")
{
	m_00 = 0;
	m_04 = 0;
	m_08 = 0;
	m_0c = 0;
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
	m_1c = 0;
	m_20 = 0;
	m_28 = 0;
	m_2c = 0;
	m_30 = 0;
	m_34 = 0;
	m_38 = 0;
	m_3c = 0;
}
