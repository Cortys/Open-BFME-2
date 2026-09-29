// ?rva0044770F@GameSlot@@QAE_NXZ
// partial score=0.94 date=2026-09-29
// ?rva0044770F@GameSlot@@QAE_NXZ
// partial score=0.94 date=2026-09-29
// cl: /O1 /MD
//
// ?rva0044770F@GameSlot@@QAE_NXZ @0x0044770F 100B.
// Local-address slot test: if human and global 0x00DFE958 present, compare
// connectInfo +0x38 as BfmeNetAddress against virtual slot 0x100 result via
// rowed Rva00248CBF 0x00248CBF; retry with port+8 copy; else false. Evidence:
// unlock lane; callees isHuman 0x003FF0F1 plus Rva00248CBF rowed; callers in
// 0x00447794 0x004477C7 0x004454A1; neighbour shares flags.
typedef int Int;
typedef bool Bool;
typedef unsigned short WideChar;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	friend class GameSlot;

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
	void set(const StringBase<T> &other);
};

class AsciiString
{
private:
	void *m_data;
};

class UnicodeString
{
	friend class GameSlot;

public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &that);
	~UnicodeString();

private:
	StringBase<WideChar> m_data;
};

struct GameSlotConnectInfo
{
	unsigned int m_nat;
	unsigned int m_port;
};

struct BfmeNetAddress
{
	bool Rva00248CBF(const BfmeNetAddress *other) const;

	unsigned int m_key0;
	unsigned short m_key4;
};

struct NetAddr8
{
	unsigned int m_ip;
	union
	{
		unsigned int m_w;
		struct
		{
			unsigned short m_port;
			unsigned short m_pad;
		};
	};
};

struct Global009FE958
{
	virtual int v00(); virtual int v01(); virtual int v02(); virtual int v03();
	virtual int v04(); virtual int v05(); virtual int v06(); virtual int v07();
	virtual int v08(); virtual int v09(); virtual int v10(); virtual int v11();
	virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15();
	virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
	virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23();
	virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27();
	virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31();
	virtual int v32(); virtual int v33(); virtual int v34(); virtual int v35();
	virtual int v36(); virtual int v37(); virtual int v38(); virtual int v39();
	virtual int v40(); virtual int v41(); virtual int v42(); virtual int v43();
	virtual int v44(); virtual int v45(); virtual int v46(); virtual int v47();
	virtual int v48(); virtual int v49(); virtual int v50(); virtual int v51();
	virtual int v52(); virtual int v53(); virtual int v54(); virtual int v55();
	virtual int v56(); virtual int v57(); virtual int v58(); virtual int v59();
	virtual int v60(); virtual int v61(); virtual int v62(); virtual int v63();
	virtual const NetAddr8 *v64();
};
#define TheGlobal00DFE958 (*(Global009FE958 **)0x00DFE958)

class GameSlot
{
public:
	virtual void _v0();
	virtual void _v4();
	virtual void _v8();
	virtual void _vC();
	virtual void reset();
	Bool isHuman() const;
	bool rva0044770F();

private:
	Int m_state;                    // +0x04
	Bool m_isAccepted;              // +0x08
	Bool m_hasMap;                  // +0x09
	Bool m_isMuted;                 // +0x0A
	char m_pad0B;                   // +0x0B
	Int m_color;                    // +0x0C
	Int m_startPos;                 // +0x10
	Int m_bfme14;                   // +0x14
	Int m_playerTemplate;           // +0x18
	Int m_teamNumber;               // +0x1C
	Int m_bfme20;                   // +0x20
	Int m_origColor;                // +0x24
	Int m_origStartPos;             // +0x28
	Int m_origPlayerTemplate;       // +0x2C
	UnicodeString m_name;           // +0x30
	AsciiString m_ip;               // +0x34
	GameSlotConnectInfo m_connectInfo; // +0x38
};

// ?rva0044770F@GameSlot@@QAE_NXZ present-unmatched
bool GameSlot::rva0044770F()
{
	if (!isHuman())
		return false;
	Global009FE958 *g = TheGlobal00DFE958;
	if (g != 0) {
		NetAddr8 tmp;
		const BfmeNetAddress *conn = (const BfmeNetAddress *)&m_connectInfo;
		if (((const BfmeNetAddress *)g->v64())->Rva00248CBF(conn))
			return true;
		tmp = *TheGlobal00DFE958->v64();
		tmp.m_port += 8;
		return ((const BfmeNetAddress *)&tmp)->Rva00248CBF(conn);
	}
	return false;
}
