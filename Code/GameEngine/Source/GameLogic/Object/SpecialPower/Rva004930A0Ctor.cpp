// cl: /Ireference/shims/bfme2_ascii /O1 /MD /GX /arch:SSE /DNDEBUG /Oy-
//
// ??0Rva004930A0@@QAE@XZ @0x004930A0 (359 bytes, Ghidra extent).
// Address-derived opaque base ctor. Target evidence: vtable 0x00C4E318;
// 0x7C-byte layout also reflected by its rowed dtor at 0x0049334F; three
// 4-byte filter handles at +0x24/+0x38/+0x3C are initialized from the
// 0x00DFEFA4 prototype through the rowed 0x00362087 method. The +0x10 pair,
// +0x34 BitFlags<11>, two strings, and scalar fields follow the retail stores.
// Callers and derived layouts support the base association; exact semantic
// identity remains unproven.

#include "ascii_string.h"

extern const char g_bfmeEmptyF9[];
extern const void *const g_00BBB554[];
extern const void *const g_00C4E318[];

class OpaqueRefCounted
{
public:
	void Release_Ref();
};

class RefHolder14
{
public:
	~RefHolder14() { if (m_ptr) m_ptr->Release_Ref(); }

private:
	OpaqueRefCounted *m_ptr;
};

class BfmeFixedStorage0004543D
{
public:
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other);

private:
	unsigned char m_bytes[28];
};

extern const BfmeFixedStorage0004543D g_009FEFA4;

class Rva003623E5Member
{
public:
	Rva003623E5Member();
	~Rva003623E5Member();
	void initFromStorages(BfmeFixedStorage0004543D first,
	                      BfmeFixedStorage0004543D second);

private:
	int m_record;
};

class Rva004CEE6EMember
{
public:
	Rva004CEE6EMember();

private:
	int m_first;
	RefHolder14 m_ref14;
};

template <int NUM_BITS>
class BitFlags
{
public:
	BitFlags();

private:
	unsigned int m_words[1];
};

class Snapshot
{
public:
	Snapshot() {}
	~Snapshot()
	{
		*(const void **)this = g_00BBB554;
	}
};

class Rva004930A0 : public Snapshot
{
public:
	Rva004930A0();

private:
	void *m_vtable;                         // +0x00
	unsigned char m_pad04[4];               // +0x04
	int m_value08;                          // +0x08
	unsigned char m_value0C;                // +0x0C
	unsigned char m_value0D;                // +0x0D
	unsigned char m_pad0E[2];               // +0x0E
	Rva004CEE6EMember m_pair10;              // +0x10
	AsciiString m_string18;                  // +0x18
	float m_value1C;                         // +0x1C
	unsigned char m_value20;                 // +0x20
	unsigned char m_pad21[3];                // +0x21
	Rva003623E5Member m_filter24;             // +0x24
	int m_value28;                           // +0x28
	unsigned char m_value2C;                 // +0x2C
	unsigned char m_pad2D[3];                // +0x2D
	int m_value30;                           // +0x30
	BitFlags<11> m_flags34;                  // +0x34
	Rva003623E5Member m_filter38;             // +0x38
	Rva003623E5Member m_filter3C;             // +0x3C
	unsigned char m_value40;                 // +0x40
	unsigned char m_value41;                 // +0x41
	unsigned char m_value42;                 // +0x42
	unsigned char m_pad43;                   // +0x43
	int m_value44;                           // +0x44
	int m_value48;                           // +0x48
	int m_value4C;                           // +0x4C
	int m_value50;                           // +0x50
	float m_value54;                         // +0x54
	int m_value58;                           // +0x58
	unsigned char m_value5C;                 // +0x5C
	unsigned char m_value5D;                 // +0x5D
	unsigned char m_value5E;                 // +0x5E
	unsigned char m_value5F;                 // +0x5F
	unsigned char m_value60;                 // +0x60
	unsigned char m_value61;                 // +0x61
	unsigned char m_pad62[2];                // +0x62
	int m_value64;                           // +0x64
	unsigned char m_value68;                 // +0x68
	unsigned char m_pad69[3];                // +0x69
	AsciiString m_string6C;                  // +0x6C
	int m_value70;                           // +0x70
	unsigned char m_value74;                 // +0x74
	unsigned char m_pad75[3];                // +0x75
	float m_value78;                         // +0x78
};

Rva004930A0::Rva004930A0()
	: Snapshot()
	, m_vtable(const_cast<void *>(reinterpret_cast<const void *>(g_00C4E318)))
	, m_value08(0)
	, m_value0C(0)
	, m_value0D(0)
	, m_string18(g_bfmeEmptyF9)
	, m_value1C(0.0f)
	, m_value20(0)
	, m_value28(0)
	, m_value2C(0)
	, m_value30(0)
	, m_value40(0)
	, m_value41(0)
	, m_value42(0)
	, m_value44(0)
	, m_value48(0)
	, m_value4C(0)
	, m_value50(-1)
	, m_value54(1.0f)
	, m_value58(0)
	, m_value5C(0)
	, m_value5D(0)
	, m_value5E(0)
	, m_value5F(0)
	, m_value60(1)
	, m_value61(1)
	, m_value64(5)
	, m_value68(0)
	, m_string6C(g_bfmeEmptyF9)
	, m_value70(0)
	, m_value74(0)
	, m_value78(0.0f)
{
	m_filter24.initFromStorages(
		BfmeFixedStorage0004543D(g_009FEFA4),
		BfmeFixedStorage0004543D(g_009FEFA4));
	m_filter38.initFromStorages(
		BfmeFixedStorage0004543D(g_009FEFA4),
		BfmeFixedStorage0004543D(g_009FEFA4));
	m_filter3C.initFromStorages(
		BfmeFixedStorage0004543D(g_009FEFA4),
		BfmeFixedStorage0004543D(g_009FEFA4));
}
// ?g_bfmeEmptyF9@@3QBDB: the global at VA 0xbbac1c is ?BfmeEmptyString@AsciiString@@0QBDB.
#pragma comment(linker, "/alternatename:?g_bfmeEmptyF9@@3QBDB=?BfmeEmptyString@AsciiString@@0QBDB")

// Retail's data references in this unit's matched rows land on globals defined
// under other spellings at the same addresses (addend-corrected DIR32). Bind them.
#pragma comment(linker, "/alternatename:?g_009FEFA4@@3VBfmeFixedStorage0004543D@@B=?g_00DFEFA4StoragePrototype@@3PAEA")
