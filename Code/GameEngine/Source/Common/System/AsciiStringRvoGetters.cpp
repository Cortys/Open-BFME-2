// cl: /O1 /Oy- /DNDEBUG /MD /GX
//
// Value-returning AsciiString getters with the RVO idiom proven by
// GlobalDataRva002360DE.cpp (retail 0x002360DE, 30 bytes):
// each returns the string member at its offset via the hidden return
// pointer; the member copy-constructs directly into it (RVO) through
// the StringBase copy body at 0x365F0, and the function returns the
// hidden pointer. Class names are address-derived (identity
// unrecoverable from 30 bytes); member names positional.

typedef int Int;
typedef unsigned short WideChar;

#define NULL 0

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;

public:
	StringBase() : m_data(0) {}

private:
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	__forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString();
	AsciiString &operator=(const AsciiString &other);
};

class UnicodeString : public StringBase<WideChar>
{
public:
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	~UnicodeString();
};

class Rva00274DB6AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x79C];
	AsciiString m_value; // +0x79C
};

// ?get@Rva00274DB6AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva00274DB6AsciiField::get() const
{
	return m_value;
}

class Rva00291775AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x318];
	AsciiString m_value; // +0x318
};

// ?get@Rva00291775AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva00291775AsciiField::get() const
{
	return m_value;
}

class Rva003821B9AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x1A8];
	AsciiString m_value; // +0x1A8
};

// ?get@Rva003821B9AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva003821B9AsciiField::get() const
{
	return m_value;
}

class Rva00382216AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x1B8];
	AsciiString m_value; // +0x1B8
};

// ?get@Rva00382216AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva00382216AsciiField::get() const
{
	return m_value;
}

class Rva00095224AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0xAC];
	AsciiString m_value; // +0xAC
};

// ?get@Rva00095224AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva00095224AsciiField::get() const
{
	return m_value;
}

class Rva0046AA11AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x308];
	AsciiString m_value; // +0x308
};

// ?get@Rva0046AA11AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva0046AA11AsciiField::get() const
{
	return m_value;
}

class Rva004CFB6DAsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x1D8];
	AsciiString m_value; // +0x1D8
};

// ?get@Rva004CFB6DAsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva004CFB6DAsciiField::get() const
{
	return m_value;
}

class Rva004DC902AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x188];
	AsciiString m_value; // +0x188
};

// ?get@Rva004DC902AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva004DC902AsciiField::get() const
{
	return m_value;
}

class Rva004FDCE1AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x1B0];
	AsciiString m_value; // +0x1B0
};

// ?get@Rva004FDCE1AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva004FDCE1AsciiField::get() const
{
	return m_value;
}

class Rva004FDD6DAsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x1DC];
	AsciiString m_value; // +0x1DC
};

// ?get@Rva004FDD6DAsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva004FDD6DAsciiField::get() const
{
	return m_value;
}

class Rva0056D653AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x258];
	AsciiString m_value; // +0x258
};

// ?get@Rva0056D653AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva0056D653AsciiField::get() const
{
	return m_value;
}

class Rva00581777AsciiField
{
public:
	AsciiString get() const;
	void rva00581740(AsciiString value);

private:
	char m_pad[0x1C8];
	AsciiString m_value; // +0x1C8
};

// ?get@Rva00581777AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva00581777AsciiField::get() const
{
	return m_value;
}

// ?rva00581740@Rva00581777AsciiField@@QAEXVAsciiString@@@Z, retail 0x00581740, 55 bytes.
// Setter for the same +0x1C8 member the getter above returns: abuts it
// (0x581740+55=0x581777), same class and offset. Takes AsciiString by value
// (lea eax,[ebp+8]; ret 4), assigns via rowed operator= then destroys the copy
// via rowed releaseBuffer with EH unwind (mov eax,scope; call __EH_prolog).
// Caller at 0x00582C77 passes a temp built from [ebp+8]+0x3A to this GameSlot-sized
// owner at [ebp-0x3E8]. Same // cl: as getters. Retail computes the member
// address before pushing the value (lea, add, push), so the slot reference
// form is needed for the byte-exact order.
void Rva00581777AsciiField::rva00581740(AsciiString value)
{
	AsciiString &slot = m_value;
	slot = value;
}

class Rva0059F322AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0xFFC];
	AsciiString m_value; // +0xFFC
};

// ?get@Rva0059F322AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva0059F322AsciiField::get() const
{
	return m_value;
}

class Rva0059F340AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0xFDC];
	AsciiString m_value; // +0xFDC
};

// ?get@Rva0059F340AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva0059F340AsciiField::get() const
{
	return m_value;
}
