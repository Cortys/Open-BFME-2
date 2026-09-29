// cl: /O1 /DNDEBUG /MD /EHsc
// ??0NetCommandMsg@@QAE@XZ, retail 0x004D5593, 37 bytes. Base message ctor:
// m_executionFrame=-1 (+8), m_timestamp=-1 (+4), m_id=0 (+0x10 word),
// m_playerID=0 (+0xC), m_commandType=UNKNOWN (-1, +0x14), vtable 0x860130,
// m_referenceCount=1 (+0x18). Donor is BFME1
// Code/GameEngine/Source/GameNetwork/NetCommandMsg_ctors.cpp
// (NetCommandMsg::NetCommandMsg, same field order; BFME2 starts timestamp at
// -1 rather than 0). Called by 33 derived ctors (0x004D55D6 NetGameCommandMsg
// shape, Ack family at 0x004D565D/0x004D568F, 30 become ready on landing).
// Vtable 0x860130 slot0 is the deleting dtor at 0x004CEEA6 rowed below.
// ??_GNetCommandMsg@@MAEPAXI@Z, retail 0x004CEEA6, 29 bytes. Deleting dtor:
// reinstalls vtable 0x860130 then frees via rowed ??3@YAXPAX@Z at 0x0002FD60.
// Abbuts the word getter at 0x004CEEA1 (prev ret) and the next body at
// 0x004CEEC3; same TU emits it byte-exact from the inline empty dtor.
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef int Int;

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

enum NetCommandType
{
	NETCOMMANDTYPE_UNKNOWN = -1,
	NETCOMMANDTYPE_KEEPALIVE = 12,
	NETCOMMANDTYPE_DISCONNECTKEEPALIVE = 0x19
};

class NetCommandMsg
{
public:
	NetCommandMsg();
protected:
	virtual ~NetCommandMsg() {}
protected:
	UnsignedInt m_timestamp;
	UnsignedInt m_executionFrame;
	UnsignedInt m_playerID;
	UnsignedShort m_id;
	NetCommandType m_commandType;
	Int m_referenceCount;
};

// ??0NetCommandMsg@@QAE@XZ
NetCommandMsg::NetCommandMsg()
{
	m_executionFrame = (UnsignedInt)-1;
	m_timestamp = (UnsignedInt)-1;
	m_id = 0;
	m_playerID = 0;
	m_commandType = NETCOMMANDTYPE_UNKNOWN;
	m_referenceCount = 1;
}

// ??0NetKeepAliveCommandMsg@@QAE@XZ, retail 0x004D57C7, 21 bytes. Calls the
// base above then stamps KEEPALIVE (12, +0x14) and its vtable 0x860244. Donor
// is BFME1 NetCommandMsg_ctors.cpp (NetKeepAliveCommandMsg, no members).
class NetKeepAliveCommandMsg : public NetCommandMsg
{
public:
	NetKeepAliveCommandMsg();
};

// ??0NetKeepAliveCommandMsg@@QAE@XZ
NetKeepAliveCommandMsg::NetKeepAliveCommandMsg() : NetCommandMsg()
{
	m_commandType = NETCOMMANDTYPE_KEEPALIVE;
}

// ??0NetDisconnectKeepAliveCommandMsg@@QAE@XZ @0x004D57DC 21B: calls base plus stamps DISCONNECTKEEPALIVE (0x19) plus vtable 0x860244 shared via ICF.
// Donor BFME1 NetCommandMsg_ctors.cpp DisconnectKeepAlive (no members).
class NetDisconnectKeepAliveCommandMsg : public NetCommandMsg
{
public:
	NetDisconnectKeepAliveCommandMsg();
};

NetDisconnectKeepAliveCommandMsg::NetDisconnectKeepAliveCommandMsg() : NetCommandMsg()
{
	m_commandType = NETCOMMANDTYPE_DISCONNECTKEEPALIVE;
}

// ??0Rva004D5795@@QAE@XZ @0x004D5795 25B: calls base plus vtable 0x860224 plus byte 0 at +0x1c plus type 10 at +0x14.
// Vtable 0x860224 names unknown owner; honest-address ctor with 1-byte derived member.
class Rva004D5795 : public NetCommandMsg
{
public:
	Rva004D5795();
private:
	bool m_1c;
};

Rva004D5795::Rva004D5795() : NetCommandMsg()
{
	m_1c = 0;
	m_commandType = (NetCommandType)10;
}

