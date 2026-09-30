// cl: /O1 /MD
// ??1Rva00205224@@UAE@XZ @0x00205224 63B: virtual dtor tearing down AsciiStrings at +0x10 then +0x0C via rowed releaseBuffer 0x00036410 then restoring Snapshot base vtable 0x00BBB554.
// Evidence: deleting dtor caller 0x00205208 (28B ??_G shape); same 63B shape as SlavedUpdateModuleDataDtor 0x00255FC1; base Snapshot BBB554.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	~AsciiString() {}
};

class Snapshot
{
public:
	virtual ~Snapshot();
};

extern const void *const g_00BBB554[];

inline Snapshot::~Snapshot()
{
	*(const void **)this = g_00BBB554;
}

class __declspec(novtable) Rva00205224 : public Snapshot
{
public:
	virtual ~Rva00205224();
private:
	char m_pad[0x0C - 4];
	AsciiString m_C; // +0x0C
	AsciiString m_10; // +0x10
};

Rva00205224::~Rva00205224()
{
}
