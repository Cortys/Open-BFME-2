// ??0Rva005C18F0@@QAE@XZ
// partial score=0.93 date=2026-09-28
// ??0Rva005C18F0@@QAE@XZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHs

// ??0Rva005C18F0@@QAE@XZ, RVA 0x005C1896, 62B. Unlock lane: default ctor
// storing 0x00A06034 at +4, constructing the member at +8 through rowed
// ??0StrategicStatsPreferences@@QAE@ABVUnicodeString@@@Z at 0x00537DBC with
// the global UnicodeString at 0x00A0C898, storing vtable 0x008743C4 under EH
// state 0. Both data addresses are unclaimed with no ledger symbol so they
// are raw immediates (reinterpret_cast precedent for unclaimed data). Member
// size is a placeholder: nothing follows it. Caller at 0x005C19FD in
// 0x005C19B6. Flags copy Rva005C18F0Dtor.cpp.
class UnicodeString
{
public:
	UnicodeString(const UnicodeString &);
private:
	void *m_data;
};

class StrategicStatsPreferences
{
public:
	StrategicStatsPreferences(const UnicodeString &);
private:
	char m_pad[4];
};

class Rva005C18F0Base
{
public:
	virtual ~Rva005C18F0Base() {}
};

class Rva005C18F0 : public Rva005C18F0Base
{
public:
	Rva005C18F0();
private:
	char *m_04;
	StrategicStatsPreferences m_08;
};

// ??0Rva005C18F0@@QAE@XZ present-unmatched
Rva005C18F0::Rva005C18F0()
	: m_08(*reinterpret_cast<const UnicodeString *>(0x00A0C898)),
	  m_04(reinterpret_cast<char *>(0x00A06034))
{
}