// ??0Rva004D57AE@@QAE@XZ @0x004D57AE 25B: calls base plus dword 0 at +0x1c via And plus vtable 0x860234 plus type 11 at +0x14.
// Honest-address ctor with 4-byte derived member; And is /O1 size form of =0.
class Rva004D57AE : public NetCommandMsg
{
public:
	Rva004D57AE();
private:
	unsigned int m_1c;
};

Rva004D57AE::Rva004D57AE() : NetCommandMsg()
{
	m_1c = 0;
	m_commandType = (NetCommandType)11;
}

// ??0Rva004D582B@@QAE@XZ @0x004D582B 25B: calls base plus vtable 0x860244 plus type 15 plus byte 0 at +0x1c.
// Honest-address ctor with 1-byte derived member sharing KeepAlive vtable via ICF.
class Rva004D582B : public NetCommandMsg
{
public:
	Rva004D582B();
private:
	bool m_1c;
};

Rva004D582B::Rva004D582B() : NetCommandMsg()
{
	m_commandType = (NetCommandType)15;
	m_1c = 0;
}

// ??0Rva004D59B8@@QAE@XZ @0x004D59B8 25B: calls base plus dword 0 at +0x1c via And plus vtable 0x860244 plus type 28 at +0x14.
// Honest-address ctor with 4-byte derived member sharing KeepAlive vtable via ICF.
class Rva004D59B8 : public NetCommandMsg
{
public:
	Rva004D59B8();
private:
	unsigned int m_1c;
};

Rva004D59B8::Rva004D59B8() : NetCommandMsg()
{
	m_1c = 0;
	m_commandType = (NetCommandType)28;
}

// ??0Rva004D57F1@@QAE@XZ @0x004D57F1 29B: calls base plus dword 0 at +0x24 via And plus vtable 0x860244 plus type 26 plus byte 0 at +0x1c.
// Honest-address ctor with 4-byte plus 1-byte derived members sharing KeepAlive vtable via ICF.
class Rva004D57F1 : public NetCommandMsg
{
public:
	Rva004D57F1();
private:
	bool m_1c;
	char m_pad1D[0x24 - 0x1D];
	unsigned int m_24;
};

Rva004D57F1::Rva004D57F1() : NetCommandMsg()
{
	m_24 = 0;
	m_commandType = (NetCommandType)26;
	m_1c = 0;
}

// ??0Rva004D580E@@QAE@XZ @0x004D580E 29B: calls base plus dword 0 at +0x20 via And plus vtable 0x860244 plus type 27 plus byte 0 at +0x1c.
// Honest-address ctor with 4-byte plus 1-byte derived members sharing KeepAlive vtable via ICF; same recipe as Rva004D57F1 above with m_20.
// Callers at 0x004D3A3D 0x0058DFDC.
class Rva004D580E : public NetCommandMsg
{
public:
	Rva004D580E();
private:
	bool m_1c;
	char m_pad1D[0x20 - 0x1D];
	unsigned int m_20;
};

Rva004D580E::Rva004D580E() : NetCommandMsg()
{
	m_20 = 0;
	m_commandType = (NetCommandType)27;
	m_1c = 0;
}

// ??0NetWrapperCommandMsg@@QAE@XZ @0x004D5844 45B: calls base plus six dword 0 at +0x1c/+0x20/+0x24/+0x28/+0x2c/+0x30 plus word 0 at +0x34 plus vtable 0x860254 plus type 18 (WRAPPER).
// Real name via vtable 0x860254 and sibling dtor ??1NetWrapperCommandMsg@@MAE@XZ at 0x004D5871; same /O1 recipe as ctors above.
// Callers at 0x0058E108 0x00594762.
class NetWrapperCommandMsg : public NetCommandMsg
{
public:
	NetWrapperCommandMsg();
private:
	unsigned int m_1c;
	unsigned int m_20;
	unsigned int m_24;
	unsigned int m_28;
	unsigned int m_2c;
	unsigned int m_30;
	unsigned short m_34;
};

NetWrapperCommandMsg::NetWrapperCommandMsg() : NetCommandMsg()
{
	m_30 = 0;
	m_1c = 0;
	m_28 = 0;
	m_2c = 0;
	m_20 = 0;
	m_24 = 0;
	m_34 = 0;
	m_commandType = (NetCommandType)18;
}

// ??0Rva004D59D1@@QAE@XZ @0x004D59D1 29B: calls base plus dword 0 at +0x1c via And plus dword -1 at +0x20 via Or plus vtable 0x860274 plus type 8.
// Honest-address ctor; same /O1 And/Or recipe as siblings above; unblocks 0x0058E367.
// Callers at 0x004D1E37 0x0058E38C.
class Rva004D59D1 : public NetCommandMsg
{
public:
	Rva004D59D1();
private:
	unsigned int m_1c;
	unsigned int m_20;
};

