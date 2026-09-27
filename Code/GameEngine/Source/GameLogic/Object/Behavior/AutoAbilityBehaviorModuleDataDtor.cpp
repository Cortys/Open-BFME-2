// cl: /O1 /DNDEBUG /MD /GX
//
// ??1AutoAbilityBehaviorModuleData@@UAE@XZ, retail 0x0045A517, 73 bytes.
// Destroys the query array at +0x2C (6 entries via ehvec ??_M with the pinned
// element dtor at 0x0045A226) then the StringBase at +0x18 via the pinned
// 0x00036410, then restores the Snapshot base vtable 0x00BBB554. Member order
// (string plus array) drives states 0 plus 1 so teardown reads 1 plus 0
// exactly as retail. Shape follows LargeGroupBonusUpdateModuleDataDtor
// (TU-local Snapshot with inline dtor doing the BBB554 restore; novtable
// suppresses the entry derived-vtable store retail lacks). Layout follows the
// pinned ctor at 0x0045A2E7 (floats at +8/+0xC/+0x10/+0x14, zero at +0x18,
// bitset reset at +0x1C via rowed 0x0024CA24, array at +0x2C via ehvec ??_L
// with init 0x0045A1D9, bytes at 0x5C-0x5F) and the factory at 0x0024AFE5
// which news 0x60. Called by the ??_G at 0x0045A4FB.

class Xfer;

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer);
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};

inline Snapshot::~Snapshot()
{
	*(const void **)this = reinterpret_cast<const void *>(0x00BBB554);
}

template <typename T>
class StringBase
{
public:
	~StringBase();

private:
	void *m_data;
};

class AutoAbilityQueryEntry
{
public:
	~AutoAbilityQueryEntry();

private:
	unsigned char m_data[8];
};

class __declspec(novtable) AutoAbilityBehaviorModuleData : public Snapshot
{
public:
	virtual ~AutoAbilityBehaviorModuleData();

private:
	int m_unused04; // +4
	float m_08; // +8
	float m_0C; // +0xC
	float m_10; // +0x10
	float m_14; // +0x14
	StringBase<char> m_str18; // +0x18
	unsigned char m_bitset1C[0x10]; // +0x1C, bitset128 via rowed reset in ctor
	AutoAbilityQueryEntry m_query2C[6]; // +0x2C
	bool m_5C; // +0x5C
	bool m_5D; // +0x5D
	bool m_5E; // +0x5E
	bool m_5F; // +0x5F
};

AutoAbilityBehaviorModuleData::~AutoAbilityBehaviorModuleData()
{
}
