// Ported from Open-BFME-1's game/GameEngine/Source/Common/SmallGaps/Rva0083ED40StreamStateReport.cpp
// (donor revision: reference/open-bfme-1 @ a38d345e) by tools/bfme1_sweep.py,
// tier T1: 0x0083ED70 (53B) -> 0x0001BDD0 (53B), "1 DIR32 string literal(s)
// agree". The donor uses build.py's base flags, so no // cl: line.
//
// The donor is held at copy-tier S because the sweep placed only addState out
// of the file's five methods. This TU carries that one body, and keeps the
// donor's __forceinline clearState because addState's bytes ARE clearState
// inlined -- writing the logic out by hand would risk a different inlining
// shape. clearState is __forceinline and used only here, so it emits no symbol
// of its own.
//
// No pin is needed: the failure path reports through g_call, which the donor
// reaches through a POINTER (a DIR32 reference, not a REL32 call), so the
// address slot is copied from retail rather than proved by a pin.

extern void* g_global;
extern void (__cdecl* g_call)(const char* what, void* where);

// ?addState@Rva0083ED40Stream@@QAEXH@Z -- 0x0001BDD0
struct Rva0083ED40Stream {
	int m_0; int m_4;
	int m_state;
	int m_c; int m_10;
	int m_exceptions;
	char m_pad[0x58 - 0x18];
	void* m_buffer;
	void addState(int state);

	__forceinline void clearState(int state)
	{
		if (!m_buffer)
			state |= 1;
		m_state = state;
		if (m_exceptions & state)
			g_call("ios failure", (char*)g_global + 0x40);
	}
};

void Rva0083ED40Stream::addState(int state)
{
	clearState(m_state | state);
}