Rva004D59D1::Rva004D59D1() : NetCommandMsg()
{
	m_1c = 0;
	m_20 = (unsigned int)-1;
	m_commandType = (NetCommandType)8;
}

// ??0Rva004D5A30@@QAE@XZ @0x004D5A30 29B: calls base plus dword 0 at +0x1c via And plus dword 0 at +0x20 via And plus vtable 0x860294 plus type 9.
// Honest-address ctor; same /O1 And recipe as siblings above; unblocks 0x0058E481 0x004CFD06.
// Callers at 0x004CFDA2 0x0058E4A5.
class Rva004D5A30 : public NetCommandMsg
{
public:
	Rva004D5A30();
private:
	unsigned int m_1c;
	unsigned int m_20;
};

Rva004D5A30::Rva004D5A30() : NetCommandMsg()
{
	m_1c = 0;
	m_20 = 0;
	m_commandType = (NetCommandType)9;
}

// ??0Rva004D60CA@@QAE@XZ @0x004D60CA 25B: calls base plus dword 0 at +0x1c via And plus vtable 0x860464 plus type 13 at +0x14.
// Honest-address ctor; same /O1 And recipe as siblings above; unblocks 0x004D187B 0x0059205C.
// Callers at 0x004D18A3 0x00592083.
class Rva004D60CA : public NetCommandMsg
{
public:
	Rva004D60CA();
private:
	unsigned int m_1c;
};

Rva004D60CA::Rva004D60CA() : NetCommandMsg()
{
	_ReadWriteBarrier();
	m_1c = 0;
	m_commandType = (NetCommandType)0xd;
}

// ??0Rva004D64F5@@QAE@XZ @0x004D64F5 25B: calls base plus vtable 0x86050C plus dword 0 at +0x1c via And plus type 5 at +0x14.
// Honest-address ctor; same barrier-pinned vptr-first recipe as Rva004D60CA above; unblocks 0x004D342A 0x00592496.
// Callers at 0x004D3548 0x005924BF.
class Rva004D64F5 : public NetCommandMsg
{
public:
	Rva004D64F5();
private:
	unsigned int m_1c;
};

Rva004D64F5::Rva004D64F5() : NetCommandMsg()
{
	_ReadWriteBarrier();
	m_1c = 0;
	m_commandType = (NetCommandType)5;
}

// ??0Rva004D6134@@QAE@XZ @0x004D6134 29B: calls base plus vtable 0x860474 plus dword 0 at +0x1c via And plus dword 0 at +0x20 via And plus type 14 at +0x14.
// Honest-address ctor; same barrier-pinned vptr-first recipe as siblings above; unblocks 0x00592123 0x004D17C5.
// Callers at 0x004D17ED 0x0059214A.
template <class T> class StringBase
{
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
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
class Rva004D6134 : public NetCommandMsg
{
public:
	Rva004D6134();
protected:
	virtual ~Rva004D6134();
private:
	StringBase<unsigned short> m_1c;
	unsigned int m_20;
};

Rva004D6134::Rva004D6134() : NetCommandMsg()
{
	_ReadWriteBarrier();
	m_20 = 0;
	m_commandType = (NetCommandType)0xe;
}

// ??1Rva004D6134@@MAE@XZ, retail 0x004D6151, 54 bytes. Protected virtual
// dtor for Rva004D6134 (vtable 0x860474, base NetCommandMsg vtable 0x860130):
// stores derived vptr, destroys wide-string member at +0x1C via the rowed
// releaseBuffer at 0x00036E70, reinstalls base vptr. Member at +0x1C is a
// 4-byte StringBase<ushort> nulled inline in the ctor (And form preserved).
// Caller at 0x004D6AA0 is the deleting dtor at 0x004D6A9D (slot 0).
Rva004D6134::~Rva004D6134()
{
}

// ??0Rva004D65DC@@QAE@XZ @0x004D65DC 29B: calls base plus vtable 0x860530 plus dword 0 at +0x1c via And plus dword 0 at +0x20 via And plus type 6 at +0x14.
// Honest-address ctor; same barrier-pinned vptr-first recipe as siblings above; unblocks 0x00592520 0x004D12B2.
// Callers at 0x004D1346 0x00592549.
class Rva004D65DC : public NetCommandMsg
{
public:
	Rva004D65DC();
private:
	unsigned int m_1c;
	unsigned int m_20;
};

Rva004D65DC::Rva004D65DC() : NetCommandMsg()
{
	_ReadWriteBarrier();
	m_1c = 0;
	m_20 = 0;
	m_commandType = (NetCommandType)6;
}
